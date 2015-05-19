#include "Action.h"

//constructors

// Called 20 times when a scenario object is created.
// Values are only place holders until given user input.
Action::Action()
{
	houseCode_ = 0;
	minutes_ = 0;
	unitCode_ = 1;
	commandNo_ = 1;
}

// Called on predefined scenario.
Action::Action(int time, int unit, int commandNo)
{
	houseCode_ = 0;
	setUnit(unit);
	setCommand(commandNo);
	setTime(time);
}


// Set functions(All have a boolean return value used for data validation).


// Sets which electric appliance should get this action.
bool Action::setUnit(int unit)
{
	// Checks if the unit called is 
	// one of our 4 predefined appliances.
	if (unit > 0 && unit < 5)
	{
		unitCode_ = unit;
		return true;
	}
	else
	{
		return false;
	}

}

// Sets what electric appliance should do eg. light, dim and so on.
bool Action::setCommand(int command)
{
	// Checks if the unit called is 
	// one of our 12 commands (only light commands are covered).
	if (command > 0 && command < 13)
	{
		commandNo_ = command;
		return true;
	}
	else
	{
		return false;
	}

}

// Sets when electric appliance should preform the command.
bool Action::setTime(int time)
{
	// checks if time is set between 00.00 to 23.59
	if (time > -1 && time < 1440)
	{
		minutes_ = time;
		return true;
	}
	else
	{
		return false;
	}

}

// Get functions

// Get function used in overridden ostream operator.
int Action::getUnit() const
{
	return unitCode_;
}

// Get function used in overridden ostream operator.
// Returns a string describing the function of the numeric command value
string Action::getCommand() const
{
	switch (commandNo_)
	{
	case 1:
		return "Taend ";
		break;
	case 2:
		return "Sluk ";
		break;
	case 3:
		return "Dim 5% ";
		break;
	case 4:
		return "Dim 15% ";
		break;
	case 5:
		return "Dim 25% ";
		break;
	case 6:
		return "Dim 35% ";
		break;
	case 7:
		return "Dim 45% ";
		break;
	case 8:
		return "Dim 55% ";
		break;
	case 9:
		return "Dim 65% ";
		break;
	case 10:
		return "Dim 75% ";
		break;
	case 11:
		return "Dim 85% ";
		break;
	case 12:
		return "Dim 95% ";
		break;
	default:
		return "null";
	}
}

// Returns time value in minutes from 00.00.
int Action::getTime() const
{
	return minutes_;
}

// Override functions

//Prints Actions object values(used in UI).
ostream &operator<<(ostream &streamRef, const Action &actionRef)
{
	// MM extracts the minutes value.
	int MM = actionRef.getTime() % 60;
	// HH extracts the hour value after being rounded down to closet hour.
	int HH = (actionRef.getTime() - MM) / 60;

	// Formatted action data send to a output stream.
	streamRef << "Time: " << HH << ":" << MM << ", Unit: " << actionRef.getUnit()
		<< ", Command: " << actionRef.getCommand() << endl;

	return streamRef;
}