/*
 * debounce.h
 *
 *  Created on: 21 abr. 2020
 *      Author: jorge
 */

#ifndef PDM_TRABAJOS_SEMAPHORE_INC_DEBOUNCE_H_
#define PDM_TRABAJOS_SEMAPHORE_INC_DEBOUNCE_H_

#include "sapi.h"

/*=====[Inclusions of public function dependencies]==========================*/

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/
typedef enum {
	UP,
	FALLING,
	DOWN,
	RISING
} debounce_state_t;

typedef struct {
	bool_t keyPressed;
	bool_t buttonReleased;
	gpioMap_t button;
	debounce_state_t buttonState;
	delay_t buttonFSMdelay;
} debounce_button_t;

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/
void fsm_debounceError( void );

void fsm_debounceInit( debounce_button_t  * pButton, gpioMap_t button );

void fsm_debounceUpdate( debounce_button_t  * pButton );

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* PDM_TRABAJOS_SEMAPHORE_INC_DEBOUNCE_H_ */

