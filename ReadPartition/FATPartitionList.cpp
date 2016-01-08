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

int_fast32_t
CPartitionList::GetPartitionCount() const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetCount();
	}
	return -1;
}

bool
CPartitionList::GetActiveFlagByID(const int_fast32_t which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetActiveFlagByID(which);
	}
	return false;
}

uint_fast8_t
CPartitionList::GetStartHeadNoByID(const int_fast32_t which)  const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetStartHeadNoByID(which);
	}
	return 0;
}

uint_fast8_t
CPartitionList::GetStartSecNOByID(const int_fast32_t which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetStartSecNOByID(which);
	}
	return 0;
}
uint_fast16_t
CPartitionList::GetStartCylinderNoByID(const int_fast32_t which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetStartCylinderNoByID(which);
	}
	return 0;
}

uint_fast8_t
CPartitionList::GetEndHeadNoByID(const int_fast32_t which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetEndHeadNoByID(which);
	}
	return 0;

}
uint_fast8_t
CPartitionList::GetEndSecNoByID(const int_fast32_t which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetEndSecNoByID(which);
	}
	return 0;

}
uint_fast16_t
CPartitionList::GetEndCylinderNoByID(const int_fast32_t which) const
{

	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetEndCylinderNoByID(which);
	}
	return 0;
}

int_fast64_t
CPartitionList::GetSecPrecedingPartitionByID(const int_fast32_t which) const
{

	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetSecPrecedingPartitionByID(which);
	}
	return -1;
}

int_fast64_t
CPartitionList::GetTotalSecByID(const int_fast32_t which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetTotalSecByID(which);
	}
	return -1;
}

int_fast64_t
CPartitionList::GetSpaceFreeByID(const int_fast32_t which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetSpaceFreeByID(which);
	}
	return -1;
}

int_fast64_t
CPartitionList::GetSpaceUsedByID(const int_fast32_t which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetSpaceUsedByID(which);
	}
	return -1;
}

const std::string*
CPartitionList::GetPartitionTypeByID(const int_fast32_t which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetPartitionTypeByID(which);
	}
	return NULL;
}

const std::string*
CPartitionList::GetPartitionNameByID(const int_fast32_t which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetPartitionNameByID(which);
	}
	return NULL;
}

const std::string*
CPartitionList::GetVolumeNameByID(const int_fast32_t which) const
{
	if (m_partitionListImpl)
	{
		return m_partitionListImpl->GetVolumeNameByID(which);
	}
	return NULL;
}

