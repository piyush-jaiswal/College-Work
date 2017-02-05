/*========================================= 
8-BIT LCD DRIVER FOR PIC16F73 CCSC 
==========================================*/ 
/////////////////////////////////////////////////////////////////// 
// LCD 16x2 
// 
////////////////////////////////////////////////////////////////// 

#include<16f877a.h>
#DEVICE ADC = 10 
#include<stdlib.h>
#use delay(clock=20000000)
#fuses HS,NOWDT,PROTECT
#zero_ram

#use rs232(baud=9600,xmit=PIN_B7,rcv=PIN_B5)


#define PORT_D                  3 

#define NCHAR_PER_LINE          16              // max char numbers per line 
#define LCD_RS                  PIN_B4 
#define LCD_E                   PIN_B2 
#define LCD_DAT                 PORT_D 
#define PRESSED(x) (input(x)==0)
#define NOTPRESSED(x) (input(x)==1)

int16 x;
char L0[]={"123456789012345"};
char L1[]={"123456789012345"};

///////////////////////////////////////////////// output() 
//lcd data bus output 
void output(int8 port, int8 dat) 
{ 
              output_D(dat);      
}//end output() 

//////////////////////////////////////////////// lcd_write_cmd() 
// 
void lcd_write_cmd(int8 cmd) 
{ 
  
        delay_us(400); 
        output_low(LCD_RS); 
//        output_low(LCD_RW); 
        output(LCD_DAT, cmd); 

        output_high(LCD_E); 
        delay_us(400); 
        output_low(LCD_E); 
   ;   
} 

/////////////////////////////////////////////// lcd_write_dat() 
// 
void lcd_write_dat(int8 dat) 
{ 
  
        delay_us(400); 
        output_high(LCD_RS); 
//        output_low(LCD_RW); 
        output(LCD_DAT, dat); 

        output_high(LCD_E); 
        delay_us(400); 
        output_low(LCD_E); 
  }

//////////////////////////////////////////// lcd_init() 
// 
void lcd_init(void) 
{ 
        output_low(LCD_E);              // Let LCD E line low 

        lcd_write_cmd(0x38);            // LCD 16x2, 5x7, 8bits data 
        delay_ms(15); 
        lcd_write_cmd(0x01);            // Clear LCD display 
        delay_ms(10); 
        lcd_write_cmd(0x0f);            // Open display & current 
        delay_ms(10); 
        lcd_write_cmd(0x06);            // Window fixed 
        delay_ms(10); 
}


///////////////////////////////////////// lcd_display_char() 
// 
void lcd_display_char(int8 line, int8 pos, int8 ch) 
{ 
        int8 tmp; 

        line = (line==0) ? 0 : 1; 
        pos  = (pos >NCHAR_PER_LINE) ? NCHAR_PER_LINE : pos; 

        tmp = 0x80 + 0x40*line + pos; 
  
        lcd_write_cmd(tmp); 
        lcd_write_dat(ch); 
   
}

/////////////////////////////////////////// lcd_display_str() 
// 
void lcd_display_str(int8 line, char str[]) 
{ 
     int8 i; 

        for(i=0; i<NCHAR_PER_LINE; i++) 
            { 
                lcd_display_char(line, i, ' '); 
                } 
        for(i=0; i<NCHAR_PER_LINE; i++) 
                { 
                if(str[i] == '\0') break; 
                lcd_display_char(line, i, str[i]); 
                } 
   delay_ms(500);
}



void main(void) 
{ 
setup_adc(ADC_CLOCK_INTERNAL);
set_adc_channel(0); 
 lcd_init();

    while(TRUE)
 {
 
      //pin a2
       if(NOTPRESSED(PIN_A2))
      {
         strcpy(L0, "Press pin.");
         lcd_display_str(0, L0);
         delay_ms(100);
      }
      
      if(PRESSED(PIN_A2))
      {
        // x=read_adc();
         delay_ms(100);
         if(PRESSED(PIN_A2))
         {
              x=read_adc();
              itoa(x,16,L1);
              //strcpy(L1, "working");
               lcd_display_str(0, L1);
               delay_ms(100);
         }
      }

 }
}
