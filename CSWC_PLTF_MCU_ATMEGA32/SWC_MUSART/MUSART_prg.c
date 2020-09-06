/*
 * MUSART_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

//main avr libraries
#include "util/delay.h"
#include "avr/interrupt.h"
//#include "avr/io.h"

//used libraries
#include "../../LIB_STDTypes/LIB_stdTypes.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../Platform/ATMega32_Features.h"

//USART
#include "MUSART_int.h"
#include "MUSART_cfg.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
static void (*G_UART_RX)  (void)= LSTY_NULL ;
static void (*G_UART_TX)  (void)= LSTY_NULL ;
/*******************************************************************************
 *                                ISR'S                                        *
 *******************************************************************************/
ISR(USART_RXC_vect)
{
	if (G_UART_RX!=LSTY_NULL)
		{
			(*G_UART_RX)();
		}
}

ISR(USART_TXC_vect)
{
	if (G_UART_TX!=LSTY_NULL)
		{
			(*G_UART_TX)();
		}
}

/*******************************************************************************
 *                                  Functions                                  *
 *******************************************************************************/

tenumFncErrorState MUSART_enuInit(void)
{
	    tenumFncErrorState ReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	    //the transmit buffer (UDR) is ready to receive new data
	    BMNP_u8SetBit(UCSRA,UDRE);

	    // Receiver Enable/Disable
	    #if MUSART_RXEN == MUSART_RXEN_ENABLE
	          BMNP_u8SetBit(UCSRB, RXEN);
	    #elif MUSART_RXEN == MUSART_RXEN_DISABLE
	          BMNP_u8ClearBit(UCSRB, RXEN);
	    #endif

	  	// Transmitter Enable/Disable
	  	#if MUSART_TXEN == MUSART_TXEN_ENABLE
	  	      BMNP_u8SetBit(UCSRB, TXEN);
	  	#elif MUSART_TXEN == MUSART_TXEN_DISABLE
	  	      BMNP_u8ClearBit(UCSRB, TXEN);
	  	#endif

	  	// RX Complete Interrupt Enable/Disable
	  	#if MUSART_RXCIE == MUSART_RXCIE_ENABLE
	  	      BMNP_u8SetBit(UCSRB, RXCIE);
	  	      BMNP_u8SetBit(SREG, 7);
	  	#elif MUSART_RXCIE == MUSART_RXCIE_DISABLE
	  	      BMNP_u8ClearBit(UCSRB, RXCIE);
	  	#endif

	  	// TX Complete Interrupt Enable/Disable
	  	#if MUSART_TXCIE == MUSART_TXCIE_ENABLE
	  	  	  BMNP_u8SetBit(UCSRB, TXCIE);
	  	  	  BMNP_u8SetBit(SREG, 7);
	  	#elif MUSART_TXCIE == MUSART_TXCIE_DISABLE
	  	  	  BMNP_u8ClearBit(UCSRB, TXCIE);
	  	#endif

	  	// USART Data Register Empty Interrupt Enable/Disable
	  	#if MUSART_UDRIE == MUSART_UDRIE_ENABLE
	  	  	  BMNP_u8SetBit(UCSRB, UDRIE);
	  	  	  BMNP_u8SetBit(SREG, 7);
	  	#elif MUSART_UDRIE == MUSART_UDRIE_DISABLE
	  	  	  BMNP_u8ClearBit(UCSRB, UDRIE);
	  	#endif
/********************************************************************************/

		#if MUSART_MODE == MUSART_ASYNCH

	  		   // Double the USART Transmission Speed
	  		    #if MUSART_U2X == MUSART_U2X_ENABLE
	  		    	 BMNP_u8SetBit(UCSRA, U2X);
	  		    #elif MUSART_U2X == MUSART_U2X_DISABLE
	  		    	 BMNP_u8ClearBit(UCSRA, U2X);
	  		   	#endif

	  		   	//baud rate (Asynchronous Mode)
	  		   	#if MUSART_U2X == MUSART_U2X_ENABLE // Double Speed Mode
	  		   	     UBRRH &=~(1<<7);
	  		   	  	 UBRRH = (((u32)(8000000)/((u32)8*MUSART_BAUD_RATE))-1 ) >> 8;
	  		   	  	 UBRRL = (((u32)(8000000)/((u32)8*MUSART_BAUD_RATE))-1 ) & 0x0ff;
	  		    	//UBRRL = 51;
	  		   	#elif MUSART_U2X == MUSART_U2X_DISABLE // Normal Mode
	  		   	  	 UBRRH &=~(1<<7);
	  		   	  	 UBRRH = (((u32)(8000000)/((u32)16*MUSART_BAUD_RATE))-1) >> 8;
	  		   	  	 UBRRL = (((u32)(8000000)/((u32)16*MUSART_BAUD_RATE))-1) & 0x0ff;
	  		   	#endif

				#if MUSART_CHAR_SIZE == MUSART_9_BITS_DATA
	  		   	  	 SET_BIT(UCSRB,UCSZ2);
				#elif MUSART_CHAR_SIZE != MUSART_9_BITS_DATA
	  		   	  	 CLR_BIT(UCSRB,UCSZ2);
				#endif

	  		   	// the UCSRC register should be set at once, not bit by bit
	  		   	UCSRC = conc(MUSART_UCPOL_DISABLE,MUSART_CHAR_SIZE_UCSZ0,MUSART_CHAR_SIZE_UCSZ1,MUSART_USBS,MUSART_PARITY_UPM0,MUSART_PARITY_UPM1,MUSART_ASYNCH,MUSART_URSEL_W_UCSRC);


		#elif MUSART_MODE == MUSART_SYNCH

	  		   	BMNP_u8ClearBit(UCSRA, U2X); // Write this bit to zero when using synchronous operation.

	  		   	//Baud Rate (Synchronous Mode)
	  		   	UBRRH &=~(1<<7);
	  		   	UBRRH = (((u32)(8000000)/((u32)2*MUSART_BAUD_RATE))-1) >> 8;
	  		   	UBRRL = (((u32)(8000000)/((u32)2*MUSART_BAUD_RATE))-1) & 0x0ff;

	  		    // the UCSRC register should be set at once, not bit by bit
	  		   	UCSRC = conc(MUSART_UCPOL,MUSART_SYN_NO_BITS,MUSART_SYN_NO_BITS,MUSART_SYN_NO_SP_BIT,MUSART_SYN_NO_PARITY,MUSART_SYN_NO_PARITY,MUSART_SYNCH,MUSART_URSEL_W_UCSRC);
		#endif


	  	return ReturnFncState;
}

