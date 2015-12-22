#ifndef	__FAT_DISKPARTITION_H__
#define	__FAT_DISKPARTITION_H__

#include "../base/FATBasicDataDefine.h"
#include <string>

class CDiskPartition {
	public:
		CDiskPartition(
				bool a,
				INT8 sh, 
				INT8 ss, 
				INT8 sc, 
				INT8 pt, 
				INT8 eh, 
				INT8 es,
				INT8 ec, 
				INT32 spp, 
				INT32 t, 
				std::string name = "") 
			:
			m_ActivePartition(a), 
			m_StartHeadNo(sh), 
			m_StartSecNo(ss), 
			m_StartCylinderNo(sc), 
			m_PartitionTypeIndicator(pt), 
			m_EndHeadNo(eh), 
			m_EndSecNo(es), 
			m_EndCylinderNo(ec), 
			m_SecPrecedingPartition(spp), 
			m_TotSec(t), 
			m_PartitionName(name)
			{ }

		~CDiskPartition();

		bool	GetActivePartition() const {
			return m_ActivePartition;
		}
		INT8	GetStartHeadNo()  const {
			return m_StartHeadNo;
		}
		INT8	GetStartSecNO() const { 
			return m_StartSecNo;
		}
		INT8	GetStartCylinderNo() const {
			return m_StartCylinderNo;
		}
		INT8	GetPartitionTypeIndicator() const  {
			return m_PartitionTypeIndicator;
		}
		INT8	GetEndHeadNo() const {
			return m_EndHeadNo;
		}
		INT8	GetEndSecNo() const {
			return m_EndSecNo;
		}
		INT8	GetEndCylinderNo() const {
			return m_EndCylinderNo;
		}
		INT32	GetSecPrecedingPartition() const {
			return m_SecPrecedingPartition;
		}
		INT32	GetTotalSec() const {
			return m_TotSec;
		}
		const std::string GetName() const {
			return m_PartitionName;
		}

	private:
		bool	m_ActivePartition;//活动分区标志
		INT8	m_StartHeadNo;//起始磁头号
		INT8	m_StartSecNo;//起始扇区号
		INT8	m_StartCylinderNo;//起始柱面号
		INT8	m_PartitionTypeIndicator;//分区格式标志
		INT8	m_EndHeadNo;//结束磁头号
		INT8	m_EndSecNo;//结束扇区号
		INT8	m_EndCylinderNo;//终止柱面号(柱面号的高2位存放在扇区字节的高2位)
		INT32	m_SecPrecedingPartition;//本分区之前已用扇区数目
		INT32	m_TotSec;//本分区扇区总数
		std::string	m_PartitionName;//注意这个成员变量并不属于磁盘分区的标准，是为了方便自己加的
};
#endif	//__FAT_DISKPARTITION_H__
