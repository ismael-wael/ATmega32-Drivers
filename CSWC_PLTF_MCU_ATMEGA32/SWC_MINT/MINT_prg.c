//main avr libraries
#include "util/delay.h"
//#include "avr/io.h"

//used libraries
#include "../../LIB_STDTypes/LIB_stdTypes.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../Platform/ATMega32_Features.h"

#define GET_BIT(VAR,Bitno)            (((VAR) >> (Bitno)) & 0x01)

//MINT
#include "MINT_int.h"
#include "MINT_cfg.h"

tenumFncErrorState MINT_enuInit(void)
{
	tenumFncErrorState enuReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	#if MINT_EXINT0_ENABLE == MINT_INT_ENABLE
		GICR |= (1 << INT0) ; // Enable External Interrupt 0
	#elif MINT_EXINT0_ENABLE == MINT_INT_DISABLE
		GICR &= ~(1 << INT0) ; // Disable External Interrupt 0
	#endif

	#if MINT_EXINT1_ENABLE == MINT_INT_ENABLE
		GICR |= (1 << INT1) ; // Enable External Interrupt 1
	#elif MINT_EXINT1_ENABLE == MINT_INT_DISABLE
		GICR &= ~(1 << INT1) ; // Disable External Interrupt 1
	#endif

	#if MINT_EXINT2_ENABLE == MINT_INT_ENABLE
		GICR |= (1 << INT2) ; // Enable External Interrupt 2
	#elif MINT_EXINT2_ENABLE == MINT_INT_DISABLE
		GICR &= ~(1 << INT2) ; // Disable External Interrupt 2
	#endif


	#if MINT_EXINT2_ISC == MINT_ISC_RISING
		MCUCSR |= (1 << ISC2) ; // Activate INT2 on Rising Edge
	#elif MINT_EXINT2_ISC == MINT_ISC_FALLING
		MCUCSR &= ~(1 << ISC2) ; //Activate INT2 on Falling Edge
	#endif

	#if MINT_EXINT0_ISC == MINT_ISC_ANYLEVEL
		MCUCR &= ~(1 << ISC01);// Activate INT0 on Any Low Level Change
		MCUCR &= ~(1 << ISC00);
	#elif MINT_EXINT0_ISC == MINT_ISC_ANYLOGIC
		MCUCR |=(1 << ISC00); // Activate INT0 on Any Logical Change
		MCUCR &=~(1 << ISC01);
	#elif MINT_EXINT0_ISC == MINT_ISC_FALLING
		MCUCR |= (1 << ISC01);// Activate INT0 on Falling Edge
		MCUCR &=~ (1 << ISC00);
	#elif MINT_EXINT0_ISC == MINT_ISC_RISING
		MCUCR |= (1 << ISC01) | (1 << ISC00); // Activate INT0 on Rising Edge
	#endif

	#if MINT_EXINT1_ISC == MINT_ISC_ANYLEVEL
		MCUCR &= ~(1 << ISC11);// Activate INT1 on Any Low Level Change
		MCUCR &= ~(1 << ISC10);
	#elif MINT_EXINT1_ISC == MINT_ISC_ANYLOGIC
		MCUCR |=(1 << ISC10); // Activate INT1 on Any Logical Change
		MCUCR &=~(1 << ISC11);
	#elif MINT_EXINT1_ISC == MINT_ISC_FALLING
		MCUCR |= (1 << ISC11);// Activate INT1 on Falling Edge
		MCUCR &=~ (1 << ISC10);
	#elif MINT_EXINT1_ISC == MINT_ISC_RISING
		MCUCR |= (1 << ISC11) | (1 << ISC10); // Activate INT1 on Rising Edge
	#endif

	SET_BIT(SREG,7); // Global Interrupt Enable

	return enuReturnFncState;
}

void MINT_ExitCriticalSection(void)
{
	SET_BIT(SREG,7);
}

void MINT_EnterCriticalSection(void)
{
	CLR_BIT(SREG,7);
}

