/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MRCC_private.h ->	private data
peri		: for the developer in MCAL only not for the user
*/


#ifndef MRCC_MRCC_PRIVATE_H_
#define MRCC_MRCC_PRIVATE_H_

/*****************************************************/
/*****************************************************/

/***************	RCC Clock SElECT macros		***************/
#define 	MRCC_HSI		0
#define  	MRCC_HSE		1
#define		MRCC_PLL		2

/*****************************************************/
/*****************************************************/

/***************	RCC HSE Source macros		***************/

#define 	MRCC_HSE_CRYSTAL	0
#define 	MRCC_HSE_RC			1
#define		MRCC_HSE_DISABLED	2

/*****************************************************/
/*****************************************************/

/***************	RCC CR Register BITS		***************/

#define 	MRCC_CR_HSION		0
#define 	MRCC_CR_HSEON		16
#define		MRCC_CR_HSEBYP		18
#define		MRCC_CR_PLLON		24

/***************	RCC CFCR Register BITS		***************/

#define 	MRCC_CFGR_SW0		0
#define 	MRCC_CFGR_SW1		1

/***************		RCC PLL SOURCE			***************/

#define		MRCC_PLL_HSE			0
#define 	MRCC_PLL_HSI			1
#define 	MRCC_PLL_DISABLED		2

/*****************************************************/
/*****************************************************/
#endif /* MRCC_MRCC_PRIVATE_H_ */
