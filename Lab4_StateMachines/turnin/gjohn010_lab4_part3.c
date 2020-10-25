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

enum States { START, INIT, S_HASH, S_Y } state;
unsigned char tmpA = 0x00, tmpB = 0x00;
    
void Tick() {
    switch(state) { 
        case START:
            state = INIT;
            break;
        case INIT:
            if (tmpA == 0x04) {
                state = S_HASH;
            }
            else {
                state = INIT;
            }
            break;
        case S_HASH:
            if (tmpA == 0x02) {
                state = S_Y;
            }
            else if (tmpA & 0x04 || ~tmpA & 0x02 || tmpA & 0x01 || tmpA & 0x80) {
                state = INIT;
            }
            break;
        case S_Y:
            if (tmpA & 0x80) {
                state = INIT;
            }
            break;
		default:
			break;
    }
    switch(state) {
        case INIT:
            tmpB = 0x00;
            PORTB = tmpB;
            break;
        case S_HASH:
            break;
        case S_Y:
            tmpB = 0x01;
            PORTB = tmpB;
            break;
		default:
			break;
    }
}

int main() {
    state = START;
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    while(1) {
        tmpA = PINA & 0x87;
        Tick();
    }
}





















































			






























































































			
























































	










    



		
