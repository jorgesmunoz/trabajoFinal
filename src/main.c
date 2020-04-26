/*
 * main.c
 *
 *  Created on: 21 abr. 2020
 *      Author: jorge
 */

/*=====[Inclusions of function dependencies]=================================*/
#include "main.h"

#include "../inc/fsm_access_system.h"
#include "semaphore.h"
#include "sapi.h"
#include "debounce.h"
#include "leds.h"
#include "system_uart.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
	// ----- Setup -----------------------------------
	system_t systemAccess;

	boardInit();

	//Init sistema de acceso
	fsm_systemInit(&systemAccess);

	// ----- Repeat for ever -------------------------
	while( TRUE ) {

		fsm_systemUpdate( &systemAccess );
}

	// YOU NEVER REACH HERE, because this program runs directly or on a
	// microcontroller and is not called by any Operating System, as in the
	// case of a PC program.
	return 0;
}



