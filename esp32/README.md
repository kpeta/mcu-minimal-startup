# ESP32 Minimal Hello World

Minimal code needed for ESP32 to blink LED on GPIO 2 and print 'Hello world!' on UART0, at baudrate of 115200.
Bootloader/startup code in ROM implements various functions; delay and UART0 'printf' are used in this example.
ROM bootloader also implements vector table, useful functions for various parts of system, BASIC interpreter, does some initialization and then copies (& executes) code from 0x1000 offset in external Flash to RAM.

BootROM initializes RTC Watchdog and Main Watchdog 0, so we must either feed or disable them.
.bss section initialization isn't performed in this minimal example.

Run
```console
. ~/esp/esp-idf/export.sh 
```
to add variables to PATH and 
```console
make flash 
```
to build the project and flash the ESP32.