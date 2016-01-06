#include <string>
#include <stdio.h>
#include "FATPartitionTypeIndicator.h"

int main(void)
{
	std::string	name;

	name = FATPartTypeName[0x83];
	printf("%s\n", FATPartTypeName[0x8e]);
	printf("%s\n", name.c_str());

	return 0;
}
