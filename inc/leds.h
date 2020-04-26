/*
 * leds.h
 *
 *  Created on: 21 abr. 2020
 *      Author: jorge
 */

#ifndef PDM_TRABAJOS_SEMAPHORE_INC_LEDS_H_
#define PDM_TRABAJOS_SEMAPHORE_INC_LEDS_H_

#include "sapi.h"

typedef gpioMap_t lamp_t;

void turnOn(lamp_t lamp);
void turnOff(lamp_t lamp);
void blink(lamp_t lamp);

#endif /* PDM_TRABAJOS_SEMAPHORE_INC_LEDS_H_ */
