/*      Author: Rodolfo Reyes 
 *      Lab Section: 23
 *      Assignment: Lab 2  Exercise 2
 *      Exercise Description: Parking space counter
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
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

	unsigned char cntavail = 0x00;

        while(1)
        {

                tmpA = PINA;//temp value hold input

                if (tmpA != 0x00) //true if input greater than 1 
                {
                	while(tmpA != 0x00)//will run as long as input contains greater than 0
			{
				count=count+1;
				tmpA=tmpA>>1;//fills in temp values with 0 
			}

			if(cntavail == 4)
                	{
                        	PORTB = 0x8f; // sets to 10001111 if count shows that the spots are full
                        	cntavail = 0;
                	}
                	else
                	{
                        	PORTB = count & 0x0f;//compares to 00001111 to make B0 - B3 the only ones that light up
                        	cntavail = 0;
                	}


                }
                else //resets count and output when no input
                {
                        cntavail=0;
			PORTB = 0x00;
         	}

        }
        return 1;
}
