#pragma once
#include <iostream>
#include <Vector>
#include "Action.h"

using namespace std;

class Scenario
{
public:
	Scenario();
	Action& getAction(int);
	vector<Action>  sortActions(vector<Action>);
private:
	vector<Action> scen_;
};

ostream &operator<<(ostream &, Scenario &);