/*
 * Codelock.cpp
 *
 * Created: 2014-12-03 11:51:23
 *  Author: Kristian Thomsen
 */ 

#include <avr/io.h>
#include "Codelock.h"

Codelock myCodelock;

Codelock::Codelock(){
	DDRA &= 0b11111110; //A0 = input
}

bool Codelock::unlocked(){
	//TRUE if unlocked, FALSE is locked. 
	//Signal is LOW when code is correct, HIGH when not correct.
	return !(PINA & 0b0000001);
}

Codelock * getMyCodelock(){
	return &myCodelock;
}