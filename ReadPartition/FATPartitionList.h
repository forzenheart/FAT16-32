#ifndef	_FAT_PARTITON_LIST_H__
#define	_FAT_PARTITON_LIST_H__

#include "ReadPartition/FATPhysicalDiskList.h"
#include "ReadPartition/FATPartitionListImpl.h"

class CPartitionList
{
	public:
		static	CPartitionList*	GetInstance();

		//int	GetPhysicalDiskCout() const;
		//CPartitionList*	GetPartitionListByPhysicalDiskID(const int which) const;

		int	GetPartitionCount() const;
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

		const std::string*	GetPartitionNameByID(const int which) const;
		const std::string*	GetPartitionTypeByID(const int which) const;
		const std::string*	GetVolumeNameByID(const int which) const;

	private:
		CPartitionList();
		CPartitionList(const CPartitionList&);
		
		static	CPartitionList*	m_partitionListInstance;
		CPartitionListImpl*	m_partitionListImpl;
};
#endif	//_FAT_PARTITON_LIST_H__
