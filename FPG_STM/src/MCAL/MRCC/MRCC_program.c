/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MRCC_program.c -> Functions impelemntations
peri		: for the developer in MCAL only not for the user
*/

/*********************************************/
/*********************************************/

/***************	RCC Files include	***************/
/*Standard LIBS*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*RCC files*/
#include "MRCC_interface.h"
#include "MRCC_private.h"
#include "MRCC_config.h"
#include "MRCC_registers.h"

/*********************************************/
/*********************************************/

/***************	RCC Functions Implementations	***************/
/********************************************************************************************/
/* @Name  	  :->		@ MRCC_voidInitializeSystemClock								 	*/
/* @Brief 	  :->		@ used to initialize RCC System Clock PreBuild configurations	 	*/
/* @parameters   :-> 	@ void															    */
/* @PreRequsteis :->	@ the configuration must be set in the prebuild file (MRCC_config.h)*/
/********************************************************************************************/
void MRCC_voidInitializeSystemClock(void){
		#if MRCC_CLK_SOURCE==MRCC_HSI
			/*ENABLE HSI*/
			SET_BIT(MRCC_CR,MRCC_CR_HSION);
			/*SelectHSI for the system*/
			CLR_BIT(MRCC_CFGR,MRCC_CFGR_SW0);
			CLR_BIT(MRCC_CFGR,MRCC_CFGR_SW1);
		#elif	MRCC_CLK_SOURCE==MRCC_HSE
				#if	MRCC_HSE_SOURCE == MRCC_HSE_CRYSTAL
				/*Enable HSE*/
				SET_BIT(MRCC_CR,MRCC_CR_HSEON);
				/*Disable BYPASS*/
				CLR_BIT(MRCC_CR,MRCC_CR_HSEBYP);
				/*Select HSE for the system*/
				SET_BIT(MRCC_CFGR,MRCC_CFGR_SW0);
				CLR_BIT(MRCC_CFGR,MRCC_CFGR_SW1);
				#elif MRCC_HSE_SOURCE == MRCC_HSE_RC
				/*Enable HSE*/
				SET_BIT(MRCC_CR,MRCC_CR_HSEON);
				/*Enable BYPASS*/
				SET_BIT(MRCC_CR,MRCC_CR_HSEBYP);
				/*Select HSE for the system*/
				SET_BIT(MRCC_CFGR,MRCC_CFGR_SW0);
				CLR_BIT(MRCC_CFGR,MRCC_CFGR_SW1);
				#endif
		#elif	MRCC_CLK_SOURCE==MRCC_PLL
			#if	MRCC_PLL_SOURCE==MRCC_PLL_HSE
				#if	MRCC_HSE_SOURCE == MRCC_HSE_CRYSTAL
					/*Enable HSE*/
					SET_BIT(MRCC_CR,MRCC_CR_HSEON);
					/*Disable BYPASS*/
					CLR_BIT(MRCC_CR,MRCC_CR_HSEBYP);
					/*Select PLL for the system*/
					CLR_BIT(MRCC_CFGR,MRCC_CFGR_SW0);
					SET_BIT(MRCC_CFGR,MRCC_CFGR_SW1);
					#elif MRCC_HSE_SOURCE == MRCC_HSE_RC
					/*Enable HSE*/
					SET_BIT(MRCC_CR,MRCC_CR_HSEON);
					/*Enable BYPASS*/
					SET_BIT(MRCC_CR,MRCC_CR_HSEBYP);
					/*Select PLL for the system*/
					CLR_BIT(MRCC_CFGR,MRCC_CFGR_SW0);
					SET_BIT(MRCC_CFGR,MRCC_CFGR_SW1);
					#endif
			#elif MRCC_PLL_SOURCE==MRCC_PLL_HSI
					/*ENABLE HSI*/
					SET_BIT(MRCC_CR,MRCC_CR_HSION);
					/*Select PLL for the system*/
					CLR_BIT(MRCC_CFGR,MRCC_CFGR_SW0);
					SET_BIT(MRCC_CFGR,MRCC_CFGR_SW1);
			#endif
		#else
			#error "Invalid Clock Source..."
		#endif
}

