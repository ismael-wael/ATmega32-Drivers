/*
 * MTWI_prg.c
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

//MTWI
#include "MTWI_int.h"
#include "MTWI_cfg.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

static volatile void (*G_TWI)  (void)='\0' ;


/*******************************************************************************
 *                                ISR'S                                        *
 *******************************************************************************/
ISR(TWI_vect)
{
	if (G_TWI!='\0')
	{
		(*G_TWI)();
	}
}
/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

tenumFncErrorState MTWI_enuInit(void)
{
	tenumFncErrorState ReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	TWCR |=(1<<TWEN);//Enable TWI

	TWSR=0x00;//Clear TWI Status Register (clear previous settings of status and prescaler)

	/*putting address & General Call Recognition: on */
	TWAR = MTWI_Slave_Add ;

	#if MTWI_MODE == MTWI_MSTR_MODE

		//pull up of SDA, SCL
		SET_BIT(PORTC_Register,0);
		SET_BIT(PORTC_Register,1);

		#if MTWI_CLK == MTWI_clk_50_KHZ
			TWBR = 72;
		#elif MTWI_CLK == MTWI_clk_100_KHZ
			TWBR = 32;
		#elif MTWI_CLK == MTWI_clk_160_KHZ
			TWBR = 17;
		#elif MTWI_CLK == MTWI_clk_200_KHZ
			TWBR = 12;
		#endif
	#elif MTWI_MODE == MTWI_SLV_MODE
			TWBR = 0;
	#endif

	return ReturnFncState;
}

void MTWI_voidStartCond(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); //start condition

	while (!(TWCR & (1<<TWINT))); //Wait for TWINT Flag set. This indicates
	//that the SLA+W has been transmitted, and ACK/NACK has been received.
}

void MTWI_voidStopCond(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO); // Transmit STOP condition
}

void MTWI_voidWriteByte(u8 u8data)
{
	TWDR = u8data; //Load DATA into TWDR Register.
	TWCR = (1<<TWINT) | (1<<TWEN); // Clear TWINT bit in TWCR to start transmission of data

	while (!(TWCR & (1<<TWINT))); //Wait for TWINT Flag set. This indicates
	//that the DATA has been transmitted, and ACK/NACK has been received.
}

u8 MTWI_enuReadStatus(void)
{
	u8 Status = TWSR & 0xF8;
	return Status ;
}

u8 MTWI_enuReadByteACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA); //Enable Ack

	while (!(TWCR & (1<<TWINT))); //Wait for TWINT Flag set. This indicates
		//that the DATA has been transmitted, and ACK/NACK has been received.

	return TWDR;
}


u8 MTWI_enuReadByteNACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN); //Disable Ack

	while (!(TWCR & (1<<TWINT))); //Wait for TWINT Flag set. This indicates
		//that the DATA has been transmitted, and ACK/NACK has been received.

	return TWDR;
}

state MTWI_enuSendString(u8 address,const pu8 str_ptr)
{
	u8 SLA_W,i=0 ;

	/* Send the Start Bit */
	MTWI_voidStartCond();

	if (MTWI_enuReadStatus() != MTWI_START)
	{
		MTWI_voidStopCond();
		return ERROR;
	}
	/* Send the Device Address */
	SLA_W=(address<<1) ; // 7-bit address + 0 (Write)
	MTWI_voidWriteByte(SLA_W);

	if (MTWI_enuReadStatus() != MTWI_MT_SLA_ACK)
	{
		MTWI_voidStopCond();
		return ERROR;
	}

	/* Send the Data */
	while(str_ptr[i]!='\0')
	{
		MTWI_voidWriteByte(str_ptr[i]);
		_delay_us(500);
		if (MTWI_enuReadStatus() != MTWI_MT_DATA_ACK)
		{
			MTWI_voidStopCond();
			return ERROR;
		}
		i++ ;
	}
	/* Send the Stop Bit */
	MTWI_voidStopCond();
	return SUCCESS;
}

void MTWI_voidReceiveString(pu8 buffer)
{
	static u8 i ;
	if((MTWI_enuReadStatus() == MTWI_SR_SLA_W_ACK) || (MTWI_enuReadStatus() == MTWI_SR_GCALL_ACK))
	{
		i=0 ; //start of data
	}

	else if ((MTWI_enuReadStatus() == MTWI_SR_DATA_ACK) || (MTWI_enuReadStatus() == MTWI_SR_GC_DATA_ACK))
	{
		buffer[i++]=TWDR; //get data in case of receive address or general call
	}
	buffer[i]='\0' ;
	TWCR |= (1 << TWINT);
}


void MTWI_Callback(void(*function_ptr) (void))
{
	G_TWI=function_ptr ;
}


