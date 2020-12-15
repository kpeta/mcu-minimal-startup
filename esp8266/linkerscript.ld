ets_delay_us = 0x40002ecc;
ets_printf = 0x400024cc;
uart_div_modify = 0x400039d8;

MEMORY
{
  dram_seg  :    org = 0x3FFE8000, len = 0x18000 - 0x400
  iram_seg  :    org = 0x40100000, len = 0x8000
}

/*  Default entry point:  */
ENTRY(hello_world);

SECTIONS
{
  .text :
  {
    _stext = .;
    _text_start = ABSOLUTE(.);
    . = ALIGN (16);
    *(.literal .text .literal.* .text.*)
    _text_end = ABSOLUTE(.);
    _etext = .;
  } > iram_seg

  .bss (NOLOAD) :
  {
    . = ALIGN (8);
    _bss_start = ABSOLUTE(.);
    *(.bss)
    *(.bss.*)
    *(COMMON)
    . = ALIGN (8);
    _bss_end = ABSOLUTE(.);
  } >dram_seg

  .data :
  {
    _data_start = ABSOLUTE(.);
    *(.data)
    *(.data.*)
    _data_end = ABSOLUTE(.);
  } >dram_seg

  .rodata :
  {
    _rodata_start = ABSOLUTE(.);
    *(.rodata)
    *(.rodata.*)
    _rodata_end = ABSOLUTE(.);
    . = ALIGN(4);
    _heap_start = ABSOLUTE(.);
  } >dram_seg
}
