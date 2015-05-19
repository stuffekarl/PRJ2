/*
* File:   Action.h
* Author: Kristian
*
* Created on November 21, 2014, 10:47 AM
*/
#pragma once
#include <iostream>
#include <String>

using namespace std;

class Action
{
public:
	Action();
	Action(int, int, int);
	bool setUnit(int);
	bool setCommand(int);
	bool setTime(int);
	int getUnit() const;
	string getCommand() const;
	int getTime() const;
private:
	int minutes_;
	int houseCode_;
	int unitCode_;
	int commandNo_;
};

ostream &operator<<(ostream &, const Action &);

