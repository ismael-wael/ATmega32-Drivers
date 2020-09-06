//main avr libraries
#include "util/delay.h"
//#include "avr/io.h"

//used libraries
#include "../../LIB_STDTypes/LIB_stdTypes.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../Platform/ATMega32_Features.h"

//MDIO
#include "../../CSWC_PLTF_MCU_ATMEGA32/SWC_MDIO/MDIO_int.h"

//HLCD
#include "HLCD_cfg.h"
#include "Priv.h"
#include "HLCD_init.h"


tenumFncErrorState HLCD_enuInit(void)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	#if HLCD_u8MODE == HLCD_u8MODE_4BIT
		MDIO_enuSetPinDirection(HLCD_u8DataPin_4,MDIO_u8DIROUTPUT);
		MDIO_enuSetPinDirection(HLCD_u8DataPin_5,MDIO_u8DIROUTPUT);
		MDIO_enuSetPinDirection(HLCD_u8DataPin_6,MDIO_u8DIROUTPUT);
		MDIO_enuSetPinDirection(HLCD_u8DataPin_7,MDIO_u8DIROUTPUT);
	#elif HLCD_u8MODE == HLCD_u8MODE_8BIT
		MDIO_enuSetPinDirection(HLCD_u8DataPin_0,MDIO_u8DIROUTPUT);
		MDIO_enuSetPinDirection(HLCD_u8DataPin_1,MDIO_u8DIROUTPUT);
		MDIO_enuSetPinDirection(HLCD_u8DataPin_2,MDIO_u8DIROUTPUT);
		MDIO_enuSetPinDirection(HLCD_u8DataPin_3,MDIO_u8DIROUTPUT);
		MDIO_enuSetPinDirection(HLCD_u8DataPin_4,MDIO_u8DIROUTPUT);
		MDIO_enuSetPinDirection(HLCD_u8DataPin_5,MDIO_u8DIROUTPUT);
		MDIO_enuSetPinDirection(HLCD_u8DataPin_6,MDIO_u8DIROUTPUT);
		MDIO_enuSetPinDirection(HLCD_u8DataPin_7,MDIO_u8DIROUTPUT);
	#endif

	MDIO_enuSetPinDirection(HLCD_u8RegSelectPin,MDIO_u8DIROUTPUT);
	MDIO_enuSetPinDirection(HLCD_u8ReadWritePin,MDIO_u8DIROUTPUT);
	MDIO_enuSetPinDirection(HLCD_u8EnablePin,MDIO_u8DIROUTPUT);
	_delay_ms(40);

	#if HLCD_u8MODE == HLCD_u8MODE_4BIT
	HLCD_enuWriteCmd(0x33);
	HLCD_enuWriteCmd(0x32);
	HLCD_enuWriteCmd(0x28);
	#elif HLCD_u8MODE == HLCD_u8MODE_8BIT
		HLCD_enuWriteCmd(FUNCTION_SET);
		_delay_ms(1);
	#endif

	HLCD_enuWriteCmd(DISPLAY_ON_WITH_CURSOR);
	_delay_ms(1);
	HLCD_enuWriteCmd(CLEAR_DISPLAY );
	_delay_ms(2);

	return ReturnFunState;
}

tenumFncErrorState HLCD_enuWriteData(u8 HLCD_u8DataCpy)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;
	MDIO_enuSetPinValue(HLCD_u8RegSelectPin,MDIO_u8OUTPUTHIGH);
	MDIO_enuSetPinValue(HLCD_u8ReadWritePin,MDIO_u8OUTPUTLOW);

	#if HLCD_u8MODE == HLCD_u8MODE_4BIT
	    u8 data = HLCD_u8DataCpy & 0xf0;
		HLCD_SendDataPort_4BIT(data); // sending high nibble first
    	MDIO_enuSetPinValue(HLCD_u8EnablePin,MDIO_u8OUTPUTHIGH); // E = 1 ;
    	_delay_us(1);
    	MDIO_enuSetPinValue(HLCD_u8EnablePin,MDIO_u8OUTPUTLOW); // E = 0
    	_delay_us(20);
    	data = HLCD_u8DataCpy <<4;
    	HLCD_SendDataPort_4BIT(data); // sending low nibble second
    	MDIO_enuSetPinValue(HLCD_u8EnablePin,MDIO_u8OUTPUTHIGH); // E = 1 ;
    	_delay_ms(1);
    	MDIO_enuSetPinValue(HLCD_u8EnablePin,MDIO_u8OUTPUTLOW); // E = 0
    	_delay_us(20);
	#elif HLCD_u8MODE == HLCD_u8MODE_8BIT
		HLCD_SendDataPort_8BIT(HLCD_u8DataCpy);
		MDIO_enuSetPinValue(HLCD_u8EnablePin,MDIO_u8OUTPUTHIGH); // E = 1 ;
		_delay_ms(20);
		MDIO_enuSetPinValue(HLCD_u8EnablePin,MDIO_u8OUTPUTLOW); // E = 0
	#endif

	return ReturnFunState;
}

