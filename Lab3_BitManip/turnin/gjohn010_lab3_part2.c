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

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
//	DDRB = 0x00;
//	PORTB = 0xFF;
    /* Insert your solution below */
  /*  while (1) {
	unsigned char tempA = PINA;
	unsigned tempB = PINB;
	unsigned char counter = 0;
	unsigned char i;
	for (i = 0; i < 8; ++i) {
		if(GetBit(tempA, i)) {
			++counter;
		}
	}
	for (i = 0; i < 8; ++i) {
		if(GetBit(tempB, i)) {
			++counter;
		}
	}
	PORTC = counter;


    }
*/

 while(1) {
/*	unsigned char fuelLevel = PINA & 0x0F;
	unsigned char light = 0;
	unsigned char lowFuel = 0;
	
	unsigned char key = GetBit(PINA, 4);
	unsigned char seat = GetBit(PINA,5);
	unsigned char seatbelt = GetBit(PINA, 6);
	unsigned char fastenbelt = 0;

	if (fuelLevel == 2 || fuelLevel == 1) {
		light = 0x20;
		lowFuel = 0x40;
	}
	if (fuelLevel == 3 || fuelLevel == 4) {
		light = 0x30;
		lowFuel = 0x40;
	}
	if (fuelLevel == 5 || fuelLevel == 6) {
		light = 0x38;
	}
	if (fuelLevel == 13 || fuelLevel == 14 || fuelLevel == 15) {
		light 0x3F;
	}
	if (fuelLevel == 10 || fuelLevel == 11 || fuelLevel == 12) {
		light = 0x3E;
	}
	if (fuelLevel == 7 || fuelLevel == 8 || fuelLevel == 9) {
		light = 0x3C;
	}
	if (seatbelt) {
		fastenbelt = 0x00;
	}
	else {
		if (seat && key) {
			fastenbelt = 0x80;
		}
		else {
			fastenbelt = 0x00;
		}
	}
		
	PORTC = light | lowFuel | fastenbelt;

 }
    return 0;
*/
 unsigned char fuelLevel = PINA & 0x0F;
 unsigned char light = 0;
 unsigned char lowFuel = 0;
		
		if (fuelLevel == 2 || fuelLevel == 1) {
			light = 0x20;
			lowFuel = 0x40;
		}
		if (fuelLevel == 3 || fuelLevel == 4) {
			light = 0x30;
			lowFuel = 0x40;
		}
		if (fuelLevel == 5 || fuelLevel == 6) {
			light = 0x38;
		
		}
		if (fuelLevel == 13 || fuelLevel == 14 || fuelLevel == 15) {
			light = 0x3F;
		}
		if (fuelLevel == 10 || fuelLevel == 11 || fuelLevel == 12) {
			light = 0x3E;
		}
		if (fuelLevel ==7 || fuelLevel == 8 || fuelLevel == 9) {
			light = 0x3C;
		}
		

		PORTC = light | lowFuel;
	}	
   return 0;
}
