#ifndef __FAT_STD_C_H__
#define __FAT_STD_C_H__

//window平台包含的c语言标准库
#include "../../platform/FATPlatformConfig.h"

#if	FAT_TARGET_PLATFROM == FAT_PLARFROM_WIN32

#include <float.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

#endif //FAT_TARGET_PLATFROM == FAT_PLARFROM_WIN32

#endif	//__FAT_STD_C_H__

