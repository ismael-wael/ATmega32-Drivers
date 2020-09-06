/*
 * HStepperMotor_prg.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: Ismael Wael
 */

//main avr libraries
#include "util/delay.h"
//#include "avr/io.h"
#define F_CPU 8000000UL
//used libraries
#include "../../LIB_STDTypes/LIB_stdTypes.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../Platform/ATMega32_Features.h"

//MDIO
#include "../../CSWC_PLTF_MCU_ATMEGA32/SWC_MDIO/MDIO_int.h"

//HStepperMotor
#include "HStepperMotor_init.h"
#include "HStepperMotor_cfg.h"

void HStepper_voidInit(void)
{
	MDIO_enuSetPinDirection(HStepper_Blue,MDIO_u8DIROUTPUT);
	MDIO_enuSetPinDirection(HStepper_Pink,MDIO_u8DIROUTPUT);
	MDIO_enuSetPinDirection(HStepper_Yellow,MDIO_u8DIROUTPUT);
	MDIO_enuSetPinDirection(HStepper_Orange,MDIO_u8DIROUTPUT);
}

void Stepper_RotateCCW(void)
{
	MDIO_enuSetPinValue(HStepper_Blue,MDIO_u8OUTPUTHIGH);
	MDIO_enuSetPinValue(HStepper_Pink,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Yellow,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Orange,MDIO_u8OUTPUTLOW);
	_delay_ms(5);

	MDIO_enuSetPinValue(HStepper_Blue,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Pink,MDIO_u8OUTPUTHIGH);
	MDIO_enuSetPinValue(HStepper_Yellow,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Orange,MDIO_u8OUTPUTLOW);
	_delay_ms(5);

	MDIO_enuSetPinValue(HStepper_Blue,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Pink,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Yellow,MDIO_u8OUTPUTHIGH);
	MDIO_enuSetPinValue(HStepper_Orange,MDIO_u8OUTPUTLOW);
	_delay_ms(5);

	MDIO_enuSetPinValue(HStepper_Blue,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Pink,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Yellow,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Orange,MDIO_u8OUTPUTHIGH);
	_delay_ms(5);
}

void Stepper_RotateCW(void)
{

	MDIO_enuSetPinValue(HStepper_Blue,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Pink,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Yellow,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Orange,MDIO_u8OUTPUTHIGH);
	_delay_ms(5);

	MDIO_enuSetPinValue(HStepper_Blue,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Pink,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Yellow,MDIO_u8OUTPUTHIGH);
	MDIO_enuSetPinValue(HStepper_Orange,MDIO_u8OUTPUTLOW);
	_delay_ms(5);

	MDIO_enuSetPinValue(HStepper_Blue,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Pink,MDIO_u8OUTPUTHIGH);
	MDIO_enuSetPinValue(HStepper_Yellow,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Orange,MDIO_u8OUTPUTLOW);
	_delay_ms(5);

	MDIO_enuSetPinValue(HStepper_Blue,MDIO_u8OUTPUTHIGH);
	MDIO_enuSetPinValue(HStepper_Pink,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Yellow,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HStepper_Orange,MDIO_u8OUTPUTLOW);
	_delay_ms(5);
}






