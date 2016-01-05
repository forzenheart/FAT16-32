#include "ReadPartition/windows/FATPhysicalDiskFactoryWindows.h"
#include "ReadPartition/windows/FATPhysicalDiskListImplWindows.h"

CPhysicalDiskFactoryWindows::CPhysicalDiskFactoryWindows()
{

}

CPhysicalDiskFactoryWindows::CPhysicalDiskFactoryWindows(const CPhysicalDiskFactoryWindows&)
{

}

CPhysicalDiskFactoryWindows::~CPhysicalDiskFactoryWindows()
{

}

CPhysicalDiskListImpl*
CPhysicalDiskFactoryWindows::MakePhysicalDisk()
{
	return new CPhysicalDiskListImplWindows;
}
