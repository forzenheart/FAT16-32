#ifndef	_FAT_PARTITION_LIST_IMPL_H__
#define	_FAT_PARTITION_LIST_IMPL_H__

#include "ReadPartition/FATDiskPartition.h"
#include <vector>
#include <map>

class CPartitionListImpl
{
	public:
		static CPartitionListImpl*	GetInstance();

		int_fast32_t	GetCount() const;
		bool	GetActiveFlagByID(const int_fast32_t which) const;
		bool	IsPrimary(const int_fast32_t which) const;
		uint_fast8_t	GetStartHeadNoByID(const int_fast32_t which)  const;
		uint_fast8_t	GetStartSecNOByID(const int_fast32_t which) const;
		uint_fast16_t	GetStartCylinderNoByID(const int_fast32_t which) const;

		uint_fast8_t	GetEndHeadNoByID(const int_fast32_t which) const;
		uint_fast8_t	GetEndSecNoByID(const int_fast32_t which) const;
		uint_fast16_t	GetEndCylinderNoByID(const int_fast32_t which) const;
		int_fast64_t	GetSecPrecedingPartitionByID(const int_fast32_t which) const;
		int_fast64_t	GetTotalSecByID(const int_fast32_t which) const;
		int_fast64_t	GetSpaceFreeByID(const int_fast32_t which) const;
		int_fast64_t	GetSpaceUsedByID(const int_fast32_t which) const;

		const std::string*	GetPartitionTypeByID(const int_fast32_t which) const;
		const std::string*	GetPartitionNameByID(const int_fast32_t which) const;
		const std::string*	GetVolumeNameByID(const int_fast32_t which) const;

	private:
		CPartitionListImpl();
		CPartitionListImpl(const CPartitionListImpl&);

		int_fast32_t	EnumPartition();
		int_fast32_t	PushPartition(uint_fast8_t *buf, int_fast32_t n, bool isprimart = false);

		std::vector<CDiskPartition*>	m_diskPartitionList;
		static CPartitionListImpl*	m_partitionListImplInstance;
};

#endif	//_FAT_PARTITION_LIST_IMPL_H__
