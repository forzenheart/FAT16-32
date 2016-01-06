#ifndef	_FAT_PHYSICAL_DISK_WINDOWS_H__
#define	_FAT_PHYSICAL_DISK_WINDOWS_H__

#include "ReadPartition/FATPhysicalDisk.h"

class CPhysicalDiskWindows : public CPhysicalDisk
{
	public:
		CPhysicalDiskWindows(void *handle);
		virtual INT64	ReadSector(INT64 secNum, void *buf, INT64 bytes);
		virtual INT64	WriteSector(INT64 secNum, const void *buf, INT64 bytes);
	protected:
		virtual INT64	Seek(INT64 secNum, int whence = 0);
};

#endif	//_FAT_PHYSICAL_DISK_WINDOWS_H__
