#include "../platform/FATPlatformConfig.h"
#include <cstdio>

int main(void)
{
	printf("platform = %d\n", FAT_TARGET_PLATFORM);
	return 0;
}
