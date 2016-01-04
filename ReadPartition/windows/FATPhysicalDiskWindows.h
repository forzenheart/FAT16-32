#ifndef	_FAT_PHYSICAL_DISK_WINDOWS_H__
#define	_FAT_PHYSICAL_DISK_WINDOWS_H__

class CPhysicalDiskWindows : public CPhysicalDisk {
	public:
		CPhysicalDiskWindows(void *handle);
		INT64	ReadSector(INT64 secNum, void *buf, INT64 bytes);
		INT64	WriteSector(INT64 secNum, const void *buf, INT64 bytes);
	protected:
		INT64	Seek(INT64 secNum, int whence = 0);
};

#endif	//_FAT_PHYSICAL_DISK_WINDOWS_H__
