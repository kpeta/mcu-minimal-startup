/*
Based on the official esp-idf linker script (components/bootloader/subproject/main/ld/esp32/bootloader.ld). 
I'm still not sure how bootrom copies instructions and data from flash to RAM.
*/

ets_delay_us = 0x40008534;
ets_printf = 0x40007d54;

ENTRY(hello_world)

MEMORY
{
    iram_seg (RWX) : org = 0x40080400, len = 0xfc00
    dram_seg (RW) : org = 0x3FFF0000, len = 0x10000
}

SECTIONS
{
    .iram.text :
    {
        . = ALIGN (16);
        _stext = .;
        _text_start = ABSOLUTE(.);
        *(.literal .text .literal.* .text.*)
        _text_end = ABSOLUTE(.);
        _etext = .;
    } > iram_seg

    .dram0.bss (NOLOAD) :
    {
        . = ALIGN (8);
        _dram_start = ABSOLUTE(.);
        _bss_start = ABSOLUTE(.);
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN (8);
        _bss_end = ABSOLUTE(.);
    } >dram_seg

    .dram0.data :
    {
        _data_start = ABSOLUTE(.);
        *(.data)
        *(.data.*)
        _data_end = ABSOLUTE(.);
    } >dram_seg

    .dram0.rodata :
    {
        _rodata_start = ABSOLUTE(.);
        *(.rodata)
        *(.rodata.*)
        _rodata_end = ABSOLUTE(.);
        . = ALIGN(4);
        _dram_end = ABSOLUTE(.);
    } >dram_seg
}
