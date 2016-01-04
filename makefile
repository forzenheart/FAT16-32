#makefile of ReadPartition
CC = g++

VPATH = base \
	platform \
	ReadPartition ReadPartition/linux ReadPartition/windows

CPPFLAGS = -I. base \
	   platform \
	   ReadPartition ReadPartition/linux ReadPartition/windows


SOURCES = FATPhysicalDisk.cpp			\
	  FATPhysicalDiskLinux.cpp		\
	  FATPhysicalDiskWindows.cpp		\
	  FATPhysicalDiskListImpl.cpp		\
	  FATPhysicalDiskListImplLinux.cpp	\
	  FATPhysicalDiskListImplWindows.cpp	\

.PHONY : all
all : FATPhysicalDisk.o FATPhysicalDiskLinux.o \
	FATPhysicalDiskListImpl.o FATPhysicalDiskListImplLinux.o

FATPhysicalDisk.o : 
FATPhysicalDiskLinux.o : FATPhysicalDisk.h
FATPhysicalDiskListImpl.o :
FATPhysicalDiskListImplLinux.o : FATPhysicalDiskListImpl.h


include $(subst .c, .d, $(SOURCE))

%.d : %.c
	$(CC) -M $(CPPFLAGS) $< > $@.$$$$;			\
	sed 's, \($*\)\.o[ :], \1.o $@ : , g' < $@.$$$$ > $@;	\
	rm -f $@.$$$$

.PHONY : clean
clean : 	
	rm *.o
