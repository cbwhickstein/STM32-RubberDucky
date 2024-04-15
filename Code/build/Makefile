CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
BIN = arm-none-eabi-objcopy
FLASH = st-flash

CFLAGS = -mthumb -mcpu=cortex-m3 -c
CFLAGS_DEBUG = -g -Wall -Wextra -Og
CFLAGS_PRODUCTION = -Os -Wall -Wextra

SRC_PATH = ../src
SRC = $(wildcard $(SRC_PATH)/*.c)

INC_PATH = ../include
CFLAGS += -I $(INC_PATH)

OBJ_PATH = ./obj
COMPILE_OBJ = $(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRC))

all: clean create_obj_folder app.bin

create_obj_folder:
	mkdir -p obj

crt.o: crt.s
	$(AS) -o $(OBJ_PATH)/crt.o crt.s

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) -o $@ $<

app.elf: linker.ld crt.o $(COMPILE_OBJ)
	$(LD) -T linker.ld -o app.elf $(OBJ_PATH)/*.o

app.bin: app.elf
	$(BIN) -O binary app.elf app.bin

clean:
	rm -f *.o *.elf *.bin
	rm -rf obj

flash: all
	$(FLASH) write app.bin 0x08000000

erase:
	$(FLASH) erase

debug:
	x-terminal-emulator -- openocd -f /usr/share/openocd/scripts/interface/stlink-v2.cfg -f /usr/share/openocd/scripts/target/stm32f1x.cfg
	gdb-multiarch app.elf -ex "target remote localhost:3333"

dissasable:
	arm-none-eabi-objdump -d obj/main.o | less