/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MSTK_program.c -> Functions implementations
peri		: for the developer in MCAL only not for the user
*/

/*********************************************/
/*********************************************/

/***************	SYSTIK Files include	***************/
/*Standard LIBS*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*RCC files*/
#include "MSTK_interface.h"
#include "MSTK_private.h"
#include "MSTK_config.h"
#include "MSTK_register.h"

/*********************************************/
/*********************************************/
/***************	Global VARIABLES	***************/

static void(*MSTK_Gpv_CallBackFunc)(void)= NULL;		/*pointer to the function of call back to the ISR*/

static u8 Gu8_PeriodicFlag = 0;			/*flag used to set periodic/single time timer interrupt*/

/*********************************************/
/*********************************************/
/***************	SYSTIK Functions Implementations	***************/
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidIntialize											 	*/
/* @Brief 	  :->		@ used to initialize STK System timer PreBuild configurations	 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the configuration must be set in the prebuild file (MSTK_config.h)*/
/********************************************************************************************/
void MSTK_voidIntialize(void){
	#if MSTK_CLOCK_SOURCE==MSTK_AHB
		/*chose AHB for clock source*/
		SET_BIT(MSTK->CTRL,MSTK_CTRL_CLKSRC);
	#elif MSTK_CLOCK_SOURCE==MSTK_AHB_DIV_8
		/*chose AHB/8 clock source*/
		CLR_BIT(MSTK->CTRL,MSTK_CTRL_CLKSRC);
	#endif
}
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidStartTimer											 	*/
/* @Brief 	  :->		@ used to START SYS tick timer 							 		 	*/
/* @parameters   :-> 	@ Copy_u32LoadValue-> Number of ticks							    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/********************************************************************************************/
void MSTK_voidStartTimer(u32 Copy_u32LoadValue){
	/*Load value in LOAD register*/
	MSTK->LOAD=Copy_u32LoadValue;
	/*start timer*/
	SET_BIT(MSTK->CTRL,MSTK_CTRL_ENABLE);
}
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidStopTimer											 	*/
/* @Brief 	  :->		@ used to stop SYS tick timer 							 		 	*/
/* @parameters   :-> 	@ Copy_u32LoadValue-> Number of ticks							    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/********************************************************************************************/
void MSTK_voidStopTimer(void){
	/*disable timer*/
	CLR_BIT(MSTK->CTRL,MSTK_CTRL_ENABLE);
}
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidDelayMS											 	*/
/* @Brief 	  :->		@ used to as a delay function (Pooling)					 		 	*/
/* @parameters   :-> 	@ Copy_u32DelayMs-> Delay in Milliseconds						    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/********************************************************************************************/
void MSTK_voidDelayMS(u32 Copy_u32DelayMs){
	/* Disable Interrupt*/
	CLR_BIT(MSTK->CTRL,1);
	u32 Copy_32TicksNumber = (Copy_u32DelayMs * 2000);
	/*load value in load register*/
	MSTK->LOAD = Copy_32TicksNumber;
	/*reset timer */
	MSTK->VAL = 0;
	/*Start timer*/
	SET_BIT(MSTK->CTRL,MSTK_CTRL_ENABLE);
	/*wait for timer*/
	while(GET_BIT(MSTK->CTRL,MSTK_CTRL_COUNTFLAG)!=1){
		asm("NOP");
	}
	/*stop timer*/
	CLR_BIT(MSTK->CTRL,MSTK_CTRL_ENABLE);
}
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidSetBusyWait											 	*/
/* @Brief 	  :->		@ used to as a delay function (Pooling)					 		 	*/
/* @parameters   :-> 	@ Copy_u32DelayUS-> Delay in Micro seconds							    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/********************************************************************************************/
void MSTK_voidDelayUS(u32 Copy_u32DelayUS){
	/* Disable Interrupt*/
	CLR_BIT(MSTK->CTRL,1);

	u32 Copy_32TicksNumber = (Copy_u32DelayUS * 2);
	/*load value in load register*/
	MSTK->LOAD = Copy_32TicksNumber;
	/*reset timer */
	MSTK->VAL = 0;
	/*Start timer*/
	SET_BIT(MSTK->CTRL,MSTK_CTRL_ENABLE);
	/*wait for timer*/
	while(GET_BIT(MSTK->CTRL,MSTK_CTRL_COUNTFLAG)!=1){
		asm("NOP");
	}
	/*stop timer*/
	CLR_BIT(MSTK->CTRL,MSTK_CTRL_ENABLE);
}
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_u32GetElapsedTime										 	*/
/* @Brief 	  :->		@ used to return the passed time from the set time		 		 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/* @return type  :->	@u32 number of elapsed ticks		 								*/
/********************************************************************************************/
u32 MSTK_u32GetElapsedTime(void){
	return (MSTK->LOAD - MSTK->VAL); 			/*return the value of the passed time*/
}
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_u32GetRemainingTime										 	*/
/* @Brief 	  :->		@ used to return the remaining time from the set time	 		 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/* @return type  :->	@u32 number of remaining ticks		 								*/
/********************************************************************************************/
u32 MSTK_u32GetRemainingTime(void){
	return (MSTK->VAL);		/*return the remaining value of the timer in val register*/
}
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidSetIntervalSingle									 	*/
/* @Brief 	  :->		@ used to enable timer interrupt for one time only		 		 	*/
/* @parameters   :-> 	@ Copy_u32TicksNUM-> Number of ticks							    */
/*						@ Copy_pvCallBackFunction-> Pointer to the ISR function			    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/********************************************************************************************/
void MSTK_voidSetIntervalSingle(u32 Copy_u32TicksNUM,void(*Copy_pvCallBackFunction)(void)){
	/*set call back function*/
	MSTK_Gpv_CallBackFunc=Copy_pvCallBackFunction;
	/*set periodic flag  as non periodic*/
	Gu8_PeriodicFlag=0;
	/*enable interrupt*/
	SET_BIT(MSTK->CTRL,MSTK_CTRL_INTERRUPT);
	/*reset timer*/
	MSTK->VAL=0;
	/*load value in load register*/
	MSTK->LOAD= Copy_u32TicksNUM;
	/*start timer */
	SET_BIT(MSTK->CTRL,MSTK_CTRL_ENABLE);
}
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidSetIntervalPeriodic									 	*/
/* @Brief 	  :->		@ used to enable timer interrupt periodically			 		 	*/
/* @parameters   :-> 	@ Copy_u32TicksNUM-> Number of ticks							    */
/*						@ Copy_pvCallBackFunction-> Pointer to the ISR function			    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/********************************************************************************************/
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32TicksNUM,void(*Copy_pvCallBackFunction)(void)){
	/*set call back function*/
	MSTK_Gpv_CallBackFunc=Copy_pvCallBackFunction;
	/*set periodic flag  as  periodic*/
	Gu8_PeriodicFlag=1;
	/*enable interrupt*/
	SET_BIT(MSTK->CTRL,MSTK_CTRL_INTERRUPT);
	/*reset timer*/
	MSTK->VAL=0;
	/*load value in load register*/
	MSTK->LOAD= Copy_u32TicksNUM;
	/*start timer */
	SET_BIT(MSTK->CTRL,MSTK_CTRL_ENABLE);
}

