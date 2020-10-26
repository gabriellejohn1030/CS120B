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
			if(PINA) {
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

























	



























	














































































































	



























