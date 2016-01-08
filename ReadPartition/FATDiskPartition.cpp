#include "ReadPartition/FATDiskPartition.h"

CDiskPartition::CDiskPartition(
		bool a,
		uint_fast8_t sh, 
		uint_fast8_t ss, 
		uint_fast16_t sc, 
		std::string pt, 
		uint_fast8_t eh, 
		uint_fast8_t es,
		uint_fast16_t ec, 
		int_fast64_t spp, 
		int_fast64_t t, 
		int_fast64_t used, 
		int_fast64_t unused, 
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

