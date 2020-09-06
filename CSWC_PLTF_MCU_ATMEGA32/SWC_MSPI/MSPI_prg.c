/*
 * MSPI_prg.c
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

//MSPI
#include "MSPI_int.h"
#include "MSPI_cfg.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

static volatile void (*G_SPI)  (void)='\0' ;

/*******************************************************************************
 *                                ISR'S                                        *
 *******************************************************************************/
/*ISR(SPI_STC_vect)
{
	if (G_SPI!='\0')
		{
			(*G_SPI)();
		}
}*/
/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/


tenumFncErrorState MSPI_enuMasterInit(void)
{
	    tenumFncErrorState ReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;
	    //SPI Enable
	    BMNP_u8SetBit(SPCR, SPE);
	    //Enable SPI Master Mode
		BMNP_u8SetBit(SPCR, MSTR);
		//SS pin as output
		BMNP_u8SetBit(DDRB_Register,4);
		//MOSI pin as output
		BMNP_u8SetBit(DDRB_Register,5);
		//MISO pin as input
		BMNP_u8ClearBit(DDRB_Register,6);
		//SCK pin as output
		BMNP_u8SetBit(DDRB_Register,7);

	    // SPI Interrupt Status
	    #if MSPI_SPI_INT_STATUS ==  MSPI_SPIE_ENABLE
	    	BMNP_u8SetBit(SPCR, SPIE);
        #elif MSPI_SPI_INT_STATUS ==  MSPI_SPIE_DISABLE
	    	BMNP_u8ClearBit(SPCR, SPIE);
        #endif

		// DATA Order (whether first bit sent is MSB or LSB)
		#if MSPI_DATA_ORDER ==  MSPI_DORD_MSB_FIRST
			BMNP_u8ClearBit(SPCR, DORD);
		#elif MSPI_DATA_ORDER ==  MSPI_SPE_LSB_FIRST
			BMNP_u8SetBit(SPCR, DORD);
	    #endif

		// Clock Polarity
		#if MSPI_CLK_POLRITY ==  MSPI_CPOL_IDLE_HIGH
			BMNP_u8SetBit(SPCR, CPOL);
		#elif MSPI_CLK_POLRITY ==  MSPI_CPOL_IDLE_LOW
			BMNP_u8ClearBit(SPCR, CPOL);
	    #endif

		// Clock PHASE
		#if MSPI_CLK_PHASE ==  MSPI_SPHA_SMPL_LEAD
			BMNP_u8SetBit(SPCR, CPHA);
		#elif MSPI_CLK_PHASE ==  MSPI_SPHA_SMPL_TRAIL
			BMNP_u8ClearBit(SPCR, CPHA);
		#endif

		// SPI Clock Rate Select
		#if MSPI_PS_SELECT ==  MSPI_PS_4_NORMAL
			SPCR &= ~(1 << SPR1) & ~(1 << SPR0);
			BMNP_u8ClearBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT == MSPI_PS_16_NORMAL
			SPCR |=(1 << SPR0);
			SPCR &= ~(1 << SPR1);
			BMNP_u8ClearBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT ==  MSPI_PS_64_NORMAL
			SPCR |= (1 << SPR1);
			SPCR &= ~(1 << SPR0);
			BMNP_u8ClearBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT ==  MSPI_PS_128_NORMAL
			SPCR |= (1 << SPR1) | (1 << SPR0);
			BMNP_u8ClearBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT ==  MSPI_PS_2_DOUBLE_SPEED
			SPCR &= ~(1 << SPR1) & ~(1 << SPR0);
			BMNP_u8SetBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT ==  MSPI_PS_8_DOUBLE_SPEED
			SPCR |=(1 << SPR0);
			SPCR &= ~(1 << SPR1);
			BMNP_u8SetBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT ==  MSPI_PS_32_DOUBLE_SPEED
			SPCR |= (1 << SPR1);
			SPCR &= ~(1 << SPR0);
			BMNP_u8SetBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT ==  MSPI_PS_64_DOUBLE_SPEED
			SPCR |= (1 << SPR1) | (1 << SPR0);
			BMNP_u8SetBit(SPSR, SPI2X);
		#endif

	  	 return ReturnFncState;
}

