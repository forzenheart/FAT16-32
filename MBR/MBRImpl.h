#ifndef	__FAT_MBR_H__
#define	__FAT_MBR_H__

#include "DiskPartition.h"
#include <vector>


class CMBR {
	public:
		CMBR(); 
		virtual ~CMBR();

		virtual int Scan() = 0;
		int GetPartitionCount() const;
		const std::string GetPartitionName(const int id) const;
		INT64	GetPartitionTolSec(const int id) const;
		bool	GetPartitionActiveFlag(const int id) const;
	protected:
		std::vector<CDiskPartition>	m_partitionList;
};

#endif	//__FAT_MBR_H__

