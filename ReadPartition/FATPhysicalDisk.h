#ifndef	_FAT_PHYSICAL_DISK_H__
#define	_FAT_PHYSICAL_DISK_H__

class CPhysicalDisk {
	public:
		virtual		INT64	ReadSector();
		virtual		INT64	WriteSector();
	private:
		virtual	INT64	seek(INT64 offset);
		virtual	int	open();
		virtual	int	close();
};

#endif	//_FAT_PHYSICAL_DISK_H__
