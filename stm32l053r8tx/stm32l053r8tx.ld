MEMORY
{
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 64K
}    

SECTIONS
{
    .text :
    {
        *(.isr_vector)
        *(.text*)
        . = ALIGN(4);
    } > FLASH
}