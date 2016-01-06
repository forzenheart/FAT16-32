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
		
INT64
CPhysicalDiskWindows::ReadSector(INT64 secNum, void *buf, INT64 bytes)
{
	DWORD	dwBytesRead;

	Seek(secNum);

	if (FALSE == ReadFile(m_diskHandle.HANDLE, buf, bytes, &dwBytesRead, NULL))
	{
		fprintf(stderr, "ReadFile error.\n");
		return -1;
	}
	return static_cast<INT64>(dwBytesRead);
}

INT64
CPhysicalDiskWindows::WriteSector(INT64 secNum, const void *buf, INT64 bytes)
{
	//None implementation
	return -1;
}

INT64
CPhysicalDiskWindows::Seek(INT64 secNum, int whence)
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
