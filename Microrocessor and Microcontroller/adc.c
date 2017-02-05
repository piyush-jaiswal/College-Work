#include<16F877a.h>
#device adc=10
#include <stdlib.h>
#use delay (clock=20000000)
#fuses HS,NOWDT,NOPROTECT,NOBROWNOUT,NOPUT
 
 main()
 {
 int16 x;
 setup_adc(ADC_CLOCK_Internal);
 set_adc_channel(0);
 while(1){
 
 output_high(pin_c0);
 output_high(pin_c1);
 output_high(pin_c2);
 output_high(pin_c3);
 
 x= read_adc();
 if(x<255)
 output_low(pin_c0);
 else if(x>255 && x<=512)
 output_low(pin_c1);
 else if(x>512 && x<=755)
 output_low(pin_c2);
 else
 output_low(pin_c3);
 }
 
 
 }
