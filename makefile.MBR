CC = g++
VPATH = base platform MBR MBR/linux MBR/windows
#CPPFLAGS = -I base platform MBR MBR/linux MBR/windows

SOURCES = diskPartition.cpp \
	  MBR.cpp \
	  MBRFactory.cpp \
	  MBRFactoryLinux.cpp MBRFactoryWindows.cpp \
	  MBRImpl.cpp \
	  MBRImplLinux.cpp MBRImplWindows.cpp

diskPartition : MBRFactory.o MBRFactoryLinux.o MBRFactoryWindows.o \
		MBRImpl.o MBRImplLinux.o MBRImplWindows.o \
		MBR.o diskPartition.cpp
	$(CC) $^ -g -o $@

MBR.o : MBRFactory.h
MBRFactoryLinux.o : MBRFactory.h
MBRFactoryWindows.o : MBRFactory.h
MBRFactory.o : MBRImpl.h
MBRImplLinux.o : MBRImpl.h
MBRImplWindows.o : MBRImpl.h
MBRImpl.o : DiskPartition.h

include $(subst .c, .d, $(SOURCE))

%.d : %.c
	$(CC) -M $(CPPFLAGS) $< > $@.$$$$;			\
	sed 's, \($*\)\.o[ :], \1.o $@ : , g' < $@.$$$$ > $@;	\
	rm -f $@.$$$$

.PHONY : clean
clean : 	
	rm diskPartition *.o
