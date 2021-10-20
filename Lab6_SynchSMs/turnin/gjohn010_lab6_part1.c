/*	Author: gabbyjohn
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #6  Exercise #1
 *	DEMO LINK:
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#include "timer.h"
#endif

enum States {Start, PB0, PB1, PB2} state;
volatile unsigned char TimerFlag = 0;
void TimerISR() {TimerFlag = 1;}

void Tick() {
	switch(state) { //transitions
		case Start:
			state = PB0;
			break;		
		case PB0:
			state = PB1;
			break;
		case PB1:
			state = PB2;
			break;
		case PB2:
			state = PB0;
			break;
		default:
			break;
	}
	switch (state) { //actions
		case Start:
			break;
		case PB0:
			PORTB = 0x01;
			break;
		case PB1:
			PORTB = 0X02;
			break;
		case PB2:
			PORTB = 0x04;
			break;
		default:
			break;
	}


}


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0xFF;
	PORTB = 0x00;
	TimerSet(1000); //1000ms = 1 second
	TimerOn();
    /* Insert your solution below */
    while (1) {
	Tick();
	while(!TimerFlag){}
	TimerFlag = 0;
    }
    return 1;
}
