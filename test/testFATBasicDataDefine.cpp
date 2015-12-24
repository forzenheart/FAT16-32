#include "../base/FATBasicDataDefine.h"
#include <cstdio>

int
main(void)
{
	INT8 c = -128;
	INT16 s = -32768;
	INT32 l = -2147483648;
	INT64 ll = (-9223372036854775807 - 1);

	UINT8 uc = 255;
	UINT16 us = 65535;
	UINT32 ul= 4294967295;
	UINT64 ull = 1844674407370955161;

	printf("%d\n", c);	
	printf("%d\n", s);	
	printf("%ld\n", l);	
	printf("%lld\n", ll);	

	printf("%d\n", uc);	
	printf("%d\n", us);	
	printf("%ld\n", ul);	
	printf("%lld\n", ull);	
	return 0;
}
