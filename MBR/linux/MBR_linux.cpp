#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>

//the probably path of physical driver;
//  /dev/mapper/vg_forzenheart-lv_root
//  /dev/sda1
// /dev/mapper/vg_forzenheart-lv_home
// scsi-SATA_ST1000DM003-1ER_W4Y5TGGF
// scsi-SATA_ST1000DM003-1ER_W4Y5TGGF-part1
// /dev/disk/by-id

static void print_now_off_set(int files)
{
	off_t	currpos;
	currpos = lseek(files, 0, SEEK_CUR);
	printf("off_t now at : %lu\n", currpos);
}
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
		print_now_off_set(DiskFd);
		if (lseek(DiskFd, sectorNo * sectorSize, SEEK_SET) == -1)
		{
			fprintf(stderr, "lseek error");
		}
		print_now_off_set(DiskFd);
		if ((n = read(DiskFd, DiskBuf, sizeof(DiskBuf))) < 0) 
			fprintf(stderr, "read error\n");
		printf("read : %d bytes.\nThe Disk info:\n", n);
		print_now_off_set(DiskFd);
		for (int i = 0; i < 32; i++)
		{
			//Change the print format of decimal or hex
			//printf("%.11d : ",i * 16);
			printf("%011X : ",i * 16);
			for (int j = 0; j < 16; j++)
			{
				printf("%02X ", DiskBuf[i * 16 + j]);
			}
			printf("\n");
		}
	}

	close(DiskFd);
	return 0;
}
