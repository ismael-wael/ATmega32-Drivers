/*
 * CSWC_HKeyPad_prg.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */
//main avr libraries
#include "util/delay.h"
#include "avr/io.h"
#define F_CPU 8000000UL
//used libraries
#include "../../LIB_STDTypes/LIB_stdTypes.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../Platform/ATMega32_Features.h"

//MDIO
#include "../../CSWC_PLTF_MCU_ATMEGA32/SWC_MDIO/MDIO_int.h"

//HKPD
#include "HKeyPad_init.h"
#include "HKPD_cfg.h"

/*u8 Au8KeyPadLayout[4][4] = {{'7','8','9','/'},
                            {'4','5','6','*'},
                            {'1','2','3','-'},
                            {'C','0','=','+'}};

void HKPD_voidInit(void)
{
//	DDRC=0b11110000;R4 R3 R2 R1 C4 C3 C2 C1 = portC
	              // 7  6  5  4  3  2  1  0
	MDIO_enuSetPinDirection(HKPD_ColumnPin_0,MDIO_u8DIROUTPUT);
	MDIO_enuSetPinDirection(HKPD_ColumnPin_1,MDIO_u8DIROUTPUT);
	MDIO_enuSetPinDirection(HKPD_ColumnPin_2,MDIO_u8DIROUTPUT);
	MDIO_enuSetPinDirection(HKPD_ColumnPin_3,MDIO_u8DIROUTPUT);
	MDIO_enuSetPinDirection(HKPD_RowPin_0,MDIO_u8DIRINPUT);
	MDIO_enuSetPinDirection(HKPD_RowPin_1,MDIO_u8DIRINPUT);
	MDIO_enuSetPinDirection(HKPD_RowPin_2,MDIO_u8DIRINPUT);
	MDIO_enuSetPinDirection(HKPD_RowPin_3,MDIO_u8DIRINPUT);
//	PORTC=0b11111111;columns are output high, activate pull-up resistors of rows
	MDIO_enuSetPinValue(HKPD_ColumnPin_0,MDIO_u8OUTPUTHIGH);
	MDIO_enuSetPinValue(HKPD_ColumnPin_1,MDIO_u8OUTPUTHIGH);
	MDIO_enuSetPinValue(HKPD_ColumnPin_2,MDIO_u8OUTPUTHIGH);
	MDIO_enuSetPinValue(HKPD_ColumnPin_3,MDIO_u8OUTPUTHIGH);
	MDIO_enuSetPinValue(HKPD_RowPin_0,MDIO_u8INPUTPULLUP );
	MDIO_enuSetPinValue(HKPD_RowPin_1,MDIO_u8INPUTPULLUP );
	MDIO_enuSetPinValue(HKPD_RowPin_2,MDIO_u8INPUTPULLUP );
	MDIO_enuSetPinValue(HKPD_RowPin_3,MDIO_u8INPUTPULLUP);
}



tenumFncErrorState KEYPAD_enuGetSwitchNo(pu8 pu8SwitchNoCPY)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;
	if( LSTY_NULL != pu8SwitchNoCPY )
	{
		pu8 pu8value ;
		u8 u8RowNo,u8ColumnNo;
		u8 u8ColPinNo,u8RowPinNo;
		*pu8SwitchNoCPY = 0 ;
	    for (u8ColumnNo=0; u8ColumnNo<=3; u8ColumnNo++)
	    {
	    	switch (u8ColumnNo)
	    	{
	    	    case 0:
	    			u8ColPinNo= HKPD_ColumnPin_0;
	    			break;
	    		case 1:
	    			u8ColPinNo= HKPD_ColumnPin_1;
	    			break;
	    		case 2:
	    			u8ColPinNo= HKPD_ColumnPin_2;
	    			break;
	    		case 3:
	    			u8ColPinNo= HKPD_ColumnPin_3;
	    			break;
	    	}
	    	MDIO_enuSetPinValue(u8ColPinNo,MDIO_u8OUTPUTLOW);
	        for (u8RowNo=0; u8RowNo<=3; u8RowNo++)
	        {
	    	    switch (u8RowNo)
	    	    {
	    		       case 0:
	    			        u8RowPinNo= HKPD_RowPin_0;
	    		       break;
	    		       case 1:
	    		            u8RowPinNo= HKPD_RowPin_1;
	    			   break;
	    		       case 2:
	    			        u8RowPinNo= HKPD_RowPin_2;
	    			   break;
	    		       case 3:
	    			        u8RowPinNo= HKPD_RowPin_3;
	    			   break;
	    	    }
	    	    //MDIO_enuGetPinValue(u8RowPinNo,pu8value);
	    	    *pu8value = BMNP_u8GetBit(u8RowPinNo/8, u8RowPinNo%8);
			    if (*pu8value == 0)
			    {
				       *pu8SwitchNoCPY= Au8KeyPadLayout[u8RowPinNo % 4][u8ColPinNo % 4];

				       while(!(*pu8value)) //while pressed
					   {
				    	   *pu8value = BMNP_u8GetBit(u8RowPinNo/8, u8RowPinNo%8);
					        //MDIO_enuGetPinValue(u8RowPinNo,pu8value);
					   }
				       _delay_ms(15);//de-bouncing
			    }
		     }
	    MDIO_enuSetPinValue(u8ColumnNo,MDIO_u8OUTPUTHIGH);//reset the bottom
	    }
	}
	else
	{
		ReturnFunState = LSTY_NULL_POINTER;
	}

	return ReturnFunState;
}*/

