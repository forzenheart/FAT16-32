/*
 *一些常用的计算公式
 *第一个存放数据的簇是簇2
 */

计算根目录所占的扇区数
RootDirSectors = (BPB_RootEntCnt*32) + (BPB_BytsPerSec - 1) / BPB_BytsPerSec;
因为FAT32的BPB_RootEntCnt为0, 所以对于FAT32卷RootDirSectors的值也一定是0;32是
每个目录项所占的字节数.计算结果四舍五入.
数据区的起始地址，簇2的第一个扇区由下面公式计算：
if (BPB_FATSz16 != 0)
{
	FATSz = BPB_FATSz16;
}
else
{
	FATSz = BPB_FATSz32;
}

Note:扇区号指的是针对卷中包含的BPB的第一个扇区的偏移量(包含BPB的第一个扇区是扇区0), 
	并不是


