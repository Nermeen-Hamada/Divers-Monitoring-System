#include"SPI_Interface.h"
#include"SPI_Private.h"
#include "SPI_config.h"
#include"Bit_CALC.h"
#include"DIO_Interface.h"
#include"STD_TYPE.h"
#include"util\delay.h"
#include "DIO_Config.h"




void SPI_Initialize( void){

	switch (SPI_Interrupt){
		         case INTR_ENABLE:					   /*Interrupt Enable mode*/
			     (SET_BIT(SPCR,7));
		 	 	 break;

		 	 	 case (INTR_DISABLE):					/* Interrupt Disable mode*/
				 (CLR_BIT(SPCR,7));
		 	 	 break;
		 }


		 switch (SPI_ON_OFF){

		 	 	  case (SPI_ON):					/*SPI ON mode*/
				 (SET_BIT(SPCR,6));
		 	 	 break;
		         case(SPI_OFF): 					/*SPI OFF mode*/
		         (CLR_BIT(SPCR,6));
		          break;
				 }

		 switch ( SPI_CLOCKPOLARITY){
				 	 	 case (CPOL_ENABLE):					/*CLK Polarity Enable*/
						 (SET_BIT(SPCR,3));
				 	 	 break;
				 	 	 case(CPOL_DISABLE): 					/*CLK Polarity Disable*/
						 (CLR_BIT(SPCR,3));
				 	 	 break;
						 }

		 switch ( SPI_CLOCKPHASE){
						 case (CPHA_ENABLE):					/*CLK PHASE Enable*/
						(SET_BIT(SPCR,2));
						 break;
						 case(CPHA_DISABLE): 					/*CLK PHASE Disable*/
					    (CLR_BIT(SPCR,2));
						 break;
								 }


 	 	 switch(SPI_MODE){

	 	    case 0:							 /* MASTER MODE ENABLE*/
			(SET_BIT(SPCR,4));
			DIO_u8SetPinDirection((u8)12 ,1); //SS
	 	 	DIO_u8SetPinValue((u8)12 ,1);
	 	 	DIO_u8SetPinDirection((u8)13,1); //MOSI
	 	 	DIO_u8SetPinDirection((u8)14,0); //MISO
	 	 	DIO_u8SetPinDirection((u8)15,1); //ck

	 	 	break;

	 	    case 1:							 /*SLAVE MODE ENABLE */

		    (CLR_BIT(SPCR,4));

			DIO_u8SetPinDirection((u8)12,0);
	 	 	DIO_u8SetPinValue((u8)12,1);
	 	    DIO_u8SetPinDirection((u8)13,0);
	 	    DIO_u8SetPinDirection((u8)14,1);
	 	    DIO_u8SetPinDirection((u8)15,0);
	 	    break;

 	 	 	 	 	 }

 	 	 switch (SPI_INTRFlag){

 	 	 	 	case(IntrF_Enable):     				  /*ENABLE INTERRUPT FLAG*/
				(SET_BIT(SPSR,7));
 	 	 	 	break;

 	 	 	    case(IntrF_Disable):					 /*DISABLE INTERRUPT FLAG*/
 	 	 	    (CLR_BIT(SPSR,7));
 	 	 	  	 break;

 	 	 }

 	 switch ( SPI_CLKRATE ){
 	 	 case 1:                     			 /* SCK FREQ = Fosc/16 */
 	 		    SET_BIT(SPCR, 0);
 	 			CLR_BIT(SPCR,1);
 	 			CLR_BIT(SPSR,0);
           break;

 	 	 case 2:                    			 /* SCK FREQ = Fosc/8 */
 	 		    SET_BIT(SPCR, 0);
 	 			CLR_BIT(SPCR,1);
 	 			SET_BIT(SPSR,0);
           break;


 	 	 }


}


	void SPI_sendChar(u8 u8data)
	{
			SPDR = u8data;
			while(!(SPSR & (0b10000000)));                /* Wait for transmission complete */

		/* *SPDR = u8data ;			// Put data in the SPDR to be transmitted
		while(!(SPSR & (0x80))) ;	// Wait till transmit complete
		return SPDR ;			// Return the received data
*/
	}




	u8 SPI_ReceiveChar()
	{		u8 Result;
			while(!(SPSR & 0b10000000));

			return SPDR ;

     }


	void SPI_SendString (u8*ptr){

			u8 i=0;
			while (ptr[i] != '\0' ){
						SPI_sendChar(ptr[i]);
						i++;
						SPDR = ptr [i];
								}

							}


	u8 SPI_ReceiveString(u8*ptr )
	{

			/*u8 i=0;
			while (ptr[i] != '\0' ){
					SPI_ReceiveChar(ptr[i]);
					i++;
					SPDR = ptr [i];
									}
			return SPDR;
			*/

			u8 i = 0;

				ptr[i] = SPI_ReceiveChar();
				while(ptr[i] != '#')
				{
					i++;
					ptr[i] = SPI_ReceiveChar();
				}
				ptr[i] = '\0';
				return SPDR;
			}


