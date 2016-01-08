#include "ReadPartition/linux/FATPhysicalDiskLinux.h"
//linux platform file head
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>

CPhysicalDiskLinux::CPhysicalDiskLinux(int_fast32_t fd)
	: CPhysicalDisk(fd)
{

}

int_fast64_t
CPhysicalDiskLinux::ReadSector(int_fast64_t secNum, void *buf, int_fast64_t bytes)
{
	int_fast64_t	bytesRead;

	Seek(secNum);

	if ((bytesRead = read(m_diskHandle.fd, buf, bytes)) < 0)
		fprintf(stderr, "ReadSector in error\n");

	return bytesRead;
}

int_fast64_t
CPhysicalDiskLinux::WriteSector(int_fast64_t secNum, const void *buf, int_fast64_t bytes)
{
	int_fast64_t	n = -1;

	return n;
}

int_fast64_t
CPhysicalDiskLinux::Seek(int_fast64_t secNum, int_fast32_t whence)
{
	int_fast64_t n;

	if ((n = lseek(m_diskHandle.fd, secNum * 512, whence)) == -1)
	{
		printf("fd = %d\n", m_diskHandle.fd);
		fprintf(stderr, "Seek error\n");
	}

	return n;
}
