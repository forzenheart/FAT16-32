#include "ReadPartition/FATPartitionListImpl.h"
#include "ReadPartition/FATPhysicalDiskList.h"
#include "base/FATPartitionTypeIndicator.h"
#include <stdio.h>

//Notice the int bytes! 
#define	GETCONTENT(S)		(*((int*)(&(S))))
#define	BUFFERSIZE		4096
#define	MBRPARTITIONNUM		4
#define	BYTESOFPARTITION	16
#define	EBRTYPE1		0x0F
#define	EBRTYPE2		0x05
#define	FAT_ZERO		0x00


CPartitionListImpl*	CPartitionListImpl::m_partitionListImplInstance = NULL;

CPartitionListImpl*
CPartitionListImpl::GetInstance()
{
	if (m_partitionListImplInstance == NULL)
	{
		m_partitionListImplInstance = new CPartitionListImpl;
	}
	return m_partitionListImplInstance;
}

CPartitionListImpl::CPartitionListImpl()
{
	EnumPartition();	
}

CPartitionListImpl::CPartitionListImpl(const CPartitionListImpl&)
{

}

int
CPartitionListImpl::EnumPartition()
{
	m_diskPartitionList.clear();

	//分别用于储存MBR扇区和EBR扇区信息
	UINT8	u8MBRbuf[BUFFERSIZE] = {0};
	UINT8	u8EBRbuf[BUFFERSIZE] = {0};

	//获取物理磁盘句柄
	CPhysicalDiskList*	pPhyDiskL = CPhysicalDiskList::GetInstance();
	//枚举物理磁盘
	pPhyDiskL->EnumPhysicalDisk();

	for (int i = 0; i < pPhyDiskL->GetCount(); i++)
	{
		//分区类型有MBR磁盘分区和GPT磁盘分区
		CPhysicalDisk*	pPhyDisk = pPhyDiskL->GetPhysicalDiskByID(i);
		pPhyDisk->ReadSector(0, u8MBRbuf, BUFFERSIZE);
		//判断是否是GPT分区类型
		if (u8MBRbuf[GPT_PARTION_TYPE] == 0xEE
				&& u8MBRbuf[GPT_SECS_IN_PART] == 0XFF
				&& u8MBRbuf[GPT_SECS_IN_PART + 2] == 0xFF)
		{
			//!尚未处理GPT分区表
		}
		else
		{
			for (int j = 0; j< MBRPARTITIONNUM; j++)
			{
				//根据前面总扇区数目是否为0来判断该分区是否存在
				//if (GETCONTENT(u8MBRbuf[MBR_SECS_PRE_PART + j * BYTESOFPARTITION]) == FAT_ZERO)
				//{
					//break;
				//}
				//判断是否是EBR分区
				if (!(u8MBRbuf[MBR_PARTION_TYPE + j * BYTESOFPARTITION] == EBRTYPE1 ||
							u8MBRbuf[MBR_PARTION_TYPE + j * BYTESOFPARTITION] == EBRTYPE2))
				{
					//将MBR分区信息加入分区链表
					PushPartition(u8MBRbuf, j, true);
				}
				else
				{
					//判断为EBR分区，循环扫描并将EBR分区信息加入分区链表里面
					pPhyDisk->ReadSector(GETCONTENT(u8MBRbuf[MBR_SECS_PRE_PART + j * BYTESOFPARTITION]),
							u8EBRbuf, BUFFERSIZE);
					//EBR循环查找
					while (u8EBRbuf[MBR_PARTION_TYPE + BYTESOFPARTITION] == EBRTYPE1 ||
							u8EBRbuf[MBR_PARTION_TYPE + BYTESOFPARTITION] == EBRTYPE2)
					{
						//将EBR分区信息加入分区链表
						//EBR第一个分区信息为该EBR的信息，第二个分区位扩展分区信息
						PushPartition(u8EBRbuf, 0);
						//获取下一个EBR分区的开始扇区
						pPhyDisk->ReadSector(GETCONTENT(u8EBRbuf[MBR_SECS_PRE_PART + BYTESOFPARTITION]),
								u8EBRbuf, BUFFERSIZE);
					}
				}
			}
		}
	}
	return m_diskPartitionList.size();
}

int
CPartitionListImpl::GetCount() const
{
	return m_diskPartitionList.size();
}

