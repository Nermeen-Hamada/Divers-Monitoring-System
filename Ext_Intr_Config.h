/************************************************************************************/
/* Description : This is a Configuration file that contains the Allowed Customizati-*/
/*               ons for Seven Segments Component                                   */
/*               allowed only for Application Engineers 							*/
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/





#ifndef EXTINT_COMPONENT_EXTINT_CONFIG_H_
#define EXTINT_COMPONENT_EXTINT_CONFIG_H_





/* Define Parameters of EXTINTs used ************************/
/*										 					*/

#define EXTINT_NUMBER			3

/*															*/
/************************************************************/



/*************************************   AVR  DEFINITIONS   ************************************/
/* Description : 																   */
/* Ranges from 																	   */
/*                                                                                             */

u8 EXTINT_Au8State[EXTINT_NUMBER]      = {   INTR_STATE_ENABLED,
								  	      	 INTR_STATE_ENABLED,
								  	      	 INTR_STATE_ENABLED
							      	      };


u8 EXTINT_Au8SenseLevel[EXTINT_NUMBER] = {   SENSE_LEVEL_FALLING,
	   										 SENSE_LEVEL_FALLING,
	   										 SENSE_LEVEL_FALLING
							    	      };

/*																						       */
/***********************************************************************************************/






#endif /* SSEG_COMPONENT_SSEG_CONFIG_H_ */
