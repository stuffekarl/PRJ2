/*
 * main.cpp
 *
 * Created: 2014-11-28 00:14:23
 *  Author: Kristian
 */ 

#include <avr/io.h>
#include "Transmitter.h"
#include "Time.h"


int main(){	
	Time * myTimePtr = getMyTime();
	Transmitter * myTransPtr = getMyTrans();
	myTimePtr->setTransPtr(myTransPtr);
	myTimePtr->startTime();
	DDRC |= (1 << 0);

	sei();
	
	while (1){
	}
	
	return 0;
}