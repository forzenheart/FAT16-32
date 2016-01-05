#include "ReadPartition/FATPhysicalDiskFactory.h"
#include "ReadPartition/FATPhysicalDiskList.h"

CPhysicalDiskList*	CPhysicalDiskList::m_physicalDiskListInstance = NULL;

CPhysicalDiskList*
CPhysicalDiskList::GetInstance()
{
	if (m_physicalDiskListInstance == NULL)
	{
		m_physicalDiskListInstance = new CPhysicalDiskList;
	}
	return m_physicalDiskListInstance;
}

CPhysicalDiskList::CPhysicalDiskList() 
	:m_physicalListImpl(NULL)
{
	CPhysicalDiskFactory*	factory = CPhysicalDiskFactory::GetPhysicalDiskFactory();
	  if(factory)
	  {
		m_physicalListImpl = factory->MakePhysicalDisk();
	  }
}

CPhysicalDiskList::CPhysicalDiskList(const CPhysicalDiskList&)
{

}

int
CPhysicalDiskList::EnumPhysicalDisk()
{
	if (m_physicalListImpl)
	{
		return m_physicalListImpl->EnumPhysicalDisk();
	}
	return -1;
}

int
CPhysicalDiskList::GetCount() const
{
	if (m_physicalListImpl)
	{
		return m_physicalListImpl->GetPhysicalDiskCount();
	}
	return -1;
}

CPhysicalDisk*
CPhysicalDiskList::GetPhysicalDiskByID(const int which) const
{
	if (m_physicalListImpl)
	{
		return m_physicalListImpl->GetPhysicalDiskByID(which);
	}
	return NULL;
}
