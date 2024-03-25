/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MRCC_interface.h -> functions prototypes
peri		: for the developer in MCAL only not for the user
*/

#ifndef MGPIO_MGPIO_INTERFACE_H_
#define MGPIO_MGPIO_INTERFACE_H_
/*********************************************/
/*********************************************/
/***************	user defined macros		***************/

/** 	Pin value	**/
#define MGPIO_u8LOW				0
#define MGPIO_u8HIGH			1

/**	 	PORT SELECTION		**/
#define MGPIO_u8PORTA			0
#define	MGPIO_u8PORTB			1
#define MGPIO_u8PORTC			2

/**		MODE SELECTION		**/
#define MGPIO_u8INPUT 			0b00
#define MGPIO_u8OUTPUT			0b01
#define MGPIO_u8ALTFUNC			0b10
#define	MGPIO_u8ANALOG			0b11

/**		OUTPUT OPTIONS		**/
#define MGPIO_u8PUSHPULL		0
#define MGPIO_u8OPENDRAIN		1

/**		Output speed		**/
#define MGPIO_u8LOW_SPEED		0b00
#define MGPIO_u8MEDIUM_SPEED	0b01
#define MGPIO_u8HIGH_SPEED		0b10
#define MGPIO_u8VERYHIGH_SPEED	0b11

/**		Input options		**/
#define MGPIO_u8NOPushPull		0b00
#define MGPIO_u8PullUP			0b01
#define	MGPIO_u8PullDown		0b10

/** 	Alternate Function  **/
#define GPIO_u8AF0					0
#define GPIO_u8AF1					1
#define GPIO_u8AF2					2
#define GPIO_u8AF3					3
#define GPIO_u8AF4					4
#define GPIO_u8AF5					5
#define GPIO_u8AF6					6
#define GPIO_u8AF7					7
#define GPIO_u8AF8					8
#define GPIO_u8AF9					9
#define GPIO_u8AF10					10
#define GPIO_u8AF11					11
#define GPIO_u8AF12					12
#define GPIO_u8AF13					13
#define GPIO_u8AF14					14
#define GPIO_u8AF15					15


/***************	GPIO FUNCTIONS prototypes	***************/
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidSetPinMode											 	*/
/* @Brief 	  :->		@ used to set the pin mode OUTPUT/INPUT							 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/*						@ Copy_u8Mode: OutPUT/InPUT											*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidSetPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,	u8 Copy_u8Mode);
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidSetOutputType							    		 	*/
/* @Brief 	  :->		@ used to set the pin mode OUTPUT/INPUT							 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/*						@ Copy_u8OutputType: OutPUTtype push pull/open drain				*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidSetOutputType(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8OutputType);
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidSetOutputSpeed							    		 	*/
/* @Brief 	  :->		@ used to set the pin output speed								 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/*						@ Copy_u8Speed: output speed										*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidSetOutputSpeed(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Speed);
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidSetPullType								    		 	*/
/* @Brief 	  :->		@ used to set the pin mode OUTPUT/INPUT							 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/*						@ Copy_u8PullType: input pull type up/down/no pushpull				*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidSetPullType(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PullType);
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_u8GetPinValue								    		 	*/
/* @Brief 	  :->		@ used to Get the value on a pin								 	*/
/*						@ returns the value of the pin High / low							*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin);
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidSetPinValue								    		 	*/
/* @Brief 	  :->		@ used to Set the value on a pin HIGH/low						 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/*						@ Copy_u8Value: high/low											*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidDirectSetReset							    		 	*/
/* @Brief 	  :->		@ 																 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Pin : Pin NUMBER											*/
/*						@ Copy_u8Value: 													*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidDirectSetReset(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);
/********************************************************************************************/
/* @Name  	  :->		@ MGPIO_voidSetPortValue								    		*/
/* @Brief 	  :->		@ used to Set the value on a pin HIGH/low						 	*/
/* @parameters   :-> 	@ Copy_u8Port: PORT NAME										    */
/*						@ Copy_u8Value: value to be set on a full port pins				*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC AHB1				*/
/********************************************************************************************/
void MGPIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);


void MGPIO_voidSetAltFunc(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8AltValue);



#endif /* MGPIO_MGPIO_INTERFACE_H_ */
