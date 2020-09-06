/*
 * MWDT_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */
//main avr libraries
#include "util/delay.h"
//#include "avr/io.h"
//used libraries
#include "../../LIB_STDTypes/LIB_stdTypes.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../Platform/ATMega32_Features.h"
//MWDT
#include "MWDT_int.h"

void MWDT_voidInit(u8 u8Val)
{
	if (u8Val == MWDT_16_ms)
	{
		WDTCR &=~(1<<WDP0) & ~(1<<WDP1) & ~(1<<WDP2);
	}
	else if( u8Val == MWDT_32_ms)
	{
		WDTCR &=~(1<<WDP1) & ~(1<<WDP2);
		WDTCR |=(1<<WDP0);
	}
	else if(u8Val == MWDT_65_ms)
	{
		WDTCR &=~(1<<WDP0) & ~(1<<WDP2);
		WDTCR |=(1<<WDP1);
	}

	else if (u8Val == MWDT_130_ms)
	{
		WDTCR &=~(1<<WDP2);
		WDTCR |=(1<<WDP1) | (1<<WDP0);
	}
	else if( u8Val == MWDT_260_ms )
	{
		WDTCR &=~(1<<WDP0) & ~(1<<WDP1);
		WDTCR |=(1<<WDP2);
	}
	else if( u8Val == MWDT_520_ms )
	{
		WDTCR &=~(1<<WDP1);
		WDTCR |=(1<<WDP2) | (1<<WDP0);
	}

	else if( u8Val == MWDT_1000_ms )
	{
		WDTCR &=~(1<<WDP0);
		WDTCR |=(1<<WDP2) | (1<<WDP1);
	}
	else if( u8Val == MWDT_2100_ms )
	{
		WDTCR |=(1<<WDP2) | (1<<WDP1) | (1<<WDP0);
	}

	WDTCR |=(1<<WDE); // Enable the WatchDog Timer
}

void MWDT_voidDisableWDT(void)
{
	WDTCR = (1<<WDTOE) | (1<<WDE);
	/* Turn off WDT */
	WDTCR = 0x00;
}
