#include <iostream>
#include "ReadPartition/FATPartitionList.h"

int main(void)
{
	CPartitionList&	pl = CPartitionList::GetInstance();

	for (int i = 0; i < pl.GetCount(); i++) {
		//use the partitionlist information here;


	}

	return 0;
}
