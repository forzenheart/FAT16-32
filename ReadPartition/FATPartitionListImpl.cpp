#include "ReadPartition/FATPartitionListImpl.h"
#include "ReadPartition/FATPhysicalDiskList.h"
#include "base/FATPartitionTypeIndicator.h"

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

	UINT8	u8MBRbuf[BUFFERSIZE] = {0};
	UINT8	u8EBRbuf[BUFFERSIZE] = {0};

	bool	bPartActiveFlag = false;
	UINT8	u8StartHead = 0;
	UINT8	u8StartSector = 0;
	UINT16	u16StartCylinder = 0;
	UINT8	u8EndHead = 0;
	UINT8	u8EndSector = 0;
	UINT16	u16EndCylinder = 0;
	INT64	i64SecUsedsize = 0;
	INT64	i64SecTolsize = 0;
	std::string	sType = "";

	CDiskPartition*	pDiskPartition = NULL;
	CPhysicalDiskList*	pPhyDiskL = CPhysicalDiskList::GetInstance();

	pPhyDiskL->EnumPhysicalDisk();

	for (int i = 0; i < pPhyDiskL->GetCount(); i++)
	{
		CPhysicalDisk*	pPhyDisk = pPhyDiskL->GetPhysicalDiskByID(i);
		pPhyDisk->ReadSector(0, u8MBRbuf, BUFFERSIZE);

		for (int j = 0; j < MBRPARTITIONNUM; j++)
		{
			//根据前面总扇区数目是否为0来判断该分区是否存在
			if (GETCONTENT(u8MBRbuf[MBR_SECS_PRE_PART+ j * BYTESOFPARTITION]) == FAT_ZERO)
			{
				break;
			}
			
			//It`s not a  Windows EBR partition
			if (!(GETCONTENT(u8MBRbuf[MBR_PARTION_TYPE + j * BYTESOFPARTITION]) == EBRTYPE1 ||
					GETCONTENT(u8MBRbuf[MBR_PARTION_TYPE + j * BYTESOFPARTITION]) == EBRTYPE2))
			{
				//Read the MBR Partition Information here
				bPartActiveFlag = GETCONTENT(u8MBRbuf[MBR_BOOTINDICATOR + j * BYTESOFPARTITION]);

				u8StartHead = GETCONTENT(u8MBRbuf[MBR_START_HEAD + j * BYTESOFPARTITION]);
				u8StartSector = GETCONTENT(u8MBRbuf[MBR_START_SECTOR + j * BYTESOFPARTITION]);
				u16StartCylinder = GETCONTENT(u8MBRbuf[MBR_START_CYLINDER + j * BYTESOFPARTITION]);

				sType = FATPartTypeName[GETCONTENT(u8MBRbuf[MBR_PARTION_TYPE + j * BYTESOFPARTITION])];

				u8EndHead = GETCONTENT(u8MBRbuf[MBR_END_HEAD + j * BYTESOFPARTITION]);
				u8EndSector = GETCONTENT(u8MBRbuf[MBR_END_SECTOR + j * BYTESOFPARTITION]);
				u16EndCylinder = GETCONTENT(u8MBRbuf[MBR_END_CYLINDER + j * BYTESOFPARTITION]);

				i64SecUsedsize = GETCONTENT(u8MBRbuf[MBR_SECS_PRE_PART + j * BYTESOFPARTITION]);
				i64SecTolsize = GETCONTENT(u8MBRbuf[MBR_SECSINPART + j * BYTESOFPARTITION]);

				pDiskPartition = new CDiskPartition(bPartActiveFlag,
						u8StartHead,
						u8StartSector,
						u16StartCylinder, 
						sType, 
						u8EndHead, 
						u8EndSector, 
						u16EndCylinder, 
						i64SecUsedsize, 
						i64SecTolsize);

				m_diskPartitionList.push_back(pDiskPartition);
			}
			else
			{
				//Get the EBR start sector number from the MBR
				pPhyDisk->ReadSector(GETCONTENT(u8MBRbuf[MBR_SECS_PRE_PART + j * BYTESOFPARTITION]),
						u8EBRbuf, BUFFERSIZE);
				while (GETCONTENT(u8EBRbuf[MBR_PARTION_TYPE + BYTESOFPARTITION]) == EBRTYPE1 ||
						GETCONTENT(u8EBRbuf[MBR_PARTION_TYPE + BYTESOFPARTITION]) == EBRTYPE2)
				{
					//Read the EBR Partition Information here
					bPartActiveFlag = GETCONTENT(u8EBRbuf[MBR_BOOTINDICATOR + j * BYTESOFPARTITION]);
					u8StartHead = GETCONTENT(u8EBRbuf[MBR_START_HEAD + j * BYTESOFPARTITION]);
					u8StartSector = GETCONTENT(u8EBRbuf[MBR_START_SECTOR + j * BYTESOFPARTITION]);
					u16StartCylinder = GETCONTENT(u8EBRbuf[MBR_START_CYLINDER + j * BYTESOFPARTITION]);

					sType = FATPartTypeName[GETCONTENT(u8EBRbuf[MBR_PARTION_TYPE + j * BYTESOFPARTITION])];

					u8EndHead = GETCONTENT(u8EBRbuf[MBR_END_HEAD + j * BYTESOFPARTITION]);
					u8EndSector = GETCONTENT(u8EBRbuf[MBR_END_SECTOR + j * BYTESOFPARTITION]);
					u16EndCylinder = GETCONTENT(u8EBRbuf[MBR_END_CYLINDER + j * BYTESOFPARTITION]);

					i64SecUsedsize = GETCONTENT(u8EBRbuf[MBR_SECS_PRE_PART + j * BYTESOFPARTITION]);
					i64SecTolsize = GETCONTENT(u8EBRbuf[MBR_SECSINPART + j * BYTESOFPARTITION]);

					pDiskPartition = new CDiskPartition(bPartActiveFlag,
							u8StartHead,
							u8StartSector,
							u16StartCylinder, 
							sType, 
							u8EndHead, 
							u8EndSector, 
							u16EndCylinder, 
							i64SecUsedsize, 
							i64SecTolsize);

					m_diskPartitionList.push_back(pDiskPartition);

					//Get the Next EBR start sector number
					pPhyDisk->ReadSector(GETCONTENT(u8EBRbuf[MBR_SECS_PRE_PART + BYTESOFPARTITION]),
							u8EBRbuf, BUFFERSIZE);
				}
			}
			
		}
	}
}

int
CPartitionListImpl::GetCount() const
{
	return m_diskPartitionList.size();
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
		//return m_diskPartitionList[which]->();
		return NULL;
	}
	return NULL;
}

