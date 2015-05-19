/*
 * Test_Transmitter.cpp
 *
 * Created: 2014-11-27 13:33:37
 *  Author: Kristian Thomsen
 */ 
#include <avr/io.h>
#include "Transmitter.h"
#include "Tx10.h"
#include "Time.h"
#include "TxUART.h"
#include "Codelock.h"

Codelock tempCode;
Codelock * getMyCodelock(){
	
	return &tempCode;
}

Time tempTime;
Time * getMyTime(){
	return &tempTime;
}



int main(){
	Transmitter * myTransPtr = getMyTrans();
	TxUART* myTxUARTPtr = getMyTxUART();
	myTxUARTPtr->setTrans(getMyTrans());

	myTransPtr->setTx10Ptr(getMyTx10());
	myTransPtr->setCodelockPtr(getMyCodelock());
	myTransPtr->setTimePtr(getMyTime());
	
	sei();
	while(1){
	}
	return 0;
}