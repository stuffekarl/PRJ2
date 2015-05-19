/* 
* Rx10.h
*
* Created: 21-11-2014 09:01:31
* Author: entvex
*/

#ifndef __RX10_H__
#define __RX10_H__

#include "RxUART.h"
#include "Receiver.h"

extern "C" void INT0_vect(void) __attribute__ ((signal));

class Rx10
{

//functions
public:
	Rx10();
	bool checkData( unsigned char );
	unsigned char translate( unsigned char );
	friend void INT0_vect(void);
	void setRxUART( RxUART *setMe);
	void setReceiver( Receiver *setMe );
	
protected:

private:
	void interruptHandler();
	void waitMs();
	unsigned char buffCount; //stores the number of ZC's left in the buffer
	unsigned char pattCount; //stores the number of patterns that have been sent (0-9), where 9 is the stop code
	unsigned char buffer; //stores the current buffer being sent on X.10
	unsigned char house; //stores the house ZC-code of the Action
	unsigned char unit; //stores the unit ZC-code of the Action
	unsigned char command; //stores the ZC-command code of the Action
	
	bool start; //stores wheneter the start code is recvied
	unsigned char count;
	RxUART*  myRxUART;
	Receiver* myReceiver;
	
}; //Rx10

Rx10 * getMyRx10();


#endif //__RX10_H__