#ifndef	_FAT_PARTITIONLISTIMPL_WINDOWS_H__
#define	_FAT_PARTITIONLISTIMPL_WINDOWS_H__

#include "../FATPartitionListImpl.h"

class CPartitionListImplWindows : public CPartitionListImpl {
	public:
		int EnumPhysicalDisk();
};
#endif	//_FAT_PARTITIONLISTIMPL_WINDOWS_H__
