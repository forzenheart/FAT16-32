#include "ReadPartition/FATDiskPartition.h"

CDiskPartition::CDiskPartition(
		bool a,
		INT8 sh, 
		INT8 ss, 
		INT8 sc, 
		INT8 pt, 
		INT8 eh, 
		INT8 es,
		INT8 ec, 
		INT32 spp, 
		INT32 t, 
		std::string name = "") 
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

