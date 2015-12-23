class CMBRFactory;

#if FAT_TARGET_PLATFORM == FAT_PLATFORM_LINUX
#include "linux/MBRFactoryLinux.h"
#endif	//linux platform

#if FAT_TARGET_PLATFORM == FAT_PLATFORM_WINDOWS
#include "windows\MBRFactoryWindows.h"
#endif	//windows platform

CMBRFactory*
CMBRFactory::GetMBRFactory()
{
	static CMBRFactory *cMBRFactory = 0;

	if (!cMBRFactory)
	{
#if FAT_TARGET_PLATFORM == FAT_PLATFORM_LINUX
		cMBRFactory = 
			CMBRFactoryLinux::GetFactoryInstance();
#endif	//linux platform

#if FAT_TARGET_PLATFORM == FAT_PLATFORM_WINDOWS
		cMBRFactory = 
			CMBRFactoryWindows::GetFactoryInstance();
#endif	//windows platform
	}

	return cMBRFactory;
}
