#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Scenario.h" //inkludere scenarie for at kunne bruge den til udskrift

using namespace std;

class UI
{
public:
	UI()
	{
		NULL;
	}
	int drawMainMenu()
	{
		int pick;
		system("cls");
		cout << "\t\t\t" << "Home Automation System\n\n" << endl;
		cout << "Indtast nummeret til venstre for den \x9Bnskede menu, efterfulgt af et ENTER\n\n";

		cout << "1. Nyt Scenarie\n\n";

		cout << "2. K\x9Br forudindstillet Scenarie\n\n";

		cout << "3. Stop Scenarie \n\n";

		while (1)
		{ 
			cin >> pick;
			if (pick >= 1 && pick <= 3) // tjekker at input værdien er indenfor gyldige grænser
				return pick;
			else
				cout << "ugyldig menu, pr\x9Bv igen: ";
			cin.clear();
			fflush(stdin);//clear og flusher alt gemt i keyboard bufferen

		}
	}
	int drawScenario(Scenario & Scen) // henter reference til Scenariet
	{
		
		int pick;
		
		system("cls"); // cleare skærmen
		cout << "\t\t\t" << "Action Selection\n\n\n";
		cout << " v\x91lg det \x9Bnskede aktion at redigere i ved indtaste nummeret til  venstre\n";

		cout << Scen; // ostream overload operater bruges til udskrivning af scenarie

		while (1)
		{
			
			
			cin >> pick;
			if (pick >= 0 && pick <= 19)
				return pick;
			else
				cout << "\nugyldig aktion, pr\x9Bv igen: ";
			
			cin.clear();
			fflush(stdin);//clear og flusher alt gemt i keyboard bufferen
		
		}
	}
	int drawAskUnits()
	{
		int pick;
		system("cls");// cleare skærmen
		cout << "\t\t\t" << "Unit Selection\n\n\n";
		cout << "Indtast nummeret til venstre for den \x9Bnskede unit, efterfulgt af et ENTER\n\n";


		cout << "1. Lampe 1\n\n";

		cout << "2. Lampe 2\n\n";

		cout << "3. TV (ikke funktionel)\n\n";

		cout << "3. Radio (ikke funktionel)\n\n";

		while (1)
		{
			cin >> pick;
			if (pick >= 1 && pick <= 2)
				return pick;
			else
				cout << "ugyldig unit, pr\x9Bv igen: ";
			cin.clear();
			fflush(stdin);//clear og flusher alt gemt i keyboard bufferen
		}
	}
	int drawAskCommand()
	{
		int pick;
		int dim;
		system("cls");// cleare skærmen
		cout << "\t\t\t" << "Command Selection\n\n\n";
		cout << "Indtast nummeret til venstre for den \x9Bnskede kommando, efterfulgt af et ENTER\n\n";


		cout << "1. T\x91nd\n\n";

		cout << "2. Sluk\n\n";

		cout << "3. Dim\n\n";


		while (1)
		{
			cin >> pick;
			if (pick >= 1 && pick <= 2) // tjekker at værdien er indenfor gyldige grænser
				return pick;
			else if (pick == 3) // anden funktionalitet for en gyldig værdi
			{
				
				cout << "\n vælg dimming niveau: (5%-95%) i hele 10'er: 5% = 1, 15% = 2, 25% = 3\n\n";
				cin >> dim;
				if (dim >= 1 && dim <= 10)
					return dim + 2;
				else

					"ugyldig Dimming, prøv kommando igen:\n ";
				cin.clear();
				fflush(stdin);//clear og flusher alt gemt i keyboard bufferen
				
			}
			else
				cout << "ugyldig kommando, pr\x9Bv igen: ";
			cin.clear();
			fflush(stdin);//clear og flusher alt gemt i keyboard bufferen
		}
	}
	int drawAskTime() 
	{
		int hour;
		int min;
		while (1) //evighedløkke der kun afsluttes når der returneres noget.
		{ 
			system("cls");// cleare skærmen
			cout << "\t\t\t" << "Time Selection\n\n\n";

			cout << "indtast \x9Bnskede time(0-23) til udf\x9Brelse af kommando: ";
			cin >> hour;
			cout << "indtast \x9Bnskede minuttal(0-59) på timen til udf\x9Brelse af kommando : ";
			cin >> min;

			if (hour >= 0 && hour <= 23 && min >= 0 && min <= 59)
				return (hour * 60 + min); // returnere tiden sidne kl 00
			else
				cout << "ugyldig tid, pr\x9Bv igen";
			
			cin.clear();
			fflush(stdin); //clear og flusher alt gemt i keyboard bufferen
			_getch(); //venter på hvilket somhelst tryk på keyboard

		}


	}
	int drawScenList()
	{
		int pick;
		system("cls"); // cleare skærmen
		cout << "\t\t\t forudindstillede scenarier \n\n\n";

		cout << "V\x91lg en af 3 forudindstillede scenarier\n\n";

		cout << "1. Scenariet t\x91nder en lampe kl 11.25, slukker kl 11.27, og t\x91nder igen kl 11.29 og slukker kl 11.31\n\n";

		cout << "2. Scenariet t\x91nder to lamper kl 18 og slukker for begge igen kl 00\n\n";

		cout << "3. Scenariet t\x91nder en lampe kl 20, slukker kl 00\n\n";


		while (1)
		{
			cin >> pick;
			if (pick >= 1 && pick <= 3)
				return pick;
			else
				cout << "ugyldig scenarie: ";
			cin.clear();
			fflush(stdin);//clear og flusher alt gemt i keyboard bufferen
		}
	}
	bool drawStopPrompt()
	{
		system("cls");// cleare skærmen

		char get;
		cout << "er du sikker på du vil stopp scenariet? : tryk (Y) hvis du er sikker";
		get = _getch(); //får ascii værdien på knappen der er trykket på keyboardet
		if (get == 89 || get == 121) // ascii værdi for y og Y
			return true;
		else
			return false;


	}

private:

};
