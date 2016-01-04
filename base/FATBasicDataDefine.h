#ifndef	__FAT_BASCI_DATA_DEFINE_H__
#define	__FAT_BASCI_DATA_DEFINE_H__

//#include "../platform/FATStdC.h"
//#include "FATPartitionTypeIndicator.h"	//分区格式标志
#include "platform/FATPlatformConfig.h"
#include "base/FATMRBDataDefine.h"		//MBR基本偏移量定义
#include "base/FATDBRDataDefine.h"		//DBR基本偏移量定义
#include "base/FATFATDataDefine.h"		//FAT16/32基本偏移量
#include "base/FATFileDataDefine.h"		//FAT基本偏移量定义

/*
 *fat文件系统基本数据结构的定义
 */
typedef	char	INT8;
typedef short	INT16;
typedef	long	INT32;

typedef	long long	INT64;
#ifdef LONGLONG
typedef	LONGLONG	INT64;
#endif //LONGLONG

typedef	unsigned char	UINT8;
#ifdef BYTE
typedef	BYTE		UINT8;
#endif //BYTE	

typedef unsigned short	UINT16;
#ifdef	WORD
typedef	WORD		UNIT16;
#endif	//WORD

typedef unsigned long	UINT32;
#ifdef DWORD
typedef	DWORD		UINT32;
#endif	//DWORD

typedef unsigned long long	UINT64;
#ifdef	ULONGLONG
typedef	ULONGLONG	UINT64;
#endif	//ULONGLONG

//suppose the max physical disk number in family computer
#define	MAXPHYSICALDISKNUMBER	24

#endif //__FAT_BASCI_DATA_DEFINE_H__
