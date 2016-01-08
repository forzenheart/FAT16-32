#ifndef	_FAT_PHYSICAL_DISK_H__
#define	_FAT_PHYSICAL_DISK_H__

#include "base/FATBasicDataDefine.h"

class CPhysicalDisk {
	friend	 class CPhysicalDiskListImpl;
	public:
	virtual	int_fast64_t	ReadSector(int_fast64_t secNum, void *buf, int_fast64_t bytes) = 0;
	virtual	int_fast64_t	WriteSector(int_fast64_t secNum, const void *buf, int_fast64_t bytes) = 0;

	protected:
	virtual	int_fast64_t	Seek(int_fast64_t secNum, int_fast32_t whence = 0) = 0;

	CPhysicalDisk(void *handle);
	CPhysicalDisk(int_fast32_t fd);

	union {
		void	*HANDLE;
		int_fast32_t	fd;
	} m_diskHandle;
};

#endif	//_FAT_PHYSICAL_DISK_H__
