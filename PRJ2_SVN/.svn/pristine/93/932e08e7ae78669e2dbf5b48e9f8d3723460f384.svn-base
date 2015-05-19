/*
 * Action_test.cpp
 *
 * Created: 2014-11-21 14:13:18
 *  Author: Snufkin
 */ 


#include <avr/io.h>
#include "Action.h"

#define TEST_OBJ 3

int main(){
	DDRC = 0xFF;
	DDRD = 0x00;
	PORTC = 0x00;
	
	Action Scenario[6];
	
	Scenario[0].setAction(0,0,0); //default parameters
	Scenario[1].setAction(1,1,20); // valid parameters
	Scenario[2].setAction(3,12,1523); //invalid parameters
	Scenario[3].setAction(2,3,753); //nice parameters
	
	while(1){
		if (!(PIND & 0b00000001)){
			PORTC = ~Scenario[TEST_OBJ].getUnit();
		}
		else if (!(PIND & 0b00000010)){
			PORTC = ~Scenario[TEST_OBJ].getCommand();
		}
		else if (!(PIND & 0b00000100)){
			PORTC = ~Scenario[TEST_OBJ].getHouseCode();
		}
		else if (!(PIND & 0b00001000)){
			PORTC = ~Scenario[TEST_OBJ].getTimeL();
		}
		else if (!(PIND & 0b00010000)){
			PORTC = ~Scenario[TEST_OBJ].getTimeH();
		}
	}
	return 0;
}