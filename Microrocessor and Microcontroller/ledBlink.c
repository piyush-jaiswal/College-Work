#include<16f917.h>
#include<stdlib.h>
#use delay(clock=8000000)
#use rs232 (baud=9600, xmit=PIN_C6, rcv = PIN_C7)
#fuses HS,NOWDT,PROTECT
#zero_ram

#define LED1 PIN_C0
#define LED2 PIN_C1
#define LED3 PIN_C2
#define LED4 PIN_C3

#define setHigh(x)  (output_bit(x,1))
#define setLow(x)    (output_bit(x,0))

void main()
{
int value;
while(TRUE)
{
setLow(LED1);
setLow(LED2);
setLow(LED3);
setLow(LED4);


delay_ms(1000);

setHigh(LED1);
setHigh(LED2);
setHigh(LED3);
setHigh(LED4);

delay_ms(1000);
}
}