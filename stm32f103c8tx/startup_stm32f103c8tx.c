void Reset_Handler(void)
{
	*(volatile unsigned int *)0x40021018 |= (1 << 4);
	*(volatile unsigned int *)0x40011004 = (1 << (4 * 5));
	while (1)
	{
		*(volatile unsigned int *)0x4001100C ^= (1 << 13);
		for(int i = 0; i < 1000000; i++);
    	}
}

int const vectors[] __attribute__ ((section (".isr_vector"))) = {
    0x20005000,
    (int)&Reset_Handler,
};
