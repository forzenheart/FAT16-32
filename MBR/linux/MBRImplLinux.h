#ifndef __FAT_MBR_IMPL_LINUX_H__
#define	__FAT_MBR_IMPL_LINUX_H__

#include "../MBRImpl.h"
//linux平台相关文件
#include <unistd.h>
#include <fcntl.h>

class CMBRLinux : public CMBR {
	public:
		CMBRLinux() {};

		virtual ~CMBRLinux() {};

		virtual int Scan();
};


#endif	//__FAT_MBR_IMPL_LINUX_H__
