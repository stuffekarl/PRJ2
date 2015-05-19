#include <iostream>
#include "Action.h"
#include "Scenario.h"
#include "UART.h"
#include "UI.h"

using namespace std;

int main()
{
	UART connection;
	UI userInterface;
	Scenario CurrentScen;
	int ScenarioNo, actionNo, unitNo, commandNo, time;
	char save;

	connection.UART_connect();
	
	while (1)
	{

		if (!connection.getLockStatus())
		{
			while (1)
			{

				switch (userInterface.drawMainMenu())
				{
					// Opret Scenarie
				case (1) :

					save = 0;

					while (save != 's' && save != 'S')
					{
						actionNo = userInterface.drawScenario(CurrentScen);

						unitNo = userInterface.drawAskUnits();
						CurrentScen.getAction(actionNo).setUnit(unitNo);

						commandNo = userInterface.drawAskCommand();
						CurrentScen.getAction(actionNo).setCommand(commandNo);

						time = userInterface.drawAskTime();
						cout << time << endl;
						CurrentScen.getAction(actionNo).setTime(time);

						cout << "\nTryk \"S\" for at sende nuv\x91rende scenarie.\nTryk p\x86 en anden knap for at forts\x91tte redigering." << endl;
						save = _getch();
					}

					connection.sendScen(CurrentScen);
					CurrentScen.clearActions();

					break;



					// Vælg Scenarie
				case (2) :
					ScenarioNo = userInterface.drawScenList();

					if (ScenarioNo == 1)
					{
						// Tænder lampe 1 kl 18:00
						CurrentScen.getAction(0).setUnit(1);
						CurrentScen.getAction(0).setCommand(1);
						CurrentScen.getAction(0).setTime(685);

						// Slukker lampe 1 kl 20:00
						CurrentScen.getAction(1).setUnit(1);
						CurrentScen.getAction(1).setCommand(2);
						CurrentScen.getAction(1).setTime(687);

						// Tænder lampe 1 kl 22:00
						CurrentScen.getAction(2).setUnit(1);
						CurrentScen.getAction(2).setCommand(1);
						CurrentScen.getAction(2).setTime(689);

						// Slukker lampe 1 kl 00:00
						CurrentScen.getAction(3).setUnit(1);
						CurrentScen.getAction(3).setCommand(2);
						CurrentScen.getAction(3).setTime(691);
					}
					else if (ScenarioNo == 2)
					{
						// Tænder lampe 1 kl 18:00
						CurrentScen.getAction(0).setUnit(1);
						CurrentScen.getAction(0).setCommand(1);
						CurrentScen.getAction(0).setTime(1080);

						// Tænder lampe 2 kl 18:00
						CurrentScen.getAction(1).setUnit(2);
						CurrentScen.getAction(1).setCommand(1);
						CurrentScen.getAction(1).setTime(1080);

						// Slukker lampe 1 kl 00:00
						CurrentScen.getAction(2).setUnit(1);
						CurrentScen.getAction(2).setCommand(2);
						CurrentScen.getAction(2).setTime(0);

						// Slukker lampe 2 kl 00:00
						CurrentScen.getAction(3).setUnit(2);
						CurrentScen.getAction(3).setCommand(2);
						CurrentScen.getAction(3).setTime(0);
					}
					else
					{
						// Tænder lampe 1 kl 20:00
						CurrentScen.getAction(0).setUnit(1);
						CurrentScen.getAction(0).setCommand(1);
						CurrentScen.getAction(0).setTime(1200);

						// Slukker lampe 1 kl 00:00
						CurrentScen.getAction(1).setUnit(1);
						CurrentScen.getAction(1).setCommand(2);
						CurrentScen.getAction(1).setTime(0);
					}

					connection.sendScen(CurrentScen);
					CurrentScen.clearActions();


					break;



					// Stop Scenarie
				case (3) :
					if (userInterface.drawStopPrompt())
					{
						connection.stopAll();
					}

					break;
				}
			}
		}
		else
		{
			cout << "\nKodelaasen er indstastet forkert" << endl;
		}
	}
}