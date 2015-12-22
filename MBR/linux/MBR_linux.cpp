#include "MBR_linux.h"
#include <unistd.h>
#include <fcntl.h>

int
main(void)
{
	int	n;
	int	DiskFd;
	int	sectorNo = 0;
	int	sectorSize = 512;

	//In Linux, number 4096 keep file system read or write run at peak efficicency
	unsigned char	DiskBuf[4096];

	if ((DiskFd = open("/dev/sda", O_RDONLY)) < 0)
		fprintf(stderr, "open error.This programma"
				"needs to be run from root! Make sure about that.\n");
	else {
		printNowOffset(DiskFd);
		if (lseek(DiskFd, sectorNo * sectorSize, SEEK_SET) == -1)
		{
			fprintf(stderr, "lseek error");
		}
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

	for (int i = 0; i < 4; i++)
		printf("%02x",src[446 + 8 + 4 - i]);
	printf("\n");
	for (int i = 0; i < 4; i++)
		printf("%02x",src[446 + 8 + 4 + i]);
	printf("\n");
	int *ptr = (int*)&src[446 + 12];
	int secsize = *ptr;
	printf("%08x\n", secsize);
	printf("%d\n", secsize);
}
