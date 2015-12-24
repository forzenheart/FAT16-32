#include <unistd.h>
#include <fcntl.h>
#include "../../base/FATBasicDataDefine.h"
#include "../../base/FATPartitionTypeIndicator.h"
#include <cstdio>
#include <cstdlib>

//中英文对照表
//柱面	Cylinder
//扇区	Sector
//磁头	Head
//磁道	Track
//盘面	Platter
//主轴	Spindle
void printNowOffset(int);
void printSectorContent(const unsigned char *, int);
unsigned int getNextMBR(const unsigned char *);


int	n;
int	DiskFd;
int	sectorNo = 0;
int	sectorSize = 512;
//In Linux, number 4096 keep file system read or write run at peak efficicency
unsigned char	DiskBuf[4096];
int	g_iPartitionNum = 0;

void PrintMBR(const unsigned char *src);

int
main(void)
{

	if ((DiskFd = open("/dev/sda", O_RDONLY)) < 0)
		fprintf(stderr, "open error.This programma"
				"needs to be run from root! Make sure about that.\n");
	else {
		if (lseek(DiskFd, sectorNo * sectorSize, SEEK_SET) == -1)
			fprintf(stderr, "lseek error\n");
		if ((n = read(DiskFd, DiskBuf, sizeof(DiskBuf))) < 0) 
			fprintf(stderr, "read error\n");
		//printf("read : %d bytes.\nThe Disk info:\n", n);
		//printSectorContent(DiskBuf, 512);
		PrintMBR(DiskBuf);
	}
	close(DiskFd);
	return 0;
}

void printNowOffset(int files)
{
	off_t	currpos;
	currpos = lseek(files, 0, SEEK_CUR);
	printf("off_t now at : %lu\n", currpos);
}

void ReadEBR(int fildes, long long offset)
{
	unsigned char EBRBuf[4096];
	offset *= 512;
	if (lseek(fildes, offset, SEEK_SET) == -1)
		fprintf(stderr, "lseek error\n");
	if (read(fildes, EBRBuf, sizeof(DiskBuf)) < 0) 
		fprintf(stderr, "read error\n");

	//printSectorContent(EBRBuf, 512);

	if (EBRBuf[446 + 4 + 16] == 0x0f || 
		EBRBuf[446 + 4 + 16] == 0x05)
		ReadEBR(fildes, offset);

}
void printSectorContent(const unsigned char *src, int size)
{
	for (int i = 0; i < size / 16; i++)
	{
		//Change the print format of decimal or hex
		//printf("%.11d : ",i * 16);
		//printf("%011X : ",i * 16);
		//for (int j = 0; j < 16; j++)
		//{
			//printf("%02X ", src[i * 16 + j]);
		//}
		//printf("\n");
	}
}

void PrintMBR(const unsigned char *src)
{
	long secUsedsize = 0;
	long secTolsize = 0;
	for (int i = 0; i < 4; i++)
	{
		//notice the bytes of int;it~s very important;
		//printf("sizeof(int) = %d\n", sizeof(int));
		if (*((int*)&src[446 + 8 + i * 16]) == 0)
			break;
		secUsedsize = *((int*)&src[446 + 8 + i * 16]);
		secTolsize = *((int*)&src[446 + 12 + i * 16]);
		if (src[446+ 4 + i * 16] == 0x0f ||
				src[446 + 4 + i * 16] == 0x05)
		{
			ReadEBR(DiskFd, secUsedsize);
		}
		else {
			printf("PartitionNum	Type		ActivePartition		Capacity\n"
				"%2d		%10s	%3s		%.2f (MB)\n", 
					g_iPartitionNum++, 
					FATPartTypeName[src[446 + 4 + i * 16]], 
					(src[446 + 0 + i * 16] == 0x80 ? "Yes" : "No"), 
					double ((secTolsize * 512) / (1024 * 1024)));
		}
	}
}
