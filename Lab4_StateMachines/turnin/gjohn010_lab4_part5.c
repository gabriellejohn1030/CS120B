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

enum States { START, LOCK, UNLOCK, INPUT_PWD } state;
unsigned char tmpA = 0x00, tmpB = 0x00, tmpC = 0x00;
unsigned char count = 0, input[4];
    
void Tick() {
    switch(state) {
        case START:
            state = LOCK;
            break;
        case LOCK:
            if (tmpA & 0xFF) {
                state = INPUT_PWD;
            }
            break;
        case UNLOCK:
            if (tmpA & 0x80) {
                state = LOCK;
            }
            else if (tmpA & 0xFF) {
                state = INPUT_PWD;
            }
            break;
        case INPUT_PWD:
            if (count < 4) {
                state = INPUT_PWD;
            }
            
            else if (tmpB == 0x01) {
                if (input[0] == 0x04 && input[1] == 0x01 && input[2] == 0x02 && input[3] == 0x01) {
                    state = LOCK;
                }
                else {
                    state = UNLOCK;    
                }
            }
            else if (tmpB == 0x00) {
                if (input[0] == 0x04 && input[1] == 0x01 && input[2] == 0x02 && input[3] == 0x01) {
                    state = UNLOCK;
                }
                else {
                    state = LOCK;
                }
            }
			break;
		default:
			break;
    }
    switch(state) {
		 case START:
            break;
        case LOCK:
            tmpC = 0;
            tmpB = 0x00;
            PORTB = tmpB;
            for (count = 0; count < 4; count++) {
                input[count] = 0;
            }
            count = 0;
            break;
        case UNLOCK:
            tmpC = 2;
            tmpB = 0x01;
            PORTB = tmpB;
            for (count = 0; count < 4; count++) {
                input[count] = 0;
            }
            count = 0;
            break;
        case INPUT_PWD:
            tmpC = 1;
            input[count] = tmpA;
            count++;
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











			
























































	










    



		
