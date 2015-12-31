#include "FATPartitionList.h"
#include "FATPartitionListFactory.h"

CDiskList::CDiskList()
{

}
int
CDiskList::GetPhysicalDiskCount() const
{
	if (m_partitionListImpl)
		m_partitionListImpl->GetPhysicalDiskCount();
	return -1;
}

const std::string*
CDiskList::GetPhysicalDiskNameByID(const int which) const
{
	return NULL;
}

CPhysicalDisk*
CDiskList::GetPhysicalDiskByID(const int which) const
{
	return NULL;
}
