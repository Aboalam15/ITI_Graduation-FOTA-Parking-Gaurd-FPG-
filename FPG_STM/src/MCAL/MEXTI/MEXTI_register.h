/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MEXTI_register.h -> registers address
peri		: for the developer in MCAL only not for the user
*/


#ifndef MEXTI_MEXTI_REGISTER_H_
#define MEXTI_MEXTI_REGISTER_H_
/*****************************************************/
/*****************************************************/

/***************	EXTI BaseAddress		***************/
#define 	MEXTI_BASE_ADDRESS		 0x40013C00
/***************	SYSCFG BaseAddress		***************/
#define    	SYSCFG_BASE_ADDRESS		 0x40013800
/*****************************************************/
/*****************************************************/

/***************	EXTI Registers		***************/
typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}MEXTI_t;

/***************	EXTI Register address		***************/
#define MEXTI		((volatile MEXTI_t*)(MEXTI_BASE_ADDRESS))
/***************	SYSCFG Register address		***************/
#define  SYSCFG_EXTICR1		*((volatile u32*)(0x40013808))
#define  SYSCFG_EXTICR2		*((volatile u32*)(0x4001380C))
#define  SYSCFG_EXTICR3		*((volatile u32*)(0x40013810))
#define  SYSCFG_EXTICR4		*((volatile u32*)(0x40013814))
#endif /* MEXTI_MEXTI_REGISTER_H_ */
