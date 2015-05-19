/*
 * Button.cpp
 *
 * Created: 20-11-2014 15:58:02
 *  Author: entvex
 */ 

#include "Button.h"

Button myButton; //Opret objektet globalt, så ISR kan kalde metoder i objektet.

Button::Button()
{
		countMe = 0;
		DDRD = 0x00;
		DDRC = 0xFF;
				
		GICR = 0b01000000 | GICR;   //Enable External Interrupt Request 0 Enable
		MCUCR = 0b00001110 | MCUCR; //interrupt settings
		sei();						//enable global interrupt
}

void Button::callMe()
{
	countMe++;
}

ISR(INT0_vect){
	myButton.callMe();
}