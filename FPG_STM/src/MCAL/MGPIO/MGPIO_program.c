/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MGPIO_program.c -> Functions impelemntations
peri		: for the developer in MCAL only not for the user
*/

/*********************************************/
/*********************************************/

/***************	GPIO Files include	***************/
/*Standard LIBS*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*GPIO files*/
#include "MGPIO_interface.h"
#include "MGPIO_private.h"
#include "MGPIO_config.h"
#include "MGPIO_register.h"

/*********************************************/
/*********************************************/

/***************	GPIO Functions Implementations	***************/


/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidSetPinMode											 	*/
/* @Brief 	  :->		@ used to set the pin mode OUTPUT/INPUT							 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/*						@ Copy_u8Mode: OutPUT/InPUT											*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidSetPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,	u8 Copy_u8Mode){
	/*check on the port*/
	switch(Copy_u8Port){
			case MGPIO_u8PORTA :MGPIOA->MODER &= ~((0b11)<<(Copy_u8Pin*2));				/*select the pin in the MODER register*/
								MGPIOA->MODER |= (Copy_u8Mode<<(Copy_u8Pin*2));			/*select the mode in the MODER register*/
								break;													/*end of case port A*/
			case MGPIO_u8PORTB :MGPIOB->MODER &= ~((0b11)<<(Copy_u8Pin*2));     		/*select the pin in the MODER register*/
								MGPIOB->MODER |= (Copy_u8Mode<<(Copy_u8Pin*2)); 		/*select the mode in the MODER register*/
								break;                                          		/*end of case port B*/
			case MGPIO_u8PORTC :MGPIOC->MODER &= ~((0b11)<<(Copy_u8Pin*2));      		/*select the pin in the MODER register*/
								MGPIOC->MODER |= (Copy_u8Mode<<(Copy_u8Pin*2));  		/*select the mode in the MODER register*/
								break;                                           		/*end of case port C*/
	}
}
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidSetOutputType							    		 	*/
/* @Brief 	  :->		@ used to set the pin mode OUTPUT/INPUT							 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/*						@ Copy_u8OutputType: OutPUTtype push pull/open drain				*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidSetOutputType(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8OutputType){
	/*check on the port*/
	switch(Copy_u8Port){
			case MGPIO_u8PORTA :MGPIOA->OTYPER &= ~((1)<<(Copy_u8Pin));             		/*select the pin in the OTYPER register*/
								MGPIOA->OTYPER |= (Copy_u8OutputType<<(Copy_u8Pin));		/*select the output type in the OTYPER register*/
								break;                                              		/*end of case port A*/
			case MGPIO_u8PORTB :MGPIOB->OTYPER &= ~((1)<<(Copy_u8Pin));              		/*select the pin in the OTYPER register*/
								MGPIOB->OTYPER |= (Copy_u8OutputType<<(Copy_u8Pin)); 		/*select the output type in the OTYPER register*/
								break;                                               		/*end of case port B*/
			case MGPIO_u8PORTC :MGPIOC->OTYPER &= ~((1)<<(Copy_u8Pin));                		/*select the pin in the OTYPER register*/
								MGPIOC->OTYPER |= (Copy_u8OutputType<<(Copy_u8Pin));   		/*select the output type in the OTYPER register*/
								break;                                                 		/*end of case port C*/
		}
}
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidSetOutputSpeed							    		 	*/
/* @Brief 	  :->		@ used to set the pin output speed								 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/*						@ Copy_u8Speed: output speed										*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidSetOutputSpeed(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Speed){
		/*check on the port*/
	switch(Copy_u8Port){
				case MGPIO_u8PORTA :MGPIOA->OSPEEDER &= ~((0b11)<<(Copy_u8Pin*2));       		/*select the pin in the OSPEEDER register*/
									MGPIOA->OSPEEDER |= (Copy_u8Speed<<(Copy_u8Pin*2));  		/*select the output SPEED in the OSPEEDER register*/
									break;                                               		/*end of case port A*/
				case MGPIO_u8PORTB :MGPIOB->OSPEEDER &= ~((0b11)<<(Copy_u8Pin*2));        		/*select the pin in the OSPEEDER register*/
									MGPIOB->OSPEEDER |= (Copy_u8Speed<<(Copy_u8Pin*2));   		/*select the output SPEED in the OSPEEDER register*/
									break;                                                		/*end of case port B*/
				case MGPIO_u8PORTC :MGPIOC->OSPEEDER &= ~((0b11)<<(Copy_u8Pin*2));        		/*select the pin in the OSPEEDER register*/
									MGPIOC->OSPEEDER |= (Copy_u8Speed<<(Copy_u8Pin*2));   		/*select the output SPEED in the OSPEEDER register*/
									break;                                                		/*end of case port C*/
}
}
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidSetPullType								    		 	*/
/* @Brief 	  :->		@ used to set the pin mode OUTPUT/INPUT							 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/*						@ Copy_u8PullType: input pull type up/down/no pushpull				*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidSetPullType(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PullType){
		/*check on the port*/
	switch(Copy_u8Port){
					case MGPIO_u8PORTA :MGPIOA->PUPDR &= ~((0b11)<<(Copy_u8Pin*2));          		/*select the pin in the PUPDR register*/
										MGPIOA->PUPDR |= (Copy_u8PullType<<(Copy_u8Pin*2));  		/*select the INPUT type in the PUPDR register*/
										break;                                               		/*end of case port A*/
					case MGPIO_u8PORTB :MGPIOB->PUPDR &= ~((0b11)<<(Copy_u8Pin*2));           		/*select the pin in the PUPDR register*/
										MGPIOB->PUPDR |= (Copy_u8PullType<<(Copy_u8Pin*2));   		/*select the INPUT type in the PUPDR register*/
										break;                                                		/*end of case port A*/
					case MGPIO_u8PORTC :MGPIOC->PUPDR &= ~((0b11)<<(Copy_u8Pin*2));           		/*select the pin in the PUPDR register*/
										MGPIOC->PUPDR |= (Copy_u8PullType<<(Copy_u8Pin*2));   		/*select the INPUT type in the PUPDR register*/
										break;                                                		/*end of case port A*/
		}
}
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_u8GetPinValue								    		 	*/
/* @Brief 	  :->		@ used to Get the value on a pin								 	*/
/*						@ returns the value of the pin High / low							*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin){
	u8 Local_PINvalue=0;
/*check on the port*/
switch (Copy_u8Port){
		case MGPIO_u8PORTA: Local_PINvalue= GET_BIT(MGPIOA->IDR,Copy_u8Pin);break;   /*get the value of the pin from IDR(PORTA)register*/
		case MGPIO_u8PORTB: Local_PINvalue= GET_BIT(MGPIOB->IDR,Copy_u8Pin);break;   /*get the value of the pin from IDR(PORTB)register*/
		case MGPIO_u8PORTC: Local_PINvalue= GET_BIT(MGPIOC->IDR,Copy_u8Pin);break;   /*get the value of the pin from IDR(PORTC)register*/
}
return Local_PINvalue;
}
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidSetPinValue								    		 	*/
/* @Brief 	  :->		@ used to Set the value on a pin HIGH/low						 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/*						@ Copy_u8Value: high/low											*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value){
	/*CHECK for the required value to be set*/
	if(Copy_u8Value == MGPIO_u8LOW){
		/*check on the port*/
			switch (Copy_u8Port){
				case MGPIO_u8PORTA: CLR_BIT(MGPIOA->ODR,Copy_u8Pin);break; 			/*SET the value of the pin in ODR (PORTA) register to  0 */
				case MGPIO_u8PORTB: CLR_BIT(MGPIOB->ODR,Copy_u8Pin);break; 			/*SET the value of the pin in ODR (PORTB) register to  0 */
				case MGPIO_u8PORTC: CLR_BIT(MGPIOC->ODR,Copy_u8Pin);break; 			/*SET the value of the pin in ODR (PORTC) register to  0 */
				}
	}
	else if(Copy_u8Value==MGPIO_u8HIGH){
	/*check on the port*/
			switch (Copy_u8Port){
				case MGPIO_u8PORTA: SET_BIT(MGPIOA->ODR,Copy_u8Pin);break;      /*SET the value of the pin in ODR (PORTA) register to  1 */
				case MGPIO_u8PORTB: SET_BIT(MGPIOB->ODR,Copy_u8Pin);break;      /*SET the value of the pin in ODR (PORTB) register to  1 */
				case MGPIO_u8PORTC: SET_BIT(MGPIOC->ODR,Copy_u8Pin);break;      /*SET the value of the pin in ODR (PORTC) register to  1 */
				}
	}
}

