CC=arm-none-eabi-gcc
CFLAGS= -c -mcpu=cortex-m4 -mthumb -std=gnu11 -O0 -Wall
LDFLAGS= -T stm32f401ccux.ld -nostdlib -Wl,-Map=final.map

all:startup_stm32f401ccux.o final.elf

startup_stm32f401ccux.o:startup_stm32f401ccux.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf:startup_stm32f401ccux.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf *.map

flash: all
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program final.elf verify reset exit"
