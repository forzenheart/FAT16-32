#include "MBRImplWindows.h"

int
CMBRWindows::Scan()
{
	m_partitionList.clear();
	//Windows平台浏览分区方式

	return m_partitionList.size();
}
