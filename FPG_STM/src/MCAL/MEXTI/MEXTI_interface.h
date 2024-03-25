/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MEXTI_interface.h -> functions prototypes
peri		: for the developer in MCAL only not for the user
*/

#ifndef MEXTI_MEXTI_INTERFACE_H_
#define MEXTI_MEXTI_INTERFACE_H_
/*********************************************/
/******************************	user defined MACROS		******************************/
/**		interrupt source 	**/
#define 	MEXTI_RISING_EDGE		0
#define 	MEXTI_FALLING_EDGE		1
#define		MEXTI_ANY_CHANGE		3
/**		interrupt port 		**/
#define 		MEXTI_PORTA			0b0000
#define 		MEXTI_PORTB			0b0001
#define			MEXTI_PORTC			0b0010
/******************************	user defined DATA TYPES	******************************/
/***************	EXTI LINES ***************/
typedef enum{
	MEXTI_LINE0 =0,
	MEXTI_LINE1,
	MEXTI_LINE2,
	MEXTI_LINE3,
	MEXTI_LINE4,
	MEXTI_LINE5,
	MEXTI_LINE6,
	MEXTI_LINE7,
	MEXTI_LINE8,
	MEXTI_LINE9,
	MEXTI_LINE10,
	MEXTI_LINE11,
	MEXTI_LINE12,
	MEXTI_LINE13,
	MEXTI_LINE14,
	MEXTI_LINE15,
}MEXTI_LINE_t;

/******************************	Functions prototypes	******************************/
/*****************************************************************************************/
/* @Name  	  :->		@ MEXTI_voidEnableEXTI											 */
/* @Brief 	  :->		@ used to Enable the wanted EXT_interrupt wanted channel(0:15)	 */
/* @parameters   :-> 	@ Copy_udtLineNum: the number corresponding the interrupt		 */
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 */
/*						@ SYSCFG Must be enabled by RCC									 */
/*						@ trigger source and interrupt PIN/PORT must be selected before  */
/*						@ NVIC Enable interrupt must be used after this function		 */
/*****************************************************************************************/
void MEXTI_voidEnableEXTI(MEXTI_LINE_t Copy_udtLineNum);
/*****************************************************************************************/
/* @Name  	  :->		@ MEXTI_voidDisableEXTI											 */
/* @Brief 	  :->		@ used to Disable the NOT wanted EXT_interrupt channel(0:15)	 */
/* @parameters   :-> 	@ Copy_udtLineNum: the number corresponding the interrupt		 */
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 */
/*						@ SYSCFG Must be enabled by RCC									 */
/*						@ NVIC Enable interrupt must be used after this function		 */
/*****************************************************************************************/
void MEXTI_voidDisableEXTI(MEXTI_LINE_t Copy_udtLineNum);
/*****************************************************************************************/
/* @Name  	  :->		@ MEXTI_voidTriggerSource										 */
/* @Brief 	  :->		@ set the interrupt trigger source								 */
/* @parameters   :-> 	@ Copy_udtLineNum: the number corresponding the interrupt		 */
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 */
/*						@ SYSCFG Must be enabled by RCC									 */
/*						@ NVIC Enable interrupt must be used after this function		 */
/*****************************************************************************************/
void MEXTI_voidTriggerSource(MEXTI_LINE_t Copy_udtLineNum, u8 Copy_u8TriggerSource);
/*****************************************************************************************/
/* @Name  	  :->		@ MEXTI_voidSelectPort											 */
/* @Brief 	  :->		@ set the interrupt PORT/pin									 */
/* @parameters   :-> 	@ Copy_udtLineNum: the number corresponding the interrupt		 */
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 */
/*						@ SYSCFG Must be enabled by RCC									 */
/*						@ NVIC Enable interrupt must be used after this function		 */
/*****************************************************************************************/
void MEXTI_voidSelectPort(MEXTI_LINE_t Copy_udtLineNum,u8 Copy_u8PortNUM);
/*****************************************************************************************/
/* @Name  	  :->		@ MEXTI_voidSetCallBack											 */
/* @Brief 	  :->		@ set ISR to the interrupt										 */
/* @parameters   :-> 	@ Copy_pvCallBackFunc: Pointer to the routine to be executed at */
/*						  Interrupt fire												 */
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 */
/*						@ SYSCFG Must be enabled by RCC									 */
/*						@ NVIC Enable interrupt must be used after this function		 */
/*****************************************************************************************/
void MEXTI_voidSetCallBack(MEXTI_LINE_t Copy_udtLineNum, void(*Copy_pvCallBackFunc)(void));






#endif /* MEXTI_MEXTI_INTERFACE_H_ */
