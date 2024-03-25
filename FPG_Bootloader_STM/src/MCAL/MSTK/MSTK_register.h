/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MSTK_register.h -> registers address
peri		: for the developer in MCAL only not for the user
*/


#ifndef MSTK_MSTK_REGISTER_H_
#define MSTK_MSTK_REGISTER_H_

/*****************************************************/
/*****************************************************/

/***************	MSTK BaseAddress		***************/
#define 		MSTK_BASE_ADDRESS			0xE000E010

/*****************************************************/
/*****************************************************/

/***************	MSTK registers	***************/
typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}MSTK_t;
/***************	MSTK registers ADRRESS		***************/

#define 	MSTK		((volatile MSTK_t*)(MSTK_BASE_ADDRESS))

/*****************************************************/
/*****************************************************/
#endif /* MSTK_MSTK_REGISTER_H_ */
