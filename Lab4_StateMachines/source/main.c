/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section: 023
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
unsigned char tempA = 0x00;
unsigned char tempB = 0x00;


void Tick() {
	switch(state) {
		case Start:
			state = PB0;
			break;
		case PB0:
			if (tempA == 0x01) {
				state = PB1;
			}
			else {
				state = PB0;
			}
			break;
		case PB1: 
			if (tempA == 0x01) {
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
			tempB = 0x01;
			PORTB = tempB;
			break;
		case PB1:
			tempB = 0x02;
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
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRB = 0xFF;
	PORTB = 0x00;
    /* Insert your solution below */
    while (1) {
	tempA = PINA;
	Tick();
    }
    return 0;
}