void MUSART_voidTransmitByte(u8 u8data)
{
	//USART Data Register Empty
	while(!GET_BIT(UCSRA,UDRE));
	UDR = u8data;
}

void MUSART_voidprintln(void)
{
	//USART Data Register Empty
	while(!GET_BIT(UCSRA,UDRE));
	UDR = '\n';
	while(!GET_BIT(UCSRA,UDRE));
	UDR = '\r';
}

void MUSART_voidTransmitString(pu8 pu8data)
{
	for(u8 i = 0; pu8data[i] != '\0' ; i++)
	{
		MUSART_voidTransmitByte(pu8data[i]);
	}
}

void MUSART_voidTransmitInt(u32 u32Value)
{
	u8 tenth = u32Value%10 ? 0 : 1;
	u8 a;
	u32 r = 0;

	while(u32Value >= 1)/*reverse the value : 2070 -> 0702*/
	{
		a = u32Value%10;
		r = r*10+a;
		u32Value = u32Value / 10;
	}

	while(r >= 1) /*reverse again and print : 207*/
	{
		a = r%10;
		MUSART_voidTransmitByte(a+'0');
		r = r / 10;
	}

	if(tenth)/*if last digit was 0 (i.e, tenth = 1), then print 0*/
	{
		MUSART_voidTransmitByte('0');
	}
	/*final output -> 2070*/
}

u8 MUSART_u8RecieveByte(void)
{
	// USART Receive Complete
	while(!GET_BIT(UCSRA,RXC));
	return UDR;
}

void MUSART_ReceiveString(u8 *Str)
{
	u8 i = 0;
	Str[i] = MUSART_u8RecieveByte();
	while(Str[i] != '\0')
	{
		i++;
		Str[i] = MUSART_u8RecieveByte();
	}
	Str[i] = '\0';
}

/*
 * calling back function enable you to use UART_ISR
 * Any function passed to callback function will be
 * called in ISR (when the condition occurs)
 */

void MUSART_Callback_TX(void(*function_ptr) (void))
{
	G_UART_TX = function_ptr ;
}

void MUSART_Callback_RX(void(*function_ptr) (void))
{
	G_UART_RX = function_ptr ;
}



