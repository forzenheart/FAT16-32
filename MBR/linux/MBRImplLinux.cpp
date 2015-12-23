#include "MBRImplLinux.h"

int
CMBRLinux::Scan()
{
	m_partitionList.clear();

	//加入Linux平台相关的浏览分区的代码
	return m_partitionList.size();
}

