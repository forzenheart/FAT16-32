#include <cstdio>
#include "MBR.h"

int
main(void)
{

	CMBR	mbr;
	mbr.Scan();

	printf("PartitionID	PartitionName	TotalSectors	Capacity	ActivePartition\n");
	for (int i = 0; i < mbr.GetPartitionCount(); i++)
	{
		printf("%d	%s	%d	%-8d(bytes)	%s", 
				mbr.GetPartitionID(j), 
				mbr.GetPartitionName(j), 
				mbr.GetPartitionTolSec(i), 
				mbr.GetPartitionTolSec(i) * 512, 
				mbr.GetPartitionActiveFlag(i));
	}

	return 0;
}
