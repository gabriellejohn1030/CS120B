/*	Author: gabbyjohn
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #7  Exercise #1
 *	DEMO LINK: https://www.youtube.com/watch?v=MRyKx0iiylo
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../header/io.h"

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


enum States {Start, Init, Wait, Inc, Dec, Zero} state;

void Tick()
{
	int num = 0;
	unsigned char temp = ~PINA&0x0F;

	switch(state) {   // Transitions
		case Start:  
			state = Init;
			break;

		case Init:
			temp = ~PINA&0x0F;
			if (temp == 0x01) {
				state = Inc;
			}
			else if (temp == 0x02) {
				state = Dec;
			}
			else if (temp == 0x03) {
				state = Zero;
			}
			break;

		case Wait:
			temp = ~PINA&0x0F;
			if ((temp == 0x01)){
				state = Inc;
			}
			else if ((temp == 0x02)){
				state = Dec;
			}
			else if ((temp == 0x01) && (temp == 0x02)){
				state = Zero;
			}
			else {
				state = Init;
			}	
			break;
		
		case Inc:
			state = Wait;
			break;
		
		case Dec:
			state = Wait;
			break;
		
		case Zero:
			state = Wait;
			break;

		default:
			state = Start;
			break;
	} // Transitions

	switch(state) {   // State actions
		case Init:
			num = 0;
			break;
		
		case Wait:
			break;
		
		case Inc:
			if (PORTC < 9) {
				PORTC = PORTC + 1;
				num = PORTC;
				LCD_WriteData(num + '0');
		}
		break;

		case Dec:
			if (PORTC > 0) {
				PORTC = PORTC - 1;
				num = PORTC;
				LCD_WriteData(num + '0');
		}
		break;
		
		case Zero:
			PORTC = 0;
			LCD_WriteData(0 +'0');
			break;

		default:
			break;
	} // State actions
}


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00; // LCD data lines
	DDRD = 0xFF; PORTD = 0x00; // LCD control lines
	TimerSet(500);
	TimerOn();
	// Initializes the LCD display
	while(1) {
		Tick();
		while(!TimerFlag);
		TimerFlag = 0;
	}
}
