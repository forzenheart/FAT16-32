#include "ReadPartition/windows/FATPhysicalDiskWindows.h"
//window platform head
#include <windows.h>
#include <tchar.h>
#include <cstdio>
#include <strsafe.h>

CPhysicalDiskWindows::CPhysicalDiskWindows(void *handle)
	: CPhysicalDisk(handle)
{

}
		
int_fast64_t
CPhysicalDiskWindows::ReadSector(int_fast64_t secNum, void *buf, int_fast64_t bytes)
{
	DWORD	dwBytesRead;

	Seek(secNum);

	if (FALSE == ReadFile(m_diskHandle.HANDLE, buf, bytes, &dwBytesRead, NULL))
	{
		fprintf(stderr, "ReadFile error.\n");
		return -1;
	}
	return static_cast<int_fast64_t>(dwBytesRead);
}

int_fast64_t
CPhysicalDiskWindows::WriteSector(int_fast64_t secNum, const void *buf, int_fast64_t bytes)
{
	//None implementation
	return -1;
}

int_fast64_t
CPhysicalDiskWindows::Seek(int_fast64_t secNum, int_fast32_t whence)
{
	LARGE_INTEGER	li;
	li.QuadPart = secNum * 512;

	 if (INVALID_SET_FILE_POINTER == SetFilePointerEx(m_diskHandle.HANDLE, li, NULL, whence))
	 {
		 fprintf(stderr, "SetFilePointerEx error\n");
		 return -1;
	 }

	return li.QuadPart;
}
