/*
 * Time.cpp
 *
 * Created: 2014-11-26 22:55:37
 *  Author: Kristian S�gaard
 */ 

#include "Time.h"
#include "Transmitter.h"

Time myTime;

Time * getMyTime(){
	return &myTime;
}

Time::Time(){
	//Timer1 initialization:
	TCCR1A |= 0; 
	TCCR1B |= (1 << CS11)|(1 << CS10); //CTC mode, toggle on compare match, 64 prescaling
	OCR1B = 57594; // See document on time implementation	
}

// Set transmitter ptr, so checkTime can be called from here
void Time::setTransPtr(Transmitter * setMe){
	this->myTransPtr = setMe;
}


// enable compare interrupt on OCR1A
void Time::startTime(){
	TCNT1 = 0; //initialize timer
	TIMSK |= (1 << TOIE1); 
}


// disable compare interrupt on OCR1A
void Time::stopTime(){
	TIMSK |= (0 << TOIE1);
}

//interrupts each second
ISR(TIMER1_OVF_vect){
	
	//increments the time by 1 sec
	myTime.seconds++;
	
	//every 60 seconds updates Minutes value.
	if(myTime.seconds > 58){
	    myTime.seconds = 0;
		myTime.minutes++;
	}
		
	//every 5 seconds updates transmitters next action time.
	if(myTime.seconds % 5 == 0){
		myTime.myTransPtr->checkTime( myTime.minutes );
	}
}