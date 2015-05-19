/*
 * Action.h
 *
 * Created: 2014-11-21 12:54:48
 *  Author: Kristian Thomsen
 */ 

#ifndef ACTION_H_
#define ACTION_H_

class Action{
public:
	Action();
	void setAction(unsigned char unit, unsigned char command, unsigned int time);
	unsigned char getHouseCode();
	unsigned char getUnit();
	unsigned char getCommand();
	unsigned char getTimeH();
	unsigned char getTimeL();
	unsigned int getTime();
private:
	unsigned int time;
	unsigned char unit;
	unsigned char command;
	unsigned char houseCode;
};

#endif /* ACTION_H_ */