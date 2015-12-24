#ifndef	__FAT_MBR_FACTORY_WINDOWS_H__
#define __FAT_MBR_FACTORY_WINDOWS_H__

#include "../MBRFactory.h"
#include "../MBRImpl.h"

class CMBRFactoryWindows : public CMBRFactory {
	public:
		static CMBRFactoryWindows* GetFactoryInstance()
		{
			static CMBRFactoryWindows *factory = 0;
			if (!factory)
				factory = new CMBRFactoryWindows;
			return factory;
		}

		virtual ~CMBRFactoryWindows() {};
		virtual CMBR*	MakeMBR();
	private:
		CMBRFactoryWindows() {};
};
#endif // __FAT_MBR_FACTORY_WINDOWS_H__
