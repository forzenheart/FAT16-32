#include "ReadPartition/FATPhysicalDiskListImpl.h"

class CPhysicalDiskList {
	public:
		int	EnumPhysicalDisk();
		int	GetCount() const;
		CPhysicalDisk*	GetPhysicalDiskByID(const int which) const;
	private:
		CPhysicalDiskList();
		CPhysicalDiskList(CPhysicalDiskList&);
		CPhysicalDiskListImpl	*m_physicalListImpl;
};
