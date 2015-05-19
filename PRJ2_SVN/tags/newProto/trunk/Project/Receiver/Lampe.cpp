#include <avr/interrupt.h>
#include <string.h>
#include "Lampe.h"

Lampe myLampe;

Lampe::Lampe(){
	
	DDRB  |= ( 1 << 3 );
	TCCR0 |= ( 1 << WGM00 ) | ( 1 << COM01 ) | ( 1 << CS01 );
	OCR0  = 0;
	TCNT0 = 0;
	
}

Lampe * getMyLampe(){
	return &myLampe;
}

void Lampe::turnOn(){
	OCR0 = 255;
}

void Lampe::turnOff(){
	OCR0 = 0;
}

void Lampe::dim(unsigned char light){
	
	switch (light)
	{
		case 1 : OCR0 = 13;
		break;
		case 2 : OCR0 = 38;
		break;
		case 3 : OCR0 = 64;
		break;
		case 4 : OCR0 = 89;
		break;
		case 5 : OCR0 = 115;
		break;
		case 6 : OCR0 = 140;
		break;
		case 7 : OCR0 = 166;
		break;
		case 8 : OCR0 = 191;
		break;
		case 9 : OCR0 = 217;
		break;
		case 10 : OCR0 = 242;
		break;
		default : OCR0 = 0;
		break;
	}
	
}