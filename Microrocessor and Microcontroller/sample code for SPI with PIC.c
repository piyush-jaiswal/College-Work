#include<16f877a.h>
#include <stdlib.h>

#use delay(clock=20000000)
#fuses HS,NOWDT,PROTECT

#define dat1 pin_c7        //connections between PIC and DAC MCP4921
#define SCLK1 pin_c4
#define cs  pin_c5

int16 tab[2]={0x3000, 0x3fff};

void main(void)
{
unsigned int16 x;
unsigned int16 i,j,k;

output_high(SCLK1);
delay_ms(200);

while(1)
{
for(k=0;k<2;k++)
{
x=tab[k];
output_low(CS);  //enable DAC's serial interface
for(i=0;i<16;i++)  //Send all 16 bits (MSB first), using the protocol that DAC expects. This is essentially bit-banged SPI port
  {
  j= x & 0x8000;
  x = x <<1;
  if(j!=0)
   {
    output_high(dat1);
    delay_us(1);
    output_high(SCLK1);
    delay_us(10);
    output_low(SCLK1);
     }   
  else
   {
    output_low(dat1);
    delay_us(1);
    output_high(SCLK1);
    delay_us(10);
    output_low(SCLK1);
     }     
  }  
delay_us(1);
output_high(CS);
delay_ms(1);
}

 }     
}

