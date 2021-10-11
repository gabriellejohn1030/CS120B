/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #4  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { Start, PA0, PA1, reset } state;
unsigned char tmp1 = 0x00;
unsigned char tmp2 = 0x00;
unsigned char output = 7;

void Tick() {
	switch(state) {
		case Start:
			state = Start;
			break;
		case PA0:
			if (PINA == 0x01) {
				state = PA0 ;
			
			}
			break;
		case PA1: 
			if (PINA == 0x02) {
				state = PA1;
			}
			break;
		case reset:
			if (PINA == 0x01 && PINA == 0x02) {
				state = reset;
			}
		default:
		{
			break;}
	}
	switch(state) {
		case Start:
		{       PORTC = 0x07;
			break;
		}
		case PA0:	
			if (PORTC < 0x09){
				PORTC++;
				
			}
			break;
		case PA1:
			if (PORTC > 0x00) {
				PORTC--;
			
			}
			break;
		case reset:
			PORTC = 0x00;	
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
