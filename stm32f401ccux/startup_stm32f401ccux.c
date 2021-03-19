void Reset_Handler(void)
{
	*(volatile unsigned int *)0x40023830 |= (1 << 2);
	*(volatile unsigned int *)0x40020800 |= (1 << (2 * 13));
	while (1)
	{
		*(volatile unsigned int *)0x40020814 ^= (1 << 13);
		for(int i = 0; i < 1000000; i++);
    	}
}

int const vectors[] __attribute__ ((section (".isr_vector"))) = {
    0x20010000,
    (int)&Reset_Handler,
};
