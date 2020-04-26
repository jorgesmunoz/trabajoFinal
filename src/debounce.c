/*
 * debounce.c
 *
 *  Created on: 21 abr. 2020
 *      Author: jorge
 */


/*=====[Inclusion of own header]=============================================*/

#include "sapi.h"
#include "debounce.h"
#include "semaphore.h"
#include "leds.h"


/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/
#define INITIAL_DEFAULT_MODE UP
#define DEBOUNCE_TIME 40

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/
void fsm_debounceError( void ){

}

void fsm_debounceInit( debounce_button_t  * pButton, gpioMap_t button ){
	pButton->buttonState = INITIAL_DEFAULT_MODE;
	pButton->keyPressed = FALSE;
	pButton->buttonReleased = TRUE;
	pButton->button = button;
}

void fsm_debounceUpdate( debounce_button_t  * pButton ){
	switch(pButton->buttonState){
	case UP:
		pButton->keyPressed = FALSE;
		if(!gpioRead(pButton->button)){
			delayInit(&pButton->buttonFSMdelay, DEBOUNCE_TIME);
			pButton->buttonState = FALLING;
		}
		break;
	case FALLING:
		pButton->buttonReleased = TRUE;
		if(delayRead(&pButton->buttonFSMdelay)){
			if(!gpioRead(pButton->button)){
				pButton->buttonState = DOWN;
			}
			else
				pButton->buttonState = UP;
		}
		//else
		//	pButton->buttonState = UP;
		break;
	case DOWN:
		pButton->buttonReleased = FALSE;
		if(gpioRead(pButton->button)){
			delayInit(&pButton->buttonFSMdelay, DEBOUNCE_TIME);
			pButton->buttonState = RISING;
		}
		break;
	case RISING:
		if(delayRead(&pButton->buttonFSMdelay)){
			if(gpioRead(pButton->button)){
				pButton->buttonState = UP;
				pButton->keyPressed = TRUE;
			}
			else
				pButton->buttonState = DOWN;
		}
		//else
		//	pButton->buttonState = DOWN;
		break;
	default:
		fsm_debounceError();
	}
}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/