tenumFncErrorState HLCD_enuWriteCmd(u8 HLCD_u8CmdCpy)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	MDIO_enuSetPinValue(HLCD_u8RegSelectPin,MDIO_u8OUTPUTLOW);
	MDIO_enuSetPinValue(HLCD_u8ReadWritePin,MDIO_u8OUTPUTLOW);

	#if HLCD_u8MODE == HLCD_u8MODE_4BIT
	    u8 data = HLCD_u8CmdCpy & 0xf0;
		HLCD_SendDataPort_4BIT(data); // sending high nibble first
    	MDIO_enuSetPinValue(HLCD_u8EnablePin,MDIO_u8OUTPUTHIGH); // E = 1 ;
    	_delay_us(1);
    	MDIO_enuSetPinValue(HLCD_u8EnablePin,MDIO_u8OUTPUTLOW); // E = 0
    	_delay_us(20);
    	data = HLCD_u8CmdCpy <<4;
    	HLCD_SendDataPort_4BIT(data); // sending low nibble second
    	MDIO_enuSetPinValue(HLCD_u8EnablePin,MDIO_u8OUTPUTHIGH); // E = 1 ;
    	_delay_ms(1);
    	MDIO_enuSetPinValue(HLCD_u8EnablePin,MDIO_u8OUTPUTLOW); // E = 0
    	_delay_us(20);
	#elif HLCD_u8MODE == HLCD_u8MODE_8BIT
		HLCD_SendDataPort_8BIT(HLCD_u8CmdCpy);
		MDIO_enuSetPinValue(HLCD_u8EnablePin,MDIO_u8OUTPUTHIGH);
		_delay_ms(20);
		MDIO_enuSetPinValue(HLCD_u8EnablePin,MDIO_u8OUTPUTLOW);
	#endif

	return ReturnFunState;
}

tenumFncErrorState HLCD_enuGoToXY(u8 HLCD_u8RowNum,u8 HLCD_u8ColumnNum )
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;
	if(((HLCD_u8FirstCol <= HLCD_u8ColumnNum) && (HLCD_u8LastCol >= HLCD_u8ColumnNum)) &&
	   ((HLCD_u8FirstRow <= HLCD_u8RowNum) && (HLCD_u8SecRow >= HLCD_u8RowNum))    )
		{
	switch (HLCD_u8RowNum)
	{
	case HLCD_u8FirstRow:
		HLCD_enuWriteCmd(HLCD_u8FirstRowStart+HLCD_u8ColumnNum);
		break;
	case HLCD_u8SecRow:
		HLCD_enuWriteCmd(HLCD_u8SecondRowStart+HLCD_u8ColumnNum);
		break;
	}
	}
	else
	{
		ReturnFunState = LSTY_OUT_OF_RANGE;
	}
	return ReturnFunState;
}

