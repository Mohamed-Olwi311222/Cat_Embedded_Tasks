MCU = atmega328p
F_CPU = 16000000UL


# Directories
SRC_DIR = src
#MCAL Layer Module
MCAL_DIR = MCAL
ADC = $(MCAL_DIR)/ADC/mcal_adc.c
USART = $(MCAL_DIR)/USART/mcal_usart.c
#MCAL Modules
MCAL_MODULES = $(ADC) $(USART)
# Source files (Add all C files from different directories)
SRC = main.c $(MCAL_MODULES)

# Object files
OBJ = $(SRC:.c=.o)

# Output files
ELF = main.elf
HEX = main.hex

# Compiler flags
CFLAGS = -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -I$(MCAL_DIR) -I$(SRC_DIR) -I.

# Build HEX file from ELF
all: $(HEX)

$(HEX): $(ELF)
	avr-objcopy -O ihex -R .eeprom $< $@

# Build ELF from object files
$(ELF): $(OBJ)
	avr-gcc $(CFLAGS) -o $@ $^

# Compile C files to object files
%.o: %.c
	avr-gcc $(CFLAGS) -c -o $@ $<

# Clean build files
clean:
	rm -f $(OBJ) $(ELF) $(HEX)
