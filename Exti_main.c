
#define SREG(I_BIT) GIE
#define GICR(BIT_6) PIE
#include "BIT_CALC.h"
#include "STD_TYPE.h"
#include "DIO_Interface.h"
#include "DIO_priv.h"
#include "AVR_DIO_REG.h"
#include <util/delay.h>
#define SREG *((u8*)0x5f)
#define GICR *((u8*)0x5b)

int main (void){
	SET_BIT( SREG,7);
	SET_BIT( GICR,6);

	DDRD = 0x00;
    DIO_u8SetPinValue((u8)24 , 1 ) ;

    DDRA = 0b00000001;
    DIO_u8SetPinValue((u8)0 , 0 ) ;
}
    void __vector_1(void) __attribute__((signal));
    void __vector_1(void){
    	 DIO_u8SetPinValue((u8)0 , 1 );




     }

}