int
CPartitionListImpl::PushPartition(UINT8 *buf, int n, bool isprimary)
{
	CDiskPartition*	pDiskPartition = NULL;

	bool	bPartActiveFlag = false;
	bool	bIsPrimary = isprimary;
	UINT8	u8StartHead = 0;
	UINT8	u8StartSector = 0;
	UINT16	u16StartCylinder = 0;
	UINT8	u8EndHead = 0;
	UINT8	u8EndSector = 0;
	UINT16	u16EndCylinder = 0;
	INT64	i64SecUsedsize = 0;
	INT64	i64SecTolsize = 0;
	INT64	i64Used = 0;
	INT64	i64Unused = 0;
	std::string	sType = "*";
	std::string	sPartName = "*";
	std::string	sVolumeName = "*";

	//获取分区信息
	bPartActiveFlag = buf[MBR_BOOTINDICATOR + n * BYTESOFPARTITION];
	u8StartHead = buf[MBR_START_HEAD + n * BYTESOFPARTITION];
	u8StartSector = buf[MBR_START_SECTOR + n * BYTESOFPARTITION];
	u16StartCylinder = buf[MBR_START_CYLINDER + n * BYTESOFPARTITION];
	sType = FATPartTypeName[buf[MBR_PARTION_TYPE + n * BYTESOFPARTITION]];
	u8EndHead = buf[MBR_END_HEAD + n * BYTESOFPARTITION];
	u8EndSector = buf[MBR_END_SECTOR + n * BYTESOFPARTITION];
	u16EndCylinder = buf[MBR_END_CYLINDER + n * BYTESOFPARTITION];
	i64SecUsedsize = GETCONTENT(buf[MBR_SECS_PRE_PART + n * BYTESOFPARTITION]);
	i64SecTolsize = GETCONTENT(buf[MBR_SECS_IN_PART + n * BYTESOFPARTITION]);
	//尚未获取非MBR内信息

	//如该分区总扇区数目为0, 则判断为空扇区
	if (i64SecTolsize == 0)
		return -1;
	//将获取的分区信息加入分区链表里面
	pDiskPartition = new CDiskPartition(bPartActiveFlag,
			u8StartHead,
			u8StartSector,
			u16StartCylinder, 
			sType, 
			u8EndHead, 
			u8EndSector, 
			u16EndCylinder, 
			i64SecUsedsize, 
			i64SecTolsize, 
			i64Used, 
			i64Unused, 
			bIsPrimary, 
			sPartName, 
			sVolumeName);

	m_diskPartitionList.push_back(pDiskPartition);
	if (pDiskPartition != NULL)
	{
		return 0;
	}
	return -1;
}

bool
CPartitionListImpl::GetActiveFlagByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetActivePartition();
	}
	return false;
}

bool
CPartitionListImpl::IsPrimary(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->IsPrimary();
	}
	return false;
}
UINT8
CPartitionListImpl::GetStartHeadNoByID(const int which)  const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetStartHeadNo();
	}
	return 0;
}

UINT8
CPartitionListImpl::GetStartSecNOByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetStartSecNO();
	}
	return 0;
}

UINT16
CPartitionListImpl::GetStartCylinderNoByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetStartCylinderNo();
	}
	return 0;
}

UINT8
CPartitionListImpl::GetEndHeadNoByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetEndHeadNo();
	}
	return 0;
}

UINT8
CPartitionListImpl::GetEndSecNoByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetEndSecNo();
	}
	return 0;
}

UINT16
CPartitionListImpl::GetEndCylinderNoByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetEndCylinderNo();
	}
	return 0;
}

INT64
CPartitionListImpl::GetSecPrecedingPartitionByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetSecPrecedingPartition();
	}
	return 0;
}

INT64
CPartitionListImpl::GetTotalSecByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetTotalSec();
	}
	return 0;
}

INT64
CPartitionListImpl::GetSpaceFreeByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetSpaceFree();
	}
	return 0;
}

INT64
CPartitionListImpl::GetSpaceUsedByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetSpaceUsed();
	}
	return 0;
}

const std::string*
CPartitionListImpl::GetPartitionTypeByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetPartitionTypeIndicator();
	}
	return NULL;
}

const std::string*
CPartitionListImpl::GetPartitionNameByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetPartitionName();
	}
	return NULL;
}

const std::string*
CPartitionListImpl::GetVolumeNameByID(const int which) const
{
	if (!m_diskPartitionList.empty())
	{
		return m_diskPartitionList[which]->GetVolumeName();
	}
	return NULL;
}
