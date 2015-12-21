#include "error.h"

#if	FAT_TARGET_PLATFROM == FAT_PLARFROM_LINUX
void	err_msg(const char *, ...);
void	err_quit(const char *, ...);
void	err_exit(int, const char *, ...);
void	err_ret(const char *, ...);
void	err_sys(const char *, ...);
#endif //FAT_TARGET_PLATFROM == FAT_PLARFROM_LINUX

#if	FAT_TARGET_PLATFROM == FAT_PLARFROM_WIN32

#endif	//FAT_TARGET_PLATFROM == FAT_PLARFROM_WIN32
