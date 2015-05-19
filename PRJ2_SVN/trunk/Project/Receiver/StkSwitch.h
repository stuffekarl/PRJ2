/**********************************************************
* "SWITCH.H":                                             *
* Header file for STK500 SWITCH panel driver (8 switches).*
* The SWITCH panel is connected to the PA pins.           *
* Henning Hargaard, 27/9 2011                             *
* Modified by Lasse and David							  *
***********************************************************/
#include <avr/io.h>

class StkSwitch
{
public:
StkSwitch();
unsigned char switchStatus();
unsigned char switchOn(unsigned char switch_nr);
};

/**********************************************************/