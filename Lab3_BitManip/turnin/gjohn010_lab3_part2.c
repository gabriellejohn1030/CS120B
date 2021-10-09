/*	Author: gjohn010
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #3  Exercise #2
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00; //port c is the output and we are initializing it to 0
    /* Insert your solution below */

	unsigned char tmpA = 0x00; //holding temp value of port a and c
	unsigned char tmpC = 0x00;
	unsigned char lowFuel = 0x00;
   while (1) {
	tmpA = PINA & 0x0F;
	tmpC = PINC & 0xC0;
	lowFuel = PINC;
	if (tmpA == 0x01 || tmpA == 0x02) {
		tmpC = 0x20;
		lowFuel = 0x40;
	}
	if (tmpA == 0x03 || tmpA == 0x04) {
                tmpC = 0xF0;
		lowFuel = 0x40;
        }
	if (tmpA == 0x05 || tmpA == 0x06 ) {
                tmpC = 0xF8;
        }
	if (tmpA == 0x07 || tmpA == 0x08 || tmp == 0x09) {
                tmpC = 0xFC;
        }
	if (tmpA == 0x0A || tmpA == 0x0B || tmpA == 0x0C) {
                tmpC = 0xFE;
        }
	if (tmpA == 0x0D || tmpA == 0x0E || tmpA == 0x0F) {
                tmpC = 0xFF;
        }
	PORTC = tmpC & lowFuel;
    }
  return 0;
}
