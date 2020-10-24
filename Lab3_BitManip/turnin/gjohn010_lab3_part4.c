/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section:023
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRB = 0xFF;
	PORTB = 0x00;
	DDRC = 0xFF;
	PORTC = 0x00;

	unsigned char tempAB = 0x00;
	unsigned char tempAC = 0x00;
	unsigned char tempB = 0x00;
	unsigned char tempC = 0x00;
    /* Insert your solution below */
 while(1) {

	tempAB = PINA & 0xF0;
	tempAC = PINA & 0x0F;

	tempB = tempAB >> 4;
	tempC = tempAC << 4;

	PORTB = tempB;
	PORTC = tempC;

	}	
   return 0;

}
