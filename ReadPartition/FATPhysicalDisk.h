#ifndef	_FAT_PHYSICAL_DISK_H__
#define	_FAT_PHYSICAL_DISK_H__

#include "base/FATBasicDataDefine.h"

class CPhysicalDisk {
	friend	 class CPhysicalDiskListImpl;
	public:
	virtual	INT64	ReadSector(INT64 secNum, void *buf, INT64 bytes) = 0;
	virtual	INT64	WriteSector(INT64 secNum, const void *buf, INT64 bytes) = 0;
	protected:
	virtual	INT64	Seek(INT64 secNum, int whence = 0) = 0;

	CPhysicalDisk(void *handle);
	CPhysicalDisk(int fd);
	union {
		void	*HANDLE;
		int	fd;
	} m_diskHandle;
};

#endif	//_FAT_PHYSICAL_DISK_H__
