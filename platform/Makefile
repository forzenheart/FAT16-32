VPATH = linux:win32
Objects = FATStdC.h FATPlatformConfig.h \
		FATPlatformMacros.h FATPlatformDefine.h
CPP = g++
Target = platform.o

$(Target): 
	$(CPP) -o $(Target) -Wall $(Objects)
.PHONY : clean
clean : 
	-rm $(Target) $(Objects) 
