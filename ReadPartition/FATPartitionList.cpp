#include "ReadPartition/FATPartitionList.h"

CPartitionList* CPartitionList::m_partitionListInstance = NULL;

CPartitionList*
CPartitionList::GetInstance()
{
	if (m_partitionListInstance == NULL)	
	{
		m_partitionListInstance = new CPartitionList;
	}
	return m_partitionListInstance;
}

CPartitionList::CPartitionList()
{
	m_partitionListImpl = CPartitionListImpl::GetInstance();
}

CPartitionList::CPartitionList(const CPartitionList&)
{

}

int
CPartitionList::GetPartitionCount() const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetCount();
	}
	return -1;
}

bool
CPartitionList::GetActiveFlagByID(const int which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetActiveFlagByID(which);
	}
	return false;
}

UINT8
CPartitionList::GetStartHeadNoByID(const int which)  const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetStartHeadNoByID(which);
	}
	return 0;
}

UINT8
CPartitionList::GetStartSecNOByID(const int which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetStartSecNOByID(which);
	}
	return 0;
}
UINT16
CPartitionList::GetStartCylinderNoByID(const int which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetStartCylinderNoByID(which);
	}
	return 0;
}

UINT8
CPartitionList::GetEndHeadNoByID(const int which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetEndHeadNoByID(which);
	}
	return 0;

}
UINT8
CPartitionList::GetEndSecNoByID(const int which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetEndSecNoByID(which);
	}
	return 0;

}
UINT16
CPartitionList::GetEndCylinderNoByID(const int which) const
{

	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetEndCylinderNoByID(which);
	}
	return 0;
}

INT64
CPartitionList::GetSecPrecedingPartitionByID(const int which) const
{

	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetSecPrecedingPartitionByID(which);
	}
	return 0;
}

INT64
CPartitionList::GetTotalSecByID(const int which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetTotalSecByID(which);
	}
	return 0;
}

const std::string*
CPartitionList::GetPartitionTypeByID(const int which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetPartitionTypeByID(which);
	}
	return 0;
}

const std::string*
CPartitionList::GetPartitionNameByID(const int which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetPartitionNameByID(which);
	}
	return 0;
}
