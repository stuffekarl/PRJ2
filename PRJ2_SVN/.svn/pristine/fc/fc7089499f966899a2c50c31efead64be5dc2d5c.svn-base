/*
 * Time.cpp
 *
 * Created: 2014-11-26 22:55:37
 *  Author: Kristian Søgaard
 */ 

#include "Time.h"
#include "Transmitter.h"
#include "TxUART.h"

#define debugging false //set to TRUE to enable debugging

Time myTime;

Time * getMyTime(){
	return &myTime;
}

Time::Time(){
	
	//Timer1 initialization:
	TCCR1A |= 0; 
	TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10); //CTC mode, 64 prescaling
	OCR1A = 57600; // See document on time implementation	
	//ICR1 = 57594;
}

// Set transmitter ptr, so checkTime can be called from here
void Time::setTransPtr(Transmitter * setMe){
	this->myTransPtr = setMe;
}


// enable compare interrupt on OCR1A
void Time::startTime(){
	TCNT1 = 0; //initialize timer
	TIMSK |= (1 << OCIE1A); 
	seconds = 0;
	minutes = 0;
}


// disable compare interrupt on OCR1A
void Time::stopTime(){
	TIMSK &= (0b11111111 & 0 << OCIE1A); //writes 0 to int on T1
}

void Time::intHandler(){
	//increments the time by 1 sec
	seconds++;
	
	//every 60 seconds updates Minutes value.
	if(seconds > 59){
	    seconds = 0;
		minutes++;
	}
		
	//every 5 seconds updates transmitters next action time.
	if(seconds % 5 == 0){
		if (debugging){
			getMyTxUART()->sendString("Checking time, current time is: ");
			getMyTxUART()->sendNumber(minutes);
			getMyTxUART()->sendChar(':');
			getMyTxUART()->sendNumber(seconds);
			getMyTxUART()->sendString("\n\r");
		}
		myTransPtr->checkTime( minutes );
	}
}

//interrupts each second
ISR(TIMER1_COMPA_vect){
	getMyTime()->intHandler();
}