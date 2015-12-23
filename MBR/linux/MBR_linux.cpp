#include "MBR_linux.h"
#include <unistd.h>
#include <fcntl.h>

int	n;
int	DiskFd;
int	sectorNo = 0;
int	sectorSize = 512;
unsigned char	DiskBuf[4096];
int
main(void)
{
	//In Linux, number 4096 keep file system read or write run at peak efficicency

	if ((DiskFd = open("/dev/sda", O_RDONLY)) < 0)
		fprintf(stderr, "open error.This programma"
				"needs to be run from root! Make sure about that.\n");
	else {
		printNowOffset(DiskFd);
		if (lseek(DiskFd, sectorNo * sectorSize, SEEK_SET) == -1)
			fprintf(stderr, "lseek error\n");
		printNowOffset(DiskFd);
		if ((n = read(DiskFd, DiskBuf, sizeof(DiskBuf))) < 0) 
			fprintf(stderr, "read error\n");
		printf("read : %d bytes.\nThe Disk info:\n", n);
		printNowOffset(DiskFd);
		printSectorContent(DiskBuf, 512);
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

void printSectorContent(const unsigned char *src, int size)
{
	for (int i = 0; i < size / 16; i++)
	{
		//Change the print format of decimal or hex
		//printf("%.11d : ",i * 16);
		printf("%011X : ",i * 16);
		for (int j = 0; j < 16; j++)
		{
			printf("%02X ", src[i * 16 + j]);
		}
		printf("\n");
	}

	int secUsedsize = 0;
	int secTolsize = 0;
	for (int i = 0; i < 4; i++)
	{
		//notice the bytes of int;it~s very important;
		//printf("sizeof(int) = %d\n", sizeof(int));
		if (*((int*)&src[446 + 8 + i * 16]) == 0)
			break;
		secUsedsize = *((int*)&src[446 + 8 + i * 16]);
		secTolsize = *((int*)&src[446 + 12 + i * 16]);
		printf("PartitionType : %d\n", )
		printf("Used sectors : %d\n", secUsedsize);
		printf("total sectors : %d\n", secTolsize);
	}

	//long nextSec = (secUsedsize) * 512;
	//printf("next sectors : %ld\n", nextSec);
	//printNowOffset(DiskFd);
	//if (lseek(DiskFd, nextSec, SEEK_SET) == -1)
		//fprintf(stderr, "lseek error\n");
	//printNowOffset(DiskFd);
	//if ((n = read(DiskFd, DiskBuf, sizeof(DiskBuf))) < 0) 
		//fprintf(stderr, "read error\n");

	//for (int i = 0; i < size / 16; i++)
	//{
		//Change the print format of decimal or hex
		//printf("%.11d : ",i * 16);
		//printf("%011X : ",i * 16);
		//for (int j = 0; j < 16; j++)
		//{
			//printf("%02X ", src[i * 16 + j]);
		//}
		//printf("\n");
	//}
}
