#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

#define BUFFERSIZE 512
#define wszDrive L"\\\\.\\PhysicalDrive0"
DWORD	g_BytesTransferred = 0;
DWORD	g_iPartitionNum = 0;

void	DisplayError(LPTSTR lpszFunction);
void	ReadEBR(HANDLE hfile, __int64 offset);

VOID CALLBACK FileIOCompletionRoutine(
		__in  DWORD dwErrorCode, 
		__in  DWORD dwNumberOfBytesTransfered, 
		__in  LPOVERLAPPED lpOverlapped
		);

VOID CALLBACK FileIOCompletionRoutine(
		__in  DWORD dwErrorCode, 
		__in  DWORD dwNumberOfBytesTransfered, 
		__in  LPOVERLAPPED lpOverlapped )
{

	_tprintf(TEXT("Error code:\t%x\n"),  dwErrorCode);
	_tprintf(TEXT("Number of bytes:\t%x\n"),  dwNumberOfBytesTransfered);
	g_BytesTransferred = dwNumberOfBytesTransfered;
}

//
// Note: this simplified sample assumes the file to read is an ANSI text file
// only for the purposes of output to the screen. CreateFile and ReadFile
// do not use parameters to differentiate between text and binary file types.
//

void __cdecl _tmain(int argc,  TCHAR *argv[])
{
	HANDLE hFile = INVALID_HANDLE_VALUE; 
	DWORD  dwBytesRead = 0;
	char   ReadBuffer[BUFFERSIZE] = {0};
	LONG	lDistance = 0;

	hFile = CreateFileW(wszDrive,            // file to open
			GENERIC_READ,           // open for reading
			FILE_SHARE_READ |
			FILE_SHARE_WRITE,	// share for reading
			NULL,                   // default security
			OPEN_EXISTING,          // existing file only
			0,  // normal file
			NULL);                 // no attr. template

	if (hFile == INVALID_HANDLE_VALUE) 
	{
		DisplayError(TEXT("CreateFile"));
		_tprintf(TEXT("Terminal failure: unable to open file \"%s\" for read.\n"),  wszDrive);
		return; 
	}

	// Read one character less than the buffer size to save room for
	// the terminating NULL character. 
	//DWORD dwPtr = SetFilePointer( hFile,  
	//lDistance,  
	//NULL,  //当需要大幅度跨越的时候，这里需要参数
	//FILE_BEGIN );

	if(FALSE == ReadFile(hFile,  ReadBuffer,  BUFFERSIZE,  &dwBytesRead,  NULL))
	{

		DisplayError(TEXT("ReadFile"));
		printf("Terminal failure: Unable to read from file.\n GetLastError=%08x\n",  GetLastError());
		CloseHandle(hFile);
		return;
	}
	SleepEx(1000,  TRUE);
	// This is the section of code that assumes the file is ANSI text. 
	// Modify this block for other data types if needed.

	if (dwBytesRead > 0 && dwBytesRead <= BUFFERSIZE-1)
	{
		/*
		 *printf("%s\n",  ReadBuffer);
		 *for (int i = 0; i < 32; i++)
		 *{
		 *        Change the print format of decimal or hex
		 *        printf("%.11d : ",i * 16);
		 *        printf("%011X : ",i * 16);
		 *        for (int j = 0; j < 16; j++)
		 *        {
		 *                printf("%02X ", ReadBuffer[i * 16 + j]);
		 *        }
		 *        printf("\n");
		 *}
		 */
		__int64 secUsedsize = 0;
		__int64 secTolsize = 0;
		for (int i = 0; i < 4; i++)
		{
			if (*((int*)&ReadBuffer[446 + 8 +  i * 16]) == 0) /*Nothing in MBR just break*/ 
				break;
			secUsedsize = *((int*)&ReadBuffer[446 +  8 + i * 16]);
			secTolsize = *((int*)&ReadBuffer[446 + 12 + i * 16]);
			if (ReadBuffer[446 + 4 + i * 16] == 0x0f ||
					ReadBuffer[446 + 4 + i * 16] == 0x05)
			{
				ReadEBR(hFile, secUsedsize);
			}
			else {
				printf("Primary Partition	Type	ActivePartition		Capacity\n"
						"%2d	%02x	%s	%.2f (MB)\n", 
						g_iPartitionNum++, 
						ReadBuffer[446 + 4 + i * 16], 
						(ReadBuffer[46 + 0 + i * 16] == 0x80 ? "Yes" : "No"), 
						(double)((secTolsize * 512) / (1024 * 1024)));
			}
		}
	}
	else if (dwBytesRead == 0)
	{
		_tprintf(TEXT("No data read from file %s\n"),  wszDrive);
	}
	else
	{
		printf("\n ** Unexpected value for dwBytesRead ** \n");
	}

	// It is always good practice to close the open file handles even though
	// the app will exit here and clean up open handles anyway.
	CloseHandle(hFile);
}

