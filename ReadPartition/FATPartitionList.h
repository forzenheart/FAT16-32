#ifndef	_FAT_PARTITONLIST_H__
#define	_FAT_PARTITONLIST_H__

#include "ReadPartition/FATPhysicalDiskListImpl.h"
#include "ReadPartition/FATDiskPartition.h"

class CPartitionList {
	public:

		const std::string*	GetNameByID(const int which) const;
		const std::string*	GetTypeByID(const int which) const;

		int	GetCount() const;
		INT64	GetCapacityByID(const int which) const;
		INT64	GetActiveFlagByID(const int which) const;
		INT8	GetStartHeadNoByID()  const;
		INT8	GetStartSecNOByID() const;
		INT8	GetStartCylinderNoByID() const;
		INT8	GetPartitionTypeIndicatorByID() const ;
		INT8	GetEndHeadNoByID() const;
		INT8	GetEndSecNoByID() const;
		INT8	GetEndCylinderNoByID() const;
		INT32	GetSecPrecedingPartitionByID() const;
		INT32	GetTotalSecByID() const;

	private:
		std::vector<CDiskPartition>	m_diskPartitionList;

		CPartitionList();
		CPartitionList(CPartitionList&);
		int ScanPartition();
};
#endif	//_FAT_PARTITONLIST_H__
