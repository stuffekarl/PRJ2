/*
* Rx10.cpp
*
* Created: 21-11-2014 09:01:31
* Author: David og Kristian
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Rx10.h"
#include "RxUART.h"

#define debugging false // Set this to true to enable debugging.

Rx10 myRx10;

// default constructor
Rx10::Rx10()
{
	start = false;
	buffer = 0x00;
	pattCount = 0x00;
	
	GICR = 0b01000000 | GICR;   //Enable interrupt on External Interrupt Request 0 Enable
	MCUCR = 0b00000001 | MCUCR; //interrupt settings: Any logical change on INTO generates an interrupt request
	
	DDRA = 0x00; // bitstream reader port
	DDRC = 0xff;
	
	//Timer 2
	TIFR = 0b00000000; //Normal mode
} //Rx10

bool Rx10::checkData( unsigned char bitcode ){
	char temp = 0;
	for (int i = 0;  i < 4; i++){
		temp = buffer << i*2;
		if ( (temp & 0b10000000) == ( (temp << 1 ) & 0b10000000) ) // bit shift right, if the first bit is equal to the next bit
			return false;
	}
	return true;
}

unsigned char Rx10::translate( unsigned char zeroCrossingCode ){
	char temp = 0;
	temp = temp | (0b00000001 & (zeroCrossingCode >> 1) ); // Shifts bit 1 into to temp
	temp = temp | (0b00000010 & (zeroCrossingCode >> 2) ); // Shifts bit 2 into to temp and so on.
	temp = temp | (0b00000100 & (zeroCrossingCode >> 3) );
	temp = temp | (0b00001000 & (zeroCrossingCode >> 4) );
	return temp;
}

void Rx10::waitMs(){
	TCNT2 = (255-(57/2)); //reset timer2, see mathcad calcs
	TCCR2 = TCCR2 | 0b00000100; // start timer2 with 64 prescaler
	while ((TIFR & 0b01000000) == 0); //wait for overflow on Timer2
	TCCR2 = TCCR2 & 0b11111011; //Stop timer2
	TIFR = TIFR | 0b01000000; // clear overflow flag by writing 1
}

void Rx10::setRxUART( RxUART * setMe){
	this->myRxUART = setMe;
}

void Rx10::setReceiver( Receiver *setMe ){
	this->myReceiver = setMe;
}

void Rx10::interruptHandler(){
	waitMs(); // wait 0.5 ms
	buffer = buffer << 1; // Make rooms the next bit
	buffer |= ( PINA & 0b00000001 ); //Adds the bit in the buffer
	//PORTC = ~buffer;

	if (!start){
		PORTC = ~buffer;
		if ( ( buffer & 0b00001111) == 0b00001110 ){
			start = true;
			pattCount = 2;
			buffCount = 7;
			if (debugging){
				myRxUART->sendString("New command!\n\r");
			}
		}
	}
	else{
		if (buffCount <= 0){
			PORTC = ~buffer;
			if (pattCount == 5){
				pattCount++;
				buffCount = 7;
				if (debugging){
					myRxUART->sendString("Checking for wait code, buffer is: ");
					myRxUART->sendNumber(buffer);
					myRxUART->sendString("\n\r");
				}
				if (buffer & 0b00111111){
					start = false;
					if (debugging){
						myRxUART->sendString("Wait-code invalid!\n\r");
					}
				}
			}
			else if ( pattCount == 9 ){
				if (debugging){
					myRxUART->sendString("Checking stop code..\n\r");
				}
				if ((buffer & 0b00001111) == 0b00001111){
					if (debugging){
						myRxUART->sendString("Command OK, executing..\n\r");
					}
					myReceiver->input(this->house,this->unit,this->command); //call Receiver with house, unit and command
					buffCount = 3;
					pattCount++;
				}
				else{
					start  = false;
					if (debugging){
						myRxUART->sendString("Stop code invalid!\n\r");
					}
				}
			}
			else if (pattCount == 10){
				start = false;
			}
			else{
				if (debugging){
					myRxUART->sendString("Checking the buffer, it is: ");
					myRxUART->sendNumber(buffer);
					myRxUART->sendString("\n\r");
				}
								
				if (checkData(buffer)){
					if ( pattCount == 2){ // checks if it is in pattern house
						house = translate(buffer);
						buffCount = 7;
							
						if (debugging){
							myRxUART->sendString("HouseCode: ");
							myRxUART->sendNumber(translate(buffer));
							myRxUART->sendString("\n\r");
						}
							
					}
					else if( pattCount == 3){ // checks if it is in pattern unit
						unit = translate(buffer);
						buffCount = 7;
							
						if (debugging){
							myRxUART->sendString("UnitCode: ");
							myRxUART->sendNumber(translate(buffer));
							myRxUART->sendString("\n\r");
						}
							
					}
					else if( pattCount == 4){ // checks if it is in command unit
						command = translate(buffer);
						buffCount = 5;
							
						if (debugging){
							myRxUART->sendString("Command: ");
							myRxUART->sendNumber(translate(buffer));
							myRxUART->sendString("\n\r");
						}
							
							
					}
					else if( pattCount == 6){ // checks if house code was correct
						if (debugging){
							myRxUART->sendString("compering house: ");
							myRxUART->sendNumber(translate(buffer));
							myRxUART->sendString("\n\r");
						}
						if ( house != translate(buffer) ){
							start = false;
							if (debugging){
								myRxUART->sendString("House check failed!\n\r");
							}
						}
						buffCount = 7;
					}
					else if( pattCount == 7){ // checks if unit code was correct
						if (debugging){
							myRxUART->sendString("compare unit code: ");
							myRxUART->sendNumber(translate(buffer));
							myRxUART->sendString("\n\r");
						}
						if ( unit != translate(buffer) ){
							start = false;
							if (debugging){
								myRxUART->sendString("Unit check failed!\n\r");
							}
						}
						buffCount = 7;
					}
					else if( pattCount == 8){ // checks if command code was correct
						if (debugging){
							myRxUART->sendString("compare command: ");
							myRxUART->sendNumber(translate(buffer));
							myRxUART->sendString("\n\r");
						}
						if ( command != translate(buffer) ){
							start = false;
							if (debugging){
								myRxUART->sendString("Command check failed!\n\r");
							}
						}
						buffCount = 3;
					}
					pattCount++;
				}
				else{
					start = false;
					if (debugging){
						myRxUART->sendString("Invalid data!\n\r");	
					}	
				}
			}
		}
		else{
			buffCount--;
		}
	}
}

	ISR( INT0_vect )
	{
		myRx10.interruptHandler();
	}

	Rx10 * getMyRx10(){
		return &myRx10;
	}