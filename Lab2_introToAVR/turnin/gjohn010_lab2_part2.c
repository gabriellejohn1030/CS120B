/*	Author: gjohn010
 * 	Partner(s) Name: none
 *	Lab Section: 022
 *	Assignment: Lab #2  Exercise #2
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

   DDRA = 0x00; PORTA = 0xFF;
   
 /* Insert your solution below */
    while (1) {
	unsigned char temp = PINA & 0x0F
	unsigned char cntavail = 0x04 ;

	if (temp == 0x01) {
		cntavail = cntavail - 1;
	}
	if (temp == 0x02) {
		cntavail = cntavail - 1;
	}
	if (temp == 0x04) {
		cntavail = cntavail - 1;
	}
	if (temp = 0x08) {
		cntavail = cntavail - 1;
	}
	PORTC = cntavail; 
    }	
    



   return 1;
}
