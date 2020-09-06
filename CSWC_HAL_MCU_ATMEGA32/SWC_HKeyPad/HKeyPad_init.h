/*
 * CSWC_HKeyPad_init.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef CSWC_HKEYPAD_INIT_H_
#define CSWC_HKEYPAD_INIT_H_

void HKPD_voidInit(void);
//tenumFncErrorState KEYPAD_enuGetSwitchNo(pu8 pu8SwitchNoCPY);

/* in main function 
_________________________ 
    HKPD_voidInit();
	u8 value ;
	pu8 pu8value = &value;

	while (1) {
		KEYPAD_enuGetSwitchNo(pu8value);
		if(*pu8value != 0)
		{
			HLCD_enuWriteData(*pu8value);
		}
	}
*/

#endif /* CSWC_HKEYPAD_INIT_H_ */