/********************************************************************************************************/
/*****************																*************************/
/*****************				SYSTIK interrupts Handlers							*************************/
/*****************																*************************/
/********************************************************************************************************/
/********************************************************************************************/
/* @Name  	  :->		@ Systick_Handler												 	*/
/* @Brief 	  :->		@ used to handle ISR Function									 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the interrupt must be triggered									*/
/********************************************************************************************/
void SysTick_Handler(void){
u8 Local_VAR=0;
	if(MSTK_Gpv_CallBackFunc != NULL){
		MSTK_Gpv_CallBackFunc();
	}
	Local_VAR =  GET_BIT(MSTK->CTRL,MSTK_CTRL_COUNTFLAG);
	if(Gu8_PeriodicFlag==0){
		CLR_BIT(MSTK->CTRL,MSTK_CTRL_ENABLE);
	}
}

void MSTK_voidSetBusyWait(u32 Copy_u32TicksNUM){
	MSTK->CTRL = 0;
	CLR_BIT(MSTK->CTRL,1);

	/*load value in load register*/
	MSTK->LOAD = Copy_u32TicksNUM;
	/*reset timer */
	MSTK->VAL = 0;
	/*Start timer*/
	SET_BIT(MSTK->CTRL,MSTK_CTRL_ENABLE);
	/*wait for timer*/
	while(GET_BIT(MSTK->CTRL,MSTK_CTRL_COUNTFLAG)!=1){
		asm("NOP");
	}
	/*stop timer*/
	CLR_BIT(MSTK->CTRL,MSTK_CTRL_ENABLE);
}

/*********************************************/
/*********************************************/
/*********************************************/
/*********************************************/
/*********************************************/
/*********************************************/
