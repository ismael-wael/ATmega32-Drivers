#ifndef CSWC_PLTF_BSW_ATMEGA32_SWC_HLCD_HLCD_CFG_H_
#define CSWC_PLTF_BSW_ATMEGA32_SWC_HLCD_HLCD_CFG_H_

#include "../../CSWC_PLTF_MCU_ATMEGA32/SWC_MDIO/MDIO_int.h"
#include "HLCD_init.h"
// Set LCD data port pins (MDIO_u8PINNO_(0 to 31))

#define HLCD_u8MODE          HLCD_u8MODE_4BIT

	#if HLCD_u8MODE == HLCD_u8MODE_4BIT
		#define  HLCD_u8DataPin_4    MDIO_u8PINNO_27
		#define  HLCD_u8DataPin_5    MDIO_u8PINNO_26
		#define  HLCD_u8DataPin_6    MDIO_u8PINNO_25
		#define  HLCD_u8DataPin_7    MDIO_u8PINNO_24
	#elif HLCD_u8MODE == HLCD_u8MODE_8BIT
		#define  HLCD_u8DataPin_0    MDIO_u8PINNO_0
		#define	 HLCD_u8DataPin_1    MDIO_u8PINNO_1
		#define  HLCD_u8DataPin_2    MDIO_u8PINNO_2
		#define  HLCD_u8DataPin_3    MDIO_u8PINNO_3
		#define  HLCD_u8DataPin_4    MDIO_u8PINNO_4
		#define  HLCD_u8DataPin_5    MDIO_u8PINNO_5
		#define  HLCD_u8DataPin_6    MDIO_u8PINNO_6
		#define  HLCD_u8DataPin_7    MDIO_u8PINNO_7
	#endif

// Select register select pin (MDIO_u8PINNO_(0 to 31))

#define HLCD_u8RegSelectPin MDIO_u8PINNO_31

// Select Read/Write pin (MDIO_u8PINNO_(0 to 31))

#define HLCD_u8ReadWritePin MDIO_u8PINNO_30

// Select Enable pin (MDIO_u8PINNO_(0 to 31))

#define HLCD_u8EnablePin MDIO_u8PINNO_29


#endif /* CSWC_PLTF_BSW_ATMEGA32_SWC_HLCD_HLCD_CFG_H_ */
