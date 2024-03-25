/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MDMA_program.c -> Functions impelemntations
peri		: for the developer in MCAL only not for the user
*/

/*********************************************/
/*********************************************/

/***************	DMA Files include	***************/
/*Standard LIBS*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*DMA files*/
#include "MDMA_interface.h"
#include "MDMA_private.h"
#include "MDMA_config.h"
#include "MDMA_register.h"

/*********************************************/
/*********************************************/

/***************	Global VAR	***************/
void (*Gpv_DMA1_CallBACK_Func)(void)= NULL;		/*pointer to the function of call back to the ISR for DMA1*/
void (*Gpv_DMA2_CallBACK_Func)(void)= NULL;		/*pointer to the function of call back to the ISR for DMA2*/

/*********************************************/
/*********************************************/
/***************	DMA Functions Implementations	***************/
/********************************************************************************************/
/* @Name  	  :->		@ MDMA1_voidInit								 					*/
/* @Brief 	  :->		@ used to initialize DMA1 configurations						 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the DMA must be enabled in the RCC clock							*/
/********************************************************************************************/
void MDMA1_voidInit(void){
	CLR_BIT(DMA1->S[0].CR,1);
	DMA1->S[0].CR |= (1<<14) | (1<<12) | (1<<10) | (1<<9) | (1<<9) | (1<<7) |(1<<4);
	DMA1->S[0].FCR |= (1<<2) | (1<<1)  | (1<<0);
}

void MDMA1_voidSetStream(u8 Copy_u8StreamID, u32* Copy_pu32SrcAddress, u32* Copy_pu32DesAddress,u32 Copy_u32BlockSize){
	DMA1->S[Copy_u8StreamID].PAR = Copy_pu32SrcAddress;
	DMA1->S[Copy_u8StreamID].M0AR= Copy_pu32DesAddress;
	DMA1->S[Copy_u8StreamID].M1AR= Copy_u32BlockSize;
}

void MDMA1_voidEnableStream(u8 Copy_u8StreamID){
	DMA1->LIFCR |= (1<<0) | (1<<2) | (1<<3) | (1<<4) | (1<<5);
	SET_BIT(DMA1->S[Copy_u8StreamID].CR,0);
}
/*****************************************************************************************/
/* @Name  	  :->		@ MDMA1_voidSetStreamcallBack									 */
/* @Brief 	  :->		@ set ISR to the interrupt										 */
/* @parameters   :-> 	@ Copy_pvCallBackFunc: Pointer to the routine to be preformed at */
/*						  Interrupt fire												 */
/*****************************************************************************************/
void MDMA1_voidSetStreamcallBack(u8 Copy_u8StreamID,void (*pv_Function)(void)){
	Gpv_DMA1_CallBACK_Func= pv_Function;
	SET_BIT(DMA1->S[Copy_u8StreamID].CR,4);
}
/******************************************************/
/********************************************************************************************/
/* @Name  	  :->		@ MDMA1_voidInit								 					*/
/* @Brief 	  :->		@ used to initialize DMA1 configurations						 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the DMA must be enabled in the RCC clock							*/
/********************************************************************************************/
void MDMA2_voidInit(void){
	CLR_BIT(DMA2->S[0].CR,1);
	DMA2->S[0].CR |= (1<<14) | (1<<12) | (1<<10) | (1<<9) | (1<<9) | (1<<7) |(1<<4);
	DMA2->S[0].FCR |= (1<<2) | (1<<1)  | (1<<0);
}

void MDMA2_voidSetStream(u8 Copy_u8StreamID, u32* Copy_pu32SrcAddress, u32* Copy_pu32DesAddress,u32 Copy_u32BlockSize){
	DMA2->S[Copy_u8StreamID].PAR = Copy_pu32SrcAddress;
	DMA2->S[Copy_u8StreamID].M0AR= Copy_pu32DesAddress;
	DMA2->S[Copy_u8StreamID].M1AR= Copy_u32BlockSize;
}

