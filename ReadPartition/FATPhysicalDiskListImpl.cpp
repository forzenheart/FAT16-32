#include "ReadPartition/FATPhysicalDiskListImpl.h"

int_fast32_t
CPhysicalDiskListImpl::GetPhysicalDiskCount() const
{
	return m_physicalDiskList.size();	
}

const std::string*
CPhysicalDiskListImpl::GetPhysicalDiskNameByID(const int_fast32_t which) const
{
	return NULL;
}

CPhysicalDisk*
CPhysicalDiskListImpl::GetPhysicalDiskByID(const int_fast32_t which) const
{
	if (!m_physicalDiskList.empty())
		return m_physicalDiskList[which];
	return NULL;
}
