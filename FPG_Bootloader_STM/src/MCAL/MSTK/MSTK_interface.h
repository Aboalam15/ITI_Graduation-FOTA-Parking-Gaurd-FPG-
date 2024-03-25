/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MRCC_interface.h -> functions prototypes
peri		: for the developer in MCAL only not for the user
*/

#ifndef MSTK_MSTK_INTERFACE_H_
#define MSTK_MSTK_INTERFACE_H_
/*********************************************/
/*********************************************/

/***************	SYSTIK FUNCTIONS prototypes	***************/
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidIntialize											 	*/
/* @Brief 	  :->		@ used to initialize STK System timer PreBuild configurations	 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the configuration must be set in the prebuild file (MSTK_config.h)*/
/********************************************************************************************/
void MSTK_voidIntialize(void);
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidStartTimer											 	*/
/* @Brief 	  :->		@ used to START SYS tick timer 							 		 	*/
/* @parameters   :-> 	@ Copy_u32LoadValue-> Number of ticks							    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/********************************************************************************************/
void MSTK_voidStartTimer(u32 Copy_u32LoadValue);
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidStopTimer											 	*/
/* @Brief 	  :->		@ used to stop SYS tick timer 							 		 	*/
/* @parameters   :-> 	@ Copy_u32LoadValue-> Number of ticks							    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/********************************************************************************************/
void MSTK_voidStopTimer(void);
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidDelayMS											 	*/
/* @Brief 	  :->		@ used to as a delay function (Pooling)					 		 	*/
/* @parameters   :-> 	@ Copy_u32DelayMS-> Delay in Milliseconds							    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/********************************************************************************************/
void MSTK_voidDelayMS(u32 Copy_u32DelayMS);
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidDelayMS											 	*/
/* @Brief 	  :->		@ used to as a delay function (Pooling)					 		 	*/
/* @parameters   :-> 	@ Copy_u32DelayMS-> Delay in Micro Seconds							    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/********************************************************************************************/
void MSTK_voidDelayUS(u32 Copy_u32DelayUS);
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_u32GetElapsedTime										 	*/
/* @Brief 	  :->		@ used to return the passed time from the set time		 		 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/* @return type  :->	@u32 number of elapsed ticks		 								*/
/********************************************************************************************/
u32 MSTK_u32GetElapsedTime(void);
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_u32GetRemainingTime										 	*/
/* @Brief 	  :->		@ used to return the remaining time from the set time	 		 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/* @return type  :->	@u32 number of remaining ticks		 								*/
/********************************************************************************************/
u32 MSTK_u32GetRemainingTime(void);
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidSetIntervalSingle									 	*/
/* @Brief 	  :->		@ used to enable timer interrupt for one time only		 		 	*/
/* @parameters   :-> 	@ Copy_u32TicksNUM-> Number of ticks							    */
/*						@ Copy_pvCallBackFunction-> Pointer to the ISR function			    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/********************************************************************************************/
void MSTK_voidSetIntervalSingle(u32 Copy_u32TicksNUM,void(*Copy_pvCallBackFunction)(void));
/********************************************************************************************/
/* @Name  	  :->		@ MSTK_voidSetIntervalPeriodic									 	*/
/* @Brief 	  :->		@ used to enable timer interrupt periodically			 		 	*/
/* @parameters   :-> 	@ Copy_u32TicksNUM-> Number of ticks							    */
/*						@ Copy_pvCallBackFunction-> Pointer to the ISR function			    */
/* @PreRequsteis :->	@ MSTK system Clock must be initialized								*/
/********************************************************************************************/
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32TicksNUM,void(*Copy_pvCallBackFunction)(void));

void MSTK_voidSetBusyWait(u32 Copy_u32TicksNUM);

/*********************************************/
/*********************************************/
#endif /* MSTK_MSTK_INTERFACE_H_ */
