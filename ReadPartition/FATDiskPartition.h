#ifndef	__FAT_DISKPARTITION_H__
#define	__FAT_DISKPARTITION_H__

#include "base/FATBasicDataDefine.h"

#include <string>

class CDiskPartition {
	public:
		CDiskPartition(
				bool a,
				uint_fast8_t sh, 
				uint_fast8_t ss, 
				uint_fast16_t sc, 
				std::string pt, 
				uint_fast8_t eh, 
				uint_fast8_t es,
				uint_fast16_t ec, 
				int_fast64_t spp, 
				int_fast64_t t, 
				int_fast64_t used = 0, 
				int_fast64_t unused = 0, 
				bool isprimary = true, 
				std::string partname = "*", 
				std::string volumename = "*");

		~CDiskPartition() {};

		bool	GetActivePartition() const {
			return m_ActivePartition;
		}
		uint_fast8_t	GetStartHeadNo()  const {
			return m_StartHeadNo;
		}
		uint_fast8_t	GetStartSecNO() const { 
			return m_StartSecNo;
		}
		uint_fast16_t	GetStartCylinderNo() const {
			return m_StartCylinderNo;
		}
		const std::string*	GetPartitionTypeIndicator() const  {
			return &m_PartitionTypeIndicator;
		}
		uint_fast8_t	GetEndHeadNo() const {
			return m_EndHeadNo;
		}
		uint_fast8_t	GetEndSecNo() const {
			return m_EndSecNo;
		}
		uint_fast16_t	GetEndCylinderNo() const {
			return m_EndCylinderNo;
		}
		int_fast64_t	GetSecPrecedingPartition() const {
			return m_SecPrecedingPartition;
		}
		int_fast64_t	GetTotalSec() const {
			return m_TotSec;
		}
		int_fast64_t	GetSpaceFree() const {
			return m_Unused;
		}
		int_fast64_t	GetSpaceUsed() const {
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
		uint_fast8_t	m_StartHeadNo;		//起始磁头号
		uint_fast8_t	m_StartSecNo;		//起始扇区号
		uint_fast16_t	m_StartCylinderNo;	//起始柱面号
		std::string	m_PartitionTypeIndicator;//分区格式标志
		uint_fast8_t	m_EndHeadNo;		//结束磁头号
		uint_fast8_t	m_EndSecNo;		//结束扇区号
		uint_fast16_t	m_EndCylinderNo;	//终止柱面号(柱面号的高2位存放在扇区字节的高2位)
		int_fast64_t	m_SecPrecedingPartition;//本分区之前已用扇区数目
		int_fast64_t	m_TotSec;		//本分区扇区总数

		//以下信息是与操作系统相关的，并不属于MBR或者GPT内容
		int_fast64_t	m_Used;			//已使用的空间
		int_fast64_t	m_Unused;		//未使用的空间
		bool	m_IsPrimary;		//MBR 微软扩展分区标志
		std::string	m_PartitionName;//硬盘分区名
		std::string	m_VolumeName;	//Windows卷标名
};
#endif	//__FAT_DISKPARTITION_H__
