#ifndef	_FAT_STD_C_H__
#define _FAT_STD_C_H__
//linux平台包含标准c语言库
#include "../../platform/FATPlatformConfig.h"
#if	FAT_TARGET_PLATFROM == FAT_PLARFROM_LINUX

#include "../../platform/FATPlatformMarcros.h"

#include <float.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <limits.h>

#ifndef	MIN
#define	MIN(x, y) (((x) < (y)) ? (x) : (y))
#endif	//MIN

#ifndef	MAX
#define	MAX(x, y) (((x) > (y)) ? (x) : (y))
#endif	//MAX

#endif	//FAT_PLARFROM_LINUX == FAT_PLARFROM_LINUX

#endif	//_FAT_STD_C_H__
