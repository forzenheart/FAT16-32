#include "MBRImpl.h"


int
CMBR::GetPartitionCount() const {
	return m_partitionList.size();
}

const std::string*
CMBR::GetPartitionName(const int id) const
{
	return m_partitionList[id].GetName();
}

bool
CMBR::GetPartitionActiveFlag(const int id) const
{
	return m_partitionList[id].GetActivePartition();

}

INT64
CMBR::GetPartitionTolSec(const int id) const
{
	return m_partitionList[id].GetTotalSec();
}
