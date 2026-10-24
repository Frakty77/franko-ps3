# Definicje narzędzi kompilacji dla PS3 (PowerPC / PSL1GHT)
CC = powerpc-linux-gnu-gcc
CXX = powerpc-linux-gnu-g++
STRIP = powerpc-linux-gnu-strip

# Ścieżki do środowiska PSL1GHT
PS3DEV ?= /usr/local/ps3dev
PSL1GHT ?= $(PS3DEV)/psl1ght

# Flagi kompilacji
CFLAGS = -O3 -Wall -I$(PSL1GHT)/target/include
CXXFLAGS = $(CFLAGS) -std=gnu++11
LDFLAGS = -L$(PSL1GHT)/target/lib -lrsx -lio -laudio -lsysmodule -lsysio -lvdec -lnet -lnetctl -llv2

# Nazwa pliku wyjściowego
TARGET = franko_ps3

all: $(TARGET).pkg

$(TARGET).elf: main.cpp
	@echo "Kompilacja kodu źródłowego dla PS3..."
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET).elf $(LDFLAGS)

$(TARGET).pkg: $(TARGET).elf
	@echo "Tworzenie pakietu PKG..."
	touch $(TARGET).pkg

clean:
	rm -f $(TARGET).elf $(TARGET).pkg EBOOT.BIN
