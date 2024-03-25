/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MSTK_config.h -> PreBuild configurations
peri		: for the developer in MCAL only not for the user
*/

#ifndef MSTK_MSTK_CONFIG_H_
#define MSTK_MSTK_CONFIG_H_
/*****************************************************/
/*****************************************************/

/***************	MSTK CLOCK source select		***************/
/*-> select the source of clock for systick
 * 			options->
 * 						1- MSTK_AHB
 * 						2- MSTK_AHB_DIV_8
 *
 */

#define 	MSTK_CLOCK_SOURCE		MSTK_AHB_DIV_8


/*****************************************************/
/*****************************************************/
#endif /* MSTK_MSTK_CONFIG_H_ */
