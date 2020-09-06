/*
 * HLCD_enuInit.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef CSWC_HLCD_INIT_H_
#define CSWC_HLCD_INIT_H_

#define CLEAR_DISPLAY         			((u8)0b00000001)
#define RETURN_HOME    		 			((u8)0b00000010)
#define ENTRY_MODE_INC 		 			((u8)0b00000111)
#define ENTRY_MODE_DEC  		 		((u8)0b00000101)
#define DISPLAY_ON_ONLY		 			((u8)0b00001100)
#define DISPLAY_ON_WITH_CURSOR  		((u8)0b00001110)
#define DISPLAY_ON_WITH_CURSOR_BLINKING ((u8)0b00001111)
#define CURSOR_SHIFT_RIGHT  			((u8)0b00010100)
#define CURSOR_SHIFT_LEFT  		 		((u8)0b00010000)
#define DISPLAY_SHIFT_RIGHT  			((u8)0b00011100)
#define DISPLAY_SHIFT_LEFT  			((u8)0b00011000)
#define FUNCTION_SET  		 			((u8)0b00111100)

#define HLCD_u8FirstRowStart            ((u8)0b10000000)
#define HLCD_u8SecondRowStart           ((u8)0b11000000)

#define HLCD_u8FirstRow       ((u8)0)
#define HLCD_u8SecRow         ((u8)1)

#define HLCD_u8FirstCol       ((u8)0)
#define HLCD_u8LastCol        ((u8)15)

#define HLCD_u8FirstCGRAMPos  ((u8)0)
#define HLCD_u8LastCGRAMPos   ((u8)8)

#define HLCD_u8MODE_4BIT      0
#define HLCD_u8MODE_8BIT      1


#define HLCD_SendDataPort_8BIT(u8DataCpy)  	 do{MDIO_enuSetPinValue(HLCD_u8DataPin_0,GETBIT(u8DataCpy,0)); \
											MDIO_enuSetPinValue(HLCD_u8DataPin_1,GETBIT(u8DataCpy,1)); \
											MDIO_enuSetPinValue(HLCD_u8DataPin_2,GETBIT(u8DataCpy,2)); \
											MDIO_enuSetPinValue(HLCD_u8DataPin_3,GETBIT(u8DataCpy,3)); \
											MDIO_enuSetPinValue(HLCD_u8DataPin_4,GETBIT(u8DataCpy,4)); \
											MDIO_enuSetPinValue(HLCD_u8DataPin_5,GETBIT(u8DataCpy,5)); \
											MDIO_enuSetPinValue(HLCD_u8DataPin_6,GETBIT(u8DataCpy,6)); \
											MDIO_enuSetPinValue(HLCD_u8DataPin_7,GETBIT(u8DataCpy,7));} while(0)

#define HLCD_SendDataPort_4BIT(u8DataCpy)  	 do{MDIO_enuSetPinValue(HLCD_u8DataPin_4,GETBIT(u8DataCpy,4)); \
											MDIO_enuSetPinValue(HLCD_u8DataPin_5,GETBIT(u8DataCpy,5)); \
											MDIO_enuSetPinValue(HLCD_u8DataPin_6,GETBIT(u8DataCpy,6)); \
											MDIO_enuSetPinValue(HLCD_u8DataPin_7,GETBIT(u8DataCpy,7));} while(0)

tenumFncErrorState HLCD_enuInit(void);
tenumFncErrorState HLCD_enuWriteData(u8);
tenumFncErrorState HLCD_enuWriteCmd(u8);
tenumFncErrorState HLCD_enuGoToXY(u8 HLCD_u8RowNum,u8 HLCD_u8ColumnNum );
void HLCD_voidDisplayString(pu8 );
void HLCD_voidIntegerToString(u32 );
void clear_screen(void);

/*in main function
____________________

	HLCD_enuInit();
	HLCD_voidDisplayString("Result = ");
	HLCD_voidIntegerToString(5*2);
	while(1)
	{

	}
*/

#endif /* CSWC_HLCD_INIT_H_ */
