/*
 * Time.h
 *
 * Created: 2014-11-26 22:56:21
 *  Author: Kristian Søgaard
 */ 

#pragma once
#ifndef TIME_H_
#define TIME_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "transmitter.h"

extern "C" void TIMER1_COMPA_vect(void) __attribute__ ((signal));

class Time{
 public:
	Time(Transmitter *);
    void startTime();
    void stopTime();
	void sendTime();
    friend void TIMER1_COMPA_vect(void);
 private:
    Time * myTimePtr;
	volatile unsigned int seconds;
};

#endif /* TIME_H_ */