tenumFncErrorState MSPI_enuSlaveInit(void)
{
	    tenumFncErrorState ReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;
	    //SPI Enable
	    BMNP_u8SetBit(SPCR, SPE);
	    //Enable SPI Slave Mode
		BMNP_u8ClearBit(SPCR, MSTR);
		//SS pin as input
		BMNP_u8ClearBit(DDRB_Register,4);
		//MOSI pin as input
		BMNP_u8ClearBit(DDRB_Register,5);
		//MISO pin as output
		BMNP_u8SetBit(DDRB_Register,6);
		//SCK pin as input
		BMNP_u8ClearBit(DDRB_Register,7);

	    // SPI Interrupt Status
	    #if MSPI_SPI_INT_STATUS ==  MSPI_SPIE_ENABLE
	    	BMNP_u8SetBit(SPCR, SPIE);
        #elif MSPI_SPI_INT_STATUS ==  MSPI_SPIE_DISABLE
	    	BMNP_u8ClearBit(SPCR, SPIE);
        #endif

		// DATA Order (whether first bit sent is MSB or LSB)
		#if MSPI_DATA_ORDER ==  MSPI_DORD_MSB_FIRST
			BMNP_u8ClearBit(SPCR, DORD);
		#elif MSPI_DATA_ORDER ==  MSPI_SPE_LSB_FIRST
			BMNP_u8SetBit(SPCR, DORD);
	    #endif

		// Clock Polarity
		#if MSPI_CLK_POLRITY ==  MSPI_CPOL_IDLE_HIGH
			BMNP_u8SetBit(SPCR, CPOL);
		#elif MSPI_CLK_POLRITY ==  MSPI_CPOL_IDLE_LOW
			BMNP_u8ClearBit(SPCR, CPOL);
	    #endif

		// Clock PHASE
		#if MSPI_CLK_PHASE ==  MSPI_SPHA_SMPL_LEAD
			BMNP_u8SetBit(SPCR, CPHA);
		#elif MSPI_CLK_PHASE ==  MSPI_SPHA_SMPL_TRAIL
			BMNP_u8ClearBit(SPCR, CPHA);
		#endif

		// SPI Clock Rate Select
		#if MSPI_PS_SELECT ==  MSPI_PS_4_NORMAL
			SPCR &= ~(1 << SPR1) & ~(1 << SPR0);
			BMNP_u8ClearBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT == MSPI_PS_16_NORMAL
			SPCR |=(1 << SPR0);
			SPCR &= ~(1 << SPR1);
			BMNP_u8ClearBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT ==  MSPI_PS_64_NORMAL
			SPCR |= (1 << SPR1);
			SPCR &= ~(1 << SPR0);
			BMNP_u8ClearBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT ==  MSPI_PS_128_NORMAL
			SPCR |= (1 << SPR1) | (1 << SPR0);
			BMNP_u8ClearBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT ==  MSPI_PS_2_DOUBLE_SPEED
			SPCR &= ~(1 << SPR1) & ~(1 << SPR0);
			BMNP_u8SetBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT ==  MSPI_PS_8_DOUBLE_SPEED
			SPCR |=(1 << SPR0);
			SPCR &= ~(1 << SPR1);
			BMNP_u8SetBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT ==  MSPI_PS_32_DOUBLE_SPEED
			SPCR |= (1 << SPR1);
			SPCR &= ~(1 << SPR0);
			BMNP_u8SetBit(SPSR, SPI2X);
		#elif MSPI_PS_SELECT ==  MSPI_PS_64_DOUBLE_SPEED
			SPCR |= (1 << SPR1) | (1 << SPR0);
			BMNP_u8SetBit(SPSR, SPI2X);
		#endif

	  	 return ReturnFncState;
}

void SPI_DataTransmit_String(pu8 pu8String)
{
	u8 i = 0;
	PORTB_Register &=~(1<<4);//low on SS pin
	while(pu8String[i] != '\0')
	{
		SPDR = pu8String[i];
		i++;
		while(!GET_BIT(SPSR,SPIF));
		_delay_ms(20);
	}
	PORTB_Register |=(1<<4);//high on SS pin
}


void SPI_DataTransmit_Byte(u8 u8Value)
{
	PORTB_Register &=~(1<<4);//low on SS pin
	SPDR = u8Value;
	while(!GET_BIT(SPSR,SPIF));
	PORTB_Register |=(1<<4);//high on SS pin
}

u8 SPI_DataRecieve_Byte(void)
{
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}

void SPI_DataRecieve_String(u8 x[])
{
	u8 i = 0;
	while(!GET_BIT(SPSR,SPIF));
	x[i] = SPDR;
	while(x[i] != '\0')
	{
		while(!GET_BIT(SPSR,SPIF));
		x[i++] = SPDR;
	}
	x[i] = '\0';
}

/*
 * calling back function enable you to use SPI_ISR
 * Any function passed to callback function will be
 * called in ISR
 */
/*void SPI_Callback(void(*function_ptr) (void))
{
	G_SPI=function_ptr ;
}*/

