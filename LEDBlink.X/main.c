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

void main() 
{
    TRISA = 0xFF;
    TRISB = 0x0;
    PORTB = 0xFF;
    int counter = 0;
    while(1)
    {
       
       switch(counter) {
           case 0 :
               PORTB = 0b01000000;
               __delay_ms(1000);
               counter++;
               break;
             
           case 1 :
               PORTB = 0b01011111;
               __delay_ms(1000);
               counter++;
               break;
               
           case 2 :
               PORTB = 0b00100100;
               __delay_ms(1000);
               counter++;
               break;
               
           
           case 3 :
               PORTB = 0b00001100;
               __delay_ms(1000);
               counter++;
               break;
               
           case 4 :
               PORTB = 0b00011010;
               __delay_ms(1000);
               counter++;
               break;
               
           case 5 :
               PORTB = 0b10001001;
               __delay_ms(1000);
               counter++;
               break;
               
           case 6 :
               PORTB = 0b10000001;
               __delay_ms(1000);
               counter++;
               break;
               
           case 7 :
               PORTB = 0b01011100;
               __delay_ms(1000);
               counter++;
               break;
               
           case 8 :
               PORTB = 0b00000000;
               __delay_ms(1000);
               counter++;
               break;
               
           case 9 :
               PORTB = 0b00001000;
               __delay_ms(1000);
               counter++;
               break;
           default:
               counter = 0;
       }
       
    }
}


