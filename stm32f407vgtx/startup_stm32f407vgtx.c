void Reset_Handler(void)
{
	*(volatile unsigned int *)0x40023830 |= (1 << 3);
	*(volatile unsigned int *)0x40020C00 |= (1 << (2 * 12));
	while (1)
	{
		*(volatile unsigned int *)0x40020C14 ^= (0xFUL << 12);
		for(int i = 0; i < 1000000; i++);
    	}
}

int const vectors[] __attribute__ ((section (".isr_vector"))) = {
    0x20020000,
    (int)&Reset_Handler,
};
