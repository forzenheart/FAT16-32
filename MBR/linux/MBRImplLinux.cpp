#include "MBRImplLinux.h"

int
CMBRLinux::Scan()
{
	m_partitionList.clear();
	CDiskPartition cd(true,
			0x00, 
			0x01, 
			0x02, 
			0x8E, 
			0x04, 
			0x05, 
			0x06,
			0xA5, 
			0x00, 
			"this is test for the platform");
			
	m_partitionList.push_back(cd);
	//加入Linux平台相关的浏览分区的代码
	return m_partitionList.size();
}

