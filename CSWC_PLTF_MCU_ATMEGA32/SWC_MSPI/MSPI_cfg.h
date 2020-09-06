/*
 * MSPI_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef MSPI_CFG_H_
#define MSPI_CFG_H_

#include "MSPI_int.h"

// SPI Interrupt Status
#define MSPI_SPI_INT_STATUS          MSPI_SPIE_DISABLE

// DATA Order (whether first bit sent is MSB or LSB)
#define MSPI_DATA_ORDER              MSPI_SPE_LSB_FIRST // MSB first to be sent (default in SPI)

// Clock Polarity
#define MSPI_CLK_POLRITY             MSPI_CPOL_IDLE_LOW // SCK is HIGH when the bus is idle

// Clock PHASE
#define MSPI_CLK_PHASE               MSPI_SPHA_SMPL_LEAD // Sample data at the leading (first) edge of SCK

// SPI Clock Rate Select
#define MSPI_PS_SELECT               MSPI_PS_16_NORMAL // normal speed mode (SPI2X = 0)

#endif /* MSPI_CFG_H_ */
