#ifndef	_FAT_DISKREAD_H__
#define	_FAT_DISKREAD_H__
//Waring!!!
//None finish

class CDISK {
	public:

		int	ReadMBR(UINT8 *buf);
		int	ReadPartition(UINT8 *buf);
		int	ReadFAT(UINT8 *buf);
		int	ReadDBR(UINT8 *buf);

		//read the content of sector through the sectorNo
		INT64	ReadSector(INT64 secNum, UINT8 *buf);
		INT64	WriteSector(INT64 secNum, const UINT8 *buf);
	private:
		CDISKImpl*	m_diskImpl;
};

#endif	//_FAT_DISKREAD_H__
