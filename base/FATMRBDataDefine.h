#ifndef	_FAT_MBR_DATA_DEFINE_H__
#define	_FAT_MBR_DATA_DEFINE_H__
//basical offset of mbr partition

/*
 *	Name			Offset	Size	Description
 *				(byte)	(bytes)
 */
#define	MBR_BOOTINDICATOR	0x01BE	//1	//引导标志：指明该分区是否是活动分区
#define	MBR_START_HEAD		0x01BF	//1	//开始磁头
#define	MBR_START_SECTOR	0x01C0	//6b	//起始扇区：只用了0～5位，后2位留给开始柱面字段
#define	MBR_START_CYLINDER	0X01C1	//10B	//起始柱面：共占用10位，最大值位1023
#define	MBR_PARTION_TYPE	0X01C2	//1	//分区类型描述，详细见FATPARTITIONTYPEINDICATOR.h
#define	MBR_END_HEAD		0x01C3	//1	//结束磁头
#define	MBR_END_SECTOR		0x01C4	//6b	//结束扇区：只用了0～5位，后2位留给结束柱面字段
#define	MBR_END_CYLINDER	0x01C5	//10b	//结束柱面：占用10位，最大为1023
#define	MBR_SECS_PRE_PART	0x01C6	//4	//本分区之前使用的扇区数，指从该磁盘开始到该分区开始之间的偏移量
						//注意是以扇区数目表示，而不是字节数目
#define	MBR_SECSINPART		0x01CA	//4	//该分区包含的总扇区数


#endif	//_FAT_MBR_DATA_DEFINE_H__
