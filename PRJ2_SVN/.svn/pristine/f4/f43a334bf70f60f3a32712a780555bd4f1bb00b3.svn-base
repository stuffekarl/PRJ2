/*
 * UART_test.cpp
 *
 * Created: 2014-11-27 08:53:15
 *  Author: Kristian Thomsen
 * Test utility for TxUART class, to be used with empty test Class Transmitter.h and TxUART.
 * How to use:
 * Run the software on STK500 with PD0-1 connected to RS232 SPARE
 * Connect RS232 cable to RS232 SPARE and run a terminal program on the PC
 * Input any of the following commands: L, S, N
 * If using N, input 80 chars (data for the scenarios)
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "TxUART.h"
#include "Transmitter.h"



int main(){
	TxUART * myTxUARTPtr = getMyTxUART();
	Transmitter myTrans;
	myTxUARTPtr->setTrans(myTrans);
	char lastMode = 0;
	char lastCount = 0;
	
	sei();
	
	while(1){
		if (myTrans.dataCounter != lastCount){
    		myTxUARTPtr->sendString("Data recieved, charNo: ");
    		myTxUARTPtr->sendNumber(myTrans.dataCounter - 1);
    		myTxUARTPtr->sendString("\n\r");
    		lastCount = myTrans.dataCounter;
		}
		else if (myTrans.mode != lastMode && myTrans.mode == 'i'){
			myTxUARTPtr->sendString("System is in idle mode.\n\r");
			lastMode = 'i';
		}
		else if (myTrans.mode != lastMode && myTrans.mode == 'r'){
			myTxUARTPtr->sendString("System is in receiving mode.\n\r");
			lastMode = 'r';
		}
		else if (myTrans.mode != lastMode && myTrans.mode == 's'){
			myTxUARTPtr->sendString("System is stopping the scenario.\n\r");
			myTrans.mode = 'i';
			lastMode = 's';
		}
	}
	return 0;
}