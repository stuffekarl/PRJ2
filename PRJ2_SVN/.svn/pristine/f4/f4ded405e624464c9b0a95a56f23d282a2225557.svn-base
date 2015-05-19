/*
 * ActionTest.cpp
 *
 * Created: 2014-11-21 12:54:57
 *  Author: Snufkin
 */ 

#include <avr/io.h>
#include "Tx10.h"
#include "Action.h"

Tx10 * getMyTx10();

int main(){
	Tx10 * myTx10 = getMyTx10();
	Action Scenario[20];

	Scenario[0].setAction(1, 1, 1);
	Scenario[1].setAction(2, 1, 2);
	Scenario[2].setAction(1, 5, 3);
	
	DDRC = 0xFF;
	myTx10->sendAction(Scenario[2]);
	sei();
	while(1);
	return 0;
}