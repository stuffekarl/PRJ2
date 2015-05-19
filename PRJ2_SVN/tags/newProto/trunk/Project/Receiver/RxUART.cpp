/*
 * TxUART.cpp
 *
 * Created: 25/11/2014 20:59:17
 *  Author: David jensen.
 */ 

#include <avr/interrupt.h>
#include <string.h>
#include "RxUART.h"

RxUART myRxUART;

RxUART::RxUART(){
	DDRD = DDRD | 0b00000010; //TxD as output.
	UCSRB = 0b10011000;	//7: RX interrupt enabled, 6: TX int disabled, 5: data empty int enable, 4: RX enabled, 3: TX enabled, 2: char size 8
	UCSRC = 0b10000110;	//7: UCSRC select, 6: assync, 5-4: no parity, 3: 1 stopbit, 2-1: 8 bit char size, 1: sync mode trigger, write 0 when async
	UBRRH = 0x00;		// see below:
	UBRRL = 0b00010111;	// UBRR = (fosc/(16*BAUD))-1     , fosc = 3.6864*10^6,  BAUD = 9600 UBRR = 23 = H:00000000 L:00010111. 	
}

RxUART * getMyRxUART(){
	return &myRxUART;
}

void RxUART::txInt(){
	
}

void RxUART::sendChar(char sendMe){
	while(!(UCSRA & 0b00100000));
	UDR = sendMe;
}

void RxUART::sendString(const char * sendMe){
    while (*sendMe != '\0'){
        sendChar(*sendMe);
        sendMe++;
    }
}

void RxUART::sendNumber(int sendMe){
	sendChar(((sendMe / 1000)%10)+48);
	sendChar(((sendMe / 100)%10)+48);
	sendChar(((sendMe / 10)%10)+48);
	sendChar(((sendMe)%10)+48);
}

ISR(USART_TXC_vect){
	myRxUART.txInt();
}