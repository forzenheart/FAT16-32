#makefile of ReadPartition
CC = g++

VPATH = . base \
	platform \
	ReadPartition ReadPartition/linux ReadPartition/windows	\
	test

CPPFLAGS = -I . 

SOURCES = FATPhysicalDisk.cpp			\
	  FATPhysicalDiskLinux.cpp		\
	  FATPhysicalDiskWindows.cpp		\
	  FATPhysicalDiskListImpl.cpp		\
	  FATPhysicalDiskListImplLinux.cpp	\
	  FATPhysicalDiskListImplWindows.cpp	\
	  FATPhysicalDiskFactory.cpp		\
	  FATPhysicalDiskFactoryLinux.cpp	\
	  FATPhysicalDiskFactoryWindows.cpp	\
	  FATPhysicalDiskList.cpp		\
	  testFATPhysicalDiskList.cpp

Objects = FATPhysicalDisk.o FATPhysicalDiskLinux.o			\
	FATPhysicalDiskListImpl.o FATPhysicalDiskListImplLinux.o	\
	FATPhysicalDiskFactory.o FATPhysicalDiskFactoryLinux.o		\
	FATPhysicalDiskList.o

.PHONY : all
all :	FATPhysicalDisk.o FATPhysicalDiskLinux.o			\
	FATPhysicalDiskListImpl.o FATPhysicalDiskListImplLinux.o	\
	FATPhysicalDiskFactory.o FATPhysicalDiskFactoryLinux.o		\
	FATPhysicalDiskList.o

testfat : $(Objects) testFATPhysicalDiskList.cpp
	g++ $(CPPFLAGS) $^ -g -o $@

FATPhysicalDiskList.o :  
FATPhysicalDisk.o : 
FATPhysicalDiskLinux.o : 
FATPhysicalDiskListImpl.o : 
FATPhysicalDiskListImplLinux.o : 
FATPhysicalDiskFactory.o : 
FATPhysicalDiskFactoryLinux.o : 

include $(subst .c, .d, $(SOURCE))

%.d : %.c
	$(CC) -M $(CPPFLAGS) $< > $@.$$$$;			\
	sed 's, \($*\)\.o[ :], \1.o $@ : , g' < $@.$$$$ > $@;	\
	rm -f $@.$$$$

.PHONY : clean
clean : 	
	rm *.o
