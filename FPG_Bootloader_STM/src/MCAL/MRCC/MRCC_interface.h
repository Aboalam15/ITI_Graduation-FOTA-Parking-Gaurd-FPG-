/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MRCC_interface.h -> functions prototypes
peri		: for the developer in MCAL only not for the user
*/


#ifndef MRCC_MRCC_INTERFACE_H_
#define MRCC_MRCC_INTERFACE_H_

/*********************************************/
/*********************************************/
/******************************	user defined MACROS		******************************/

/***************	RCC Peripheral IDs		***************/

/*	AHB1  peripherals */
#define		MRCC_GPIOA_EN			0
#define		MRCC_GPIOB_EN			1
#define		MRCC_GPIOC_EN			2
#define		MRCC_GPIOD_EN			3
#define		MRCC_GPIOE_EN			4
#define		MRCC_GPIOH_EN			7
#define		MRCC_CRC_EN				12
#define		MRCC_DMA1_EN			21
#define		MRCC_DMA2_EN			22
/*	APB1  peripherals */
#define		MRCC_TIM2_EN			0
#define		MRCC_TIM3_EN			1
#define		MRCC_TIM4_EN			2
#define		MRCC_TIM5_EN			3

/*	APB2 Peripherals*/
#define		MRCC_SYSCFG_EN			14
#define		MRCC_USART1_EN			4
#define 	MRCC_FLITFLP_EN			15

/******************************	user defined DATA TYPES		******************************/
/***************	RCC Bus NAME	 ***************/
typedef enum{
	MRCC_AHB1	=0,
	MRCC_AHB1LP	  ,
	MRCC_AHB2	  ,
	MRCC_AHB2LP	  ,
	MRCC_APB1	  ,
	MRCC_APB1LP	  ,
	MRCC_APB2     ,
	MRCC_APB2LP

}Bus_NAME_t;

/*********************************************/
/*********************************************/

/***************	RCC FUNCTIONS prototypes	***************/
/********************************************************************************************/
/* @Name  	  :->		@ MRCC_voidInitializeSystemClock								 	*/
/* @Brief 	  :->		@ used to initialize RCC System Clock PreBuild configurations	 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the configuration must be set in the prebuild file (MRCC_config.h)*/
/********************************************************************************************/
void MRCC_voidInitializeSystemClock(void);
/*****************************************************************************************/
/* @Name  	  :->		@ MRCC_voidEnablePeripheralClock								 */
/* @Brief 	  :->		@ used to Enable the wanted to use Peripherals					 */
/* 				    	  to reserve power  											 */
/* @parameters   :-> 	@ Copy_udtBusName: the name of the internal processor bus		 */
/* 										   connect to the peripheral					 */
/* 						@ Copy_u8PeripheralNUM: the number of the bit corresponding to 	 */
/* 											peripheral in the enable control register	 */
/* @PreRequsteis :->	@ RCC system Clock must be initialized					 		 */
/*****************************************************************************************/
void MRCC_voidEnablePeripheralClock(Bus_NAME_t Copy_u8BusName,u8 Copy_u8PeripheralNUM);
/*****************************************************************************************/
/* @Name  	  :->		@ MRCC_voidDisablePeripheralClock								 */
/* @Brief 	  :->		@ used to disable not in use Peripherals						 */
/* 				    	  to reserve power  											 */
/* @parameters   :-> 	@ Copy_udtBusName: the name of the internal processor bus		 */
/* 										   connect to the peripheral					 */
/* 						@ Copy_u8PeripheralNUM: the number of the bit corresponding to 	 */
/* 											peripheral in the enable control register	 */
/* @PreRequsteis :->	@ RCC system Clock must be initialized					 		 */
/*****************************************************************************************/
void MRCC_voidDisablePeripheralClock(Bus_NAME_t Copy_udtBusName,u8 Copy_u8PeripheralNUM);

#endif /* MRCC_MRCC_INTERFACE_H_ */
