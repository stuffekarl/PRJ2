/*
 * Transmitter.cpp
 *
 * Created: 2014-11-27 13:32:54
 *  Author: Kristian Thomsen
 */ 

#include "Transmitter.h"
#include "Action.h"
#include "Tx10.h"
#include "Time.h"
#include "Codelock.h"
#include "TxUART.h"

#define Transdebugging false //set to true to enable debugging

Transmitter myTrans;

Transmitter * getMyTrans(){
	return &myTrans;
}

 Transmitter::Transmitter(){
    charCounter = 0;
	scenCounter = 0;
	
	for (int i = 0; i < 20; i++){
		myScenario[i].setAction(0,0,0);
	}
 }

 void Transmitter::scenData(char input){
	if (charCounter == 1){		//Check the first block, which is the unit
		if (input == 'A'){		//Lamp1
			tempUnit = 1;
		}
		else if (input == 'C'){ //Lamp2
			tempUnit = 2; 
		}
		else if (input == 'P'){ //TV
			tempUnit = 4; 
		}
		else if (input == 'N'){ //Radio
			tempUnit = 8; 
		}
		else tempUnit = 0;
	}
	else if (charCounter == 2){			//Check the second block, the command
		if (input > 'A' && input < 'J'){ //Dim
			tempCommand = input - 63;
		}
		else if (input == 'T'){			//Turn on
			tempCommand = 1;
		}
		else if (input == 'S'){			//Turn off
			tempCommand = 0;
		}
	}
	else if (charCounter == 3){			//TimeH
		tempTime = input - 48;
		tempTime = tempTime << 8;
	}
	else if (charCounter == 4){			//TimeL
		tempTime |= ((input - 48) << 4);
	}
	else if (charCounter == 5){
		tempTime |= (input - 48);
		charCounter = 0;
		myScenario[scenCounter].setAction(tempUnit, tempCommand, tempTime);
		scenCounter++;
	}
	charCounter++;
	if (scenCounter == 20){
		nextAction = 0;
		myTimePtr->startTime();
	}
}

 void Transmitter::newScen(void){
	charCounter = 1;
	scenCounter = 0;
}

bool Transmitter::getLockStatus(void){
	return myCodelockPtr->unlocked();
}

void Transmitter::stopAll(){
	myTimePtr->stopTime();
	myTx10Ptr->turnAllOff();
}

void Transmitter::checkTime(unsigned int theTime){
	if (Transdebugging){
		getMyTxUART()->sendString("checkTime called.. theTime = ");
		getMyTxUART()->sendNumber(theTime);
		getMyTxUART()->sendString("\n\r");
		getMyTxUART()->sendString("Next action is: ");
		getMyTxUART()->sendNumber(nextAction);
		getMyTxUART()->sendString(" at t = ");
		getMyTxUART()->sendNumber(myScenario[nextAction].getTime());
		getMyTxUART()->sendString("\n\r");

	}
	if (myScenario[nextAction].getTime() == theTime){ //Check to see if the time has past the next action to be sent
		if (firstLoop){					//Check if this is the first recursive call
			breakAt = nextAction;		//Set the breaking point for recursive calls
			firstLoop = false;
		}
		else{
			if (breakAt == nextAction){	//Check if the breaking point has been reached
				firstLoop = true;
				return;					//Break out of the recursive calls, if all the actions in the Scenario have been sent simultaniously
			}
		}
		myTx10Ptr->sendAction(myScenario[nextAction]);
		if (Transdebugging){
			getMyTxUART()->sendString("sendAction called...\n\rnextAction: ");
			getMyTxUART()->sendNumber(nextAction);
			getMyTxUART()->sendString("\n\r");
			getMyTxUART()->sendString("Unit: ");
			getMyTxUART()->sendNumber(myScenario[nextAction].getUnit());
			getMyTxUART()->sendString("\n\r");
			getMyTxUART()->sendString("Command: ");
			getMyTxUART()->sendNumber(myScenario[nextAction].getCommand());
			getMyTxUART()->sendString("\n\r");
		}
		nextAction++;
		if (nextAction == 20){ //If the last action has been sent, queue the first action
			nextAction = 0;
		}
		checkTime(theTime);		//Recursive call, to check if several actions are on the same time.
	}
	else{
		firstLoop = true;
	}
}

void Transmitter::setTimePtr(Time * setMe){
	this->myTimePtr = setMe;
}

void Transmitter::setTx10Ptr(Tx10 * setMe){
	this->myTx10Ptr = setMe;
}

void Transmitter::setCodelockPtr(Codelock * setMe){
	this->myCodelockPtr = setMe;
}

void Transmitter::turnOn1(){
	Action temp;
	temp.setAction(1,1,1000);
	myTx10Ptr->sendAction(temp);
}

void Transmitter::turnOn2(){
	Action temp;
	temp.setAction(2,1,1000);
	myTx10Ptr->sendAction(temp);
}

void Transmitter::turnOff1(){
	Action temp;
	temp.setAction(1,0,1000);
	myTx10Ptr->sendAction(temp);
}

void Transmitter::turnOff2(){
	Action temp;
	temp.setAction(2,0,1000);
	myTx10Ptr->sendAction(temp);
}

void Transmitter::dim1(){
	Action temp;
	temp.setAction(1,5,1000);
	myTx10Ptr->sendAction(temp);
}

void Transmitter::dim2(){
	Action temp;
	temp.setAction(2,5,1000);
	myTx10Ptr->sendAction(temp);
}