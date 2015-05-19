/*
 * ReceiverProj.cpp
 *
 * Created: 21-11-2014 08:33:37
 *  Author: sem2 gruppe
 */ 


#include <avr/io.h>
#include "Rx10.h"
#include "RxUART.h"

int main(void)
{
	
	Rx10* myRx10Ptr = getMyRx10();
	RxUART* myRxUART = getMyRxUART();
	
	myRx10Ptr->setRxUAR(*myRxUART);
	
}