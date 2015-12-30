#ifndef _FAT_PHYSICAL_DISK_H__
#define	_FAT_PHYSICAL_DISK_H__

#include <string>

class CPhycialDisk {
	public:
		int	GetPhysicalDiskIDbyName(const std::string &name);
		const std::string*	GetPhycsicalDiskNameByID(const int which);
	private:
	int	m_physicalDiskNo;
	std::string	m_physicalDiskName;
};

#endif	//_FAT_PHYSICAL_DISK_H__
