#include "ReadPartition/linux/FATPhysicalDiskListImplLinux.h"
#include "ReadPartition/linux/FATPhysicalDiskLinux.h"

//linux platform header
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <cstdio>
#include <string.h>

int
CPhysicalDiskListImplLinux::EnumPhysicalDisk()
{
	m_physicalDiskList.clear();

	int	iDiskFd = -1;
	CPhysicalDisk	*pPhydisk = NULL;

	/*Because of the physical disk pathname, this function just
	 *Just work in Centos and Ubuntu;
	 *I haven`t test it on another linux platform;
	 */
	std::string	pathName = "/dev/sd"; 

	for (int i = 0; i < MAXPHYSICALDISKNUMBER; i++)
	{
		//Get the filedes in linux;
		if ((iDiskFd = open((pathName + (char)(i + 'a')).c_str(), O_RDONLY)) < 0)
		{
			int errsv = errno;
			if (errsv == EACCES)
			{
				fprintf(stderr, "Please run this program from root.\n");
				break;
			}
			else if (errsv == ENOENT)
			{
				//Got the max number of this computer physical disk;
				break;
			}
			else
			{
				fprintf(stderr, "another mistake in linux : %s\n", strerror(errsv));
				break;
			}
		}
		//push the physical disk into the disklist here
		pPhydisk = new CPhysicalDiskLinux(iDiskFd);
		printf("%d\n", iDiskFd);
		m_physicalDiskList.push_back(pPhydisk);
	}
	pPhydisk = NULL;

	return m_physicalDiskList.size();
}

