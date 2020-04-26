/*
 * sistema_acceso.c
 *
 *  Created on: 22 abr. 2020
 *      Author: jorge
 */

/*=====[Inclusions of function dependencies]=================================*/

#include "fsm_access_system.h"
#include "sapi.h"
#include "debounce.h"
#include "leds.h"
#include "system_uart.h"

/*=====[Definition macros of private constants]==============================*/
#define INITIAL_DEFAULT_MODE MANUAL
#define INITIAL_DEFAULT_STATE CLOSE
#define BAUD_RATE 115200
#define UART UART_USB

uint8_t message  = 0;

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/
static debounce_button_t button1; //Botón open en modo manual
static debounce_button_t button2; //Botón close en modo manual
static debounce_button_t button3; //Botón para modo manual
static debounce_button_t button4; //Botón para modo consola

static system_t systemAccess;

/*=====[Main function, program entry point after power on or reset]==========*/

/*=====[Prototypes (declarations) of private functions]======================*/
static void system_status(system_t * pSystem);
static void system_console(system_t * pSystem);

//Función error de FSM
void fsm_systemError( void ){
	fsm_systemInit( &systemAccess );
}

//Función inicialización de FSM
void fsm_systemInit( system_t  * pSystem ){
	//Configuración inicial por default
	pSystem->mode = INITIAL_DEFAULT_MODE;
	pSystem->state = INITIAL_DEFAULT_STATE;

	//Inicializo máquina de estados finitos debounce para TEC1, TEC2 y TEC3
	fsm_debounceInit(&button1, TEC1);
	fsm_debounceInit(&button2, TEC2);
	fsm_debounceInit(&button3, TEC3);
	fsm_debounceInit(&button4, TEC4);

	//Inicializo máquina de estados finitos debounce para TEC1, TEC2 y TEC3
	system_uartInit(UART, BAUD_RATE);
}

//Función update de FSM
void fsm_systemUpdate( system_t  * pSystem ){
	//Llamo a funciones de FSM debounce
	fsm_debounceUpdate(&button1);
	fsm_debounceUpdate(&button2);
	fsm_debounceUpdate(&button3);
	fsm_debounceUpdate(&button4);

	//Chequear teclas TEC1, TEC2, TEC3 y TEC4
	if(button1.keyPressed){
		if(pSystem->mode == MANUAL)
			pSystem->state = OPEN;
	}
	else if(button2.keyPressed){
		if(pSystem->mode == MANUAL)
			pSystem->state = CLOSE;
	}
	else if(button3.keyPressed){
		pSystem->mode = MANUAL;
	}
	else if(button4.keyPressed){
		pSystem->mode = CONSOLE;
		//Mensaje de inicio
		system_uart_WriteString( UART,"Para abrir el sistema de acceso ingrese 'S', para cerrarla ingrese 'N'\r\n" );
	}

	//Ejecuto función modo manual o por consola según corresponda
	switch(pSystem->mode){
	case MANUAL:
		system_status(pSystem);
		turnOn(LED2);
		turnOff(LEDB);
		break;
	case CONSOLE:
		system_console(pSystem);
		turnOff(LED2);
		turnOn(LEDB);
		break;
	default:
		fsm_systemInit(pSystem);
	}
}

static void system_status(system_t * pSystem){
	switch(pSystem->state){
	case OPEN:
		turnOff(LED1);
		turnOn(LED3);
		break;
	case CLOSE:
		turnOn(LED1);
		turnOff(LED3);
		break;
	default:
		fsm_systemError();
	}
}

static void system_console(system_t * pSystem){
	/* Si recibe un byte de la UART_USB lo guardarlo en la variable dato. */
	if(uartReadByte( UART, &message )){
		if(message == 'S'){
			pSystem->state = OPEN;
			system_uart_WriteString( UART,"Sistema de acceso abierto\r\n" );
		}
		else if(message == 'N'){
			pSystem->state = CLOSE;
			system_uart_WriteString( UART,"Sistema de acceso cerrado\r\n" );
		}
		else
			system_uart_WriteString( UART,"Ha ingresado un codigo erroneo\r\n" );
	}

	system_status(pSystem);
}




