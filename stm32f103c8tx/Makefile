CC=arm-none-eabi-gcc
CFLAGS= -c -mcpu=cortex-m3 -mthumb -std=gnu11 -O0 -Wall
LDFLAGS= -T stm32f103c8tx.ld -nostdlib -Wl,-Map=final.map

all:startup_stm32f103c8tx.o final.elf

startup_stm32f103c8tx.o:startup_stm32f103c8tx.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf:startup_stm32f103c8tx.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf *.map

flash: all
	openocd -f interface/stlink.cfg -f target/stm32f1x.cfg -c "program final.elf verify reset exit"
