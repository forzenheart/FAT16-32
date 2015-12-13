#ifndef	__FATPLATFORMDEFINE_H__
#define	__FATPLATFORMDEFINE_H__

//定义平台相关的头文件
#include "../../platform/FATPlatformConfig.h"
#if FAT_TARGET_PLATFROM == FAT_PLARFROM_LINUX

#include <string.h>
#include <assert.h>

//定义空指针
#ifndef NULL
#ifdef	__cplusplus
#define	NULL	0
#else
#define	NULL	((void*)0)
#endif
#endif

#endif	//FAT_TARGET_PLATFROM == FAT_PLARFROM_LINUX

#endif	//__FATPLATFORMDEFINE_H__
