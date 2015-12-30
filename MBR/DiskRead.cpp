#include "DiskRead.h"

INT64 Read(INT64 secNum, UINT8* buf)
{
	if(m_diskImp)
	{
	}
	return -1;
}

int	Open()
int	Close();
INT64	Seek(off_t offset, int whence);
INT64	Read(INT64 secNum, UINT8 *buf);
INT64	Write(INT64 secNum, const UINT8 *buf);