void HLCD_enuCGRAM(void)//maximum 8 charcters (each 5*8 pixels stored in 8 addresses starting from 0x00)
{
	    //(1)
		HLCD_enuWriteCmd(0b01000000);//move to CGRAM address 0
	    HLCD_enuWriteData(0b00000100);
		HLCD_enuWriteData(0b00000100);
		HLCD_enuWriteData(0b00000100);
		HLCD_enuWriteData(0b00000100);
		HLCD_enuWriteData(0b00000000);
		HLCD_enuWriteData(0b00000111);
		HLCD_enuWriteData(0b00000100);
		HLCD_enuWriteData(0b00011100);
		HLCD_enuGoToXY(15,HLCD_u8FirstRow);
		//HLCD_enuWriteData(0x00);//1
		//(2)
		HLCD_enuWriteCmd(0b01001000);//move to CGRAM address 8
		HLCD_enuWriteData(0x00);
		HLCD_enuWriteData(0x00);
		HLCD_enuWriteData(0b00010101);
		HLCD_enuWriteData(0b00010101);
		HLCD_enuWriteData(0b00010101);
		HLCD_enuWriteData(0b00011111);
		HLCD_enuWriteData(0x00);
		HLCD_enuWriteData(0x00);
		HLCD_enuGoToXY(14,HLCD_u8FirstRow);
		HLCD_enuWriteData(0x01);//2
		//(3)
		HLCD_enuWriteCmd(0b01010000);//move to CGRAM address 16
		HLCD_enuWriteData(0b00000000);
		HLCD_enuWriteData(0b00000000);
		HLCD_enuWriteData(0b00000000);
		HLCD_enuWriteData(0b00000000);
		HLCD_enuWriteData(0b00000000);
		HLCD_enuWriteData(0b00011111);
		HLCD_enuWriteData(0b00001010);
		HLCD_enuWriteData(0b00001110);
		HLCD_enuGoToXY(13,HLCD_u8FirstRow);
		HLCD_enuWriteData(0x02);//3
		//(4)
		HLCD_enuWriteCmd(0b01011000);//move to CGRAM address 24
		HLCD_enuWriteData(0b00000000);
	    HLCD_enuWriteData(0b00001000);
	    HLCD_enuWriteData(0b00001000);
		HLCD_enuWriteData(0b00001000);
		HLCD_enuWriteData(0b00001000);
		HLCD_enuWriteData(0b00001111);
		HLCD_enuWriteData(0b00000000);
		HLCD_enuWriteData(0b00000000);
		HLCD_enuGoToXY(12,HLCD_u8FirstRow);
		HLCD_enuWriteData(0x03);//4
		//(5)
		HLCD_enuWriteCmd(0b01100000);//move to CGRAM address 32
		HLCD_enuWriteData(0b00000000);
	    HLCD_enuWriteData(0b00000000);
	    HLCD_enuWriteData(0b00001111);
		HLCD_enuWriteData(0b00001000);
		HLCD_enuWriteData(0b00001000);
		HLCD_enuWriteData(0b00011111);
		HLCD_enuWriteData(0b00000000);
		HLCD_enuWriteData(0b00000000);
		HLCD_enuGoToXY(11,HLCD_u8FirstRow);
		HLCD_enuWriteData(0x04);//5
		//(6)
		HLCD_enuWriteCmd(0b01101000);//move to CGRAM address 40
		HLCD_enuWriteData(0b00000000);
	    HLCD_enuWriteData(0b00000000);
	    HLCD_enuWriteData(0b00000000);
		HLCD_enuWriteData(0b00000100);
		HLCD_enuWriteData(0b00000100);
		HLCD_enuWriteData(0b00011111);
		HLCD_enuWriteData(0b00000000);
		HLCD_enuWriteData(0b00001010);
		HLCD_enuGoToXY(10,HLCD_u8FirstRow);
		HLCD_enuWriteData(0x05);//6
		//(7)
		HLCD_enuWriteCmd(0b01110000);//move to CGRAM address 48
		HLCD_enuWriteData(0b00000000);
	    HLCD_enuWriteData(0b00000010);
	    HLCD_enuWriteData(0b00000010);
		HLCD_enuWriteData(0b00000010);
		HLCD_enuWriteData(0b00000010);
		HLCD_enuWriteData(0b00010011);
		HLCD_enuWriteData(0b00010010);
		HLCD_enuWriteData(0b00001100);
		HLCD_enuGoToXY(9,HLCD_u8FirstRow);
		HLCD_enuWriteData(0x06);//7

}

/******************TESTED*****************************/
void HLCD_voidIntegerToString(u32 u32Value)
{
	u8 ones = u32Value%10 ? 0 : 1; // check if ones element is zeo or not
	u8 a;
	u32 hold = 0;

	while(u32Value >= 1)/*reverse the value : 2070 -> 0702*/
	{
		a = u32Value%10;
		hold = hold*10+a;
		u32Value = u32Value / 10;
	}
	
	while(hold >= 1) /*reverse again and print : 207*/
	{
		a = hold%10;
		HLCD_enuWriteData(a+'0');
		hold = hold / 10;
	}
	
	if(ones)/*if last digit was 0 (i.e, ones = 1), then print 0*/
	{
		HLCD_enuWriteData('0');
	}
	/*final output -> 2070*/
}

/******************TESTED*****************************/
void HLCD_voidDisplayString(pu8 pu8String)
{
	u8 u8Counter;
	for(u8Counter=0;*(pu8String+u8Counter)!='\0';u8Counter++)
	{
		HLCD_enuWriteData(*(pu8String+u8Counter));
	}
}

void clear_screen(void)
{
	_delay_ms(1);
	HLCD_enuWriteCmd(CLEAR_DISPLAY );
	_delay_ms(2);
}


