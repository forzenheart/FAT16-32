#ifndef	_FAT_PHYSICAL_DISK_LINUX_H__
#define	_FAT_PHYSICAL_DISK_LINUX_H__
#include "ReadPartition/FATPhysicalDisk.h"

class CPhysicalDiskLinux : public CPhysicalDisk {
	public:
		CPhysicalDiskLinux(int fd);
		INT64	ReadSector(INT64 secNum, void *buf, INT64 bytes);
		INT64	WriteSector(INT64 secNum, const void *buf, INT64 bytes);
	protected:
		INT64	Seek(INT64 secNum, int whence = 0);
};

#endif	//_FAT_PHYSICAL_DISK_LINUX_H__
