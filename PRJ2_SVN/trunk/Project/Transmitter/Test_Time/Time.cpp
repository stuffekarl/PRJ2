/*
 * Time.cpp
 *
 * Created: 2014-11-26 22:55:37
 *  Author: Kristian Søgaard
 */ 

#include "Time.h"

Time myTime;

Time * getMyTime(){
	return &myTime;
}

Time::Time(Transmitter * transmitterPtr = nullptr)
{
	//Transmitter pointer
	myTransmitterPtr = transmitterPtr;
	
	//Timer1 initialization:
	TCCR1A |= 0; //CTC mode, toggle on compare match, 64 prescaler
	TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10); //CTC mode, toggle on compare match, 64 prescaler
	OCR1A = 57594; // See document on time implementation
	TCNT1 = 0; //initialize timer	
}


// enable compare interrupt on OCR1A
void Time::startTime()
{
	TIMSK |= (1 << OCIE1A); 
}


// disable compare interrupt on OCR1A
void Time::stopTime()
{
	TIMSK |= (0 << OCIE1A);
}

//Sends updated time in mint
void Time::sendTime()
{
	unsigned int minutes;
	
	minutes = ((seconds - (seconds % 60)) / 60); // round to lowest whole minute
	
	myTransmitterPtr->checkTime( minutes );
}

//interrupts each second
ISR(TIMER1_COMPA_vect)
{
	//increments the time by 1 sec
	myTime.seconds++;
		
	//every 5 second updates transmitters next action time.
	if(myTime.seconds % 5 == 0)
	{
		myTime.checkTime();
	}
}
