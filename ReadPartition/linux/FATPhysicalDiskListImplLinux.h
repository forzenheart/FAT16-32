#ifndef	_FAT_PHYSICAL_DISK_LISTIMPL_LINUX_H__
#define	_FAT_PHYSICAL_DISK_LISTIMPL_LINUX_H__

#include "ReadPartition/FATPhysicalDiskListImpl.h"

class CPhysicalDiskListImplLinux : public CPhysicalDiskListImpl {
	public:
		virtual int_fast32_t	EnumPhysicalDisk();
};
#endif	//_FAT_PHYSICAL_DISK_LISTIMPL_LINUX_H__
