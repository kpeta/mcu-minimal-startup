CC=arm-none-eabi-gcc
CFLAGS= -c -mcpu=cortex-m0plus -mthumb -std=gnu11 -O0 -Wall 
LDFLAGS= -T stm32l053xx.ld -nostdlib -Wl,-Map=final.map

all:start.o final.elf

start.o:start.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf:start.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf *.map

flash: all
	openocd -f interface/stlink.cfg -f target/stm32l0.cfg -c "program final.elf verify reset exit"