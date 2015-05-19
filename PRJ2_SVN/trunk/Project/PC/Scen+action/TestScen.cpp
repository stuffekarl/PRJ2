#include "Scenario.h"

int main()
{
	Scenario s;

	Action & a1 = s.getAction(0);
	Action & a2 = s.getAction(1);
	Action & a3 = s.getAction(2);

	a1.setUnit(1);
	a1.setCommand(5);
	a1.setTime(625);

	a2.setUnit(2);
	a2.setCommand(8);
	a2.setTime(234);

	a3.setUnit(3);
	a3.setCommand(1);
	a3.setTime(1400);

	cout << s;

	return 0;
}
