/*
 * HEEPROM_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

//used libraries
#include "../../LIB_STDTypes/LIB_stdTypes.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../Platform/ATMega32_Features.h"

//MDIO
#include "../../CSWC_PLTF_MCU_ATMEGA32/SWC_MTWI/MTWI_int.h"


tenumI2CErrorState HEEPROM_WriteByte(u8 data)
{
	u8 x[6]="waelxx";
   tenumI2CErrorState state = 0;

  // Start TWI
   MTWI_voidStartCond();

  // Get State
  state = MTWI_enuReadStatus();

  //send Addess + '0' for write
  MTWI_voidWriteByte(0b10100000);

  //send Location
  MTWI_voidWriteByte(0x00);

  // Get State
  state = MTWI_enuReadStatus();

  // Send Data
  MTWI_voidWriteByte(x[data]);

  // Get State
  state = MTWI_enuReadStatus();

  // TWI Stop
  MTWI_voidStopCond();
  // Return Done
  return state;
}

tenumI2CErrorState HEEPROM_ReadByte(unsigned char *data)
{
	tenumI2CErrorState state = 0;

	// Start TWI
	MTWI_voidStartCond();

	// Get State
	state = MTWI_enuReadStatus();

	//send Addess + '0' for write
	MTWI_voidWriteByte(0b10100000);

	//send Location
	MTWI_voidWriteByte(0x00);

	// Get State
	state = MTWI_enuReadStatus();

	// repeat Start TWI
	MTWI_voidStartCond();

	// Get State
	state = MTWI_enuReadStatus();

	//send Addess + '1' for read
	MTWI_voidWriteByte(0b10100001);

  // Read Data
	*data = MTWI_enuReadByteNACK();

  // TWI Stop
	MTWI_voidStopCond();
  // Return Done
  return state;
}

