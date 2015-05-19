#include "Receiver.h"
#include "StkSwitch.h"
#include "Rx10.h"
#include "RxUART.h"
#include "Lampe.h"

int main(){
		
	char key = 0;
	StkSwitch myStkSwitch;
	
	while(key == 0){
		//Stays in here until one of the two buttons is pushed
		if(myStkSwitch.switchOn(0x01)){
			key = 1;
		}
		else if (myStkSwitch.switchOn(0x02)){
			key = 2;
		}
	}
	// Setting up the pointers for use.
	Receiver * myReceiverPtr = getMyReceiver(); 
	//Setting unitCode via Receiverpointer.
	myReceiverPtr->setUnitcode(key); 
	
	//Setting up relation between Rx10 and RxUART
	Rx10* myRx10Ptr = getMyRx10();
	RxUART* myRxUARTPtr = getMyRxUART();
	
	myRx10Ptr->setRxUAR(*myRxUARTPtr);
	myReceiverPtr->setLampePtr( *getMyLampe());  //myReceiverPtr->setLampePtr(LampePtr), LampePtr fås før dette funktionskald
	
	// Enable interrupts
	sei();
	
	while(1){
		
	}
	
	return 0;
}