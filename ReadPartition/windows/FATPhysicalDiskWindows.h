#ifndef	_FAT_PHYSICAL_DISK_WINDOWS_H__
#define	_FAT_PHYSICAL_DISK_WINDOWS_H__

#include "ReadPartition/FATPhysicalDisk.h"

class CPhysicalDiskWindows : public CPhysicalDisk
{
	public:
		CPhysicalDiskWindows(void *handle);
		virtual int_fast64_t	ReadSector(int_fast64_t secNum, void *buf, int_fast64_t bytes);
		virtual int_fast64_t	WriteSector(int_fast64_t secNum, const void *buf, int_fast64_t bytes);
	protected:
		virtual int_fast64_t	Seek(int_fast64_t secNum, int_fast32_t whence = 0);
};

#endif	//_FAT_PHYSICAL_DISK_WINDOWS_H__