tenumFncErrorState MINT_enuGetINT0Flag(pu8 pu8INT0FlagCpy)
{
	tenumFncErrorState enuReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	if(LSTY_NULL != pu8INT0FlagCpy)
	{
		*pu8INT0FlagCpy=GET_BIT(GIFR,INTF0);
	}
	else
	{
		enuReturnFncState = LSTY_NULL_POINTER;
	}
	return enuReturnFncState;
}

tenumFncErrorState MINT_enuGetINT1Flag(pu8 pu8INT1FlagCpy)
{
	tenumFncErrorState enuReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	if(LSTY_NULL != pu8INT1FlagCpy)
	{
		*pu8INT1FlagCpy=GET_BIT(GIFR,INTF1);
	}
	else
	{
		enuReturnFncState = LSTY_NULL_POINTER;
	}
	return enuReturnFncState;
}

tenumFncErrorState MINT_enuGetINT2Flag(pu8 pu8INT2FlagCpy)
{
	tenumFncErrorState enuReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	if(LSTY_NULL != pu8INT2FlagCpy)
	{
		*pu8INT2FlagCpy=GET_BIT(GIFR,INTF2);
	}
	else
	{
		enuReturnFncState = LSTY_NULL_POINTER;
	}
	return enuReturnFncState;
}

tenumFncErrorState MINT_enuSetINT0Flag(u8 u8INT0ValCpy)
{
	tenumFncErrorState enuReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	switch(u8INT0ValCpy)
	{
		case MINT_INTF_SET : SET_BIT(GIFR,INTF0); break;
		case MINT_INTF_CLEAR : CLR_BIT(GIFR,INTF0); break;
		default : enuReturnFncState = LSTY_OUT_OF_RANGE; break;
	}
	return enuReturnFncState;
}

tenumFncErrorState MINT_enuSetINT1Flag(u8 u8INT1ValCpy)
{
	tenumFncErrorState enuReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	switch(u8INT1ValCpy)
	{
		case MINT_INTF_SET : SET_BIT(GIFR,INTF1); break;
		case MINT_INTF_CLEAR : CLR_BIT(GIFR,INTF1); break;
		default : enuReturnFncState = LSTY_OUT_OF_RANGE; break;
	}
	return enuReturnFncState;
}
tenumFncErrorState MINT_enuSetINT2Flag(u8 u8INT2ValCpy)
{
	tenumFncErrorState enuReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	switch(u8INT2ValCpy)
	{
		case MINT_INTF_SET : SET_BIT(GIFR,INTF2); break;
		case MINT_INTF_CLEAR : CLR_BIT(GIFR,INTF2); break;
		default : enuReturnFncState = LSTY_OUT_OF_RANGE; break;
	}
	return enuReturnFncState;
}

tenumFncErrorState MINT_enuEnableINTHandler(u8 u8IntNoCpy)
{
	tenumFncErrorState enuReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	switch(u8IntNoCpy)
	{
		case MINT_EXINT0 : GICR |= (1 << INT0) ; break; // Enable External Inturpet 0
		case MINT_EXINT1 : GICR |= (1 << INT1) ; break; // Enable External Inturpet 1
		case MINT_EXINT2 : GICR |= (1 << INT2) ; break; // Enable External Inturpet 2
		default : enuReturnFncState = LSTY_OUT_OF_RANGE; break;
	}
	return enuReturnFncState;
}

tenumFncErrorState MINT_enuDisableINTHandler(u8 u8IntNoCpy)
{
	tenumFncErrorState enuReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	switch(u8IntNoCpy)
	{
		case MINT_EXINT0 : GICR |= (0 << INT0) ; break; // Disable External Inturpet 0
		case MINT_EXINT1 : GICR |= (0 << INT1) ; break; // Disable External Inturpet 1
		case MINT_EXINT2 : GICR |= (0 << INT2) ; break; // Disable External Inturpet 2
		default : enuReturnFncState = LSTY_OUT_OF_RANGE; break;
	}
	return enuReturnFncState;
}


/*
GetVar(pu8 ptr)
{
	*ptr=x;
}

SetVar(u8 valcpy)
{
	x=valcpy;
}
*/
