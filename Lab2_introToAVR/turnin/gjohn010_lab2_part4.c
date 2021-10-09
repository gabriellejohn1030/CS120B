/*	Author: gjohn010
 *  Partner(s) Name: none
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

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s

    unsigned char tmpA = 0x00; // Temporary variable to hold the value of B
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of A
    unsigned char tmpC = 0x00;
    unsigned char tmpD = 0x00;
    unsigned char avg = 0x00;
    int count = 0;
    int average;
    int kg;
    /* Insert your solution below */

/*
    while (1) {
	// 1) Read input
	tmpA = PINA & 0x03;
	// 2) Perform computation
	// if PA0 is 1, set PB1PB0 = 01, else = 10
	if (tmpA != 0x01) { // True if PA0 is 1
		PORTB = 0x00; // Sets tmpB to bbbbbb01
					 // (clear rightmost 2 bits, then set to 01)

	 } 
	else {
		PORTB = 0x01; // Sets tmpB to bbbbbb10
					// (clear rightmost 2 bits, then set to 10)

	}
	

    }
*/
   while (1) {
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;

	count = tmpA + tmpB + tmpC;

	average = count / 15;

	tmpD = average;
	tmpD = tmpD << 2;
	
	kg = (tmpD >> 2) * 15;

	if (count > 0x8C) {
		tmpD = tmpD + 0x01;
	}
	if ((tmpA - tmpC > 0x50) || ((tmpC - tmpA) >0x50)) {
		tmpD = tmpD + 0x02;
	}

	PORTD = tmpD;

	tmpD = 0x00;

  }
    return 0;
}
