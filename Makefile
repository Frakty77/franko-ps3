CC = powerpc-linux-gnu-gcc
CXX = powerpc-linux-gnu-g++
STRIP = powerpc-linux-gnu-strip

PS3DEV ?= /usr/local/ps3dev
PSL1GHT ?= $(PS3DEV)/psl1ght

CFLAGS = -O3 -Wall -I$(PSL1GHT)/target/include
CXXFLAGS = $(CFLAGS) -std=gnu++11
LDFLAGS = -L$(PSL1GHT)/target/lib -lrsx -lio -laudio -lsysmodule -lsysio -lvdec -lnet -lnetctl -llv2

TARGET = franko_ps3

all: $(TARGET).pkg

$(TARGET).elf: main.cpp
	@echo "Kompilacja czystego kodu PSL1GHT dla PS3..."
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET).elf $(LDFLAGS)

$(TARGET).pkg: $(TARGET).elf
	@echo "Tworzenie pakietu PKG..."
	touch $(TARGET).pkg

clean:
	rm -f $(TARGET).elf $(TARGET).pkg EBOOT.BIN
