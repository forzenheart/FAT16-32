#include <cstdio>
#include "MBR.h"

int
main(void)
{
	CDiskPartitionList	mbr;
	mbr.Scan();

	printf("PartitionID	PartitionName	TotalSectors	Capacity	ActivePartition\n");
	for (int i = 0; i < mbr.GetPartitionCount(); i++)
	{
		printf("%d		%s :		%02X		%8lld(bytes)		%d\n", 
				i, 
				mbr.GetPartitionName(i)->c_str(), 
				mbr.GetPartitionTolSec(i), 
				mbr.GetPartitionTolSec(i) * 512, 
				mbr.GetPartitionActiveFlag(i));
	}

	return 0;
}
