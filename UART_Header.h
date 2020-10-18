/*
 * Header.h
 *
 *  Created on: Mar 31, 2020
 *      Author: menna
 */

#ifndef UART_HEADER_H_
#define UART_HEADER_H_
#include "UART_Config.h"
#include "BIT_CALC.h"
#include "STD_TYPE.h"
#include "UART_PRIV.h"

#define Normal_speed 0
#define Double_speed 1
#define RXINT_enable 1
#define RXINT_disable 0
#define TXINT_enable 1
#define TXINT_disable 0
#define UDREINT_enable 1
#define UDREINT_disable 0
#define CHAR_8bit 1
#define CHAR_9bit 0
#define READ_UCSRC 1
#define READ_UBRRH 0
#define SYNC 1
#define ASYNC 0
#define PARITY_disable 0
#define PARITY_even 1
#define PARITY_odd 2
#define STPBIT_1 0
#define STPBIT_2 1




void UART_INIT(void);
void Send_Char(u8 ch);
u8 Receive_Char();
void Send_String(u8 *ptr);
u8 Receive_String();



#endif /* UART_HEADER_H_ */
