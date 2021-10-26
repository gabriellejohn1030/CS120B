/*	Author: gabbyjohn
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #6  Exercise #2
 *	DEMO LINK: https://www.youtube.com/watch?v=RM1ekfdGiH8
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

volatile unsigned char TimerFlag = 0; // TimerISR() sets this to 1. Cprogrammer should clear to 0.

// Internal variables for mapping AVR's ISR to our cleaner TimerISR model.
unsigned long _avr_timer_M = 1; // Start count from here, down to 0.Default 1 ms.
unsigned long _avr_timer_cntcurr = 0; // Current internal count of 1ms ticks

void TimerOn() {
	// AVR timer/counter controller register TCCR1
	TCCR1B = 0x0B;
	OCR1A = 125;
	TIMSK1 = 0x02;
	TCNT1=0;

	_avr_timer_cntcurr = _avr_timer_M;
	// TimerISR will be called every _avr_timer_cntcurr milliseconds

	//Enable global interrupts
	SREG |= 0x80; // 0x80: 1000000
}

void TimerOff() {
	TCCR1B = 0x00; // bit3bit1bit0=000: timer off
}

void TimerISR() {
	TimerFlag = 1;
}

// In our approach, the C programmer does not touch this ISR, butrather TimerISR()
ISR(TIMER1_COMPA_vect) {
	// CPU automatically calls when TCNT1 == OCR1 (every 1 ms per TimerOn settings)
	_avr_timer_cntcurr--; // Count down to 0 rather than up to TOP
	if (_avr_timer_cntcurr == 0) { // results in a more efficient compare
		TimerISR(); // Call the ISR that the user uses
		_avr_timer_cntcurr = _avr_timer_M;
	}
}

// Set TimerISR() to tick every M ms
void TimerSet(unsigned long M) {
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}



enum States {Start, PortZero, PortOne, PortTwo, Pause} state;

unsigned int count = 0;

void Tick() {
	switch(state) { //transitions
		case Start:
			state = PortZero;
			break;		
		case PortZero:	
			if (~PINA & 0x01) {
                                state = Pause;
				count = 1;
                        }
			state = PortOne;
			break;
		case PortOne:
			if (~PINA & 0x01) {
                                state = Pause;
				count = 2;
                        }
			state = PortTwo;
			break;
		case PortTwo:;
			if (~PINA == 0x01) {
                                state = Pause;
				count = 3;
                        }
			state = PortZero;
			break;
		case Pause:
			PINA & 0x00;
			if (~PINA & 0x01) {
				state = Start;
			}
			break;
		default:
			state = Start;
			break;
	}
	switch (state) { //actions
		case Start:
			break;
		case PortZero:
			PORTB = 0x01;
			break;
		case PortOne:
			PORTB = 0X02;
			break;
		case PortTwo:
			PORTB = 0x04;
			break;
		case Pause:
			if (count == 1) {
				PORTB = 0x01;
				count = 0;
			}
			else if (count == 2) {
				PORTB = 0x02;
				count = 0;
			}
			else if (count == 3) {
				PORTB = 0x04;
				count = 0;
			}
			break;
		default:
			break;
	}


}


int main() {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRB = 0xFF;
	PORTB = 0x00;
	TimerSet(300); //1000ms = 1 second
	TimerOn();
	state = Start;
    /* Insert your solution below */
    while (1) {
	Tick();
	while(!TimerFlag);
	TimerFlag = 0;
    }
    
}
