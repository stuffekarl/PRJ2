/*
 * Receiver.h
 *
 * Created: 02/12/2014 20:52:46
 *  Author: Lasse
 */ 
#ifndef _Receiver_H
#define _Receiver_H

#include "Lampe.h"

class Receiver{
public:
	Receiver();
	void input(char, char, char);
	void setUnitcode(char);
	void setLampePtr( Lampe &setme);
	
private:
	int houseCode_ = 1;
	int unitCode_;
	int CurrentDim_ = '11';
	//This is necessary for interaction with the lamp.
	Lampe * myLampePtr;		
};

Receiver * getMyReceiver();		

#endif 