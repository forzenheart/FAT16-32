#ifndef	__FAT_MBR_FACTORY_LINUX_H__
#define __FAT_MBR_FACTORY_LINUX_H__

#include "../MBRFactory.h"
#include "../MBRImpl.h"
class CMBRFactoryLinux : public CMBRFactory {
	public:
		static CMBRFactoryLinux* GetFactoryInstance()
		{
			static CMBRFactoryLinux *factory = 0;
			if (!factory)
				factory = new CMBRFactoryLinux;
			return factory;
		}

		virtual ~CMBRFactoryLinux()
		{}
		virtual CMBR*	MakeMBR();
	private:
		CMBRFactoryLinux() {};
};

#endif //__FAT_MBR_FACTORY_LINUX_H__
