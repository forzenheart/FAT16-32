#ifndef	__FAT_DISKPARTITION_H__
#define	__FAT_DISKPARTITION_H__

#include "base/FATBasicDataDefine.h"

#include <string>

class CDiskPartition {
	public:
		CDiskPartition(
				bool a,
				UINT8 sh, 
				UINT8 ss, 
				UINT16 sc, 
				std::string pt, 
				UINT8 eh, 
				UINT8 es,
				UINT16 ec, 
				INT64 spp, 
				INT64 t, 
				INT64 used = 0, 
				INT64 unused = 0, 
				bool isprimary = true, 
				std::string partname = "*", 
				std::string volumename = "*");

		~CDiskPartition() {};

		bool	GetActivePartition() const {
			return m_ActivePartition;
		}
		UINT8	GetStartHeadNo()  const {
			return m_StartHeadNo;
		}
		UINT8	GetStartSecNO() const { 
			return m_StartSecNo;
		}
		UINT16	GetStartCylinderNo() const {
			return m_StartCylinderNo;
		}
		const std::string*	GetPartitionTypeIndicator() const  {
			return &m_PartitionTypeIndicator;
		}
		UINT8	GetEndHeadNo() const {
			return m_EndHeadNo;
		}
		UINT8	GetEndSecNo() const {
			return m_EndSecNo;
		}
		UINT16	GetEndCylinderNo() const {
			return m_EndCylinderNo;
		}
		INT64	GetSecPrecedingPartition() const {
			return m_SecPrecedingPartition;
		}
		INT64	GetTotalSec() const {
			return m_TotSec;
		}
		INT64	GetSpaceFree() const {
			return m_Unused;
		}
		INT64	GetSpaceUsed() const {
			return m_Used;
		}
		bool	IsPrimary() const {
			return m_IsPrimary;
		}
		const std::string* GetPartitionName() const {
			return &m_PartitionName;
		}
		const std::string* GetVolumeName() const {
			return &m_VolumeName;
		}

	private:
		bool	m_ActivePartition;	//活动分区标志
		UINT8	m_StartHeadNo;		//起始磁头号
		UINT8	m_StartSecNo;		//起始扇区号
		UINT16	m_StartCylinderNo;	//起始柱面号
		std::string	m_PartitionTypeIndicator;//分区格式标志
		UINT8	m_EndHeadNo;		//结束磁头号
		UINT8	m_EndSecNo;		//结束扇区号
		UINT16	m_EndCylinderNo;	//终止柱面号(柱面号的高2位存放在扇区字节的高2位)
		INT64	m_SecPrecedingPartition;//本分区之前已用扇区数目
		INT64	m_TotSec;		//本分区扇区总数

		//以下信息是与操作系统相关的，并不属于MBR或者GPT内容
		INT64	m_Used;			//已使用的空间
		INT64	m_Unused;		//未使用的空间
		bool	m_IsPrimary;		//MBR 微软扩展分区标志
		std::string	m_PartitionName;//硬盘分区名
		std::string	m_VolumeName;	//Windows卷标名
};
#endif	//__FAT_DISKPARTITION_H__
