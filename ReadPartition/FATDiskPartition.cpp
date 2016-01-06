#include "ReadPartition/FATDiskPartition.h"

CDiskPartition::CDiskPartition(
		bool a,
		UINT8 sh, 
		UINT8 ss, 
		UINT16 sc, 
		std::string pt, 
		UINT8 eh, 
		UINT8 es,
		UINT16 ec, 
		INT64 spp, 
		INT64 t, 
		std::string name) 
:
m_ActivePartition(a), 
	m_StartHeadNo(sh), 
	m_StartSecNo(ss), 
	m_StartCylinderNo(sc), 
	m_PartitionTypeIndicator(pt), 
	m_EndHeadNo(eh), 
	m_EndSecNo(es), 
	m_EndCylinderNo(ec), 
	m_SecPrecedingPartition(spp), 
	m_TotSec(t), 
	m_PartitionName(name)
{ }

