/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MNVIC_register.h -> registers address
peri		: for the developer in MCAL only not for the user
*/
#ifndef MNVIC_MNVIC_REGISTER_H_
#define MNVIC_MNVIC_REGISTER_H_
/*****************************************************/
/*****************************************************/

/***************	NVIC BaseAddress		***************/
#define MNVIC_BASE_ADDRESS	 0xE000E100
/*****************************************************/
/*****************************************************/

/***************	NVIC Registers		***************/
typedef struct{
	u32 ISER[8];
	u32 RESERVED0[24];
	u32 ICER[8];
	u32 RESERVED1[24];
	u32 ISPR[8];
	u32 RESERVED2[24];
	u32 ICPR[8];
	u32 RESERVED3[24];
	u32 IABR[8];
	u32 RESERVED4[56];
	u8 IPR[240];
	u32 RESERVED5[580];
	u32 STIR;
}MNVIC_t;

/*****************************************************/
/*****************************************************/

/***************	NVIC Register		***************/
#define  MNVIC 	((volatile MNVIC_t*)(MNVIC_BASE_ADDRESS))
#define  MSCB_AICR	*((volatile u32*)(0xE000ED0C))

#define MNVIC_VECTKEY		0x05FA0000
#endif /* MNVIC_MNVIC_REGISTER_H_ */
