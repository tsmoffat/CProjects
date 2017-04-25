/* 
 * File:   main.c
 * Author: Tom Moffat & James Pollard
 *
 * Created on March 27, 2017, 11:09 AM
 */
#pragma config FOSC = XT //XT Oscillator
#pragma config WDTE = OFF //WDT disabled
#pragma config PWRTE = ON //Power-up timer on
#pragma config CP = OFF //No code protection

#define _XTAL_FREQ 4000000

#include <xc.h>
#include <stdlib.h>
#include "lcd.h"
#include "adc.h"
unsigned int voltage = 0;

/*char conv(int a){
    int bitvolt = a;
    int bitvoltb = bitvolt;
    bitvolt << 2;
    bitvoltb >> 1;
    bitvolt = bitvolt + bitvoltb;
    bitvolt = bitvolt >> 5;
    bitvolt = bitvolt >> 5;
    float absolutev = bitvolt*4.5;
    return absolutev;
}*/

void main(void) 
{
    TRISA = 0b00000011;
    TRISB = 0b01010000;//sets everything except RB0 as an output
    RW = 0;
    CS = 1;
    CLK = 0;
    Lcd_Init();
    
    Lcd_Clear(); 
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String((char *)"Welcome");
    __delay_ms(1000);
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String((char *)"Range:");
    __delay_ms(1000);
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String((char *)"-0.6V->");
    __delay_ms(1000);
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String((char *)"5.1V");
    __delay_ms(1000);
    
    while(1){
        voltage = readADC();
        //int charvolt = conv(voltage);
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        Lcd_Write_Int(charvolt);
        if RA1 == 1{
            
        }
        __delay_ms(200);
    }
}


