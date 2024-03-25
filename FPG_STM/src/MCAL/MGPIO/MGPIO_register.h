/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MGPIO_register.h -> registers address
peri		: for the developer in MCAL only not for the user
*/

#ifndef MGPIO_MGPIO_REGISTER_H_
#define MGPIO_MGPIO_REGISTER_H_

/*****************************************************/
/*****************************************************/

/***************	GPIO BaseAddress		***************/

#define 	MGPIOA_BASE_ADDRESS		0x40020000
#define 	MGPIOB_BASE_ADDRESS		0x40020400
#define		MGPIOC_BASE_ADDRESS		0x40020800

/*****************************************************/
/*****************************************************/

/***************	GPIO registers	***************/
typedef struct{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDER;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}MGPIOx_t;
/*****************************************************/
/*****************************************************/

/***************	GPIO registers ADRRESS		***************/

#define 	MGPIOA		((volatile MGPIOx_t *)(MGPIOA_BASE_ADDRESS))
#define 	MGPIOB		((volatile MGPIOx_t *)(MGPIOB_BASE_ADDRESS))
#define 	MGPIOC		((volatile MGPIOx_t *)(MGPIOC_BASE_ADDRESS))

/*****************************************************/
/*****************************************************/
#endif /* MGPIO_MGPIO_REGISTER_H_ */
