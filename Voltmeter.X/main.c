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
#include <math.h>
#include "lcd.h"
#include "adc.h"
unsigned int voltage = 0;
unsigned int voltagemax = 0;
unsigned int displaymode = 0;
char voltagestring;
eeprom int voltagesample;

void main(void){
    TRISA = 0b00000011;
    TRISB = 0b01010000;//sets everything except RB0 as an output
    RW = 0;
    CS = 1;
    CLK = 0;
    Lcd_Init();

    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String((char *)"Welcome ");
    __delay_ms(1500);
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String((char *)"Range: 0");
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String((char *)".6V-5.1V");
    __delay_ms(1500);

    while(1)
    {
        int voltage = readADC();
        voltage=voltage*44;
        //itoa(voltage,voltagestring,10);
        if (voltage>voltagemax){
            voltagemax=voltage;
        }
        if (displaymode==0){
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String((char *)"Voltage=");
            Lcd_Set_Cursor(2,1);
            Lcd_Write_Int(voltage);
            Lcd_Set_Cursor(2,6);
            Lcd_Write_String((char *)"mv");
        }/*
        else if (displaymode==1){
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_Int(voltage);
            Lcd_Set_Cursor(1,6);
            Lcd_Write_String((char *)"mv");
            Lcd_Set_Cursor(2,1);
            Lcd_Write_Int(voltagemax);
            Lcd_Set_Cursor(2,6);
            Lcd_Write_String((char *)"mv");
        }*/
        if (RA0==1){
            voltagesample=voltage;
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String((char *)"Voltage");
            Lcd_Set_Cursor(2,1);
            Lcd_Write_String((char *)"Stored");
            __delay_ms(1500);
        }

        if (RA1==1){
            voltagehold(voltage);
        }

        if(RB4==1){
            displaymode=~displaymode;
        }
        __delay_ms(100);

    }
}

int voltagehold(voltage){//toggles displaying fixed voltage
    __delay_ms(200);
    while(RA1!=1)//looks for hold button pressed a second time
    {
        Lcd_Set_Cursor(2,1);
        Lcd_Write_Int(voltage);
        Lcd_Set_Cursor(2,6);
        Lcd_Write_String((char *)"mv");
    }
    return;
}
