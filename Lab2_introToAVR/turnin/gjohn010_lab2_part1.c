/*	Author: gjohn010
<<<<<<< HEAD
 *  Partner(s) Name: 
=======
 *  Partner(s) Name: none
 *	Lab Section: 022
 *	Assignment: Lab #2  Exercise #1
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
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0xFF;

	unsigned char tmpPB0 = 0x00;
	unsigned char tmpPA0 = 0x00;
	unsigned char tmpPA1 = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpPA0 = PINA & 0x00;
	tmpPA1 = PINA & 0x00;
	
	if (tmpPA0 == 0x00 && tmpPA1 == 0x00) {
		tmpPB0 = (tmpPB0 & 0xFC) | 0x00;

    	}
	else if (tmpPA0 == 0x01 && tmpPA1 == 0x00) {
		tmpPB0 = (tmpPB0 & 0xFC) | 0x01;
	}
	else if (tmpPA0 == 0x00 && tmpPA1 == 0x01) {
		tmpPB0 = (tmpPB0 & 0xFC) | 0x00;
	}
	else {
		tmpPB0 = (tmpPB0 & 0xFC) | 0x01;
	}
	PORTB = tmpPB0;
    }
    return 0;
}	
