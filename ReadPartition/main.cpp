#include "MBRImplLinux.h"

#define	GETCONTENT(S)	(*((int*)(&(S))))

int
CMBRLinux::Scan()
{
	UINT8	MBRbuf[512];
	UINT8	EBRbuf[512];
	m_partitionList.clear();

	CDiskList	diskList;
	diskList.Scan();
	for (int i = 0; i < diskList.count(); i++)
	{
		diskListGetDiskByID(i)->ReadSec(0, MBRbuf);

		INT64	secUsedsize = 0;
		INT64	secTolsize = 0;

		for (int j = 0; j < 4; j++)
		{
			//if it`s not a partition the sectornum will be zeor;
			if (GETCONTENT(MBRbuf[446 + 8 + j * 16]) == 0x00)
				break;
			//It`s EBR partition
			if (MBRbuf[446 + 4 + j * 16] == 0x0f ||
					MBRbuf[446 + 4 + j * 16] == 0x05)
			{
				//Get the EBR start sector number from the MBR
				diskListGetDiskByID(i)->ReadSec(GETCONTENT(MBRBuf[446 + 8 + j * 16]), EBRbuf);
				 while(GETCONTENT(EBRbuf[446 + 4 + 16]) == 0x0f ||
						 GETCONTENT(EBRBuf[446 + 4 + 16]) == 0x05)
				 {
					 //Read the EBR Partition Information here


					 //Get the Next EBR start sector number
					diskListGetDiskByID(i)->ReadSec(GETCONTENT(EBRBuf[446 + 8 + 16]), EBRbuf);
				 }
			}
			else {
				//Read the MBR Partition Information here

			}
		}
	}

	m_partitionList.push_back(cd);
	//加入Linux平台相关的浏览分区的代码
	return m_partitionList.size();
}

int main(void)
{
	return 0;
}
