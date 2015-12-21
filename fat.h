#ifndef __FAT_H__
#define __FAT_H__
/*
 *platform
 *平台相关头文件
 */
#include "platform/FATPlatformConfig.h" 
#include "platform/FATPlatformDefine.h"
#include "platform/FATPlatformMacros.h"
#include "platform/FATStdC.h"

//linux 
#if (FAT_TARGET_PLATFROM == FAT_PLARFROM_LINUX)
/*specific heads include*/

#endif	//FAT_TARGET_PLATFROM == FAT_PLARFROM_LINUX

//windows specific heads include
#if (FAT_TARGET_PLATFROM == FAT_PLARFROM_WIN32)
/*specific heads include*/

#endif	//FAT_TARGET_PLATFROM == FAT_PLARFROM_WIN32

/*
 *errorSystem
 *出错处理系统
 */
#include "errorSystem/error.h"

/*
 *dateTypeDefineOfFAT
 *FAT基本数据类型定义
 *注意这个头文件一定要被最后包含，以避免我们自定义的一些数据类型
 *不兼容其他库的调用
 */
#include "base/FATBasicDataDefine.h"

#endif	//__FAT_H__
