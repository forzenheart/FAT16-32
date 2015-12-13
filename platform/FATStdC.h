#ifndef _PLATFORM_FATSTDC_H__
#define	_PLATFORM_FATSTDC_H__

//不同平台包含不同的stdc标准头文件

#include "../platform/FATPlatformConfig.h"

#if	FAT_TARGET_PLATFROM == FAT_PLARFROM_LINUX
#include "../platform/linux/FATStdCLinux.h"
#elif	FAT_TARGET_PLATFROM == FAT_PLARFROM_WIN32
#include "../platform/win32/FATStdCWin32.h"
#elif	FAT_TARGET_PLATFROM == FAT_PLARFROM_WEB
#include "../platform/web/FATStdCWeb.h"
#endif

#endif	//_PLATFORM_FATSTDC_H__
