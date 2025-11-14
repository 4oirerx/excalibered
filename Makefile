HOME=$(shell pwd)
SRC=$(HOME)/src
SRCCODE=$(SRC)/*.cpp
ENCODING=ANSI
IONAME=game
CPP=g++
DEFINES=


commonlibflags    = -luser32 -lgdi32 -ld3d11 -ldxgi -ld3dcompiler
linkerflags       = -I$(HOME)/include -L$(HOME)/libs -mwindows
ifeq ($(ENCODING), ANSI)
	DEFINES += -D__USE_MINGW_ANSI_STDIO
endif

default:
	$(CPP) $(SRCCODE) -o $(IONAME) $(DEFINES) $(linkerflags) $(commonlibflags)  

