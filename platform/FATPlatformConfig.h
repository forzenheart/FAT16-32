#ifndef	__FAT_PLATFORM_CONFIG_H__
#define	__FAT_PLATFORM_CONFIG_H__

#define	FAT_PLATFORM_UNKNOWN	0
#define	FAT_PLATFORM_LINUX	1
#define	FAT_PLATFORM_WINDOWS	2
#define	FAT_PLATFORM_WEB	3

#define	FAT_TARGET_PLATFORM	FAT_PLATFORM_UNKNOWN

//linux
#if	defined(LINUX)
#undef FAT_TARGET_PLATFORM
#define	FAT_TARGET_PLATFORM	FAT_PLATFORM_LINUX
#endif

//windows
#if	defined(WINDOWS)
#undef FAT_TARGET_PLATFORM
#define	FAT_TARGET_PLATFORM	FAT_PLATFORM_WINDOWS
#endif

//web
#if	defined(WEB)
#undef FAT_TARGET_PLATFORM
#define	FAT_TARGET_PLATFORM	FAT_PLATFORM_WEB
#endif

#if	!FAT_TARGET_PLATFORM
	#error "Can not reconginze the platform!"
#endif	//check the platform
#endif	//__FAT_PLATFORM_CONFIG_H__