/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidDirectSetReset							    		 	*/
/* @Brief 	  :->		@ 																 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/*						@ Copy_u8Value: 													*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidDirectSetReset(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value){
	if(Copy_u8Value==MGPIO_u8HIGH){
		switch(Copy_u8Port){
		case MGPIO_u8PORTA: MGPIOA->BSRR = 1<<Copy_u8Pin;break;
		case MGPIO_u8PORTB: MGPIOB->BSRR = 1<<Copy_u8Pin;break;
		case MGPIO_u8PORTC: MGPIOC->BSRR = 1<<Copy_u8Pin;break;
		}
	}
	else if(Copy_u8Value==MGPIO_u8LOW){
	Copy_u8Pin +=16;
	switch(Copy_u8Port){
			case MGPIO_u8PORTA: MGPIOA->BSRR = 1<<Copy_u8Pin;break;
			case MGPIO_u8PORTB: MGPIOB->BSRR = 1<<Copy_u8Pin;break;
			case MGPIO_u8PORTC: MGPIOC->BSRR = 1<<Copy_u8Pin;break;
			}
	}
}
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidSetPortValue								    		*/
/* @Brief 	  :->		@ used to Set the value on a pin HIGH/low						 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Value: value to be setted on a full port pins				*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value){
	/*check on the port*/
	switch(Copy_u8Port){
			case	MGPIO_u8PORTA:	MGPIOA->ODR=Copy_u8Value;break;    /*set the required value to all the pins in port A*/
			case	MGPIO_u8PORTB:	MGPIOB->ODR=Copy_u8Value;break;    /*set the required value to all the pins in port B*/
			case	MGPIO_u8PORTC:	MGPIOC->ODR=Copy_u8Value;break;    /*set the required value to all the pins in port C*/
		}
}


