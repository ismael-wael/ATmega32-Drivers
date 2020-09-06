/*
 * MUSART_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef MUSART_CFG_H_
#define MUSART_CFG_H_

#include "MUSART_int.h"

	// Receiver Enable/Disable
	#define MUSART_RXEN               MUSART_RXEN_ENABLE

	// Transmitter Enable/Disable
	#define MUSART_TXEN               MUSART_TXEN_ENABLE

	// RX Complete Interrupt Enable/Disable
	#define MUSART_RXCIE              MUSART_RXCIE_DISABLE

	// TX Complete Interrupt Enable/Disable
	#define MUSART_TXCIE              MUSART_TXCIE_DISABLE

	// USART Data Register Empty Interrupt Enable/Disable
	#define MUSART_UDRIE              MUSART_UDRIE_DISABLE

/*****************************************************************************/

	//USART Mode Select (MUSART_ASYNCH , MUSART_SYNCH)
	#define MUSART_MODE					MUSART_ASYNCH


		#if MUSART_MODE == MUSART_ASYNCH
				#define MUSART_BAUD_RATE               9600

				// Double the USART Transmission Speed (only in Asynchronous)
				#define MUSART_U2X               MUSART_U2X_ENABLE

				// Parity Mode
				#define MUSART_PARITY             MUSART_EVEN_PARITY

    				#if MUSART_PARITY == MUSART_DISABLED
				 	 	 #define MUSART_PARITY_UPM0   0
         	 	 	 	 #define MUSART_PARITY_UPM1   0
    	    		#elif MUSART_PARITY == MUSART_EVEN_PARITY
			 	 	 	 #define MUSART_PARITY_UPM0   0
			     	 	 #define MUSART_PARITY_UPM1   1
    				#elif MUSART_PARITY == MUSART_ODD_PARITY
         	 	 	 	 #define MUSART_PARITY_UPM0   1
				 	 	 #define MUSART_PARITY_UPM1   1
    				#endif

				// Stop Bit Select
				#define MUSART_USBS               MUSART_USBS_1_BIT

				//number of data bits (character size)
				#define MUSART_CHAR_SIZE          MUSART_8_BITS_DATA

    				#if MUSART_CHAR_SIZE == MUSART_5_BITS_DATA
			 	 	 	 #define MUSART_CHAR_SIZE_UCSZ0   0
         	 	 	 	 #define MUSART_CHAR_SIZE_UCSZ1   0
         	 	 	 	 #define MUSART_CHAR_SIZE_UCSZ2   0
    				#elif MUSART_CHAR_SIZE == MUSART_6_BITS_DATA
			 	 	 	 #define MUSART_CHAR_SIZE_UCSZ0   1
         	 	 	 	 #define MUSART_CHAR_SIZE_UCSZ1   0
         	 	 	 	 #define MUSART_CHAR_SIZE_UCSZ2   0
    				#elif MUSART_CHAR_SIZE == MUSART_7_BITS_DATA
         	 	 	 	 #define MUSART_CHAR_SIZE_UCSZ0   0
         	 	 	 	 #define MUSART_CHAR_SIZE_UCSZ1   1
			 	 	 	 #define MUSART_CHAR_SIZE_UCSZ2   0
        			#elif MUSART_CHAR_SIZE == MUSART_8_BITS_DATA
         	 	 	 	 #define MUSART_CHAR_SIZE_UCSZ0   1
         	 	 	 	 #define MUSART_CHAR_SIZE_UCSZ1   1
         	 	 	 	 #define MUSART_CHAR_SIZE_UCSZ2   0
    				#elif MUSART_CHAR_SIZE == MUSART_9_BITS_DATA
			 	 	 	 #define MUSART_CHAR_SIZE_UCSZ0   1
         	 	 	 	 #define MUSART_CHAR_SIZE_UCSZ1   1
         	 	 	 	 #define MUSART_CHAR_SIZE_UCSZ2   1
    				#endif

		#elif MUSART_MODE == MUSART_SYNCH

				#define MUSART_BAUD_RATE               9600

				//Clock Polarity
				#define MUSART_UCPOL          MUSART_UCPOL_FT_RR

		#endif


#endif /* MUSART_CFG_H_ */
