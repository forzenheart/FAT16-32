#ifndef	_FAT_PHYSICAL_DISK_H__
#define	_FAT_PHYSICAL_DISK_H__

#include "FATPartitionListImpl.h"

class CPhysicalDisk {
	friend	int CPartitionListImpl::EnumPhysicalDisk();
	//public:
		//virtual	INT64	ReadSector() = 0;
		//virtual	INT64	WriteSector() = 0;
	//protected:
		//virtual	int	Open() = 0;
		//virtual	int	Close() = 0;
		//virtual	INT64	Seek() = 0;
	private:
		//int	*m_diskHandle;
};

#endif	//_FAT_PHYSICAL_DISK_H__
