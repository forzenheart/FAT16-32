#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <errno.h>

int
main(void)
{
	int	iDiskFd = -1;

	std::string pathName = "/dev/sd";
	std::string pathName2 = pathName + 'a';
	printf("%s\n", pathName2.c_str());
	for (int i = 0; i < 10; i++)
	{
		printf("%s\n", (pathName + (char)(i + 'a')).c_str());
		if ((iDiskFd = open((pathName + (char)(i + 'a')).c_str(), O_RDONLY)) < 0)
		{
			int errsv = errno;
			if (errsv == ENOENT)
			{
				printf("no file\n");
				printf("%d\n", iDiskFd);
				break;
			}
		}
		printf("%d\n", iDiskFd);
	}
	return 0;
}
