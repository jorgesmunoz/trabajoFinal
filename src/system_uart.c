/*
 * system_uart.c
 *
 *  Created on: 22 abr. 2020
 *      Author: jorge
 */

/*=====[Inclusion of own header]=============================================*/

#include "sapi.h"
#include "system_uart.h"

/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/
void system_uartInit( uartMap_t uart, uint32_t baudRate){
	uartConfig( uart, baudRate );
}

void system_uart_WriteString( uartMap_t uart, const char* str ){
	uartWriteString( uart, str);
}

bool_t system_uart_ReadByte( uartMap_t uart, uint8_t* receivedByte ){
	if(uartReadByte( uart, &receivedByte )){
		return TRUE;
	}
	else
		return FALSE;
}

void system_uart_WriteByte( uartMap_t uart, const uint8_t value ){
	uartWriteByte( uart, value );
}



