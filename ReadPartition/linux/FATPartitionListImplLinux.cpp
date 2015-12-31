#include "FATPartitionListImplLinux.h"

//linux platform header
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <cstdio>

int
CPartitionListImplLinux::EnumPhysicalDisk()
{
	m_physicalDiskList.clear();

	int	DiskFd;//linux filedes
	CPhysicalDisk	*phydisk;
	/*just in Centos and Ubuntu;I haven`t test it on another linux platform*/ 
	std::string	pathName = "/dev/sd"; 

	for (int i = 0; i < MAXPHYSICALDISKNUMBER; i++) {
		//Get the filedes in linux;
		if (DiskFd = open((pathName + char(i + 'a')).c_str(), O_RDONLY) < 0) {
			int errsv = errno;
			if (errsv == EACCES) {
				fprintf(stderr, "Please run this program from root.\n");
				break;
			} else if (errsv == ENOENT) {
				break;
			} else {
				fprintf(stderr, "%s\n", strerror(errsv));
				break;
			}
		}

		//push the physical disk into the disklist here

	}
	return m_physicalDiskList.size();
}

