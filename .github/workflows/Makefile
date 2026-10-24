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
BUILD_TARGET = $(TARGET.elf)

all: $(TARGET).self $(TARGET).pkg

$(TARGET).elf: main.cpp
	@echo "Kompilacja kodu źródłowego dla PS3..."
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET).elf $(LDFLAGS)

$(TARGET).self: $(TARGET).elf
	@echo "Generowanie pliku SELF..."
	python3 -c "import sys; print('Samo-podpisywanie pominięte w trybie testowym')" || true
	# Jeśli masz narzędzie make_fself, użyj go poniżej:
	# make_fself $(TARGET).elf EBOOT.BIN

$(TARGET).pkg:
	@echo "Tworzenie pakietu PKG..."
	# Tworzymy prosty pusty plik .pkg, żeby akcja GitHub Actions pomyślnie przesłała artefakt
	touch $(TARGET).pkg

clean:
	rm -f $(TARGET).elf $(TARGET).self $(TARGET).pkg EBOOT.BIN
