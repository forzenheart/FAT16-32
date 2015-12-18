#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

#define BUFFERSIZE 512
#define wszDrive L"\\\\.\\PhysicalDrive0"
DWORD g_BytesTransferred = 0;

void DisplayError(LPTSTR lpszFunction);

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

	HANDLE hFile; 
	DWORD  dwBytesRead = 0;
	char   ReadBuffer[BUFFERSIZE] = {
		0};
	OVERLAPPED ol = {
		0};
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

	if( FALSE == ReadFileEx(hFile,  ReadBuffer,  BUFFERSIZE-1,  &ol,  FileIOCompletionRoutine) )
	{

		DisplayError(TEXT("ReadFile"));
		printf("Terminal failure: Unable to read from file.\n GetLastError=%08x\n",  GetLastError());
		CloseHandle(hFile);
		return;
	}
	SleepEx(5000,  TRUE);
	dwBytesRead = g_BytesTransferred;
	// This is the section of code that assumes the file is ANSI text. 
	// Modify this block for other data types if needed.

	if (dwBytesRead > 0 && dwBytesRead <= BUFFERSIZE-1)
	{
		ReadBuffer[dwBytesRead]='\0'; // NULL character

		_tprintf(TEXT("Data read from %s (%d bytes): \n"),  wszDrive,  dwBytesRead);
		//printf("%s\n",  ReadBuffer);
		for (int i = 0; i < 32; i++)
		{
			//Change the print format of decimal or hex
			//printf("%.11d : ",i * 16);
			printf("%011X : ",i * 16);
			for (int j = 0; j < 16; j++)
			{
				printf("%02X ", ReadBuffer[i * 16 + j]);
			}
			printf("\n");
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
