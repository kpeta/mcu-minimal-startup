CC=xtensa-esp32-elf-gcc
CFLAGS= -c -O0 -std=gnu11 -Wall -Werror=all
LDFLAGS= -nostdlib -T ./linkerscript.ld -Wl,-Map=final.map

all: clean final.elf

hello_world.o:hello_world.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf:hello_world.o
	$(CC) $(LDFLAGS) $^ -o $@

final.bin:final.elf
	esptool.py --chip esp32 elf2image --flash_mode="dio" --flash_freq "40m" -o $@ $^

flash: clean final.bin 
	esptool.py write_flash 0x1000 final.bin

monitor:
	putty -load esp32
	
clean:
	rm -rf *.o *.elf *.map *.bin