#ifndef	_FAT_PHYSICAL_DISK_LINUX_H__
#define	_FAT_PHYSICAL_DISK_LINUX_H__
#include "ReadPartition/FATPhysicalDisk.h"

class CPhysicalDiskLinux : public CPhysicalDisk {
	public:
		CPhysicalDiskLinux(int_fast32_t fd);
		virtual int_fast64_t	ReadSector(int_fast64_t secNum, void *buf, int_fast64_t bytes);
		virtual int_fast64_t	WriteSector(int_fast64_t secNum, const void *buf, int_fast64_t bytes);
	protected:
		int_fast64_t	Seek(int_fast64_t secNum, int_fast32_t whence = 0);
};

#endif	//_FAT_PHYSICAL_DISK_LINUX_H__
