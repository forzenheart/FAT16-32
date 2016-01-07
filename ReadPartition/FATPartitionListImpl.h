#ifndef	_FAT_PARTITION_LIST_IMPL_H__
#define	_FAT_PARTITION_LIST_IMPL_H__

#include "ReadPartition/FATDiskPartition.h"
#include <vector>
#include <map>

class CPartitionListImpl
{
	public:
		static CPartitionListImpl*	GetInstance();

		int	GetCount() const;
		bool	GetActiveFlagByID(const int which) const;
		bool	IsPrimary(const int which) const;
		UINT8	GetStartHeadNoByID(const int which)  const;
		UINT8	GetStartSecNOByID(const int which) const;
		UINT16	GetStartCylinderNoByID(const int which) const;

		UINT8	GetEndHeadNoByID(const int which) const;
		UINT8	GetEndSecNoByID(const int which) const;
		UINT16	GetEndCylinderNoByID(const int which) const;
		INT64	GetSecPrecedingPartitionByID(const int which) const;
		INT64	GetTotalSecByID(const int which) const;
		INT64	GetSpaceFreeByID(const int which) const;
		INT64	GetSpaceUsedByID(const int which) const;

		const std::string*	GetPartitionTypeByID(const int which) const;
		const std::string*	GetPartitionNameByID(const int which) const;
		const std::string*	GetVolumeNameByID(const int which) const;

	private:
		CPartitionListImpl();
		CPartitionListImpl(const CPartitionListImpl&);

		int	EnumPartition();
		int	PushPartition(UINT8 *buf, int n, bool isprimart = false);

		std::vector<CDiskPartition*>	m_diskPartitionList;
		static CPartitionListImpl*	m_partitionListImplInstance;
};

#endif	//_FAT_PARTITION_LIST_IMPL_H__
