CC = g++
#VPATH = linux windows

#SOURCE = FATPartitionListImpl.cpp

FATPartitionListImpl.o : FATPhysicalDisk.h
	$(CC) $< > $@
	

.PHONY : clean
clean :
	rm *.o
