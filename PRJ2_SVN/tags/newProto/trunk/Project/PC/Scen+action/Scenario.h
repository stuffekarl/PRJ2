
#include <iostream>
#include <Vector>
#include <algorithm>
#include "Action.h"

using namespace std;

class Scenario
{
public:
	// Constructor

	// Creates 20 Action's with dafault values.
	Scenario::Scenario()
	{
		scen_.assign(20, Action());
	}

	// Returns a refence to an action object based on its place in the vector.
	// E.g s.getAction(3) gives the third action object created.
	Action& Scenario::getAction(int ActionNo)
	{
		return scen_[ActionNo];
	}

	//Sorts a Scenario's actions based on each actions time value from low to high.
	void Scenario::sortActions()
	{
		sort(scen_.begin(), scen_.end());
	}

private:
	vector<Action> scen_;
};

// Override function for printing a Scenario.
inline ostream &operator<<(ostream &streamRef, Scenario &scenRef)
{

	for (int i = 0; i < 20; i++)
	{
		streamRef << i << ": " << scenRef.getAction(i);
	}

	return streamRef;
}