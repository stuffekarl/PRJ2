/*
 * Tx10.h
 *
 * Created: 2014-11-21 08:43:49
 *  Author: Kristian Thomsen
 */ 

#ifndef Tx10_H_
#define Tx10_H_

#include <avr/interrupt.h>

class Action;
extern "C" void INT0_vect(void) __attribute__ ((signal));

class Tx10{
public:
	Tx10();	
	void turnAllOff();
	void sendAction(Action & myAction);
	friend void INT0_vect(void);
	void intHandler();
private:
	void waitMs();
	void sendCrossing(unsigned char send); // accepts 0 or 1
	unsigned char convertToCrossings(unsigned char myChar);
	unsigned char translate(unsigned char bitCode); //Translated a binary pattern to zerocrossings.
	volatile bool start;
	volatile unsigned char buffCount;	//stores the number of ZC's left in the buffer
	volatile unsigned char pattCount;	//stores the number of patterns that have been sent (0-9), where 9 is the stop code
	volatile unsigned char buffer;		//stores the current buffer being sent on X.10
	volatile unsigned char house;		//stores the house ZC-code of the Action
	volatile unsigned char unit;		//stores the unit ZC-code of the Action
	volatile unsigned char command;		//stores the ZC-command code of the Action
};

Tx10 * getMyTx10();

#endif