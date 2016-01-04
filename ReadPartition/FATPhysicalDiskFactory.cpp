#include "ReadPartition/FATPhysicalDiskFactory.h"

//windows
#if	FAT_TARGET_PLATFORM == FAT_PLATFORM_WINDOWS
#include "ReadPartition/windows/windowsfactory.h"
#endif

//linux
#if	FAT_TARGET_PLATFORM == FAT_PLATFORM_LINUX
#include "ReadPartition/linux/linuxfactory.h"
#endif


