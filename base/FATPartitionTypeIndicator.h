#ifndef __FAT_PARTITION_TYPE_INDICATOR_H__
#define	__FAT_PARTITION_TYPE_INDICATOR_H__
//Partition type indicator
//常见分区格式

const char *FATPartTypeName[] = {
	"Illegal in DOS and Windws", //00H
	"FAT12",		//01H
	"XENIX root",		//02H
	"XENIX usr",		//03H
	"FAT16(<32MB)",		//04H
	"Extend",		//05H
	"FAT16(>32MB)",		//06H
	"HPFS/NTFS",		//07H
	"AIX",			//08H
	"AIX bootalble",	//09H
	"OS/2 Boot Manager",	//0AH
	"Windows 95 FAT32",	//0BH
	"Windows 95 FAT32",	//0CH
	"Unknown",		//0DH
	"Windows 95 FAT16",	//0EH
	"Windows 95 Extended(>8GB)",	//0FH

	"OPUS",			//10H
	"Hidden FAT12",		//11H
	"Compaq diagnost",	//12H
	"Unknown",		//13H
	"Hidden FAT16 (<32MB)", //14H
	"Unknown",		//15H
	"Hidden FAT16",		//16H
	"Hidden HPFS/NTFS",	//17H
	"AST Windows swap",	//18H
	"Unknown",		//19H
	"Unknown",		//1AH
	"Hidden FAT32",		//1BH
	"Hidden FAT32 partition(using LBA-mode INT 12 extensions)",	//1CH
	"Unknown",		//1DH
	"Hidden LBA VFAT partition",	//1EH
	"Unknown",		//1FH

	"Unknown",		//20H
	"Unknown",		//21H
	"Unknown",		//22H
	"Unknown",		//23H
	"NEC DOS",		//24H
	"Unknown",		//25H
	"Unknown",		//26H
	"Unknown",		//27H
	"Unknown",		//28H
	"Unknown",		//29H
	"Unknown",		//2AH
	"Unknown",		//2BH
	"Unknown",		//2CH
	"Unknown",		//2DH
	"Unknown",		//2EH
	"Unknown",		//2FH

	"Unknown",		//30H
	"Unknown",		//31H
	"Unknown",		//32H
	"Unknown",		//33H
	"Unknown",		//34H
	"Unknown",		//35H
	"Unknown",		//36H
	"Unknown",		//37H
	"Unknown",		//38H
	"Unknown",		//39H
	"Unknown",		//3AH
	"Unknown",		//3BH
	"Partition Magic",	//3CH
	"Unknown",		//3DH
	"Unknown",		//3EH
	"Unknown",		//3FH

	"Venix 80286",		//40H
	"PPC PreP Boot",	//41H
	"SFS",			//42H
	"Unknown",		//43H
	"Unknown",		//44H
	"Unknown",		//45H
	"Unknown",		//46H
	"Unknown",		//47H
	"Unknown",		//48H
	"Unknown",		//49H
	"Unknown",		//4AH
	"Unknown",		//4BH
	"Unknown",		//4CH
	"QNX4.x",		//4DH
	"QNX4.x 2nd part",	//4EH
	"QNX4.x 3rd part",	//4FH

	"OnTrack DM",		//50H
	"OnTrack DM6 Aux",	//51H
	"CP/M",			//52H
	"OnTrack DM6 Aux",	//53H
	"OnTrack DM6",		//54H
	"EZ-Drive",		//55H
	"Golden Bow",		//56H
	"Unknown",		//57H
	"Unknown",		//58H
	"Unknown",		//59H
	"Unknown",		//5AH
	"Unknown",		//5BH
	"Priam Edisk",		//5CH
	"Unknown",		//5DH
	"Unknown",		//5EH
	"Unknown",		//5FH

	"Unknown",		//60H
	"Speed Stor",		//61H
	"Unknown",		//62H
	"GNU HURD or Sys",	//63H
	"Novell Netware",	//64H
	"Novell Netware",	//65H
	"Unknown",		//66H
	"Unknown",		//67H
	"Unknown",		//68H
	"Unknown",		//69H
	"Unknown",		//6AH
	"Unknown",		//6BH
	"Unknown",		//6CH
	"Unknown",		//6DH
	"Unknown",		//6EH
	"Unknown",		//6FH

	"Disk Secure Mult",	//70H
	"Unknown",		//71H
	"Unknown",		//72H
	"Unknown",		//73H
	"Unknown",		//74H
	"PC/IX",		//75H
	"Unknown",		//76H
	"Unknown",		//77H
	"Unknown",		//78H
	"Unknown",		//79H
	"Unknown",		//7AH
	"Unknown",		//7BH
	"Unknown",		//7CH
	"Unknown",		//7DH
	"Unknown",		//7EH
	"Unknown",		//7FH

	"Old Minix",		//80H
	"Minix/Old Linux",	//81H
	"Linux swap",		//82H
	"Linux",		//83H
	"OS/2 hidden C:",	//84H
	"Linux extended",	//85H
	"NTFS volume set",	//86H
	"NTFS volume set",	//87H
	"Unknown",		//88H
	"Unknown",		//89H
	"Unknown",		//8AH
	"Unknown",		//8BH
	"Unknown",		//8CH
	"Unknown",		//8DH
	"Linux LVM",		//8EH
	"Unknown",		//8FH

	"Unknown",		//90H
	"Unknown",		//91H
	"Unknown",		//92H
	"Amoeba",		//93H
	"Amoeba BBT",		//94H
	"Unknown",		//95H
	"Unknown",		//96H
	"Unknown",		//97H
	"Unknown",		//98H
	"Unknown",		//99H
	"Unknown",		//9AH
	"Unknown",		//9BH
	"Unknown",		//9CH
	"Unknown",		//9DH
	"Unknown",		//9EH
	"Unknown",		//9FH

	
	"IBM Thinkpad hidden",	//A0H
	"Unknown",		//A1H
	"Unknown",		//A2H
	"Unknown",		//A3H
	"Unknown",		//A4H
	"BSD/386",		//A5H
	"Open BSD",		//A6H
	"NextSTEP",		//A7H
	"Unknown",		//A8H
	"Unknown",		//A9H
	"Unknown",		//AAH
	"Unknown",		//ABH
	"Unknown",		//ACH
	"Unknown",		//ADH
	"Unknown",		//AEH
	"Unknown",		//AFH

	"Unknown",		//B0H
	"Unknown",		//B1H
	"Unknown",		//B2H
	"Unknown",		//B3H
	"Unknown",		//B4H
	"Unknown",		//B5H
	"Unknown",		//B6H
	"BSD fs",		//B7H
	"BSDI swap",		//B8H
	"Unknown",		//B9H
	"Unknown",		//BAH
	"Unknown",		//BBH
	"Unknown",		//BCH
	"Unknown",		//BDH
	"Solaris boot partition",		//BEH
	"Unknown",		//BFH

	"DR-DOS/Novell DOS secured partition",	//C0H
	"DRDOS/sec",		//C1H
	"Unknown",		//C2H
	"Unknown",		//C3H
	"DRDOS/sec",		//C4H
	"Unknown",		//C5H
	"DRDOS/sec",		//C6H
	"Syrinx",		//C7H
	"Unknown",		//C8H
	"Unknown",		//C9H
	"Unknown",		//CAH
	"Unknown",		//CBH
	"Unknown",		//CCH
	"Unknown",		//CDH
	"Unknown",		//CEH
	"Unknown",		//CFH


	"Unknown",		//D0H
	"Unknown",		//D1H
	"Unknown",		//D2H
	"Unknown",		//D3H
	"Unknown",		//D4H
	"Unknown",		//D5H
	"Unknown",		//D6H
	"Unknown",		//D7H
	"Unknown",		//D8H
	"Unknown",		//D9H
	"Unknown",		//DAH
	"CP/M/CTOS",		//DBH
	"Unknown",		//DCH
	"Unknown",		//DDH
	"Unknown",		//DEH
	"Unknown",		//DFH

	"Unknown",		//E0H
	"DOS access",		//E1H
	"Unknown",		//E2H
	"DOS R/0",		//E3H
	"SpeedStor",		//E4H
	"Unknown",		//E5H
	"Unknown",		//E6H
	"Unknown",		//E7H
	"Unknown",		//E8H
	"Unknown",		//E9H
	"Unknown",		//EAH
	"BeOs fs",		//EBH
	"Unknown",		//ECH
	"Unknown",		//EDH
	"Unknown",		//EEH
	"Unknown",		//EFH

	"Unknown",		//F0H
	"SpeedStor",		//F1H
	"DOS 3.3+secondary partition",		//F2H
	"Unknown",		//F3H
	"SpeedStor",		//F4H
	"Unknown",		//F5H
	"Unknown",		//F6H
	"Unknown",		//F7H
	"Unknown",		//F8H
	"Unknown",		//F9H
	"Unknown",		//FAH
	"Unknown",		//FBH
	"Unknown",		//FCH
	"Unknown",		//FDH
	"LAN step",		//FEH
	"BBT"			//FFH
};
#endif	//__FAT_PARTITION_TYPE_INDICATOR_H__
