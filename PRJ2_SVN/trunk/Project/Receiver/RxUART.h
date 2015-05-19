/*
 * RxUART.h
 *
 * Created: 2014-11-27 12:12:34
 *  Author: David Jensen
 */ 

#ifndef _RxUART_H
#define _RxUART_H

#include <avr/io.h>
#include <avr/interrupt.h>
//#include  " controller class "

extern "C" void USART_TXC_vect(void) __attribute__ ((signal));

class RxUART{
public:
	RxUART();
	void sendChar(char sendMe);				//method to send a char, used for debugging
	void sendString(const char * sendMe);	//method to send a string, used for debugging
	void sendNumber(int sendMe);			//method to send a number as a string of chars, used for debugging
	friend void USART_TXC_vect(void);		//allows the USART transmit interrupt to call txInt();
private:
	void txInt();
};

RxUART * getMyRxUART();

#endif