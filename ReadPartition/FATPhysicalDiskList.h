#include "ReadPartition/FATPhysicalDiskListImpl.h"

class CPhysicalDiskList
{
	public:
		static CPhysicalDiskList*	GetInstance();

		int_fast32_t	EnumPhysicalDisk();
		int_fast32_t	GetCount() const;
		CPhysicalDisk*	GetPhysicalDiskByID(const int_fast32_t which) const;

	protected:
		CPhysicalDiskList();
		CPhysicalDiskList(const CPhysicalDiskList&);
		static	CPhysicalDiskList	*m_physicalDiskListInstance;

	private:
		CPhysicalDiskListImpl	*m_physicalListImpl;
};
