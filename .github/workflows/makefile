TITLE := FRANKO001
CONTENT_ID := UP0001-FRANKO001_00-0000000000000000
TARGET := Franko
SOURCES := main.cpp
OBJS := $(SOURCES:.cpp=.o)

PS3DEV ?= /usr/local/ps3dev
PSL1GHT ?= $(PS3DEV)/psl1ght

PREFIX := $(PS3DEV)/ppu/bin/powerpc-eabi-
CXX := $(PREFIX)g++
STRIP := $(PREFIX)strip

CFLAGS := -O2 -Wall
CXXFLAGS := $(CFLAGS)
INCLUDES := -I$(PSL1GHT)/include -I$(PS3DEV)/portlibs/ppu/include/SDL2
LDFLAGS := -L$(PSL1GHT)/lib -L$(PS3DEV)/portlibs/ppu/lib
LIBS := -lSDL2_image -lSDL2_mixer -lSDL2 -lpsl1ght -lsysutil -lio -lrsx -lgcm_sys -lsysmodule -lnet -lcpp

all: $(TARGET).pkg

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET).elf: $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) $(LIBS) -o $@

$(TARGET).self: $(TARGET).elf
	make_self $< $@

$(TARGET).pkg: $(TARGET).self
	pkg.py --contentid $(CONTENT_ID) $< $@

clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).self $(TARGET).pkg
