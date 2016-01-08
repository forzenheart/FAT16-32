#ifndef	_FAT_PARTITIONLISTIMPL_H__
#define	_FAT_PARTITIONLISTIMPL_H__

#include "ReadPartition/FATPhysicalDisk.h"
#include <vector>
#include <string>

class CPhysicalDiskListImpl {
	public:
		//Get the physical disk information on different platform 
		virtual int_fast32_t	EnumPhysicalDisk() = 0;

		int_fast32_t	GetPhysicalDiskCount() const;
		CPhysicalDisk*	GetPhysicalDiskByID(const int_fast32_t which) const;
		const std::string*	GetPhysicalDiskNameByID(const int_fast32_t which) const;
	protected:
		std::vector<CPhysicalDisk*>	m_physicalDiskList;
};
#endif	//_FAT_PARTITIONLISTIMPL_H__



