/*
 * Time.h
 *
 * Created: 2014-11-27 15:32:45
 *  Author: Kristian Thomsen
 * Empty class for testing of Transmitter class
 */ 


#ifndef TIME_H_
#define TIME_H_

class Time
{
public:
	Time(){
		//DDRD = DDRD & 0b11110111; // PD3/INT1 as input
		//MCUCR = MCUCR | 0b00001100; //interrupt on falling edge of INT1
		//GICR = GICR | 0b10000000; // INT1 enabled
	}
	void stopTime(){}
	void startTime(){}
private:
	
};

Time * getMyTime();

#endif /* TIME_H_ */