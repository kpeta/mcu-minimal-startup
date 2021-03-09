# STM32L053xx minimal blinky

Minimal code needed to blink green LED (PA5) on STM32L053 Nucleo board.
Only stack pointer and reset handler are implemented in the vector table for this minimal example.
Also, .data and .bss section initialization isn't performed. In the linker script, vector table is placed at the beginning of flash memory.

Run
```console
make flash
```
to build the project and flash STM32.