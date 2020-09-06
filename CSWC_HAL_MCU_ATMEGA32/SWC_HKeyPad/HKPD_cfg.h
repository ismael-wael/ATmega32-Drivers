#ifndef CSWC_PLTF_BSW_ATMEGA32_SWC_HKPD_HKPD_CFG_H_
#define CSWC_PLTF_BSW_ATMEGA32_SWC_HKPD_HKPD_CFG_H_

#include "../../CSWC_PLTF_MCU_ATMEGA32/SWC_MDIO/MDIO_int.h"

// Select Column pins from MDIO_u8PINNO_0 to MDIO_u8PINNO_31
#define HKPD_ColumnPin_0 	 MDIO_u8PINNO_0
#define HKPD_ColumnPin_1  	 MDIO_u8PINNO_1
#define HKPD_ColumnPin_2 	 MDIO_u8PINNO_2
#define HKPD_ColumnPin_3 	 MDIO_u8PINNO_3

// Select Column pins from MDIO_u8PINNO_0 to MDIO_u8PINNO_31
#define HKPD_RowPin_0		 MDIO_u8PINNO_4
#define HKPD_RowPin_1 		 MDIO_u8PINNO_5
#define HKPD_RowPin_2		 MDIO_u8PINNO_6
#define HKPD_RowPin_3 		 MDIO_u8PINNO_7

/* 2 constraints to consider that apply to columns and rows
 * ________________________________________________________
 * 1 - pin0 must be either in the first or middle(4) pin of a port
 * 2 - all sub-sequent pins must follow pin0 in an increasing order
 */


#endif /* CSWC_PLTF_BSW_ATMEGA32_SWC_HKPD_HKPD_CFG_H_ */
