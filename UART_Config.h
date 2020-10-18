/*
 * UART_Config.h
 *
 *  Created on: Mar 31, 2020
 *      Author: menna
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
#include "BIT_CALC.h"
#include "STD_TYPE.h"
#include "UART_PRIV.h"

#define F_CPU 8000000UL 		// Clock speed
#define UART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (UART_BAUDRATE * 16UL)))-1)

#define UARTSPEED 	Normal_speed	//Write Normal_speed or Double_speed
#define  RXINT		RXINT_enable	//Write RXINT_enable or RXINT_disable
#define  TXINT		TXINT_enable	//Write TXINT_enable or TXINT_disable
#define UDREINT		UDREINT_enable	//Write UDREINT_enable or UDREINT_disable
#define CHARSIZE	CHAR_8bit	//Determine the character size CHAR_8bit or CHAR_9bit
#define REGSELECT	READ_UCSRC	//READ_UCSRC or READ_UBRRH
#define MODE		ASYNC	//SYNC or ASYNC
#define PARITY		PARITY_even	//Choose parity mode PARITY_disable or PARITY_even or PARITY_odd
#define STPBIT		STPBIT_1	//Stop bit modes STPBIT_1 or STPBIT_2








#endif /* UART_CONFIG_H_ */
