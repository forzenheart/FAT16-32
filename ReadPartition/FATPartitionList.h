#ifndef	_FAT_PARTITON_LIST_H__
#define	_FAT_PARTITON_LIST_H__

#include "ReadPartition/FATPhysicalDiskList.h"

class CPartitionList
{
	public:
		static	CPartitionList*	GetInstance();

		int	EnumPartition();
		int	GetPartitionCount() const;

		bool	GetActiveFlagByID(const int which) const;

		INT64	GetCapacityByID(const int which) const;

		INT8	GetStartHeadNoByID(const int which)  const;
		INT8	GetStartSecNOByID(const int which) const;
		INT8	GetStartCylinderNoByID(const int which) const;

		INT8	GetEndHeadNoByID(const int which) const;
		INT8	GetEndSecNoByID(const int which) const;
		INT8	GetEndCylinderNoByID(const int which) const;

		INT32	GetSecPrecedingPartitionByID(const int which) const;
		INT32	GetTotalSecByID(const int which) const;
		const std::string*	GetPartitionNameByID(const int which) const;
		const std::string*	GetPartitionTypeByID(const int which) const;

	private:
		std::vector<CDiskPartition>	m_diskPartitionList;

		CPartitionList();
		CPartitionList(const CPartitionList&);
		
		static	CPartitionList*	m_partitionListInstance;
};
#endif	//_FAT_PARTITON_LIST_H__
