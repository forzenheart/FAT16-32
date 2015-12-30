#include "MBRImplLinux.h"

int
CMBRLinux::Scan()
{
	UINT8	MBRbuf[512];
	m_partitionList.clear();


	CDiskList	diskList;
	diskList.Scan();
	for (int i = 0; i < diskList.count(); i++)
		diskListGetDiskByID(i)->ReadSec(0, MBRbuf);
			
	m_partitionList.push_back(cd);
	//加入Linux平台相关的浏览分区的代码
	return m_partitionList.size();
}

