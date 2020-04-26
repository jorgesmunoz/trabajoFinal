/*
 * system_uart.h
 *
 *  Created on: 22 abr. 2020
 *      Author: jorge
 */

#ifndef PDM_TRABAJOS_TRABAJOFINAL_INC_SYSTEM_UART_H_
#define PDM_TRABAJOS_TRABAJOFINAL_INC_SYSTEM_UART_H_

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdint.h>
#include <stddef.h>
#include "sapi.h"

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/
void system_uartInit( uartMap_t uart, uint32_t baudRate);

void system_uart_WriteString( uartMap_t uart, const char* str );

bool_t system_uart_ReadByte( uartMap_t uart, uint8_t* receivedByte );

void system_uart_WriteByte( uartMap_t uart, const uint8_t value );


/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif


#endif /* PDM_TRABAJOS_TRABAJOFINAL_INC_SYSTEM_UART_H_ */
