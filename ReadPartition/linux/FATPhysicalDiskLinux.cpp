#include "ReadPartition/linux/FATPhysicalDiskLinux.h"
//linux platform file head
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>

CPhysicalDiskLinux::CPhysicalDiskLinux(int fd)
	: CPhysicalDisk(fd)
{

}

INT64
CPhysicalDiskLinux::ReadSector(INT64 secNum, void *buf, INT64 bytes)
{
	INT64	bytesRead;

	Seek(secNum);

	if ((bytesRead = read(m_diskHandle.fd, buf, bytes)) < 0)
		fprintf(stderr, "ReadSector in error\n");

	return bytesRead;
}

INT64
CPhysicalDiskLinux::WriteSector(INT64 secNum, const void *buf, INT64 bytes)
{
	INT64	n = -1;

	return n;
}

INT64
CPhysicalDiskLinux::Seek(INT64 secNum, int whence)
{
	INT64 n;

	if ((n = lseek(m_diskHandle.fd, secNum * 512, whence)) == -1)
		fprintf(stderr, "Seek error\n");

	return n;
}
