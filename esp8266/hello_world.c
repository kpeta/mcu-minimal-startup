extern void ets_delay_us(unsigned int us);
extern int ets_printf(const char *fmt, ...);
extern void uart_div_modify(unsigned int uart_no, unsigned int baud_div);

void hello_world(void)
{
    *(volatile unsigned int*)0x60000838 = 0<<4; // Set pin 2 to function GPIO2. Pin 2 is mapped to pad number 13. Function 0 at bit position 4
    *(volatile unsigned int*)0x6000030C |= 1<<2; // Set pin 2 as output.
    uart_div_modify(0, 52*1000000 / 115200); //set uart baudrate to 115200
    
    while (1)
    {
        *(volatile unsigned int*)0x60000308 |= 1<<2; //GPIO high
        ets_printf("Hello world!\n");
        ets_delay_us(500000);  
        *(volatile unsigned int*)0x60000304 |= 1<<2; //GPIO low
        ets_printf("Hello world!\n");
        ets_delay_us(500000);  
    }

}
