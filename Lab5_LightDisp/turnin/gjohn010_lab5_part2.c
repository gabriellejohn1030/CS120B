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

enum States { Start, increment, decrement, zero } state;
unsigned char output = 7;

void Tick() {
	switch(state) {
		case Start:
			PORTC = 7;
			state = Start;
			break;
		case increment:
			if (PINA == 0x01) {
				state = increment;
			
			}
			break;
		case decrement: 
			if (PINA == 0x02) {
				state = decrement;
			}
			break;
		case zero:
			if (PINA == 0x03) {
				state = zero;
			}
			break;
		default:
		{
			break;}
	}
	switch(state) {
		case Start:
		{       
			break;
		}
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
