#include "MBR.h"

CDiskPartitionList::CDiskPartitionList()
	:
	m_diskPartitionImpl(NULL)
{
	CMBRFactory	*factory = CMBRFactory::GetMBRFactory();

	if (factory)
	{
		m_diskPartitionImpl = factory->MakeMBR();
	}
}

CDiskPartitionList::~CDiskPartitionList()
{ }

int
CDiskPartitionList::Scan()
{
	if (m_diskPartitionImpl)
		m_diskPartitionImpl->Scan();
	return -1;
}

bool
CDiskPartitionList::GetPartitionActiveFlag(const int which) const
{
	if (m_diskPartitionImpl)
		return m_diskPartitionImpl->GetPartitionActiveFlag(which);
	return false;
}

INT64
CDiskPartitionList::GetPartitionTolSec(const int which) const
{
	if(m_diskPartitionImpl)
		return m_diskPartitionImpl->GetPartitionTolSec(which);
	return -1;
}

const std::string*
CDiskPartitionList::GetPartitionName(const int which) const
{
	if (m_diskPartitionImpl)
		return m_diskPartitionImpl->GetPartitionName(which);
	return NULL;
}

int
CDiskPartitionList::GetPartitionCount() const
{
	if (m_diskPartitionImpl)
		return m_diskPartitionImpl->GetPartitionCount();
	return -1;
}
