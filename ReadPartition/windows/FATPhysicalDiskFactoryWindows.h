#ifndef	_FAT_PHYSICAL_DISK_FACTORY_WINDOWS_H__
#define	_FAT_PHYSICAL_DISK_FACTORY_WINDOWS_H__

#include "ReadPartition/FATPhysicalDiskFactory.h"

class CPhysicalDiskFactoryWindows : public CPhysicalDiskFactory
{
	public:
	static CPhysicalDiskFactoryWindows* GetFactoryInstance()
	{
		static CPhysicalDiskFactoryWindows * factory = NULL;
		if (!factory)
		{
			factory = new CPhysicalDiskFactoryWindows;
		}
		return factory;
	}
	virtual ~CPhysicalDiskFactoryWindows();
	virtual CPhysicalDiskListImpl*	MakePhysicalDisk();
	private:
	CPhysicalDiskFactoryWindows();
	CPhysicalDiskFactoryWindows(const CPhysicalDiskFactoryWindows&);
};

#endif	//_FAT_PHYSICAL_DISK_FACTORY_WINDOWS_H__
