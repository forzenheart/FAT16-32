#read MBR on Linux
#author : ForzenHeart
#version 0.0.1
CPP = g++
Objects = MBR_linux.o

readMBROnLinux : $(Objects)
	$(CPP) -Wall -g -ansi -o readMBROnLinux $(Objects)

MBR_linux.o : 

.PHONY : clean
clean:
	-rm readMBROnLinux $(Objects)
