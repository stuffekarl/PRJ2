/*
 * Transmitter.h
 *
 * Created: 2014-12-04 15:04:22
 *  Author: Snufkin
 */ 


#ifndef TRANSMITTER_H_
#define TRANSMITTER_H_

#include <avr/io.h>

class Transmitter{
public: 
	void checkTime(unsigned int thetime){
		PORTC = ~PINC;
	}
	void stopAll(){}
	void scenData(unsigned char){}
	void newScen(){}
	bool getLockStatus(){return true;}
};



#endif /* TRANSMITTER_H_ */