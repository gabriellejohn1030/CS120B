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

/*
enum my_states { start, s0, s1 } my_state;

void tick() {
	switch (my_state) { //transitions
		case start:
			my_state = s0;		
			break;
		case s0:
			if(!PINA) {
				my_state = s0;
			}
			else {
				my_state = s1;
			}
			break;
		case s1:
			if(!PINA) {
				my_state = s0;
			}
			else {
				my_state = s1;
			}
			break;
		default:
			my_state = start;
			break;
	}
	
	switch (my_state) {
		case s0:
			PORTB = 0x01;
			break;
		case s1:
			PORTB = 0x02;
			break;
		default:
			break;

	}
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
        PORTB = 0x01;	
	my_state = start;


	while(1) {
		tick();
	}




	
return 0;
}
*/

enum my_states { start, s0, inc, dec, zero } my_state;

void tick() {
       switch(my_state) {
               case start:
                       my_state = s0;
                       break;
               case s0:
			if (PINA == 0x01) {
				my_state = inc;
			}
			else if (PINA == 0x02) {
				my_state = dec;
			}
			else if (PINA == 0x03) {
				my_state = zero;
			}
			break;
		case inc:
			my_state = s0;
			break;
		case dec:
			my_state = s0;
			break;
		case zero:
			my_state = s0;
			break;
		default:
			my_state = start;
			break;
	}

	switch(my_state) {
		case start:
			PORTC = 0x07;
			break;
		case s0:
			break;
		case inc:
			if (PORTC < 9){
				PORTC++;	
			}
			break;
		case dec:
			if (PORTC == 0x00) {
				break;
			}
			PORTC--;
		case zero:
			PORTC = 0;
			break;
		default:
			break;
	}
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
//	my_state = start;

//	PORTC = 0x07;

	while(1) {
		tick();
	}




	
return 0;
}

































	



























