#ifndef	_FAT_PARTITONLIST_H__
#define	_FAT_PARTITONLIST_H__
#include "FATPartitionListImpl.h"

class CDiskList {
	public:
	//virtual int	EnumPhysicalDisk() = 0;
	int	GetPhysicalDiskCount() const;
	CPhysicalDisk*	GetPhysicalDiskByID(const int which) const;
	const std::string*	GetPhysicalDiskNameByID(const int which) const;
	private:
	CPartitionListImpl	*m_partitionListImpl;
};
#endif	//_FAT_PARTITONLIST_H__
