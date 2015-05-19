/*
 * temp.cpp
 *
 * Created: 2014-12-03 11:35:23
 *  Author: Kristian Thomsen
 * HOW TO:
 * Connect STK500 LED's to PORTC
 * Run program and connect codelock to PIN A0
 * If the LED's are on, the code is correct. 
 */ 


#include <avr/io.h>
#include "Codelock.h"

int main(void)
{
	Codelock * myCodelockPtr = getMyCodelock();
	DDRC = 0xFF;  //LED port as output

	while(1){
		if (myCodelockPtr->unlocked()){
			PORTC = 0x00; //LEDs ON
		}
		else{
			PORTC = 0xFF; //LEDs OFF
		}
	}
}