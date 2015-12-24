#include "MBRImplWindows.h"
#include "MBRFactoryWindows.h"

CMBR*
CMBRFactoryWindows::MakeMBR()
{
	return new CMBRWindows;
}
