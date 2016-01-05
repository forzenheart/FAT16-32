#ifndef	_FAT_PHYSICAL_DISK_LIST_IMPL_WINDOWS_H__
#define	_FAT_PHYSICAL_DISK_LIST_IMPL_WINDOWS_H__

#include "ReadPartition/FATPhysicalDiskListImpl.h"

class CPhysicalDiskListImplWindows : public CPhysicalDiskListImpl {
	public:
		virtual int	EnumPhysicalDisk();
};
#endif	//_FAT_PHYSICAL_DISK_LIST_IMPL_WINDOWS_H__
