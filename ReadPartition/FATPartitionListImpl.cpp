#include "FATPartitionListImpl.h"

int
CPartitionListImpl::GetPhysicalDiskCount() const
{
	return m_physicalDiskList.size();	
}

const std::string*
CPartitionListImpl::GetPhysicalDiskNameByID(const int which) const
{
	return NULL;
}

CPhysicalDisk*
CPartitionListImpl::GetPhysicalDiskByID(const int which) const
{
	return NULL;
}
