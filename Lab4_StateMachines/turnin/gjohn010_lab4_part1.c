/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { Start, PB0, PB1 } state;
unsigned char tmp1 = 0x00;
unsigned char tmp2 = 0x00;


void Tick() {
	switch(state) {
		case Start:
			state = PB0;
			break;
		case PB0:
			if (tmp1 == 0x01) {
				state = PB1;
			}
			else {
				state = PB0;
			}
			break;
		case PB1: 
			if (tmp1 == 0x01) {
				state = PB0;
			}
			else {
				state = PB1;
			}
			break;
		default:
		{
			break;}
	}
	switch(state) {
		case Start:
		{
			break;}
	
		case PB0:	
			tmp2 = 0x01;
			PORTB = tempB;
			break;
		case PB1:
			tmp2 = 0x02;
			PORTB = tempB;
			break;
		default:
		{
			break;}
	}
}
int main() {
    /* Insert DDR and PORT initializations */
	state = Start;
	DDRB = 0xFF;
	PORTB = 0x00;
    /* Insert your solution below */
    while (1) {
	tempA = PINA;
	Tick();
    }
    return 0;
}
