#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <Windows.h>
#include <time.h>




#include "rs232.h"
#include "Scenario.h"

using namespace std;
class UART
{
public:
	UART()
	{

	}

	void UART_connect()
	{
		char mode[] = { '8', 'N', '1', 0 },
			str[20][5];
		cout << "leder efter gyldig port\n";
		//inialitisere og finder gyldig Comport ved at loope igennem alle com-porte
		while (RS232_OpenComport(cport_nr, bdrate, mode))
		{

			printf("ugyldig Com-port\n");
			cport_nr++;

		

		}
		cout << "port: " << cport_nr << " aaben\n";
	}
	bool getLockStatus()
	{

		/* FOR TESTING PURPOSES ONLY*/

		return 0;

		/* FOR TESTING PURPOSES ONLY  END*/

		RS232_cputs(cport_nr, "L");

		unsigned char buf[2];
		char mode[] = { '8', 'N', '1', 0 };
		int n = RS232_PollComport(cport_nr, buf, 4095);

			while(1)
			{
		

			if (n > 0)
			{
				buf[n] = 0;  //null sættes som afsluttende bit

				for (int i = 0; i < n; i++)
				{
					if (buf[i] < 32)  /* replace unreadable control-codes by dots */
					{
						buf[i] = '.';
					}
				}

				printf("received %i bytes: %s\n", n, (char *)buf);

				if (buf[0] == 'U')
				{
					return 0;
				}
				else if (buf[0] == 'L')
				{
					return 1;
				}
				
			}

			Sleep(100);
			
			}

	}
	void sendScen(Scenario &scen)
	{
		char mode[] = { '8', 'N', '1', 0 },
			str[20][5];

		sent = 1;
		while (sent)
		{

			RS232_cputs(cport_nr, "N");


			Action & action = scen.getAction(c);
			action.setTime(791);
		

			//fejlfinding
			cout << action.getCommand() << " " << action.getUnit() << " " << action.getTime() << "" << endl;
			//fejlfinding end
			
			char command = action.getCommand();
			char unit;
			char TimeLow, TimeHigh;


			//tidsscope
			{

				//udregner tiden til den gældne commando skal ekseveres
				int timeTillExecution;
				if (action.getTime() >= Ctime())
				{
					timeTillExecution = action.getTime() - Ctime();
				}
				else
				{ 
					timeTillExecution = 1440 - (Ctime()-action.getTime()); 
				}
				//tager sig af at omregne tiden fra int til char og dele tiden op i 2 chars, da den kan ske at fylde mere end 8 bit
				int timeL = timeTillExecution % 256; 
				int timeH = int((floor(timeTillExecution / 256)));

				TimeLow = ((char)timeL);
			
				TimeHigh = ((char)timeH);
			}


			switch (action.getUnit()) // tager sig af at oversætte unit til at følge UART protocollen
			{
			case 1:
				unit = 'A';
				break;
			case 2:
				unit = 'C';
				break;
			case 3:
				unit = 'P';
				break;
			case 4:
				unit = 'N';
				break;
			default: 
				unit = '0';
				break;

			}

			char data[5] = { unit, command, TimeLow, TimeHigh }; // data der skal sendes over
			strcpy(str[c], data);
			RS232_cputs(cport_nr, str[c]); //funktion fra rs232 biblioteket til at sende  data ud på porten


			//udskrivning af sendt data;
			printf("sendt data: %s\n", str[c]);


			Sleep(1000);



		
			c++;
			if (c == 20)
			{
				printf("Transmission fuldfoert\n");
				c = 0;
				sent = 0;
				break;
				
			}
		}

	}
	void stopAll()
	{
		RS232_cputs(cport_nr, "S");
	}


private:
	bool sent = 1;
	int c = 0;
	int	cport_nr = 0;
	int bdrate = 9600;     

	int Ctime()
	{


			time_t tid;
			time(&tid);


			struct tm *mytime = localtime(&tid);

			int timesince00 = mytime->tm_min + (mytime->tm_hour * 60);

			return timesince00;

		}


};

