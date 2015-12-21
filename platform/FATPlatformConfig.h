#ifndef	__PLATFORM_FAT_CONFIG_H__
#define __PLATFORM_FAT_CONFIG_H__

/*
 *FAT支持的系统
 */

//定义支持的系统宏

#define	FAT_PLARFROM_UNKNOWN	0
#define	FAT_PLARFROM_LINUX	1
#define	FAT_PLARFROM_WIN32	2
#define	FAT_PLARFROM_WEB	3

//通过环境宏定义目标平台 先定义为linux
#define	FAT_TARGET_PLATFROM	FAT_PLARFROM_LINUX

//linux
#if defined(LINUX) && !defined(__APPLE__)
	#undef	FAT_TARGET_PLATFROM
	#define	FAT_TARGET_PLATFROM	FAT_PLARFROM_LINUX
#endif

//win32
#if defined(__WIN32) && defined(_WINDOWS)
	#undef	FAT_TARGET_PLATFROM
	#define	FAT_TARGET_PLATFROM	FAT_PLARFROM_WIN32
#endif

//web
#if defined(WEB)
	#undef	FAT_TARGET_PLATFROM
	#define	FAT_TARGET_PLATFROM	FAT_PLARFROM_WEB
#endif

//检查是否支持用户平台
#if ! FAT_TARGET_PLATFROM
	#error	"Cannot recognize the target platform;are you targeting an unsupported platform?"
#endif

//若用户是win32平台看是否包含mingw
//#if (FAT_TARGET_PLATFROM == FAT_PLARFROM_WIN32)
//#ifndef	__MINGW32__
//#pragma	waring	(disable:4127)
//#endif
//#endif//检查是否包含minGW32

#endif	//__PLATFORM_FAT_CONFIG_H__
