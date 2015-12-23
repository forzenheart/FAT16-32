#ifndef	__FAT_MBR_FACTORY_H__
#define	__FAT_MBR_FACTORY_H__

#include "MBRImpl.h"

class CMBRFactory {
	public:
	virtual	~CMBRFactory()
	{}

	virtual CMBR	*MakeMBR() = 0;
	static CMBRFactory*	GetMBRFactory();
};

#endif	//__FAT_MBR_FACTORY_H__

