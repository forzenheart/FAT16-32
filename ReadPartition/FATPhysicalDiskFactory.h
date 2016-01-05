#ifndef	_FAT_PHYSICAL_DISK_FACTORY_H__
#define	_FAT_PHYSICAL_DISK_FACTORY_H__

#include "ReadPartition/FATPhysicalDiskListImpl.h"

class CPhysicalDiskFactory {
	public:
		virtual ~CPhysicalDiskFactory() { };
		virtual CPhysicalDiskListImpl*	MakePhysicalDisk() = 0;
		static	CPhysicalDiskFactory*	GetPhysicalDiskFactory();
};

#endif	//_FAT_PHYSICAL_DISK_FACTORY_H__
