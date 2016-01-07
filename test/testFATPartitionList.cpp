#include "ReadPartition/FATPartitionList.h"
#include <stdio.h>

int main(void)
{
	CPartitionList*	cp = CPartitionList::GetInstance();

	for (int j = 0; j < 2; j++)
	{
		printf("中文Disk ID:%2d <%s Basic>, Sector count:%12d, C:%5d, H:%5d, S:%2d\n", 
				j, 
				"MBR", 
				0, 
				0, 
				0, 
				0);
		printf("ID  Letter	Type		Capacity(MB)	Used	Unused	State	Primary	Start(MB)\n");
		for (int i = 0; i < cp->GetPartitionCount(); i++)
		{
			printf("%2d  %-10s	%-10s	%-9lld	%-5d	%-5d	%s	%s	%-8d\n", 
					i, 
					" ", 
					cp->GetPartitionTypeByID(i)->c_str(),
					(cp->GetTotalSecByID(i) * 512) / 1024, 
					0, 
					0, 
					cp->GetActiveFlagByID(i) ? "Active" : "None", 
					"Primary", 
					0);

		}
	}
	return 0;
}
