/*
 * main.cpp
 *
 * Created: 2014-11-28 00:14:23
 *  Author: Kristian
 */ 

#include <avr/io.h>
#include "Transmitter.h"
#include "Time.h"

Transmitter myTrans;

Transmitter * getMyTrans(){
	return &myTrans;
}

int main(){	
	getMyTime()->setTransPtr(getMyTrans());
	getMyTime()->startTime();

	DDRC = 0xFF;

	sei();
	
	while (1);	
	return 0;
}