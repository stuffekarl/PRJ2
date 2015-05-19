﻿/********************************************************
* "SWITCH.C":                                           *
* Implementation file for the STK500 SWITCH PORT driver.*
* The SWITCHES are connected to the PA pins.            *
* Henning Hargaard, 27/9 2011							*
* Modified by Lasse and David						    *
*********************************************************/
#include "StkSwitch.h"

#define MAX_SWITCH_NR 7

// Klargør switch-porten
StkSwitch::StkSwitch()
{
	// Switch-port = All inputs
	DDRA = 0;
}

// Læser alle switches samtidigt
unsigned char StkSwitch::switchStatus()
{
	return (~PINA);
}

// Returnerer TRUE, hvis switchen med nummeret
// "switch_nr" er aktiveret - ellers returneres FALSE
unsigned char StkSwitch::switchOn(unsigned char switch_nr)
{
	unsigned char mask;
	if (switch_nr <= MAX_SWITCH_NR)
	{
		mask = 0b00000001 << switch_nr;
		return (~PINA & mask);
	}
	else
	return 0;
}