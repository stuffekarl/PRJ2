/*
 * main.cpp
 *
 * Created: 2014-12-03 13:19:06
 *  Author: Kristian Thomsen
 */ 

#include "Action.h"
#include "Codelock.h"
#include "Time.h"
#include "Transmitter.h"
#include "Tx10.h"
#include "TxUART.h"

int main(){
	//Setting all the pointers for objects that need them.
	getMyTrans()->setCodelockPtr(getMyCodelock());
	getMyTrans()->setTimePtr(getMyTime());
	getMyTrans()->setTx10Ptr(getMyTx10());
	getMyTime()->setTransPtr(getMyTrans());
	getMyTxUART()->setTrans(getMyTrans());

	//Enabling interrupts
	sei();

	while(1);
	return 0;
}