/*****************************************************************************************/
/* @Name  	  :->		@ MRCC_voidEnablePeripheralClock								 */
/* @Brief 	  :->		@ used to Enable the wanted to use Peripherals					 */
/* 				    	  to reserve power  											 */
/* @parameters   :-> 	@ Copy_udtBusName: the name of the internal processor bus		 */
/* 										   connect to the peripheral					 */
/* 						@ Copy_u8PeripheralNUM: the number of the bit corresponding to 	 */
/* 											peripheral in the enable control register	 */
/* @PreRequsteis :->	@ RCC  system Clock must be initialized					 		 */
/*****************************************************************************************/
void MRCC_voidEnablePeripheralClock(Bus_NAME_t Copy_u8BusName,u8 Copy_u8PeripheralNUM){
	switch (Copy_u8BusName){
			case MRCC_AHB1:	SET_BIT(MRCC_AHB1ENR,Copy_u8PeripheralNUM);		break;     /*enable Peripheral on the AHB1 BUS*/
			case MRCC_AHB2:	SET_BIT(MRCC_AHB2ENR,Copy_u8PeripheralNUM);		break;     /*enable Peripheral on the AHB2 BUS*/
			case MRCC_APB1:	SET_BIT(MRCC_APB1ENR,Copy_u8PeripheralNUM);		break;     /*enable Peripheral on the APB1 BUS*/
			case MRCC_APB2:	SET_BIT(MRCC_APB2ENR,Copy_u8PeripheralNUM);		break;     /*enable Peripheral on the APB2 BUS*/
			case MRCC_AHB1LP:SET_BIT(MRCC_AHB1LPENR,Copy_u8PeripheralNUM);	break;     /*enable Peripheral on the AHB1LP BUS*/
			case MRCC_AHB2LP:SET_BIT(MRCC_AHB2LPENR,Copy_u8PeripheralNUM);	break;     /*enable Peripheral on the AHB2LP BUS*/
			case MRCC_APB1LP:SET_BIT(MRCC_APB1LPENR,Copy_u8PeripheralNUM);	break;     /*enable Peripheral on the APB1LP BUS*/
			case MRCC_APB2LP:SET_BIT(MRCC_APB2LPENR,Copy_u8PeripheralNUM);	break;     /*enable Peripheral on the APB2LP BUS*/
		}
}
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
void MRCC_voidDisablePeripheralClock(Bus_NAME_t Copy_udtBusName,u8 Copy_u8PeripheralNUM){
	switch (Copy_udtBusName){
			case MRCC_AHB1:	CLR_BIT(MRCC_AHB1ENR,Copy_u8PeripheralNUM);		break;		/*Disable Peripheral on the AHB1 BUS*/
			case MRCC_AHB2:	CLR_BIT(MRCC_AHB2ENR,Copy_u8PeripheralNUM);		break;		/*Disable Peripheral on the AHB2 BUS*/
			case MRCC_APB1:	CLR_BIT(MRCC_APB1ENR,Copy_u8PeripheralNUM);		break;		/*Disable Peripheral on the APB1 BUS*/
			case MRCC_APB2:	CLR_BIT(MRCC_APB2ENR,Copy_u8PeripheralNUM);		break;		/*Disable Peripheral on the APB2 BUS*/
			case MRCC_AHB1LP:CLR_BIT(MRCC_AHB1LPENR,Copy_u8PeripheralNUM);	break;      /*Disable Peripheral on the AHB1LP BUS*/
			case MRCC_AHB2LP:CLR_BIT(MRCC_AHB2LPENR,Copy_u8PeripheralNUM);	break;      /*Disable Peripheral on the AHB2LP BUS*/
			case MRCC_APB1LP:CLR_BIT(MRCC_APB1LPENR,Copy_u8PeripheralNUM);	break;      /*Disable Peripheral on the APB1LP BUS*/
			case MRCC_APB2LP:CLR_BIT(MRCC_APB2LPENR,Copy_u8PeripheralNUM);	break;      /*Disable Peripheral on the APB2LP BUS*/
		}
}

