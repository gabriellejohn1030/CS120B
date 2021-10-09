/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab #4  Exercise #4
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
unsigned char tempA = 0x00, tempB = 0x00, tempC = 0x00;
unsigned char count = 0, input[2];
    
void Tick() {
    switch(state) {
        case START:
            state = LOCK;
            break;
        case LOCK:
            if (tempA & 0xFF) {
                state = INPUT_PWD;
            }
            break;
        case UNLOCK:
            if (tempA & 0x80) {
                state = LOCK;
            }
            else if (tempA & 0xFF) {
                state = INPUT_PWD;
            }
            break;
        case INPUT_PWD:
            if (count < 2) {
                state = INPUT_PWD;
            }
            else if (tempB == 0x01) {
                if (input[0] == 0x04 && input[1] == 0x02) {
                    state = LOCK;
                }
                else {
                    state = UNLOCK;    
                }
            }
            else if (tempB == 0x00) {
                if (input[0] == 0x04 && input[1] == 0x02) {
                    state = UNLOCK;
                }
                else {
                    state = LOCK;
                }
            }
            break;
    }
    switch(state) {
		case START:
			
			break;
        case LOCK:
            tempC = 0;
            tempB = 0x00;
            PORTB = tempB;
            for (count = 0; count < 2; count++) {
                input[count] = 0;
            }
            count = 0;
            break;
        case UNLOCK:
            tempC = 2;
            tempB = 0x01;
            PORTB = tempB;
            for (count = 0; count < 2; count++) {
                input[count] = 0;
            }
            count = 0;
            break;
        case INPUT_PWD:
            tempC = 1;
            input[count] = tempA;
            count++;
            break;
    }
}

int main() {
    state = START;
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    while(1) {
        tempA = PINA & 0x87;
        Tick();
    }
}


























































			
























































	










    



		
