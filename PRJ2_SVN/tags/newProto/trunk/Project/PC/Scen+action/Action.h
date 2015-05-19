#include <iostream>
#include <String>

using namespace std;

class Action
{
public:

	//constructors

	Action::Action()
	{
		minutes_ = 0;
		unitCode_ = 1;
		command_ = 'S';
	}

	Action::Action(int time, int unit, int commandNo)
	{
		setUnit(unit);
		setCommand(commandNo);
		setTime(time);
	}

	// Set functions


	bool Action::setUnit(int unit)
	{

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

	bool Action::setCommand(int command)
	{
		if (command > 0 && command < 13)
		{
			switch (command)
			{
			case 1:
				command_ = 'T';
				break;
			case 2:
				command_ = 'S';
				break;
			case 3:
				command_ = 'A';
				break;
			case 4:
				command_ = 'B';
				break;
			case 5:
				command_ = 'C';
				break;
			case 6:
				command_ = 'D';
				break;
			case 7:
				command_ = 'E';
				break;
			case 8:
				command_ = 'F';
				break;
			case 9:
				command_ = 'G';
				break;
			case 10:
				command_ = 'H';
				break;
			case 11:
				command_ = 'I';
				break;
			case 12:
				command_ = 'J';
				break;
			default:
				break;
			}

			return true;
		}
		else
		{
			return false;
		}

	}

	bool Action::setTime(int time)
	{

		if (time > -1 && time < 1440) // checks if time is set between 00.00 to 23.59
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


	int Action::getUnit() const
	{
		return unitCode_;
	}

	char Action::getCommand() const
	{
		return command_;
	}

	int Action::getTime() const
	{
		return minutes_;
	}

	// Override functions
	
	//Used to compare action objects in sort based on its time value
	bool Action::operator <(const Action& a) const {
		if (this->getTime() < a.getTime())
			return true;
		else
			return false;
	}

private:
	int minutes_;
	int unitCode_;
	char command_;
};


// Override functions

ostream &operator<<(ostream &streamRef, const Action &ActionRef)
{

	int MM = ActionRef.getTime() % 60;
	int HH = (ActionRef.getTime() - MM) / 60;

	string command;

	switch (ActionRef.getCommand())
	{
	case 'T':
		command = "Taend ";
		break;
	case 'S':
		command = "Sluk ";
		break;
	case 'A':
		command = "Dim 5% ";
		break;
	case 'B':
		command = "Dim 15% ";
		break;
	case 'C':
		command = "Dim 25% ";
		break;
	case 'D':
		command = "Dim 35% ";
		break;
	case 'E':
		command = "Dim 45% ";
		break;
	case 'F':
		command = "Dim 55% ";
		break;
	case 'G':
		command = "Dim 65% ";
		break;
	case 'H':
		command = "Dim 75% ";
		break;
	case 'I':
		command = "Dim 85% ";
		break;
	case 'J':
		command = "Dim 95% ";
		break;
	default:
		command = "Ingen kommando ";
		break;
	}

	streamRef << "Time: " << HH << ":" << MM << ", Unit: " << ActionRef.getUnit()
		<< ", Command: " << command << endl;

	return streamRef;
}