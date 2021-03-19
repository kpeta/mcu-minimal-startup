CC=arm-none-eabi-gcc
CFLAGS= -c -mcpu=cortex-m4 -mthumb -std=gnu11 -O0 -Wall
LDFLAGS= -T stm32f407vgtx.ld -nostdlib -Wl,-Map=final.map

all:startup_stm32f407vgtx.o final.elf

startup_stm32f407vgtx.o:startup_stm32f407vgtx.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf:startup_stm32f407vgtx.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf *.map

flash: all
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program final.elf verify reset exit"
