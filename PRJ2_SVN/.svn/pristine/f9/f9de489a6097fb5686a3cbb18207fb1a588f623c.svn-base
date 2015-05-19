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

	if (connection.getLockStatus() == false)
	{
		while (1)
		{

			switch (userInterface.drawMainMenu())
			{
				// Opret Scenarie
			case (1):
				
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

					cout << "\nTryk \"S\" for at k\x9Bre nuv\x91rende scenarie.\nTryk p\x86 en anden knap for at forts\x91tte redigering." << endl;
					save = _getch();
				}

				CurrentScen.sortActions();
				connection.sendScen(CurrentScen);

				break;



				// Vælg Scenarie
			case (2): 
				ScenarioNo = userInterface.drawScenList();

				if (ScenarioNo == 1)
				{
					// Tænder lampe 1 kl 18:00
					CurrentScen.getAction(16).setUnit(1);
					CurrentScen.getAction(16).setCommand(1);
					CurrentScen.getAction(16).setTime(1080);

					// Slukker lampe 1 kl 20:00
					CurrentScen.getAction(17).setUnit(1);
					CurrentScen.getAction(17).setCommand(2);
					CurrentScen.getAction(17).setTime(1200);

					// Tænder lampe 1 kl 22:00
					CurrentScen.getAction(18).setUnit(1);
					CurrentScen.getAction(18).setCommand(1);
					CurrentScen.getAction(18).setTime(1320);

					// Slukker lampe 1 kl 00:00
					CurrentScen.getAction(19).setUnit(1);
					CurrentScen.getAction(19).setCommand(2);
					CurrentScen.getAction(19).setTime(0);
				}
				else if (ScenarioNo == 2)
				{
					// Tænder lampe 1 kl 18:00
					CurrentScen.getAction(16).setUnit(1);
					CurrentScen.getAction(16).setCommand(1);
					CurrentScen.getAction(16).setTime(1080);

					// Tænder lampe 2 kl 18:00
					CurrentScen.getAction(17).setUnit(2);
					CurrentScen.getAction(17).setCommand(1);
					CurrentScen.getAction(17).setTime(1080);

					// Slukker lampe 1 kl 00:00
					CurrentScen.getAction(18).setUnit(1);
					CurrentScen.getAction(18).setCommand(2);
					CurrentScen.getAction(18).setTime(0);

					// Slukker lampe 2 kl 00:00
					CurrentScen.getAction(19).setUnit(2);
					CurrentScen.getAction(19).setCommand(2);
					CurrentScen.getAction(19).setTime(0);
				}
				else
				{
					// Tænder lampe 1 kl 20:00
					CurrentScen.getAction(17).setUnit(1);
					CurrentScen.getAction(17).setCommand(1);
					CurrentScen.getAction(17).setTime(1200);

					// Slukker lampe 1 kl 00:00
					CurrentScen.getAction(19).setUnit(1);
					CurrentScen.getAction(19).setCommand(2);
					CurrentScen.getAction(19).setTime(0);
				}

				connection.sendScen(CurrentScen);
				
				break;



				// Stop Scenarie
			case (3):
				if (userInterface.drawStopPrompt())
				{
					connection.stopAll();
				}

				break;
			}
		}
	}
}