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


void main(void) 
{
    TRISA = 0xFF;
    TRISB = 0x00;//sets everything except RB0 as an output
    PORTB = 0xFF;
    RW = 0;
    Lcd_Init();
    int counter = 0;
    Lcd_Clear(); 
    while(1){
        if(PORTAbits.RA0 == 1){
            Lcd_Clear();
            int random = rand() % 6;
            random = random + 1;
            Lcd_Set_Cursor(1,1);
            Lcd_Write_Int(random);
            __delay_ms(1000);
        }
             
    }
}
