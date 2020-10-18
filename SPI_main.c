#include "SPI_config.h"
#include "SPI_Private.h"
#include "STD_TYPE.h"
#include "BIT_CALC.h"
#include <avr/delay.h>
#include "SPI_Interface.h"
#include "LCDpriv.h"
#include "LCDheader.h"
#include<avr/io.h>

int main(void){

	DDRA=0XFF;
	DDRB=0X07;
	init_LCD();
	SPI_Initialize();

	u8 RX='z';


	while (1){
RX=SPI_ReceiveChar();
LCD_write(RX);
		_delay_ms(2000);
	}
}






