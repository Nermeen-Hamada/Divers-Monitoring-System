/*
 * UART_main.c
 *
 *  Created on: Mar 31, 2020
 *      Author: menna
 */


#include "BIT_CALC.h"
#include "STD_TYPE.h"
#include "UART_PRIV.h"
#include "UART_Config.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_priv.h"
#include "UART_Header.h"
#include <avr/io.h>
#include <avr/delay.h>


int main (void){


		UCSRA=0b0000000;
		UCSRC=0b10000110;
		UCSRB=0b00011000;
		UBRRH=0b00000000;
		UBRRL=51;

		DDRA=0XFF;
		DDRB=0X07;
		init_LCD();
		UART_INIT();

		u32 RX;


		while (1){
	RX=Receive_String();
	LCD_write_string(RX);
			_delay_ms(2000);
		}


}



