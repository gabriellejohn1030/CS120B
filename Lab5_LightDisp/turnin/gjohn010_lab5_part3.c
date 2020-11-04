/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

/*

enum States { START, INIT, ADD, SUB, STOP, RESET, HOLD, RELEASE } state;
unsigned char tmpA = 0x00, tmpB = 0x00;
unsigned int count;
void Tick() {
    switch(state) { // Transitions
        case START:
            state = INIT;
            break;
        case INIT:
            if (tmpA == 0x01) { // add 1
                state = ADD;
            }
            else if (tmpA == 0x02) { // subtract 1
                state = SUB;
            }
            else if (tmpA == 0x03) { // reset
                state = RESET;
            }
            break;
        case ADD:
            if (tmpA == 0x02) { // subtract 1
                state = SUB;
            }
            else if (tmpB == 0x09) { // if B=9
                state = STOP;
            }
            else if (tmpA == 0x03) { // reset
                state = RESET;
            }
			else if ( tmpA == 0x01)
			{
				state = HOLD;
			}
            break;
        case SUB:
            if (tmpA == 0x01) { // add 1
                state = ADD;
            }
            else if (tmpB == 0x00) { // if B=0
                state = STOP;
            }
            else if (tmpA == 0x03) { // reset
                state = RESET;
            }
			else if (tmpA ==0x02)
			{
				state = HOLD;
			}
            break;
        case STOP:
			if (tmpA == 0x01 && tmpB != 0x09)
			{
				state = ADD;
			}
            if (tmpA == 0x02 && tmpB != 0x00) { // subtract 1
                state = SUB;
            }
            else if (tmpA == 0x03) { // reset
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
            if (tmpA == 0x01) { // add 1
	            state = ADD;
            }
            else if (tmpA == 0x02) { // subtract 1
	            state = SUB;
            }
            else if (tmpA == 0x03) { // reset
	            state = RESET;
            }
            break;			
        case RESET:
            if (tmpA == 0x01) { // add 1
                state = ADD;
            }
            break;
        default:
            break;
    }
    switch(state) { // State actions
        case INIT:
            tmpB = 0x07; //initial at 0
            PORTC = tmpB;
            break;
        case ADD:
            tmpB = tmpB + 0x01;
            PORTC = tmpB;
            break;
        case SUB:
            if (tmpB == 0x00) {
                break;     
            }         
            tmpB = tmpB - 0x01;
            PORTC = tmpB;   
            break;
        case STOP:
            break;
		case HOLD:
			break;
		case RELEASE:
			break;
        case RESET:
            tmpB = 0x00;
            PORTC = tmpB;
            break;
        default:
            break;
    }
}

int main() {
    state = START;
    DDRA = 0x00; PORTA = 0xFF;//input, initial at 1
    DDRC = 0xFF; PORTC = 0x07;//output, initial at 7
    while(1) {
        tmpA = ~PINA & 0x03;//make sure  only PA1-PA0 work
        Tick();
    }
}
*/

unsigned char tmpA = 0x00;
unsigned char k=0;
unsigned char D;
enum States { Init, WaitRise, WaitFall } State;

Tick() {
   switch(State) { // Transitions
      case Init: 
         if (1) {
            State = WaitRise;
         }
         break;
      case WaitRise: 
         if (!tmpA) {
            State = WaitRise;
         }
         else if (tmpA) {
            State = WaitFall;
            D=0xFF<<k;
		PORTB = D;
            if(D==0) k=0;

            k=k+1;
         }
         break;
      case WaitFall: 
         if (!tmpA) {
            State = WaitRise;
         }
         else if (tmpA) {
            State = WaitFall;
         }
         break;
      default:
         State = Init;
   } // Transitions

   switch(State) { // State actions
      case Init:
         D=0xFF;
         break;
      case WaitRise:
         break;
      case WaitFall:
         break;
      default: // ADD default behaviour below
      break;
   } // State actions

}

int main() {

   State = Init; // Initial state
   D = 0; // Init outputs
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;

   while(1) {
      tmpA = PINA & 0x01;
      Tick();
   } // while (1)
} // Main

