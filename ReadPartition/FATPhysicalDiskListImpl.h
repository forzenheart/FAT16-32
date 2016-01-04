#ifndef	_FAT_PARTITIONLISTIMPL_H__
#define	_FAT_PARTITIONLISTIMPL_H__

#include "ReadPartition/FATPhysicalDisk.h"
#include <vector>
#include <string>

class CPhysicalDiskListImpl {
	public:
		//Get the physical disk information on different platform 
		virtual int	EnumPhysicalDisk() = 0;

		int	GetPhysicalDiskCount() const;
		CPhysicalDisk*	GetPhysicalDiskByID(const int which) const;
		const std::string*	GetPhysicalDiskNameByID(const int which) const;
	protected:
		std::vector<CPhysicalDisk*>	m_physicalDiskList;
};
#endif	//_FAT_PARTITIONLISTIMPL_H__



