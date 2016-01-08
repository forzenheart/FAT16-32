#include "ReadPartition/FATPhysicalDisk.h"

CPhysicalDisk::CPhysicalDisk(void *handle)
{
	m_diskHandle.HANDLE = handle;
}

CPhysicalDisk::CPhysicalDisk(int_fast32_t fd)
{
	m_diskHandle.fd = fd;
} 
