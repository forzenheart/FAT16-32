#include "ReadPartition/FATPhysicalDiskListImpl.h"

class CPhysicalDiskList
{
	public:
		static CPhysicalDiskList*	GetInstance();

		int	EnumPhysicalDisk();
		int	GetCount() const;
		CPhysicalDisk*	GetPhysicalDiskByID(const int which) const;

	protected:
		CPhysicalDiskList();
		CPhysicalDiskList(const CPhysicalDiskList&);
		static	CPhysicalDiskList	*m_physicalDiskListInstance;

	private:
		CPhysicalDiskListImpl	*m_physicalListImpl;
};
