#read MBR on Linux
#author : ForzenHeart
#version 0.0.1
VPATH = ../../base : ../../platform
CPP = g++
Objects = MBR_linux.o FATBasicData.o

readMBROnLinux : $(Objects)
	$(CPP) -Wall -g -ansi -o readMBROnLinux $(Objects)

MBR_linux.o : 

FATBasicData.o :
	$(CPP) -o FATBasicData.o -Wall FATBasicDataDefine.h 	

.PHONY : clean
clean:
	-rm readMBROnLinux $(Objects)
