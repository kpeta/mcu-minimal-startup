void reset(void)
{
	*(volatile unsigned int *)0x4002102C |= (1 << 0);
	*(volatile unsigned int *)0x50000000 = 3959420159;
	while (1)
	{
		*(volatile unsigned int *)0x50000014 ^= (1 << 5);
		for(int i = 0; i < 100000; i++);
    }
}

int const vectors[] __attribute__ ((section (".isr_vector"))) = {
    0x20002000,
    (int)&reset,
};
