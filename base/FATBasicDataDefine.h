#ifndef	_FATBASCIDATADEFINE_H
#define	_FATBASCIDATADEFINE_H
/*
 *fat文件系统基本数据结构的定义
 */
/*
 *在以下的描述中, 凡名称与 BPB_开头的域都是 BPB 的一部分
 *凡是名称与BS_开头的项都是启动扇区的一部分，而不是
 *真正属于BPB内容.
 *In the following description,  all the fields whose
 *names start with BPB_ are part of the BPB. All the 
 *fields whose names start with BS_ are part of the 
 *boot sector and not really part of the BPB.The following 
 *shows the start of sector 0 of a FAT volume,  which
 *contains the BPB:
 */

/*
 *BS(Boot Sector)
 */
/*	Name		Offset	Size	Description */
/*			(byte)	(bytes)		    */
#define	BS_jmpBoot	0	//3
#define	BS_OEMName	3	//8

/*
 *BPB(BIOS Parameter Block)
 */
#define	BPB_BytsPerSec	11	//2
#define	BPB_BytsPerClus	13	//1
#define	BPB_RsvdSecCnt	14	//2
#define	BPB_NumFATs	16	//1
#define	BPB_RootEntCnt	17	//2
#define	BPB_TotSec	19	//2
#define	BPB_Media	21	//1
#define	BPB_FATSz16	22	//2
#define	BPB_SecPerTrk	24	//2
#define	BPB_NumHeads	26	//2
#define	BPB_HiddSec	28	//4
#define	BPB_TotSec32	32	//4

/*
 *从偏移量36开始，FAT16/FAT32的内容开始区别于FAT32，以下
 *是FAT12\FAT16的内容
 */
#if	FATTYPE == FAT16
/*
 *FAT12\FAT16
 */
#define	BS_drvNum	36	//1
#define	BS_Reserved1	37	//1
#define	BS_BootSig	38	//1
#define	BS_VolID	39	//4
#define	BS_VolLab	43	//11
#define	BS_FileSysType	54	//8

#elif
/*
 *FAT32
 */
#define	BPB_FATSz32	36	//4	
#define	BPB_ExtFlags	40	//2	
#define	BPB_FSVer	42	//2	
#define	BPB_RootClus	44	//4	
#define	BPB_FSInfo	48	//2	
#define	BPB_BkBootSec	50	//2	
#define	BPB_Reserved	52	//12	
#define	BS_DrvNum	64	//1	
#define	BS_Reserved1	65	//1	
#define	BS_BootSig	66	//1	
#define	BS_VolID	67	//4	
#define	BS_FilSysType	71	//11	
#define	BS_FilSysType	82	//8	
#endif //FATTYPE == FAT16 or FATYTYPE == FAT32

#endif //_FATBASCIDATADEFINE_H
