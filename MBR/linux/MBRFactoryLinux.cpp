#include "MBRImplLinux.h"
#include "MBRFactoryLinux.h"

CMBR*
CMBRFactoryLinux::MakeMBR()
{
	return new CMBRLinux;
}
