#include "ReadPartition/linux/FATPhysicalDiskFactoryLinux.h"
#include "ReadPartition/linux/FATPhysicalDiskListImplLinux.h"

CPhysicalDiskFactoryLinux::CPhysicalDiskFactoryLinux()
{

}

CPhysicalDiskFactoryLinux::CPhysicalDiskFactoryLinux(const CPhysicalDiskFactoryLinux&)
{

}

CPhysicalDiskFactoryLinux::~CPhysicalDiskFactoryLinux()
{

}

CPhysicalDiskListImpl*
CPhysicalDiskFactoryLinux::MakePhysicalDisk()
{
	return new CPhysicalDiskListImplLinux;
}
