/*	Author: gabbyjohn
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #6  Exercise #2
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

enum States {Start, PA0, PB0, PB1, light, reset} state;
volatile unsigned char TimerFlag = 0;
void TimerISR() {TimerFlag = 1;}

void Tick() {
	switch(state) { //transitions
		case Start:
			if (PA0 = 0x01) {
				state = light;
				PA0 = 0;
			}
			break;		
		case light:
			if (PA0 = 0x00) {
				state = reset;
				PA0 = 0x00;
			}
			break;
		case reset:
			state = Start;
			break;
		default:
			break;
	}
	switch (state) { //actions
		case Start:
			break;
		case light:
			while (PA0 = 0x00) {
				PB0 = 0x01;
				Tick(300);
				PB0 = 0;
				PB1 = 1;
				Tick(300);
				PB1 = 0x00;
				PB2 = 0x01;
				Tick(300);
			}
			break;
		case reset:
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
