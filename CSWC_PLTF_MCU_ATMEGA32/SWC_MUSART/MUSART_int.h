/*
 * MUSART_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef MUSART_INT_H_
#define MUSART_INT_H_

/***********************************   UCSRA   ***************************/

// Double the USART Transmission Speed (only in Asynchronous)
#define MUSART_U2X_ENABLE       1 // only in Asynchronous
#define MUSART_U2X_DISABLE      0 // must in case of synchronous

/***********************************   UCSRB   ***************************/

// Receiver Enable
#define MUSART_RXEN_ENABLE       1
#define MUSART_RXEN_DISABLE      0

// Transmitter Enable
#define MUSART_TXEN_ENABLE       1
#define MUSART_TXEN_DISABLE      0

// RX Complete Interrupt Enable
#define MUSART_RXCIE_ENABLE      1
#define MUSART_RXCIE_DISABLE     0

// TX Complete Interrupt Enable
#define MUSART_TXCIE_ENABLE      1
#define MUSART_TXCIE_DISABLE     0

// USART Data Register Empty Interrupt Enable
#define MUSART_UDRIE_ENABLE      1
#define MUSART_UDRIE_DISABLE     0

/***********************************   UCSRC   ***************************/

// Register Select (bit 7 in UCSRC & bit 15 in UBRR)
#define MUSART_URSEL_W_UCSRC     1 // The URSEL must be one when writing the UCSRC
#define MUSART_URSEL_W_UBRRH     0 // The URSEL must be zero when writing the UBRRH

// USART Mode Select
#define MUSART_SYNCH       1 // Synchronous Operation
#define MUSART_ASYNCH      0 // Asynchronous Operation

//Parity Mode
#define MUSART_SYN_NO_PARITY     0 //synchronous mode
#define MUSART_DISABLED          0
#define MUSART_EVEN_PARITY       2
#define MUSART_ODD_PARITY        3

// Stop Bit Select
#define MUSART_USBS_2_BIT        1 // 2 bit
#define MUSART_USBS_1_BIT        0 // 1 bit
#define MUSART_SYN_NO_SP_BIT     0 // Synchronous mode

//number of data bits (character size)
#define MUSART_SYN_NO_BITS	     0 // synchronous mode
#define MUSART_5_BITS_DATA       0
#define MUSART_6_BITS_DATA       1
#define MUSART_7_BITS_DATA       2
#define MUSART_8_BITS_DATA       3
#define MUSART_9_BITS_DATA       4

// Clock Polarity (Write this bit to zero when Asynchronous mode is used.)
#define MUSART_UCPOL_RT_FR       0 //Rising Transmitter, Falling Receiver
#define MUSART_UCPOL_FT_RR       1 //Falling Transmitter, Rising Receiver
#define MUSART_UCPOL_DISABLE     0 //Asynchronous mode

/*****************************************************************************/

tenumFncErrorState MUSART_enuInit(void);
void MUSART_voidTransmitByte(u8 u8data);
void MUSART_voidprintln(void);
void MUSART_voidTransmitString(pu8 pu8data);
void MUSART_voidTransmitInt(u32 u32Value);
u8 MUSART_u8RecieveByte(void);
void MUSART_ReceiveString(u8 *Str);
void MUSART_Callback(void(*function_ptr) (void));


/*int main(void)
{
	HLCD_enuInit();
	MUSART_enuInit();
	MUSART_voidTransmitString("ismael wael");

	while (1)
	{
		u8 x = MUSART_u8RecieveByte();// receive byte from keyboard
		HLCD_enuWriteData(x);//display on LCD
		MUSART_voidTransmitByte(x);//echo
	}
}
 * */

#endif /* MUSART_INT_H_ */
