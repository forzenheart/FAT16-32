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
#define	BS_jmpBoot	0	//3	//跳转指令

#define	BS_OEMName	3	//8	//建议值为MSWIN4.1，很多情况下用于显示
					//格式化该FAT卷的操作系统名称

/*
 *BPB(BIOS Parameter Block)
 */
#define	BPB_BytsPerSec	11	//2	//每扇区字节数, 可以是512, 1024, 2048, 4096

#define	BPB_BytsPerClus	13	//1	//每簇扇区数, 其值必须是2的整数次方(该整数必须>=0)
					//还必须保证每簇的字节数不超过32K, 即:
					//(BPB_BytsPerSec * BPB_BytsPerClus <= 32K(1024*32))

#define	BPB_RsvdSecCnt	14	//2	//保留区中保留扇区的数目, 保留扇区从FAT第一个扇区开始
					//此域不能为0, FAT12/16必须为1, FAT32典型取值为32

#define	BPB_NumFATs	16	//1	//此卷中FAT表的份数.任何FAT格式此域都建议为2.

#define	BPB_RootEntCnt	17	//2	//对于FAT12/FAT16此域包含根目录中的目录项数
					//(每个项长度为32bytes), FAT32此项必须为0.
					//对于FAT12/FAT16此数值乘以32必须为BPB_BytsPerSec的
					//偶数倍数, 为了兼容性，FAT12/FAT16应该取值为512

#define	BPB_TotSec16	19	//2	//早期版本中16-bit的总扇区数目.

#define	BPB_Media	21	//1

#define	BPB_FATSz16	22	//2	//FAT12/FAT16一个FAT表所占的扇区数.FAT32此域名必须为0

#define	BPB_SecPerTrk	24	//2	//每磁道扇区数

#define	BPB_NumHeads	26	//2	//磁头数

#define	BPB_HiddSec	28	//4	//在此FAT分区之前所隐藏的扇区数

#define	BPB_TotSec32	32	//4	//该卷总扇区数(32-bits), 包括FAT卷上四个基本区的全部扇区
					//此域可以为0, 若此域为0，BPB_TotSec16必须为非0, 对于FAT
					//32此域一定非0, 对于FAT12/FAT16, 如果总扇区数大于等于
					//0x10000的话, 此域就是总扇区数，同时BPB_TotSec16的值为0

/*
 *从偏移量36开始，FAT16/FAT32的内容开始
 *区别于FAT32，以下是FAT12\FAT16的内容
 */

/*未完成FAT文件系统的检验*/
#if	FATTYPE == FAT16
/*
 *FAT12\FAT16
 */
#define	BS_drvNum	36	//1	//磁盘驱动器参数

#define	BS_Reserved1	37	//1	//保留(NT使用), 格式化FAT卷时把此域设置为0

#define	BS_BootSig	38	//1	//扩展引导标记(0x29), 用于指明此后的3个域可用

#define	BS_VolID	39	//4	//卷标序列号，与BS_VolLab一起工作，用来判断连接的
					//可移动磁盘是否正确，往往是由时间和日期组成的
					//一个32位值.
#define	BS_VolLab	43	//11

#define	BS_FileSysType	54	//8	//有以下几种之一，"FAT12", "FAT16", "FAT32"微乳
					//操作系统并不使用此域来确定FAT文件的类型．


#elif
/*
 *FAT32
 */
#define	BPB_FATSz32	36	//4	//一个FAT表所占的扇区数, FAT32特有, 同时BPB_FATSz16必须为0

#define	BPB_ExtFlags	40	//2	//FAT32特有．
					//Bits 0-3:不小于0的活动FAT(active FAT)数目，
					//只有在镜像禁止时才有效
					//Bits 4-6:保留
					//Bits	7:--0表示FAT实时镜像到所有FAT表中.
					//	  --1表示只有一个活动的FAT表，
					//		这个表就是bits 0-3所指定的那个.
					//Bits 8-15:保留

#define	BPB_FSVer	42	//2	//FAT32特有, 高位为FAT32的主版本号，低位为次版本号．
#define	BPB_RootClus	44	//4	//FAT32特有, 根目录所在第一个簇的簇号，通常该数值为2.
#define	BPB_FSInfo	48	//2	//FAT32特有, 保留区中FAT32卷FSINFO结构所占的扇区数，常为1
#define	BPB_BkBootSec	50	//2	//FAT32特有，如果不为0, 表示在保留区中引导记录的备份数据
					//所占的扇区数, 通常为6.不建议使用6意外的其他数值.
#define	BPB_Reserved	52	//12	//FAT32特有，用于以后FAT扩展使用，对于FAT32此域用0填充
#define	BS_DrvNum	64	//1	//与 FAT12/FAT16 的定义相同, 只不过两者位于启动扇区不同
					//位置而已
#define	BS_Reserved1	65	//1	//与 FAT12/FAT16 的定义相同, 只不过两者位于启动扇区不同
					//位置而已
#define	BS_BootSig	66	//1	//与 FAT12/FAT16 的定义相同, 只不过两者位于启动扇区不同
					//位置而已
#define	BS_VolID	67	//4	//与 FAT12/FAT16 的定义相同, 只不过两者位于启动扇区不同
					//位置而已
#define	BS_FilSysType	71	//11	//与 FAT12/FAT16 的定义相同, 只不过两者位于启动扇区不同
					//位置而已
#define	BS_FilSysType	82	//8	//通常设置为"FAT32", 该域内容和FAT类型判定无关
#endif //FATTYPE == FAT16 or FATYTYPE == FAT32

#endif //_FATBASCIDATADEFINE_H
