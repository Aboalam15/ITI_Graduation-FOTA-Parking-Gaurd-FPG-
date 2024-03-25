/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MRCC_config.h -> PreBuild configurations
peri		: for the developer in MCAL only not for the user
*/
#ifndef MRCC_MRCC_CONFIG_H_
#define MRCC_MRCC_CONFIG_H_

/*****************************************************/
/*****************************************************/

/***************	RCC Clock SElECTION		***************/
/*		->	OPTIONS
 * 					1-	MRCC_HSI
 * 					2-	MRCC_HSE
 * 					3- 	MRCC_PLL
 */

#define 		MRCC_CLK_SOURCE				MRCC_HSI

/*****************************************************/
/*****************************************************/

/***************	RCC HSE SOURCE		***************/
/*	@ Active only when in HSE CLOCK SOURCE
 * 	->	OPTIONS
 * 					1-	MRCC_HSE_CRYSTAL		-> for external HSE Crystal Clock SOURCE
 * 					2-	MRCC_HSE_RC				-> For external HSE Electrical RC Clock SOURCE
 * 					3-  MRCC_HSE_DISABLED		-> Different clock source is used
 */

#define 		MRCC_HSE_SOURCE				MRCC_HSE_DISABLED

/*****************************************************/
/*****************************************************/

/***************	PLL SOURCE		***************/
/*	@ Active only when in PLL CLOCK SOURCE
 * 		->	OPTIONS
 * 					1-	MRCC_PLL_HSE			-> PLL SOURCE from HSE CLOCK
 * 					2-	MRCC_PLL_HSI			-> PLL SOURCE from HSI CLOCK
 * 					3-  MRCC_PLL_DISABLED		-> Different clock source is used
 */

#define 		MRCC_PLL_SOURCE				MRCC_PLL_DISABLED

/*****************************************************/
/*****************************************************/
#endif /* MRCC_MRCC_CONFIG_H_ */
