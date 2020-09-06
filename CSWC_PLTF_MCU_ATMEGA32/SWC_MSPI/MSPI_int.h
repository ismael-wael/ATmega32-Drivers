/*
 * MSPI_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef MSPI_INT_H_
#define MSPI_INT_H_


// SPI Interrupt Enable
#define MSPI_SPIE_ENABLE         1
#define MSPI_SPIE_DISABLE        0

// DATA Order (whether first bit sent is MSB or LSB)
#define MSPI_SPE_LSB_FIRST       1 // LSB first to be sent
#define MSPI_DORD_MSB_FIRST      0 // MSB first to be sent (default in SPI)

// Clock Polarity
#define MSPI_CPOL_IDLE_HIGH      1 // SCK is HIGH when the bus is idle
#define MSPI_CPOL_IDLE_LOW       0 // SCK is LOW when the bus is idle

// Clock PHASE
#define MSPI_SPHA_SMPL_LEAD      1 // Sample data at the leading (first) edge of SCK
#define MSPI_SPHA_SMPL_TRAIL     0 // Sample data at the trailing (second) edge of SCK

// SPI Clock Rate Select
#define MSPI_PS_4_NORMAL           0 // normal speed mode (SPI2X = 0)
#define MSPI_PS_16_NORMAL          1 // normal speed mode (SPI2X = 0)
#define MSPI_PS_64_NORMAL          2 // normal speed mode (SPI2X = 0)
#define MSPI_PS_128_NORMAL         3 // normal speed mode (SPI2X = 0)
#define MSPI_PS_2_DOUBLE_SPEED     4 // Double speed mode (SPI2X = 1)
#define MSPI_PS_8_DOUBLE_SPEED     5 // Double speed mode (SPI2X = 1)
#define MSPI_PS_32_DOUBLE_SPEED    6 // Double speed mode (SPI2X = 1)
#define MSPI_PS_64_DOUBLE_SPEED    7 // Double speed mode (SPI2X = 1)

/************************************************************************/

tenumFncErrorState MSPI_enuSlaveInit(void);
tenumFncErrorState MSPI_enuMasterInit(void);
void SPI_DataTransmit_String(pu8 pu8String);
void SPI_DataTransmit_Byte(u8 u8Value);
u8 SPI_DataRecieve_Byte(void);
void SPI_DataRecieve_String(u8 x[]);
void SPI_Callback(void(*function_ptr) (void));



#endif /* MSPI_INT_H_ */
