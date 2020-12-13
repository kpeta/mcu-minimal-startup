extern void ets_delay_us(unsigned int us);
extern int ets_printf(const char *fmt, ...);

void hello_world(void)
{
    *(volatile unsigned int*)0x3ff4808c = 0; //disable rtc wdt
    *(volatile unsigned int*)0x3ff5f048 = 0; //disable mwdt0
    *(volatile unsigned int*)0x3ff44024 |= 1<<2; //enable output for GPIO2
    while (1)
    {
	    *(volatile unsigned int*)0x3ff44008 |= 1<<2; //gpio high
        ets_printf("Hello world!\n");
        ets_delay_us(500000);  
	    *(volatile unsigned int*)0x3ff4400c |= 1<<2; //gpio low
        ets_printf("Hello world!\n");
        ets_delay_us(500000);  
    }
}
