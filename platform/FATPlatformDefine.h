#ifndef	_PLATFORM_FATPLATFORMDEFINE_H__
#define	_PLATFORM_FATPLATFORMDEFINE_H__

#include "../platform/FATPlatformConfig.h"

#if	FAT_TARGET_PLATFROM == FAT_PLARFROM_LINUX
#include "../platform/linux/FATPlatformDefineLinux.h"
#elif	FAT_TARGET_PLATFROM == FAT_PLARFROM_WIN32
#include "../platform/win32/FATPlatformDefineWin32.h"
#elif	FAT_TARGET_PLATFROM == FAT_PLARFROM_WEB
#include "../platfomr/web/FATPlatformDefineWeb.h"
#endif


#endif	//_PLATFORM_FATPLATFORMDEFINE_H__
