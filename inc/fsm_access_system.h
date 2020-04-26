/*
 * sistema_acceso.h
 *
 *  Created on: 22 abr. 2020
 *      Author: jorge
 */

#ifndef PDM_TRABAJOS_TRABAJOFINAL_INC_FSM_ACCESS_SYSTEM_H_
#define PDM_TRABAJOS_TRABAJOFINAL_INC_FSM_ACCESS_SYSTEM_H_

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
typedef enum {MANUAL, CONSOLE} system_mode_t;
typedef enum {OPEN, CLOSE} system_state_t;

typedef struct{
	system_mode_t mode;
	system_state_t state;
} system_t;

/*=====[Prototypes (declarations) of public functions]=======================*/
void fsm_systemError( void );

void fsm_systemInit( system_t  * pSystem );

void fsm_systemUpdate( system_t  * pSystem );

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif



#endif /* PDM_TRABAJOS_TRABAJOFINAL_INC_FSM_ACCESS_SYSTEM_H_ */
