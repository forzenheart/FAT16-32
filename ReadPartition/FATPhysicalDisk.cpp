#include "ReadPartition/FATPhysicalDisk.h"

CPhysicalDisk::CPhysicalDisk(void *handle)
{
	m_diskHandle.HANDLE = handle;
}

CPhysicalDisk::CPhysicalDisk(int fd)
{
	m_diskHandle.fd = fd;
} 
