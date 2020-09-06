/*
 * HEEPROM_init.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef HEEPROM_INIT_H_
#define HEEPROM_INIT_H_

#include "../../LIB_STDTypes/LIB_stdTypes.h"
//MTWI
#include "../../CSWC_PLTF_MCU_ATMEGA32/SWC_MTWI/MTWI_int.h"

tenumI2CErrorState HEEPROM_WriteByte(u8 data);
tenumI2CErrorState HEEPROM_ReadByte(u8 *data);

/*int main(void)
{
	MTWI_enuInit();
	HLCD_enuInit();
	u8 y[8];

    for(u8 i =0;i<=5;i++)
    {
    	HEEPROM_WriteByte(i);
    	_delay_ms(2);
    	HEEPROM_ReadByte(&y[i]);
    	_delay_ms(2);
    	HLCD_enuWriteData(y[i]);
    }

	while (1)
	{

	}
}*/

#endif /* HEEPROM_INIT_H_ */
