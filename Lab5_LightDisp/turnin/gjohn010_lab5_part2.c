/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { Start, decide, increment, decrement, zero } state;
unsigned char output = 7;

void Tick() {
	switch(state) { //transitions
		case Start:
			PORTC = 7;
			state = Start;
			break;
		case decide:
			if (PINA == 0x01) {
				state = increment;	
			} 
			else if (PINA == 0x02) {
				state = decrement;
			}
			else if (PINA == 0x03) {
				state = zero;
			}
			break;
		case next_state:
			if (PINA == 0x01 || PINA == 0x02) {
				state = next_state;
			}
			else if (PINA == 0x01 || PINA == 0x02) {
				state = zero;
			}
			else {
				state = Start;
			}
		default:
		{
			break;}
		}
	switch(state) { //actions
		case Start:
		{       
			break;
		}
		case next_state:
			break;

		case increment:	
			if (PORTC < 9){
				PORTC = PORTC + 1;
				
			}
			break;
		case decrement:
			if (PORTC > 0) {
				PORTC = PORTC - 1;
			
			}
			break;
		case zero:
			PORTC = 0;	
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
