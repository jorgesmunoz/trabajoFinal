/*
 * leds.c
 *
 *  Created on: 21 abr. 2020
 *      Author: jorge
 */

#include "leds.h"
#include "sapi.h"

void turnOn(lamp_t lamp){
	gpioWrite( lamp, ON );
}

void turnOff(lamp_t lamp){
	gpioWrite( lamp, OFF );
}

void blink(lamp_t lamp){
	gpioToggle( lamp );
}


