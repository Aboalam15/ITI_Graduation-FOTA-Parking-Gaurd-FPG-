/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MEXTI_program.c -> Functions impelemntations
peri		: for the developer in MCAL only not for the user
*/

/*********************************************/
/*********************************************/

/***************	EXTI Files include	***************/
/*Standard LIBS*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*EXTI files*/
#include "MEXTI_interface.h"
#include "MEXTI_private.h"
#include "MEXTI_config.h"
#include "MEXTI_register.h"

/*********************************************/
/*********************************************/

/***************	Global VAR	***************/
static void (*MEXTI_GpvCallBackFunc[15])(void)= {NULL};
u8 GlobalFlag=NULL;
/***************	EXTI Functions Implementations	***************/

/*****************************************************************************************/
/* @Name  	  :->		@ MEXTI_voidEnableEXTI											 */
/* @Brief 	  :->		@ used to Enable the wanted EXT_interrupt wanted channel(0:15)	 */
/* @parameters   :-> 	@ Copy_udtLineNum: the number corresponding the interrupt		 */
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 */
/*						@ SYSCFG Must be enabled by RCC									 */
/*						@ trigger source and interrupt PIN/PORT must be selected before  */
/*						@ NVIC Enable interrupt must be used after this function		 */
/*****************************************************************************************/
void MEXTI_voidEnableEXTI(MEXTI_LINE_t Copy_udtLineNum){
	SET_BIT(MEXTI->IMR,Copy_udtLineNum);		/*enable the channel of the interrupt*/
}
/*****************************************************************************************/
/* @Name  	  :->		@ MEXTI_voidDisableEXTI											 */
/* @Brief 	  :->		@ used to Disable the NOT wanted EXT_interrupt channel(0:15)	 */
/* @parameters   :-> 	@ Copy_udtLineNum: the number corresponding the interrupt		 */
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 */
/*						@ SYSCFG Must be enabled by RCC									 */
/*						@ NVIC Enable interrupt must be used after this function		 */
/*****************************************************************************************/
void MEXTI_voidDisableEXTI(MEXTI_LINE_t Copy_udtLineNum){
	CLR_BIT(MEXTI->IMR,Copy_udtLineNum);		/*Disable the channel of the interrupt*/
}
/*****************************************************************************************/
/* @Name  	  :->		@ MEXTI_voidTriggerSource										 */
/* @Brief 	  :->		@ set the interrupt trigger source								 */
/* @parameters   :-> 	@ Copy_udtLineNum: the number corresponding the interrupt		 */
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 */
/*						@ SYSCFG Must be enabled by RCC									 */
/*						@ NVIC Enable interrupt must be used after this function		 */
/*****************************************************************************************/
void MEXTI_voidTriggerSource(MEXTI_LINE_t Copy_udtLineNum, u8 Copy_u8TriggerSource){
	/*check on trigger source*/
	switch(Copy_u8TriggerSource){
	case MEXTI_RISING_EDGE: SET_BIT(MEXTI->RTSR,Copy_udtLineNum);		/*Set the value of RTSR register to 1 in order to set rising edge trigger source*/
							CLR_BIT(MEXTI->FTSR,Copy_udtLineNum);		/*Set the value of FTSR register to 0 in order to set rising edge trigger source*/
							break;										/*end of case rising edge*/
	case MEXTI_FALLING_EDGE: CLR_BIT(MEXTI->RTSR,Copy_udtLineNum);		/*Set the value of RTSR register to 0 in order to set rising edge trigger source*/
							 SET_BIT(MEXTI->FTSR,Copy_udtLineNum);		/*Set the value of FTSR register to 1 in order to set rising edge trigger source*/
							 break;                               		/*end of case rising edge*/
	case MEXTI_ANY_CHANGE: SET_BIT(MEXTI->RTSR,Copy_udtLineNum); 		/*Set the value of RTSR register to 1 in order to set rising edge trigger source*/
						   SET_BIT(MEXTI->FTSR,Copy_udtLineNum); 		/*Set the value of FTSR register to 1 in order to set rising edge trigger source*/
						   break;                                		/*end of any change*/
	}
}
/*****************************************************************************************/
/* @Name  	  :->		@ MEXTI_voidSelectPort											 */
/* @Brief 	  :->		@ set the interrupt PORT/pin									 */
/* @parameters   :-> 	@ Copy_udtLineNum: the number corresponding the interrupt		 */
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 */
/*						@ SYSCFG Must be enabled by RCC									 */
/*						@ NVIC Enable interrupt must be used after this function		 */
/*****************************************************************************************/
void MEXTI_voidSelectPort(MEXTI_LINE_t Copy_udtLineNum,u8 Copy_u8PortNUM){
/*check on the interrupt channel*/
	if(Copy_udtLineNum<=4){
			SYSCFG_EXTICR1 &= ~(0x0000000F<<(Copy_udtLineNum*4));				/*set the channel in the register*/
			SYSCFG_EXTICR1 |= (Copy_u8PortNUM<<(4));							/*set the port in the register*/
	}
	else if((Copy_udtLineNum<9)&&(Copy_udtLineNum>=5)){
		SYSCFG_EXTICR2 &= ~(0x0000000F<<((Copy_udtLineNum-5)*4));				/*set the channel in the register*/
		SYSCFG_EXTICR2 |= (Copy_u8PortNUM <<(4));                				/*set the port in the register*/
	}
	else if((Copy_udtLineNum<12)&&(Copy_udtLineNum>=9)){
		SYSCFG_EXTICR3 &= ~(0x0000000F<<((Copy_udtLineNum-9)*4));				/*set the channel in the register*/
		SYSCFG_EXTICR3 |= (Copy_u8PortNUM<<(4));                 				/*set the port in the register*/
	}
	else if((Copy_udtLineNum<16)&&(Copy_udtLineNum>=12)){
		SYSCFG_EXTICR4 &= ~(0x0000000F<<((Copy_udtLineNum-12)*4));              /*set the channel in the register*/
		SYSCFG_EXTICR4 |= (Copy_u8PortNUM<<(4));                               	/*set the port in the register*/
	}
	else{
		asm("NOP");
	}
}
/*****************************************************************************************/
/* @Name  	  :->		@ MEXTI_voidSetCallBack											 */
/* @Brief 	  :->		@ set ISR to the interrupt										 */
/* @parameters   :-> 	@ Copy_pvCallBackFunc: Pointer to the routine to be preformed at */
/*						  Interrupt fire												 */
/*****************************************************************************************/
void MEXTI_voidSetCallBack(MEXTI_LINE_t Copy_udtLineNum, void(*Copy_pvCallBackFunc)(void)){
	MEXTI_GpvCallBackFunc[Copy_udtLineNum]=Copy_pvCallBackFunc;		/*set the global ptr to function value to pass the ISR to the Handler*/
	GlobalFlag=Copy_udtLineNum;
}
/********************************************************************************************************/
/*****************																*************************/
/*****************				External interrupts Handlers					*************************/
/*****************																*************************/
/********************************************************************************************************/
/********************************************************************************************/
/* @Name  	  :->		@ EXTI0_IRQHandler												 	*/
/* @Brief 	  :->		@ used to handle ISR Function									 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the interrupt must be triggered									*/
/********************************************************************************************/
void EXTI0_IRQHandler(void){
	if(MEXTI_GpvCallBackFunc[0] != NULL){
		MEXTI_GpvCallBackFunc[0]();
	}
	SET_BIT(MEXTI->PR,0);
}
/********************************************************************************************/
/* @Name  	  :->		@ EXTI1_IRQHandler												 	*/
/* @Brief 	  :->		@ used to handle ISR Function									 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the interrupt must be triggered									*/
/********************************************************************************************/
void EXTI1_IRQHandler(void){
	if(MEXTI_GpvCallBackFunc[1] != NULL){
		MEXTI_GpvCallBackFunc[1]();
	}
	SET_BIT(MEXTI->PR,0);
}
/********************************************************************************************/
/* @Name  	  :->		@ EXTI2_IRQHandler												 	*/
/* @Brief 	  :->		@ used to handle ISR Function									 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the interrupt must be triggered									*/
/********************************************************************************************/
void EXTI2_IRQHandler(void){
	if(MEXTI_GpvCallBackFunc[2] != NULL){
		MEXTI_GpvCallBackFunc[2]();
	}
	SET_BIT(MEXTI->PR,0);
}
/********************************************************************************************/
/* @Name  	  :->		@ EXTI3_IRQHandler												 	*/
/* @Brief 	  :->		@ used to handle ISR Function									 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the interrupt must be triggered									*/
/********************************************************************************************/
void EXTI3_IRQHandler(void){
	if(MEXTI_GpvCallBackFunc[3] != NULL){
		MEXTI_GpvCallBackFunc[3]();
	}
	SET_BIT(MEXTI->PR,0);
}
/********************************************************************************************/
/* @Name  	  :->		@ EXTI4_IRQHandler												 	*/
/* @Brief 	  :->		@ used to handle ISR Function									 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the interrupt must be triggered									*/
/********************************************************************************************/
void EXTI4_IRQHandler(void){
	if(MEXTI_GpvCallBackFunc[4] != NULL){
		MEXTI_GpvCallBackFunc[4]();
	}
	SET_BIT(MEXTI->PR,0);
}
/********************************************************************************************/
/* @Name  	  :->		@ EXTI9_5_IRQHandler											 	*/
/* @Brief 	  :->		@ used to handle ISR Function									 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the interrupt must be triggered									*/
/********************************************************************************************/
void EXTI9_5_IRQHandler(void){
	if(MEXTI_GpvCallBackFunc[GlobalFlag] != NULL){
		MEXTI_GpvCallBackFunc[GlobalFlag]();
	}
	SET_BIT(MEXTI->PR,0);
}
/********************************************************************************************/
/* @Name  	  :->		@ EXTI15_10_IRQHandler											 	*/
/* @Brief 	  :->		@ used to handle ISR Function									 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the interrupt must be triggered									*/
/********************************************************************************************/
void EXTI15_10_IRQHandler(void){
	if(MEXTI_GpvCallBackFunc[GlobalFlag] != NULL){
		MEXTI_GpvCallBackFunc[GlobalFlag]();
	}
	SET_BIT(MEXTI->PR,0);
}
