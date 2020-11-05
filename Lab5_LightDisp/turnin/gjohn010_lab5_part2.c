/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif



enum States { START, INIT, ADD, SUB, STOP, RESET, HOLD, RELEASE } state;
unsigned char tmpA = 0x00;
unsigned char tmpC = 0x00;
unsigned int count;
void Tick() {
    switch(state) { 
        case START:
            state = INIT;
            break;
        case INIT:
            if (tmpA == 0x01) {
                state = ADD;
            }
            else if (tmpA == 0x02) { 
                state = SUB;
            }
            else if (tmpA == 0x03) { 
                state = RESET;
            }
            break;
        case ADD:
            if (tmpA == 0x02) { 
                state = SUB;
            }
            else if (tmpC == 0x09) { 
                state = STOP;
            }
            else if (tmpA == 0x03) { 
                state = RESET;
            }
			else if ( tmpA == 0x01)
			{
				state = HOLD;
			}
            break;
        case SUB:
            if (tmpA == 0x01) { 
                state = ADD;
            }
            else if (tmpC == 0x00) { 
                state = STOP;
            }
            else if (tmpA == 0x03) { 
                state = RESET;
            }
			else if (tmpA ==0x02)
			{
				state = HOLD;
			}
            break;
        case STOP:
			if (tmpA == 0x01 && tmpC != 0x09)
			{
				state = ADD;
			}
            if (tmpA == 0x02 && tmpC != 0x00) { 
                state = SUB;
            }
            else if (tmpA == 0x03) { 
                state = RESET;
            }
            break;
		case HOLD:
			if (tmpA == 0x00)
			{
				state = RELEASE;
			}
			if (tmpA == 0x03)
			{
				state = RESET;
			}
			break;
		case RELEASE:
            if (tmpA == 0x01) { 
	            state = ADD;
            }
            else if (tmpA == 0x02) { 
	            state = SUB;
            }
            else if (tmpA == 0x03) { 
	            state = RESET;
            }
            break;			
        case RESET:
            if (tmpA == 0x01) {
                state = ADD;
            }
            break;
        default:
            break;
    }
    switch(state) { 
        case INIT:
            tmpC = 0x07; 
            PORTC = tmpB;
            break;
        case ADD:
            tmpC = tmpC + 0x01;
            PORTC = tmpC;
            break;
        case SUB:
            if (tmpC == 0x00) {
                break;     
            }         
            tmpC = tmpC - 0x01;
            PORTC = tmpC;   
            break;
        case STOP:
            break;
		case HOLD:
			break;
		case RELEASE:
			break;
        case RESET:
            tmpC = 0x00;
            PORTC = tmpC;
            break;
        default:
            break;
    }
}

int main() {
    state = START;
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x07;
    while(1) {
	tmpA = ~PINA & 0x03;
        Tick();
    }
}

