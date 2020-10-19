/*	Author: Rodolfo Reyes 
 *	Lab Section: 23
 *	Assignment: Lab 2  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) 
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
			
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpB = 0x00;

	while(1)
	{

		tmpA = PINA & 0x01;
	
	
		if (tmpA == 0x01)//true if PA0 is 1 
		{
			tmpB = (tmpB & 0xFC) | 0x01; // Sets tmpB to bbbbbb01
			// (clear rightmost 2 bits, then set to 01)
		} 
		else
		{
			tmpB = (tmpB & 0xFC) | 0x00; // Sets tmpB to bbbbbb00
                        // (clear rightmost 2 bits, then set to 00)
		}
		
		PORTB = tmpB;	

	}
	return 1;
}
