#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//  /dev/mapper/vg_forzenheart-lv_root
//  /dev/sda1
// /dev/mapper/vg_forzenheart-lv_home
// scsi-SATA_ST1000DM003-1ER_W4Y5TGGF
// scsi-SATA_ST1000DM003-1ER_W4Y5TGGF-part1
// /dev/disk/by-id
int
main(void)
{
	int	n;
	int	DiskFd;
	off_t	currpos;
	unsigned char	DiskBuf[512];

	if ((DiskFd = open("/dev/sda", O_RDONLY)) < 0)
		fprintf(stderr, "open error\n");
	else {
		currpos = lseek(DiskFd, 0, SEEK_CUR);
		printf("off_t now at : %lu\n", currpos);

		if ((n = read(DiskFd, DiskBuf, sizeof(DiskBuf))) < 0) 
			fprintf(stderr, "read error\n");
		printf("read : %d bytes.\nThe Disk info:\n", n);

		for (int i = 0; i < 32; i++)
		{
			printf("%d : ",i);
			for (int j = 0; j < 16; j++)
			{
				printf("%02x ", DiskBuf[i * 32 + j]);
			}
			printf("\n");
		}

	}

	close(DiskFd);
	return 0;
}
