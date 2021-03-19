# STM32F401CCUx minimal blinky

Minimal code needed to blink LED (C13) on STM32F401 'Black Pill' board.
Only stack pointer and reset handler are implemented in the vector table for this minimal example.
Also, .data and .bss section initialization isn't performed. In the linker script, vector table is placed at the beginning of flash memory.

Run
```console
make flash
```
to build the project and flash STM32.