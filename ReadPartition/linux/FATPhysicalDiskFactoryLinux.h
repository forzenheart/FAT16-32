#ifndef	_FAT_PHYSICAL_DISK_FACTORY_LINUX_H__
#define	_FAT_PHYSICAL_DISK_FACTORY_LINUX_H__

#include "ReadPartition/FATPhysicalDiskFactory.h"

class CPhysicalDiskFactoryLinux : public CPhysicalDiskFactory
{
	public:
	static CPhysicalDiskFactoryLinux* GetFactoryInstance()
	{
		static CPhysicalDiskFactoryLinux * factory = NULL;
		if (factory == NULL)
		{
			factory = new CPhysicalDiskFactoryLinux;
		}
		return factory;
	}
	virtual ~CPhysicalDiskFactoryLinux();
	virtual CPhysicalDiskListImpl*	MakePhysicalDisk();
	private:
	CPhysicalDiskFactoryLinux();
	CPhysicalDiskFactoryLinux(const CPhysicalDiskFactoryLinux&);
};

#endif	//_FAT_PHYSICAL_DISK_FACTORY_LINUX_H__
