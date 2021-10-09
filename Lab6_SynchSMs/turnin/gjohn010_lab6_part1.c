/*	Author: gabbyjohn
 *  Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab #6  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char tmpB;

enum States {START, LEDOne, LEDTwo, LEDThree} state;

void Tick() {
    switch(state) {
        case START:
            state = LEDOne;
            break;
        case LEDOne:
            state = LEDTwo;
            break;
        case LEDTwo:
            state = LEDThree;
            break;
        case LEDThree:
            state = LEDOne;
            break;
        default:
            break;
    }
    switch(state) {
        case START:
            break;
        case LEDOne:
            tmpB = 0x01;
            PORTB = tmpB;
            break;
        case LEDTwo:
            tmpB = 0x02;
            PORTB = tmpB;
            break;
        case LEDThree:
            tmpB = 0x04;
            PORTB = tmpB;
            break;
        default:
            break;
    }
}


int main(void) {
    DDRB = 0xFF;
    PORTB = 0x00;
    TimerSet(1000);
    TimerOn();
    state = START;
    while (1) {
        Tick();
        while(!TimerFlag) {}
        TimerFlag = 0;
    }
}
