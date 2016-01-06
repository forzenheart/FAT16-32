#include "ReadPartition/FATPhysicalDiskList.h"
#include <cstdio>

int
main(void)
{
	CPhysicalDiskList	*cp = CPhysicalDiskList::GetInstance();

	printf("%d\n", cp->EnumPhysicalDisk());
	printf("%d\n", cp->GetCount());

	CPhysicalDisk*	pd = cp->GetPhysicalDiskByID(0);

	unsigned char buf[512] = {0};

	pd->ReadSector(0, buf, 512);

	for (int i = 0; i < 512 / 16; i++)
	{
		//Change the print format of decimal or hex
		//printf("%.11d : ",i * 16);
		printf("%011X : ",i * 16);
		for (int j = 0; j < 16; j++)
		{
		printf("%02X ", buf[i * 16 + j]);
		}
		printf("\n");
	}
	
	return 0;
}

