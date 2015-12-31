#ifndef	_FAT_PARTITIONLISTIMPL_LINUX_H__
#define	_FAT_PARTITIONLISTIMPL_LINUX_H__

#include "FATPartitionListImpl.h"

class CPartitionListImplLinux : public CPartitionListImpl {
	public:
		//enum the physical information on different platform
		int	EnumPhysicalDisk();
};
#endif	//_FAT_PARTITIONLISTIMPL_LINUX_H__
