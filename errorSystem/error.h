#ifndef	_FAT_SYSTEM_ERROR_H__
#define	_FAT_SYSTEM_ERROR_H__

#include "../platform/FATPlatformDefine.h"
/*
   Linux system error
 */

#if	FAT_TARGET_PLATFROM == FAT_PLARFROM_LINUX
#include <errno.h>	//for definition of errno
#include <stdarg.h>	//ISO C varible aruments
#ifdef __cplusplus
extern "C" {

/*
 *void	err_msg(const char *, ...);
 *void	err_quit(const char *, ...);
 *void	err_exit(int, const char *, ...);
 *void	err_ret(const char *, ...);
 *void	err_sys(const char *, ...);
 */
#ifdef __cplusplus
}
#endif //__cplusplus
#endif //FAT_TARGET_PLATFROM == FAT_PLARFROM_LINUX


#if	FAT_TARGET_PLATFROM == FAT_PLARFROM_WIN32

#endif	//FAT_TARGET_PLATFROM == FAT_PLARFROM_WIN32

#endif	//_FAT_SYSTEM_ERROR_H__
