#ifndef __FAT_DISK_PARTITION_LIST_H__
#define	__FAT_DISK_PARTITION_LIST_H__
#include "MBRFactory.h"

class CDiskPartitionList {
	public:
		CDiskPartitionList();
		~CDiskPartitionList();
		int	Scan();
		bool	GetPartitionActiveFlag(const int which) const;
		INT64	GetPartitionTolSec(const int which) const;
		const std::string*	GetPartitionName(const int which) const;
		int	GetPartitionCount() const;
	private:
		CMBR	*m_diskPartitionImpl;
};

#endif //__FAT_DISK_PARTITION_LIST_H__
