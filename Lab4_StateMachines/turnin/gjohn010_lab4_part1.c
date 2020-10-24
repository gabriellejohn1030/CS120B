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

enum States { Start, PBZero, PBOne } state;


void Tick() {
	switch(state) {
		case Start:
			state = PBZero;
			break;
		case PBZero:
			if (!PINA) {
				state = PBZero;
			}
			else if (PINA) {
				state = PBOne;
			}
			break;
		case PBOne: 
			if (!PINA) {
				state = PBOne;
			}
			else if (PINA) {
				state = PBZero;
			}
			break;


	switch(state) {
		case PBZero:	
			PORTB = 0x01;	
			break;
		case PBOne:
			PORTB = 0x02;
			break;
		default:
		break;
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
	Tick();
    }

}
