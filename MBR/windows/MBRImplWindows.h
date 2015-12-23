#ifndef __FAT_MBR_IMPL_WINDOWS_H__
#define	__FAT_MBR_IMPL_WINDOWS_H__

#include "../MBRImpl.h"
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

class CMBRWindows : public CMBR {
	public:
		CMBRWindows()
		{}

		virtual ~CMBRWindows()
		{}

		virtual int Scan();
};


#endif	//__FAT_MBR_IMPL_WINDOWS_H__
