#include <cstdio>
#include "../MBR/MBR.h"

int
main(void)
{
	CDiskPartitionList	mbr;
	mbr.Scan();

	printf("PartitionID	PartitionName	TotalSectors	Capacity	ActivePartition\n");
	for (int i = 0; i < mbr.GetPartitionCount(); i++)
	{
		printf("%s	%d	%-8d(bytes)	%s", 
				mbr.GetPartitionName(i), 
				mbr.GetPartitionTolSec(i), 
				mbr.GetPartitionTolSec(i) * 512, 
				mbr.GetPartitionActiveFlag(i));
	}

	return 0;
}
