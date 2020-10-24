/*	Author: gjohn010
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
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
	DDRB = 0x00;
	PORTB = 0xFF;
    /* Insert your solution below */
    while (1) {
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
    return 0;
}
