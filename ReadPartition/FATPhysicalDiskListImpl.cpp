#include "ReadPartition/FATPhysicalDiskListImpl.h"

int
CPhysicalDiskListImpl::GetPhysicalDiskCount() const
{
	return m_physicalDiskList.size();	
}

const std::string*
CPhysicalDiskListImpl::GetPhysicalDiskNameByID(const int which) const
{
	return NULL;
}

CPhysicalDisk*
CPhysicalDiskListImpl::GetPhysicalDiskByID(const int which) const
{
	if (!m_physicalDiskList.empty())
		return m_physicalDiskList[which];
	return NULL;
}
