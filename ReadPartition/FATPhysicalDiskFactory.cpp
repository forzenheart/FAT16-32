#include "ReadPartition/FATPhysicalDiskFactory.h"

//windows
#if	FAT_TARGET_PLATFORM == FAT_PLATFORM_WINDOWS
#include "ReadPartition/windows/FATPhysicalDiskFactoryWindows.h"
#endif

//linux
#if	FAT_TARGET_PLATFORM == FAT_PLATFORM_LINUX
#include "ReadPartition/linux/FATPhysicalDiskFactoryLinux.h"
#endif

CPhysicalDiskFactory*
CPhysicalDiskFactory::GetPhysicalDiskFactory()
{
	static CPhysicalDiskFactory* physicalDiskFactory = NULL;
	
	if (physicalDiskFactory == NULL)
	{
#if	FAT_TARGET_PLATFORM == FAT_PLATFORM_LINUX
		physicalDiskFactory = CPhysicalDiskFactoryLinux::GetFactoryInstance();
#endif//Linux
#if	FAT_TARGET_PLATFORM == FAT_PLATFORM_WINDOWS
		physicalDiskFactory = CPhysicalDiskFactoryWindows::GetFactoryInstance();
#endif//Windows
	}
	return physicalDiskFactory;
}


