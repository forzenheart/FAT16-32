#ifndef	__FAT_BASCI_DATA_DEFINE_H__
#define	__FAT_BASCI_DATA_DEFINE_H__

//#include "../platform/FATStdC.h"
//#include "FATPartitionTypeIndicator.h"	//分区格式标志
#include "platform/FATPlatformConfig.h"
#include "base/FATMRBDataDefine.h"		//MBR基本偏移量定义
#include "base/FATDBRDataDefine.h"		//DBR基本偏移量定义
#include "base/FATFATDataDefine.h"		//FAT16/32基本偏移量
#include "base/FATFileDataDefine.h"		//FAT基本偏移量定义
#include <stdint.h>

/*
 *fat文件系统基本数据结构的定义
 */
/*
 *typedef	char	int_fast8_t;
 *typedef short	int_fast16_t;
 *typedef	long	int_fast32_t;
 *
 *typedef	long long	int_fast64_t;
 *
 *#if defined(LONGLONG)
 *typedef	LONGLONG	int_fast64_t;
 *#endif //LONGLONG
 *
 *typedef	unsigned char	uint_fast8_t;
 *
 *#if defined(BYTE)
 *typedef	BYTE		uint_fast8_t;
 *#endif //BYTE	
 *
 *typedef unsigned short	uint_fast16_t;
 *#if defined(WORD)
 *typedef	WORD		uint_fast16_t;
 *#endif	//WORD
 *
 *typedef unsigned long	uint_fast32_t;
 *#if defined(DWORD)
 *typedef	DWORD		uint_fast32_t;
 *#endif	//DWORD
 *
 *typedef unsigned long long	uint_fast64_t;
 *#if defined(ULONGLONG)
 *typedef	ULONGLONG	uint_fast64_t;
 *#endif	//ULONGLONG
 */

//suppose the max physical disk number in family computer
#if	!defined(MAXPHYSICALDISKNUMBER)
#define	MAXPHYSICALDISKNUMBER	24
#endif	//MAXPHYSICALDISKNUMBER

#endif //__FAT_BASCI_DATA_DEFINE_H__
