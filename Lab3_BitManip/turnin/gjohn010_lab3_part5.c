/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section:023
 *	Assignment: Lab #3  Exercise #5
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
	DDRD = 0x00;
	PORTD = 0xFF;
	DDRB = 0xFE;
	PORTB = 0x00;

	unsigned short weight = 0x0000;
	unsigned char tempD = 0x00;
	unsigned char tempB = 0x00;



    /* Insert your solution below */
 while(1) {

	tempD = PIND;
	tempB = PINB & 0x01;

	weight = (tempD << 1) + tempB;

	if (weight >= 70) {
		tempB = 0x02;
	}
	else if (weight > 5 && weight < 70) {
		tempB = 0x00;
	}
	else {
		tempB = 0x00;
	}


 }	
   return 0;

}
