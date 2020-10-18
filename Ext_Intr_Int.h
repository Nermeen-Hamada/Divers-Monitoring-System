/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the Switch Component in    		    */
/* 				 high efficiency													*/
/* 				 This Driver Supports AVR ATmel32                                   */
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


#ifndef EXTINT_COMPONENT_INTERFACE_H_
#define EXTINT_COMPONENT_INTERFACE_H_





/*************************************   AVR  DEFINITIONS   ************************************/
/* Description : Defining Available Pins On AVR ATmel32, Which contain 32 Pins 				   */
/* Ranges from (0 -> 31) 																	   */
/*                                                                                             */
/* Example : #define EXTINT_PIN21  													           */
/*																						       */
#define EXTINT_PIN0    		     	   (u8)0
#define EXTINT_PIN1    		     	   (u8)1
#define EXTINT_PIN2    		     	   (u8)2
#define EXTINT_PIN3    		     	   (u8)3
#define EXTINT_PIN4    		     	   (u8)4
#define EXTINT_PIN5    		     	   (u8)5
#define EXTINT_PIN6    		     	   (u8)6
#define EXTINT_PIN7    		     	   (u8)7
/*																							   */
#define EXTINT_PIN8    			       (u8)8
#define EXTINT_PIN9    			       (u8)9
#define EXTINT_PIN10    			   (u8)10
#define EXTINT_PIN11    			   (u8)11
#define EXTINT_PIN12    			   (u8)12
#define EXTINT_PIN13    			   (u8)13
#define EXTINT_PIN14    			   (u8)14
#define EXTINT_PIN15    			   (u8)15
/*																							   */
#define EXTINT_PIN16    			   (u8)16
#define EXTINT_PIN17    			   (u8)17
#define EXTINT_PIN18    			   (u8)18
#define EXTINT_PIN19    			   (u8)19
#define EXTINT_PIN20    			   (u8)20
#define EXTINT_PIN21    			   (u8)21
#define EXTINT_PIN22    			   (u8)22
#define EXTINT_PIN23    			   (u8)23
/*																							   */
#define EXTINT_PIN24    			   (u8)24
#define EXTINT_PIN25    			   (u8)25
#define EXTINT_PIN26    			   (u8)26
#define EXTINT_PIN27    			   (u8)27
#define EXTINT_PIN28    			   (u8)28
#define EXTINT_PIN29    			   (u8)29
#define EXTINT_PIN30    			   (u8)30
#define EXTINT_PIN31    			   (u8)31
/*																						       */
/***********************************************************************************************/





/******* Configurations Dependencies ********/
/*									        */

/* Defining Private Variables               */
#define INTR_STATE_ENABLED 				(u8)21
#define INTR_STATE_DISABLED 			(u8)20

#define SENSE_LEVEL_LOW 				(u8)0
#define SENSE_LEVEL_RISING 				(u8)3
#define SENSE_LEVEL_FALLING 			(u8)2
#define SENSE_LEVEL_ON_CHANGE 			(u8)1

/*									        */
/********************************************/



/*************************************************************************************************/
/* Description: Initializes the pointers to Fns, Sets the initial states (PIE) of each Interrupt */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 EXTINT_u8Initialize( ) ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Assigns a Fn to the Function pointer of each Interrupt				             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex 				-> No of Interrupt							         */
/* 			(*Copy_PvoidFuncCallBack)(void) -> the address of the function to be used			 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 EXTINT_u8SetCallBack(u8 Copy_u8IntrIndex , void (*Copy_PvoidFuncCallBack)(void) ) ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 EXTINT_u8Enable(u8 Copy_u8IntrIndex) ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 EXTINT_u8Disable(u8 Copy_u8IntrIndex) ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Chooses the Sense level of the Interrupt  							             */
/*			(SENSE_LEVEL_LOW - SENSE_LEVEL_RISING - SENSE_LEVEL_FALLING - SENSE_LEVEL_ON_CHANGE) */
/* Inputs : Copy_u8IntrIndex    -> Interrupt			      						             */
/* 			Copy_u8SenseLevel   -> The chosen sense level										 */
/* Outputs: u8Error 			-> Error State										             */
/*																					             */

u8 EXTINT_u8SetSenseLevel(u8 Copy_u8IntrIndex ,u8 Copy_u8SenseLevel) ;

/*																					             */
/*************************************************************************************************/





#endif /* EXTINT_COMPONENT_EXTINT_INTERFACE_H_ */
