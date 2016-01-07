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
		INT64 used, 
		INT64 unused, 
		bool isprimary, 
		std::string partname, 
		std::string volumename) 
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
	m_Used(used), 
	m_Unused(unused), 
	m_IsPrimary(isprimary), 
	m_PartitionName(partname), 
	m_VolumeName(volumename)
{ }

