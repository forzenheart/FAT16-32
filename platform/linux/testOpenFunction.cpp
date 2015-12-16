#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int
main(void)
{
	int	DiskFd;
	int	n;
	unsigned char	DiskBuf[512];
	off_t	currpos;

	if ((DiskFd = open("/dev/sda", O_RDONLY)) < 0) 
		fprintf(stderr, "open error\n");
	//currpos = lseek(DiskFd, 0, SEEK_CUR);
	//printf("off_t now at : %d\n", currpos);

	if ((n = read(DiskFd, DiskBuf, sizeof(DiskBuf))) < 0) 
		fprintf(stderr, "read error\n");
	printf("read : %d bytes.\nThe Disk info:\n", n);

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			printf("%02x ", DiskBuf[i * 32 + j]);
		}
		printf("\n");
	}

	close(DiskFd);
	return 0;
}
