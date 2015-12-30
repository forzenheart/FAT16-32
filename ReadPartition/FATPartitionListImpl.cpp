#include "FATPartitionListImpl.h"

int
CPartitionListImpl::GetPhysicalDiskCount() const
{
	return m_physicalDiskList.size();	
}

const std::string*
CPartitionListImpl::GetPhysicalDiskNameByID(const int which) const
{
	if(which >= 0 && which < m_physicalDiskList.size())
		return m_physicalDiskList[which].GetName();
	return NULL;
}

CPhysicalDisk*
CPartitionListImpl::GetPhysicalDiskByID(const int which) const
{
	if(which >= 0 && which < m_physicalDiskList.size())
		return	&m_physicalDiskList[which];
	return NULL;
}
