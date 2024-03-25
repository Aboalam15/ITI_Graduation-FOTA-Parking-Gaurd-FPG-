/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MSTK_private.h ->	private data
peri		: for the developer in MCAL only not for the user
*/

#ifndef MSTK_MSTK_PRIVATE_H_
#define MSTK_MSTK_PRIVATE_H_

/*****************************************************/
/*****************************************************/

/***************	MSTK CLOCK		***************/
#define 	MSTK_AHB			1
#define    	MSTK_AHB_DIV_8  	2

/*****************************************************/
/*****************************************************/
/***************	MSTK CTRL register BITs 	***************/

#define 	MSTK_CTRL_ENABLE		0
#define 	MSTK_CTRL_INTERRUPT		1
#define 	MSTK_CTRL_CLKSRC		2
#define 	MSTK_CTRL_COUNTFLAG		16

/*****************************************************/
/*****************************************************/

#endif /* MSTK_MSTK_PRIVATE_H_ */
