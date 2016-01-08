#include "ReadPartition/windows/FATPhysicalDiskListImplWindows.h"
#include "ReadPartition/windows/FATPhysicalDiskWindows.h"

#include <windows.h>
#include <winerror.h>
#include <tchar.h>
#include <string>
#include <strsafe.h>

int_fast32_t
CPhysicalDiskListImplWindows::EnumPhysicalDisk()
{
	m_physicalDiskList.clear();

	//windows platform
	HANDLE	hFile;
	DWORD	dwErrorsv;
	CPhysicalDisk	*pPhydisk = NULL;

	std::string	pathName = "\\\\.\\PhysicalDrive";
	for (int_fast32_t i = 0; i < MAXPHYSICALDISKNUMBER; i++)
	{
		//Get the disk Handle in windows
		if ((hFile = CreateFile((pathName + (CHAR)(i + '0')).c_str(),
					GENERIC_READ, 
					FILE_SHARE_READ |
					FILE_SHARE_WRITE, 
					NULL, OPEN_EXISTING, 0, NULL))
				== INVALID_HANDLE_VALUE)	
		{
			dwErrorsv = GetLastError();
			if (dwErrorsv == ERROR_ACCESS_DENIED)
			{
				fprintf(stderr, "This programma need be run from root\n");
				break;
			}
			else if (dwErrorsv == ERROR_FILE_NOT_FOUND)
			{
				fprintf(stdout, "Can`t find the PhysicalDisk %d\n", i);
				break;
			}
			else
			{
				fprintf(stderr, "another Mistake in Windows, the errorNum %lld\n", dwErrorsv);
				break;
			}
		}
		//put the disk Handle into disklist here
		pPhydisk = new CPhysicalDiskWindows(hFile);
		m_physicalDiskList.push_back(pPhydisk);
	}
	pPhydisk = NULL;
	return m_physicalDiskList.size();
}

