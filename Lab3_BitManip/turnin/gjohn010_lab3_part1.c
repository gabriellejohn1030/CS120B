/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //port a and b are inputs
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00; //port c is the output and we are initializing it to 0
    /* Insert your solution below */

	unsigned char tmpA = 0x00; //holding temp value of port a and b
	unsigned char tmpB = 0x00;
	unsigned char totalA = 0x00; //counting the total amount of 1s in these variables
	unsigned char totalB = 0x00;
   while (1) {
	tmpA = PINA;
	tmpB = PINB;

	if (tmpA == 0x01) {
		totalA = totalA + 1;
	}
	if (tmpA == 0x02) {
                totalA = totalA + 1;
        }
	if (tmpA == 0x04) {
                totalA = totalA + 1;
        }
	if (tmpA == 0x08) {
                totalA = totalA + 1;
        }
	if (tmpA == 0x10) {
                totalA = totalA + 1;
        }
	if (tmpA == 0x20) {
                totalA = totalA + 1;
        }
	if (tmpA == 0x40) {
                totalA = totalA + 1;
        }
	if (tmpA == 0x80) {
                totalA = totalA + 1;
        }
	//now we start counting the amount of 1s in portB
	if (tmpB == 0x01) {
		totalB = totalB + 1;
	}
	if (tmpB == 0x02) {
                totalB = totalB + 1;
        }
	if (tmpB == 0x04) {
                totalB = totalB + 1;
        }
	if (tmpB == 0x08) {
                totalB = totalB + 1;
        }
	if (tmpB == 0x10) {
                totalB = totalB + 1;
        }
	if (tmpB == 0x20) {
                totalB = totalB + 1;
        }
	if (tmpB == 0x40) {
                totalB = totalB + 1;
        }
	if (tmpB == 0x80) {
                totalB = totalB + 1;
        }	
	PORTC = totalA + totalB;
    }
  return 0;
}
