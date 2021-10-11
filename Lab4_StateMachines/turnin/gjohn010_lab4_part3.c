/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #4  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { Start, door_state, unlock } state;
unsigned char tmpA - 0x00;

void Tick() {
	switch(state) {
		case Start:
			state = Start;
			break;
		case unlock:
			if (PINA == 0x03) { //pressing "#" first
				PINA = 0x00; //pinA is released
		                if (PINA == 0x02) { //pressing "Y" now
					state = door_state;
					tmpA = 0x01; //PORTC is set to 1 to unlock
				}
				else {
					state = door_state;
					tmpA = 0x00;
				}
			}

			break;
		case lock: 
			if (PINA == 0x07) {
				state = door_state;
				tmpA = 0x00;
			}
		default:
		{
			break;}
	}
	switch(state) {
		case Start:
		{       PORTC = 0x00;
			break;
		}
		case door_state:
			PORTC = tmpA;
			
			break;
		default:
		{
			break;}
	}
}
int main() {
    /* Insert DDR and PORT initializations */
	state = Start;
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    while (1) {

	Tick();
    }
    return 0;
}
