/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum states {init, empty, led1, led2, led3, led4, led5, led6} state;

unsigned char tmpA = 0x00; unsigned char ledB = 0xFF;
unsigned char tmpB = 0x00;


void Tick() 
{
	switch(state)
	{
		case init:
			state = empty;
			break;
		case empty:
			if (tmpA > 0x00)
			{
				state = led1;
			}
			break;
		case led1:
			if (tmpA > 0x02)
			{
				
				state = led2;
			}
			else if (tmpA < 0x01)
			{
				state = empty;
			}
			break;
		case led2:
			if (tmpA > 0x04)
            {
				state = led3;
			}
				else if (tmpA < 0x03)
			{
				state = led1;
			}
			break;
		case led3:
			if (tmpA > 0x06)
            {
				state = led4;
			}
			else if (tmpA < 0x05)
			{
				state = led2;
			}
			break;
		case led4:
			if(tmpA > 0x09)
			{
				state = led5;
			}
			else if (tmpA < 0x07)
			{
				state = led2;
			}			
			break;
		case led5:
			if(tmpA > 0x0C)
			{
				state = led6;
			}
			else if (tmpA < 0x0A)
			{
				state = led2;
			}
			break;
		case led6:
			if (tmpA < 0x0D)
			{
				state = led2;
			}
			break;
	}
	
	switch(state)
	{
		case init:
			break;
		case empty:
			tmpB = 0x40;
			break;
		case led1:
			tmpB = 0x60;
			break;
		case led2:
			tmpB = 0x70;
			break;
		case led3:
			tmpB = 0x38;
			break;
		case led4:
			tmpB = 0x3C;
			break;
		case led5:
			tmpB = 0x3E;
			break;
		case led6:
			tmpB = 0x3F;
			break;
			
			
	}	
	PORTC = tmpB;
	tmpB = 0x00;
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	state = init;
	while(1)
	{
		tmpA = ~PINA;
		Tick();
	}
}