void MDMA2_voidEnableStream(u8 Copy_u8StreamID){
	DMA2->LIFCR |= (1<<0) | (1<<2) | (1<<3) | (1<<4) | (1<<5);
	SET_BIT(DMA2->S[Copy_u8StreamID].CR,0);
}
/*****************************************************************************************/
/* @Name  	  :->		@ MDMA2_voidSetStreamcallBack									 */
/* @Brief 	  :->		@ set ISR to the interrupt										 */
/* @parameters   :-> 	@ Copy_pvCallBackFunc: Pointer to the routine to be preformed at */
/*						  Interrupt fire												 */
/*****************************************************************************************/
void MDMA2_voidSetStreamcallBack(u8 Copy_u8StreamID,void (*pv_Function)(void)){
	Gpv_DMA2_CallBACK_Func= pv_Function;
	SET_BIT(DMA2->S[Copy_u8StreamID].CR,4);
}
/********************************************************************************************************/
/*****************																*************************/
/*****************				DMA interrupts Handlers							*************************/
/*****************																*************************/
/********************************************************************************************************/

void DMA1_Stream0_IRQHandler(void) {
	if(Gpv_DMA1_CallBACK_Func!=NULL){
		Gpv_DMA1_CallBACK_Func();
	}
}

void DMA1_Stream1_IRQHandler(void) {
	if(Gpv_DMA1_CallBACK_Func!=NULL){
		Gpv_DMA1_CallBACK_Func();
	}
}

void DMA1_Stream2_IRQHandler(void) {
	if(Gpv_DMA1_CallBACK_Func!=NULL){
		Gpv_DMA1_CallBACK_Func();
	}
}

void DMA1_Stream3_IRQHandler(void) {
	if(Gpv_DMA1_CallBACK_Func!=NULL){
		Gpv_DMA1_CallBACK_Func();
	}
}

void DMA1_Stream4_IRQHandler(void) {
	if(Gpv_DMA1_CallBACK_Func!=NULL){
		Gpv_DMA1_CallBACK_Func();
	}
}

void DMA1_Stream5_IRQHandler(void) {
	if(Gpv_DMA1_CallBACK_Func!=NULL){
		Gpv_DMA1_CallBACK_Func();
	}
}


void DMA1_Stream6_IRQHandler(void) {
	if(Gpv_DMA1_CallBACK_Func!=NULL){
		Gpv_DMA1_CallBACK_Func();
	}
}

void DMA1_Stream7_IRQHandler(void) {
	if(Gpv_DMA1_CallBACK_Func!=NULL){
		Gpv_DMA1_CallBACK_Func();
	}
}


/***********************************************************/
void DMA2_Stream0_IRQHandler(void) {
	if(Gpv_DMA2_CallBACK_Func!=NULL){
		Gpv_DMA2_CallBACK_Func();
	}
}

void DMA2_Stream1_IRQHandler(void) {
	if(Gpv_DMA2_CallBACK_Func!=NULL){
		Gpv_DMA2_CallBACK_Func();
	}
}

void DMA2_Stream2_IRQHandler(void) {
	if(Gpv_DMA2_CallBACK_Func!=NULL){
		Gpv_DMA2_CallBACK_Func();
	}
}

void DMA2_Stream3_IRQHandler(void) {
	if(Gpv_DMA2_CallBACK_Func!=NULL){
		Gpv_DMA2_CallBACK_Func();
	}
}

void DMA2_Stream4_IRQHandler(void) {
	if(Gpv_DMA2_CallBACK_Func!=NULL){
		Gpv_DMA2_CallBACK_Func();
	}
}

void DMA2_Stream5_IRQHandler(void) {
	if(Gpv_DMA2_CallBACK_Func!=NULL){
		Gpv_DMA2_CallBACK_Func();
	}
}


void DMA2_Stream6_IRQHandler(void) {
	if(Gpv_DMA2_CallBACK_Func!=NULL){
		Gpv_DMA2_CallBACK_Func();
	}
}

void DMA2_Stream7_IRQHandler(void) {
	if(Gpv_DMA2_CallBACK_Func!=NULL){
		Gpv_DMA2_CallBACK_Func();
	}
}

/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
