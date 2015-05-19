/*
 * Transmitter.h
 *
 * Created: 2014-11-27 12:12:34
 *  Author: Kristian Thomsen
 * Empty class for testing purposes - to be used with UART_test and TxUART class.
 */ 

#ifndef TRANSMITTER_H_
#define TRANSMITTER_H_

class Transmitter{
    public:
	char dataCounter;
	char mode;
	Transmitter(){
		dataCounter = 0;
		mode = 'i';
	}
    void scenData(char){
		dataCounter++;
		if (dataCounter == 80){
			mode = 'i';
		}
	}
	void newScen(void){
		mode = 'r';
		dataCounter = 0;
	}
	bool getLockStatus(void){
		return true;
	}
	void stopAll(){
		mode = 's';
	}
};

#endif /* TRANSMITTER_H_ */