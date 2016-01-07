#include <windows.h>

int main(void)
{
	wchar_t *dsk=_T("\\\\.\\PhysicalDrive0");
	DWORD dwRead;  

	HANDLE hDisk=CreateFile(_dsk,  GENERIC_READ,  FILE_SHARE_READ,  0 ,  OPEN_EXISTING,  0,  0);
	if(hDisk==INVALID_HANDLE_VALUE) // this may happen if another program is already reading from disk  
	{
		wcout<<"Could not open file error("<<GetLastError()<<")"<<endl;
		CloseHandle(hDisk);    
		return -1;
	}  
	else 
	{
		// CreateFile OK
		GET_LENGTH_INFORMATION lpOutBuffer; 
		DWORD lpBytesReturned; 
		BOOL ndcRet;

		ndcRet = DeviceIoControl( 
				(HANDLE) hDisk,                 // handle to device
				IOCTL_DISK_GET_LENGTH_INFO,     // dwIoControlCode 
				NULL,                           // lpInBuffer 
				0,                              // nInBufferSize 
				&lpOutBuffer,                      // output buffer   
				sizeof(GET_LENGTH_INFORMATION), // size of output buffer 
				(LPDWORD) &lpBytesReturned,     // number of bytes returned 
				NULL                           // OVERLAPPED structure
				);

		if(ndcRet == TRUE)  
		{
			// success
			wcout<<"size is "<<lpOutBuffer.Length.QuadPart<<" bytes"<<endl;  
			wcout<<"size is "<<lpOutBuffer.Length.QuadPart/1024<<" KB"<<endl;   
			wcout<<"size is "<<lpOutBuffer.Length.QuadPart/1048576<<" MB"<<endl;   
			wcout<<"size is "<<lpOutBuffer.Length.QuadPart/1073741824<<" GB"<<endl;  
		}  
		else  
		{
			// Error occured
		}  

	}  
	CloseHandle(hDisk); 
}
