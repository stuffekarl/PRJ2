 #include "Scenario.h"

//constructor

Scenario::Scenario()
{
	scen_.assign(20, Action());
}


Action& Scenario::getAction(int ActionNo)
{
	return scen_[ActionNo];
}

vector<Action> Scenario::sortActions(vector<Action> v)
{
	return v;
}


// Override function

ostream &operator<<(ostream &streamRef, Scenario &scenRef)
{

	for (int i = 0; i < 20; i++)
	{
		streamRef << i << ": " << scenRef.getAction(i);
	}

	return streamRef;
}