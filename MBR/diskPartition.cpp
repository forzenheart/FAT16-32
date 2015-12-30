#include <cstdio>
#include "MBR.h"

int
main(void)
{
	CDiskPartitionList	partition;
	partition.Scan();

	printf("PartitionID	PartitionName	TotalSectors	Capacity	ActivePartition\n");
	for (int i = 0; i < partition.GetPartitionCount(); i++)
	{
		printf("%d		%s :		%02X		%8lld(bytes)		%d\n", 
				i, 
				partition.GetPartitionName(i)->c_str(), 
				partition.GetPartitionTolSec(i), 
				partition.GetPartitionTolSec(i) * 512, 
				partition.GetPartitionActiveFlag(i));
	}

	return 0;
}