void MGPIO_voidSetAltFunc(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8AltValue)
{
	if(Copy_u8Pin < 8 )
	{
		switch(Copy_u8Port)
		{
				case MGPIO_u8PORTA:
					MGPIOA->AFRL &= ~((0b1111)<<(Copy_u8Pin*4));
					MGPIOA->AFRL |= Copy_u8AltValue<<(Copy_u8Pin*4);
					break;
				case MGPIO_u8PORTB:
					MGPIOB->AFRL &= ~((0b1111)<<(Copy_u8Pin*4));
					MGPIOB->AFRL |= Copy_u8AltValue<<(Copy_u8Pin*4);
					break;
				case MGPIO_u8PORTC:
					MGPIOC->AFRL &= ~((0b1111)<<(Copy_u8Pin*4));
					MGPIOC->AFRL |= Copy_u8AltValue<<(Copy_u8Pin*4);
					break;
		}
	}
	else if(Copy_u8Pin >= 8 )
	{
		Copy_u8Pin = Copy_u8Pin - 8;
		switch(Copy_u8Port)
		{
				case MGPIO_u8PORTA:
					MGPIOA->AFRH &= ~((0b1111)<<(Copy_u8Pin*4));
					MGPIOA->AFRH |= Copy_u8AltValue<<(Copy_u8Pin*4);
					break;
				case MGPIO_u8PORTB:
					MGPIOB->AFRH &= ~((0b1111)<<(Copy_u8Pin*4));
					MGPIOB->AFRH |= Copy_u8AltValue<<(Copy_u8Pin*4);
					break;
				case MGPIO_u8PORTC:
					MGPIOC->AFRH &= ~((0b1111)<<(Copy_u8Pin*4));
					MGPIOC->AFRH |= Copy_u8AltValue<<(Copy_u8Pin*4);
					break;
		}
	}
}








