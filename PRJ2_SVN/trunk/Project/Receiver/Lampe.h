/*
 * Lampe.h
 *
 * Created: 2014-12-03 11:28:57
 *  Author: Kristian Søgaard
 */ 

#ifndef LAMPE_H_
#define LAMPE_H_

class Lampe{
public:
	Lampe();
	void turnOn();	         //method for turning on lamp
	void turnOff();	         //method for turning off lamp
	void dim(unsigned char light); //Set light level between 5-95% in steps of 10%
private:
};

Lampe * getMyLampe();


#endif /* LAMPE_H_ */