/*
 * TxUART.cpp
 *
 * Created: 25/11/2014 20:59:17
 *  Author: Kristian Thomsen
 */ 

#include <avr/interrupt.h>
#include <string.h>
#include "TxUART.h"
#include "Transmitter.h"

TxUART myTxUART;

TxUART * getMyTxUART(){
	return &myTxUART;
}

TxUART::TxUART(){
	mode = 'i'; //idle
	charNo = 0;
	DDRD = DDRD | 0b00000010; //TxD as output.
	DDRD = DDRD & 0b11111110; // RxD as input
	UCSRB = 0b10011000;	//7: RX interrupt enabled, 6: TX int disabled, 5: data empty int enable, 4: RX enabled, 3: TX enabled, 2: char size 8
	UCSRC = 0b10000110;	//7: UCSRC select, 6: assync, 5-4: no parity, 3: 1 stopbit, 2-1: 8 bit char size, 1: sync mode trigger, write 0 when async
	UBRRH = 0x00;		// see below:
	UBRRL = 0b00010111;	// UBRR = (fosc/(16*BAUD))-1     , fosc = 3.6864*10^6,  BAUD = 9600 UBRR = 23 = H:00000000 L:00010111. 	
}


void TxUART::rxInt(){
	char input = UDR;
	if (mode == 'i'){
		if (input == 'L'){
			bool temp = myTrans->getLockStatus();
			if (temp)
				sendChar('U');
			else
    			sendChar('L');
		}
		else if (input == 'N'){
			mode = 'r'; //put in receiving mode
			myTrans->newScen();
		}
		else if (input == 'S'){
			myTrans->stopAll();
		}
	}
	else if (mode == 'r'){
		if (charNo <= 80){
			myTrans->scenData(input);
			charNo++;
		}
		if (charNo == 80){ //end of data
			charNo = 0; //reset counter
			mode = 'i'; //put in idle mode
		}
	}
}

void TxUART::txInt(){
	
}

void TxUART::sendChar(char sendMe){
	while(!(UCSRA & 0b00100000));
	UDR = sendMe;
}

void TxUART::sendString(const char * sendMe){
    while (*sendMe != '\0'){
        sendChar(*sendMe);
        sendMe++;
    }
}

void TxUART::sendNumber(unsigned int sendMe){
	sendChar(((sendMe / 1000)%10)+48);
	sendChar(((sendMe / 100)%10)+48);
	sendChar(((sendMe / 10)%10)+48);
	sendChar(((sendMe)%10)+48);
}

void TxUART::setTrans(Transmitter * setMe ){
	myTrans = setMe;
}

ISR(USART_RXC_vect){
	myTxUART.rxInt();
}

ISR(USART_TXC_vect){
	myTxUART.txInt();
}