#ifndef	_FAT_PARTITON_LIST_H__
#define	_FAT_PARTITON_LIST_H__

#include "ReadPartition/FATPhysicalDiskList.h"
#include "ReadPartition/FATPartitionListImpl.h"

class CPartitionList
{
	public:
		static	CPartitionList*	GetInstance();

		//int_fast32_t	GetPhysicalDiskCout() const;
		//CPartitionList*	GetPartitionListByPhysicalDiskID(const int_fast32_t which) const;

		int_fast32_t	GetPartitionCount() const;
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

		const std::string*	GetPartitionNameByID(const int_fast32_t which) const;
		const std::string*	GetPartitionTypeByID(const int_fast32_t which) const;
		const std::string*	GetVolumeNameByID(const int_fast32_t which) const;

	private:
		CPartitionList();
		CPartitionList(const CPartitionList&);
		
		static	CPartitionList*	m_partitionListInstance;
		CPartitionListImpl*	m_partitionListImpl;
};
#endif	//_FAT_PARTITON_LIST_H__
