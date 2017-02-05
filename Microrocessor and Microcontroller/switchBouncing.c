#include<16f877a.h>
#include <stdlib.h>
#use delay(clock=8000000)
#fuses HS,NOWDT,PROTECT
#zero_ram
 
#define LED1 PIN_c0
#define LED2 PIN_c1
#define LED3 PIN_c2
#define LED4 PIN_c3
#define SetHigh(x)      (output_bit(x,1))
#define SetLow(x)       (output_bit(x,0))
#define PRESSED(x) (input(x)==0)
#define NOTPRESSED(x) (input(x)==1)

void main()
{
   while(1)
   {
      //pin A0
      if(NOTPRESSED(PIN_A0))
      {
         SetHigh(LED1);
      }
      
      else if(PRESSED(PIN_A0))
      {
         delay_ms(100);
         if(PRESSED(PIN_A0))
         {
              SetLow(LED1);
         }
      }
      
      //pin a1
       if(NOTPRESSED(PIN_A1))
      {
         SetHigh(LED2);
      }
      
      else if(PRESSED(PIN_A1))
      {
         delay_ms(100);
         if(PRESSED(PIN_A1))
         {
              SetLow(LED2);
         }
      }
      
      //pin a2
       if(NOTPRESSED(PIN_A2))
      {
         SetHigh(LED3);
      }
      
      else if(PRESSED(PIN_A2))
      {
         delay_ms(100);
         if(PRESSED(PIN_A2))
         {
              SetLow(LED3);
         }
      }
      
      //pin a3
       if(NOTPRESSED(PIN_A3))
      {
         SetHigh(LED4);
      }
      
      else if(PRESSED(PIN_A3))
      {
         delay_ms(100);
         if(PRESSED(PIN_A3))
         {
              SetLow(LED4);
         }
      }
   }
   
}
