/*
 * Action.cpp
 *
 * Created: 2014-11-21 12:54:39
 *  Author: Kristian Thomsen
 */ 

#include "Action.h"
#include "TxUART.h"

#define Actiondebugging false

Action::Action(unsigned char house, unsigned char unit, unsigned char command, unsigned int time){
	this->time = time;
	this->unit = unit;
	this->command = command;
	this->houseCode = house;	
}

void Action::setAction(unsigned char unit, unsigned char command, unsigned int time){
	if (Actiondebugging){
		getMyTxUART()->sendString("setAction called..\n\r");
	}
	if ((unit == 1) || (unit == 2)){
		this->houseCode = 1;
		this->unit = unit;
	}
	else if (unit == 4){
		this->houseCode = 2;
		this->unit = unit;
	}
	else if (unit == 8){
		this->houseCode = 3;
		this->unit = unit;
	}
	else{
		this->unit = 0;
		this->houseCode = 0;
	}

	if (Actiondebugging){
		getMyTxUART()->sendString("Unit = ");
		getMyTxUART()->sendNumber(unit);
		getMyTxUART()->sendString("\n\r");
	}
	
	if (command <= 11){
		this->command = command;
	}
	else{
		this->command = 0;
	}
	if (Actiondebugging){
		getMyTxUART()->sendString("Command = ");
		getMyTxUART()->sendNumber(command);
		getMyTxUART()->sendString("\n\r");
	}
			
	if (time < 1440){
		this->time = time;
	}
	else this->time = 0;
	if (Actiondebugging){
		getMyTxUART()->sendString("Time = ");
		getMyTxUART()->sendNumber(time);
		getMyTxUART()->sendString("\n\r");
	}
}

unsigned char Action::getHouseCode(){
	return houseCode;
}

unsigned char Action::getUnit(){
	return unit;
}

unsigned char Action::getCommand(){
	return command;
}

unsigned char Action::getTimeH(){
	return time >> 8;
}

unsigned char Action::getTimeL(){
	return time;
}

unsigned int Action::getTime(){
	return time;
}