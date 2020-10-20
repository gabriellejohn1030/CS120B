/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section:023
 *	Assignment: Lab #3  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}
unsigned char SetBit(unsigned char x, unsigned char y, unsigned char z) {
	return (z ? | (0x01 << y) : x & ~(0x01 << y));
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
	unsigned char temp1 = 0x00;
	unsigned char temp2 = 0xFF;
	unsigned char temp3 = 0x00;

    /* Insert your solution below */
 while(1) {
	temp1 = PINA;
        			 
		if (temp1 <= 0x0F && temp1 >= 0x0D) // 13-15 --> PC5-PC0 
		{
			temp2 = 0xFF;
		}
		if(temp1 <= 0x0C && temp1 >= 0x0A) // 10-12 --> PC5-PC1
		{
			temp2 = 0xFF << 1;
		}
		if (temp1 <= 0x09 && temp1 >= 0x07) // 7-9 --> PC5-PC2
		{
			temp2 = 0xFF << 2;	
		}
		if (temp1 <= 0x06 && temp1 >= 0x05) // 5-6 --> PC5-PC3
		{
			temp2 = 0xFF << 3;
		}
		if (temp1 <= 0x04 && temp1 >= 0x03) // 3-4 --> PC5-PC4
		{
			temp2 = 0xFF << 4;
		}
		if (temp1 <= 0x02 && temp1 >= 0x01) // 1-2 --> PC5
        	{
           		temp2 = 0xFF << 5;
       	}
		if (temp1 == 0x00) { // 0 --> all off
           		temp2 = 0xFF << 6;
        	}
		
		temp3 = temp2 & 0x3F;
		
		if (temp1 <= 0x04) // if PA <= 4, set PC6
        	{
           		temp3 = temp3 + 0x40;
        	}

		PORTC = temp3;
    }
}
