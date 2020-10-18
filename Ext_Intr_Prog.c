/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the Seven Segments  */
/*               Component in high efficiency									    */
/* 				                     												*/
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


#include "STD_TYPE.h"

#include "Ext_Intr_Int.h"
#include "Ext_Intr_Priv.h"
#include "Ext_Intr_Config.h"


static void (*PtrToFunctions[EXTINT_NUMBER])(void) ;




/*************************************************************************************************/
/* Description: Initializes the pointers to Fns, Sets the initial states (PIE) of each Interrupt */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 EXTINT_u8Initialize( ) {

	u8 Local_u8ErrorState = ERROR_OK ;



	for(u8 count = 0 ; count < EXTINT_NUMBER ; count ++){



		PtrToFunctions[count] = NULL ;



		if(EXTINT_Au8State[count] == INTR_STATE_ENABLED){
			EXTINT_u8Enable(count) ;
		}
		else {
			EXTINT_u8Disable(count) ;
		}



		EXTINT_u8SetSenseLevel(count ,EXTINT_Au8SenseLevel[count]) ;


	}







	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Assigns a Fn to the Function pointer of each Interrupt				             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex 				-> No of Interrupt							         */
/* 			(*Copy_PvoidFuncCallBack)(void) -> the address of the function to be used			 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 EXTINT_u8SetCallBack(u8 Copy_u8IntrIndex , void (*Copy_PvoidFuncCallBack)(void) ) {

	u8 Local_u8ErrorState = ERROR_OK ;

	if(Copy_PvoidFuncCallBack != NULL){
		PtrToFunctions[Copy_u8IntrIndex] = Copy_PvoidFuncCallBack ;
	}

	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Enables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 EXTINT_u8Enable(u8 Copy_u8IntrIndex) {

	u8 Local_u8ErrorState = ERROR_OK ;

	u8 Local_bitshift = (6+Copy_u8IntrIndex);


	if(Local_bitshift < 8){

		((Register*) LOCAL_GICR ) -> ByteAccess  |= (1 << Local_bitshift ) ;

	}
	else if (Local_bitshift == 8){
		((Register*) LOCAL_GICR ) -> ByteAccess  |= (1 << (Local_bitshift-3) ) ;
	}
	else {

		Local_u8ErrorState = ERROR_NOK ;

	}

	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Disables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 EXTINT_u8Disable(u8 Copy_u8IntrIndex) {

	u8 Local_u8ErrorState = ERROR_OK ;

	u8 Local_bitshift = (6+Copy_u8IntrIndex);


	if(Local_bitshift < 8){

		((Register*) LOCAL_GICR ) -> ByteAccess  &= ~(1 << Local_bitshift ) ;

	}
	else if (Local_bitshift == 8){
		((Register*) LOCAL_GICR ) -> ByteAccess  &= ~(1 << (Local_bitshift-3) ) ;
	}
	else {

		Local_u8ErrorState = ERROR_NOK ;

	}

	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Chooses the Sense level of the Interrupt  							             */
/*			(SENSE_LEVEL_LOW - SENSE_LEVEL_RISING - SENSE_LEVEL_FALLING - SENSE_LEVEL_ON_CHANGE) */
/* Inputs : Copy_u8IntrIndex    -> Interrupt			      						             */
/* 			Copy_u8SenseLevel   -> The chosen sense level										 */
/* Outputs: u8Error 			-> Error State										             */
/*																					             */

u8 EXTINT_u8SetSenseLevel(u8 Copy_u8IntrIndex ,u8 Copy_u8SenseLevel) {

	u8 Local_u8ErrorState = ERROR_OK ;

	//u8 Local_bitshift = (6+Copy_u8IntrIndex);

	if(Copy_u8IntrIndex < 2){

		((Register*) LOCAL_MCUCR ) -> ByteAccess  &= ~(0b11 << (Copy_u8IntrIndex*2) ) ;
		((Register*) LOCAL_MCUCR ) -> ByteAccess  |= (Copy_u8SenseLevel << (Copy_u8IntrIndex*2) ) ;

	}
	else if(Copy_u8IntrIndex == 2){

		if((Copy_u8SenseLevel == 2) || (Copy_u8SenseLevel == 3)){

			((Register*) LOCAL_MCUCSR ) -> ByteAccess  &= ~(0b1 << (6) ) ;
			((Register*) LOCAL_MCUCSR ) -> ByteAccess  |= ((Copy_u8SenseLevel-2) << (6) ) ;

		}
		else {
			Local_u8ErrorState = ERROR_NOK ;
		}

	}




	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/








/*************************************************************************************************/
/*								The functions to be used as an ISR								 */
/*																					             */

void __vector_1 (void) __attribute__ ((signal)) ;

void __vector_1 (void) {

	if (PtrToFunctions[0] != NULL)
		PtrToFunctions[0]() ;

}


void __vector_2 (void) __attribute__ ((signal)) ;

void __vector_2 (void) {

	if (PtrToFunctions[1] != NULL)
			PtrToFunctions[1]() ;

}


void __vector_3 (void) __attribute__ ((signal)) ;

void __vector_3 (void) {

	if (PtrToFunctions[2] != NULL)
			PtrToFunctions[2]() ;

}

/*																								 */
/*************************************************************************************************/


















