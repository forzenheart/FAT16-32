#ifndef __MBR_LINUX_H__
#define	__MBR_LINUX_H__
#include "../../base/FATBasicDataDefine.h"
#include <cstdio>
#include <cstdlib>

//中英文对照表
//柱面	Cylinder
//扇区	Sector
//磁头	Head
//磁道	Track
//盘面	Platter
//主轴	Spindle
typedef struct CMBR {
	INT16	m_MBRNo;//MBR编号，这里不区分是否为扩展分区

	static const int size = 4096;
	//这里使用4096的目的是因为在linux系统上，read的IO效率最高
	unsigned char	Content[size];
}CMBR;

void printNowOffset(int);
void printSectorContent(const unsigned char *, int);
unsigned int getNextMBR(const unsigned char *);

#endif	//__MBR_LINUX_H__

//the probably path of physical driver;
//  /dev/mapper/vg_forzenheart-lv_root
//  /dev/sda1
// /dev/mapper/vg_forzenheart-lv_home
// scsi-SATA_ST1000DM003-1ER_W4Y5TGGF
// scsi-SATA_ST1000DM003-1ER_W4Y5TGGF-part1
// /dev/disk/by-id


