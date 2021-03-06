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
#include "lcd.h"
int display = 0;//global variable for stopping counting

void interrupt isr(){//interrupts counting cycle
    INTCONbits.INTF = 0;
    display = ~display;
    return;
}
int convert_seven_seg(int input){//returns the corresponding seven segment code from an integer
    switch(input) {
           case 0 :
               return 0b01000000;
               break;
             
           case 1 :
               
               return 0b01011111;
               break; 
               
           case 2 :
               
               return 0b00100100;
               break;
               
           
           case 3 :
               
               return 0b00001100;
               break;
               
           case 4 :
               
               return 0b00011010;
               break;
               
           case 5 :
               
               return 0b10001001;
               break;
               
           case 6 :
               
               return 0b10000001;
               break;
               
               
           case 7 :
               
               return 0b01011100;
               break;
               
           case 8 :
               
               return 0b00000000;
               break;
               
           case 9 :
               
               return 0b00001000;
               break;
           default:
               
               return 0b01000000;
               break;
    }
}
void main() 
{
    INTCONbits.INTF = 0; //reset external interrupts
    OPTION_REGbits.INTEDG = 1; //use rising edge for interrupts
    INTCONbits.INTE = 1; //Enable external interrupts
    INTCONbits.GIE = 1; //enable global interrupts
    TRISA = 0xFF;
    TRISB = 0x1;//sets everything except RB0 as an output
    PORTB = 0xFF;
    int counter = 0;
    while(1){
        while(display == 0){//while the global counter variable is 0...
            __delay_ms(1000);
            int output = convert_seven_seg(counter);//...count up and display the value on the seven seg
            counter++; 
            PORTB = output;
            if(counter > 9){
                counter = 0;//trip over to 0 again
            }
        }
             
    }
}







