/*
 * TxUART.h
 *
 * Created: 2014-11-27 12:12:34
 *  Author: Kristian Thomsen
 */ 

#ifndef _TxUART_H
#define _TxUART_H

#include <avr/interrupt.h>

class Transmitter;
extern "C" void USART_RXC_vect(void) __attribute__ ((signal));
extern "C" void USART_TXC_vect(void) __attribute__ ((signal));

class TxUART{
public:
	TxUART();
	void setTrans(Transmitter * setMe );	//method for setting the myTrans ptr
	void sendChar(char sendMe);				//method to send a char
	void sendString(const char * sendMe);	//method to send a string, used for debugging
	void sendNumber(unsigned int sendMe);			//method to send a number as a string of chars, used for debugging
	friend void USART_RXC_vect(void);		//allows the USART receive interrupt to call rxInt();
	friend void USART_TXC_vect(void);		//allows the USART transmit interrupt to call txInt();
private:
	void txInt();
	void rxInt();
	unsigned char charNo;					//counter of how much data has been received.
	Transmitter * myTrans;					//pointer to the controller class to be able to send data
	char mode;								//char to control the mode, can be 'i' or 'r' for idle or receiving
};

TxUART * getMyTxUART();

#endif