void DisplayError(LPTSTR lpszFunction) 
	// Routine Description:
	// Retrieve and output the system error message for the last-error code
{

	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError(); 

	FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS, 
			NULL, 
			dw, 
			MAKELANGID(LANG_NEUTRAL,  SUBLANG_DEFAULT), 
			(LPTSTR) &lpMsgBuf, 
			0,  
			NULL );

	lpDisplayBuf = 
		(LPVOID)LocalAlloc( LMEM_ZEROINIT,  
				( lstrlen((LPCTSTR)lpMsgBuf)
				  + lstrlen((LPCTSTR)lpszFunction)
				  + 40) // account for format string
				* sizeof(TCHAR) );

	if (FAILED( StringCchPrintf((LPTSTR)lpDisplayBuf,  
					LocalSize(lpDisplayBuf) / sizeof(TCHAR), 
					TEXT("%s failed with error code %d as follows:\n%s"),  
					lpszFunction,  
					dw,  
					lpMsgBuf)))
	{

		printf("FATAL ERROR: Unable to output error code.\n");
	}

	_tprintf(TEXT("ERROR: %s\n"),  (LPCTSTR)lpDisplayBuf);

	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
}

void	ReadEBR(HANDLE hfile, __int64 offset)
{
	UCHAR	EBRBuf[4096];
	DWORD	dwBytesReadEBR;
	LARGE_INTERGER	li;
	li.QuadPart = offset * 512;

	if (INVALID_SET_FILE_POINTER == SetFilePointerEx(hfile, li, NULL, FILE_BEGIN))
	{
		DisplayError(TEXT("ReadFile"));
		printf("Terminal failure : Unable to read from file.\n GetLastError = %08x\n", 
				GerLastError());
		return;
	}

	if (FALSE == ReadFile(hfile, EBRBuf, BUFFERSIZE, &dwBytesRead, NULL))
	{
		DisplayError(TEXT("ReadFile"));
		printf("Terminal failure: Unable to read from file, \n GetLastError = %08x\n", 
				GetLastError());
		return;
	}
	__int64	secUsedsize = 0;
	__int64 secTolsize = 0;
	UCHAR	EBRFlag;

	for (int i = 0;  i < 2; i++)
	{
		if (*((int*)EBRBuf[446 + 8 + i * 16]) == 0)
			break;
		secUsedsize = *((int*)&EBRBuf[446 + 8 + i * 16]);
		secTolsize = *((int*)&EBRBuf[446 + 12 + i * 16]);
		EBRFlag = EBRBuf[446 + 4 + i * 16];
		if (EBRFlag == 0x0f || EBRFlag == 0x05)
			ReadEBR(hfile, secUsedsize);
		else {
			printf("Primary Partition	Type	ActivePartition		Capacity\n"
					"%2d	%02x	%s	%.2f (MB)\n", 
					g_iPartitionNum++, 
					EBRBuf[446 + 4 + i * 16], 
					(EBRBuf[46 + 0 + i * 16] == 0x80 ? "Yes" : "No"), 
					double(secTolsize * 512 / 1024 / 1024));
		}
	}
}
