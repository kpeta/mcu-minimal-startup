CC=xtensa-lx106-elf-gcc
CFLAGS= -c -O0 -Wall -Werror=all -mlongcalls -std=c11
LDFLAGS= -nostdlib -T ./linkerscript.ld -Wl,-Map=final.map

all: clean final.elf

hello_world.o:hello_world.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf:hello_world.o
	$(CC) $(LDFLAGS) $^ -o $@

final.bin:final.elf
	esptool.py --chip=esp8266 elf2image final.elf -o final.bin

flash: clean final.bin 
	esptool.py --chip=esp8266 --port /dev/ttyUSB0 write_flash 0x00000 final.bin -ff 40m -fm dio

monitor:
	putty -load esp32
	
clean:
	rm -rf *.o *.elf *.map *.bin