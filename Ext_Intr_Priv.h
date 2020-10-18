/************************************************************************************/
/* Description : This is a Private file that contains the private definitions and   */
/*               Private functions needed to use the Switch Component 		        */
/* 				 This Driver Supports AVR ATmel32                                   */
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/




#ifndef EXTINT_COMPONENT_EXTINT_PRIV_H_
#define EXTINT_COMPONENT_EXTINT_PRIV_H_


#define SREG(I_BIT) GIE
#define GICR(BIT_6) PIE

/********* Hardware Dependencies ************/
/*									        */

/* Defining EXT-INTR Registers              */
#define LOCAL_MCUCR 					0X55
#define LOCAL_MCUCSR 					0X54
#define LOCAL_GICR 						0X5B
#define LOCAL_GIFR 						0X5A

/*									        */
/********************************************/



#endif /* EXTINT_COMPONENT_EXTINT_PRIV_H_ */
