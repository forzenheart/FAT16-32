#ifndef	_FAT_PARTITIONLISTIMPL_H__
#define	_FAT_PARTITIONLISTIMPL_H__

#include <vector>

class CPartitionListImpl {
	public:
		//enum the physical information on different platform
		virtual	int	EnumPhysicalDisk() = 0;

		int	GetPhysicalDiskCount() const;
		CPhysicalDisk*	GetPhysicalDiskByID(const int which) const;
		const std::string*	GetPhysicalDiskNameByID(const int which) const;
	private:
		std::vector<CPhysicalDisk>	m_physicalDiskList;
};
#endif	//_FAT_PARTITIONLISTIMPL_H__



