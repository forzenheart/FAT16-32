#include "ReadPartition/FATPartitionList.h"
#include <stdio.h>

int main(void)
{
	
	CPartitionList*	cp = CPartitionList::GetInstance();

	printf("No	AcFlag	Capacity(MB)	TypeName\n");
	for (int i = 0; i < cp->GetPartitionCount(); i++)
	{
		printf("%d	%s	 %9lld	%s\n", 
				i, 
				cp->GetActiveFlagByID(i) ? "Yes" : "No", 
				cp->GetTotalSecByID(i) * 512 / 1024, 
				cp->GetPartitionTypeByID(i)->c_str());

	}
	return 0;
}
