/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
    /* Insert your solution below */

while(1) {


		unsigned char fuelLevel = PINA & 0x0F;
		unsigned char light = 0;
		unsigned char lowFuel = 0;
	
        
        	if (fuelLevel == 0) {
        	    lowFuel = 0x40;
        	}	
	
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
