/*
 * MDIO_prg.c
 *
 * Created on: Jan 9, 2020
 * Author: Ismael Wael
 */
//main avr libraries
#include "util/delay.h"
//#include "avr/io.h"
//used libraries
#include "../../LIB_STDTypes/LIB_stdTypes.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../Platform/ATMega32_Features.h"

//MDIO
#include "MDIO_int.h"
#include "MDIO_cfg.h"

tenumFncErrorState MDIO_Init(void)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	DDRA_Register = conc(MDIO_PIN0_Dir,MDIO_PIN1_Dir,MDIO_PIN2_Dir,MDIO_PIN3_Dir,MDIO_PIN4_Dir,MDIO_PIN5_Dir,MDIO_PIN6_Dir,MDIO_PIN7_Dir);
	PORTA_Register = conc(MDIO_PIN0_Value,MDIO_PIN1_Value,MDIO_PIN2_Value,MDIO_PIN3_Value,MDIO_PIN4_Value,MDIO_PIN5_Value,MDIO_PIN6_Value,MDIO_PIN7_Value);
	PINA_Register = conc(MDIO_PIN0_Mode,MDIO_PIN1_Mode,MDIO_PIN2_Mode,MDIO_PIN3_Mode,MDIO_PIN4_Mode,MDIO_PIN5_Mode,MDIO_PIN6_Mode,MDIO_PIN7_Mode);

	DDRB_Register = conc(MDIO_PIN8_Dir,MDIO_PIN9_Dir,MDIO_PIN10_Dir,MDIO_PIN11_Dir,MDIO_PIN12_Dir,MDIO_PIN13_Dir,MDIO_PIN14_Dir,MDIO_PIN15_Dir);
	PORTB_Register= conc(MDIO_PIN8_Value,MDIO_PIN9_Value,MDIO_PIN10_Value,MDIO_PIN11_Value,MDIO_PIN12_Value,MDIO_PIN13_Value,MDIO_PIN14_Value,MDIO_PIN15_Value);
	PINB_Register = conc(MDIO_PIN8_Mode,MDIO_PIN9_Mode,MDIO_PIN10_Mode,MDIO_PIN11_Mode,MDIO_PIN12_Mode,MDIO_PIN13_Mode,MDIO_PIN14_Mode,MDIO_PIN15_Mode);

	DDRC_Register = conc(MDIO_PIN16_Dir,MDIO_PIN17_Dir,MDIO_PIN18_Dir,MDIO_PIN19_Dir,MDIO_PIN20_Dir,MDIO_PIN21_Dir,MDIO_PIN22_Dir,MDIO_PIN23_Dir);
	PORTC_Register= conc(MDIO_PIN16_Value,MDIO_PIN17_Value,MDIO_PIN18_Value,MDIO_PIN19_Value,MDIO_PIN20_Value,MDIO_PIN21_Value,MDIO_PIN22_Value,MDIO_PIN23_Value);
	PINC_Register = conc(MDIO_PIN16_Mode,MDIO_PIN17_Mode,MDIO_PIN18_Mode,MDIO_PIN19_Mode,MDIO_PIN20_Mode,MDIO_PIN21_Mode,MDIO_PIN22_Mode,MDIO_PIN23_Mode);

	DDRD_Register = conc(MDIO_PIN24_Dir,MDIO_PIN25_Dir,MDIO_PIN26_Dir,MDIO_PIN27_Dir,MDIO_PIN28_Dir,MDIO_PIN29_Dir,MDIO_PIN30_Dir,MDIO_PIN31_Dir);
	PORTD_Register= conc(MDIO_PIN24_Value,MDIO_PIN25_Value,MDIO_PIN26_Value,MDIO_PIN27_Value,MDIO_PIN28_Value,MDIO_PIN29_Value,MDIO_PIN30_Value,MDIO_PIN31_Value);
	PIND_Register = conc(MDIO_PIN24_Mode,MDIO_PIN25_Mode,MDIO_PIN26_Mode,MDIO_PIN27_Mode,MDIO_PIN28_Mode,MDIO_PIN29_Mode,MDIO_PIN30_Mode,MDIO_PIN31_Mode);

	return ReturnFunState;
}

tenumFncErrorState MDIO_enuSetPinDirection (u8 u8PinNoCpy,
						                   u8 u8DirValCpy)
{
	u8 ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	u8  u8PortNoCpy = u8PinNoCpy / 8 ;
	u8PinNoCpy = u8PinNoCpy % 8 ;

	if( ((MDIO_u8PINNO_0 <= u8PinNoCpy) && (MDIO_u8PINNO_7 >= u8PinNoCpy)) &&
		((MDIO_u8PORTNO_A <= u8PortNoCpy) && (MDIO_u8PORTNO_D >= u8PortNoCpy)) &&
		((MDIO_u8DIROUTPUT == u8DirValCpy) || (MDIO_u8DIRINPUT == u8DirValCpy)) )
	{
		switch(u8PortNoCpy)
		{
			case MDIO_u8PORTNO_A:
				if(MDIO_u8DIROUTPUT == u8DirValCpy)
				{
					BMNP_u8SetBit(DDRA_Register, u8PinNoCpy);
				}
				else
				{
					BMNP_u8ClearBit(DDRA_Register, u8PinNoCpy);
				}
			break;
			case MDIO_u8PORTNO_B:
				if(MDIO_u8DIROUTPUT == u8DirValCpy)
				{
					BMNP_u8SetBit(DDRB_Register, u8PinNoCpy);
				}
				else
				{
					BMNP_u8ClearBit(DDRB_Register, u8PinNoCpy);
				}
			break;
			case MDIO_u8PORTNO_C:
				if(MDIO_u8DIROUTPUT == u8DirValCpy)
				{
					BMNP_u8SetBit(DDRC_Register, u8PinNoCpy);
				}
				else
				{
					BMNP_u8ClearBit(DDRC_Register, u8PinNoCpy);
				}
			break;
			case MDIO_u8PORTNO_D:
				if(MDIO_u8DIROUTPUT == u8DirValCpy)
				{
					BMNP_u8SetBit(DDRD_Register, u8PinNoCpy);
				}
				else
				{
					BMNP_u8ClearBit(DDRD_Register, u8PinNoCpy);
				}
			break;
			default:
			break;
		}
	}
	else
	{
		ReturnFunState = LSTY_OUT_OF_RANGE;
	}

	return ReturnFunState;
}

tenumFncErrorState MDIO_enuSetPinValue(u8 u8PinNoCpy,
                                      u8 u8ValCpy)
{
	u8 ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	u8  u8PortNoCpy = u8PinNoCpy / 8 ;
	u8PinNoCpy = u8PinNoCpy % 8 ;

	if( ((MDIO_u8PINNO_0 <= u8PinNoCpy) && (MDIO_u8PINNO_7 >= u8PinNoCpy)) &&
		((MDIO_u8PORTNO_A <= u8PortNoCpy) && (MDIO_u8PORTNO_D >= u8PortNoCpy)) )
	{
		switch(u8PortNoCpy)
		{
			case MDIO_u8PORTNO_A:
				if(MDIO_u8OUTPUTHIGH == u8ValCpy)
				{
					BMNP_u8SetBit(PORTA_Register, u8PinNoCpy);
				}
				else
				{
					BMNP_u8ClearBit(PORTA_Register, u8PinNoCpy);
				}
			break;
			case MDIO_u8PORTNO_B:
				if(MDIO_u8DIROUTPUT == u8ValCpy)
				{
					BMNP_u8SetBit(PORTB_Register, u8PinNoCpy);
				}
				else
				{
					BMNP_u8ClearBit(PORTB_Register, u8PinNoCpy);
				}
			break;
			case MDIO_u8PORTNO_C:
				if(MDIO_u8DIROUTPUT == u8ValCpy)
				{
					BMNP_u8SetBit(PORTC_Register, u8PinNoCpy);
				}
				else
				{
					BMNP_u8ClearBit(PORTC_Register, u8PinNoCpy);
				}
			break;
			case MDIO_u8PORTNO_D:
				if(MDIO_u8DIROUTPUT == u8ValCpy)
				{
					BMNP_u8SetBit(PORTD_Register, u8PinNoCpy);
				}
				else
				{
					BMNP_u8ClearBit(PORTD_Register, u8PinNoCpy);
				}
			break;
			default:
			break;
		}
	}
	else
	{
		ReturnFunState = LSTY_OUT_OF_RANGE;
	}

	return ReturnFunState;
}

tenumFncErrorState MDIO_enuGetPinValue(u8 u8PinNoCpy,
                                      pu8 pu8ValCpy)
{
   u8 ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

    u8 u8PortNoCpy = u8PinNoCpy / 8 ;
    u8PinNoCpy = u8PinNoCpy % 8 ;

	if( ((MDIO_u8PINNO_0 <= u8PinNoCpy) && (MDIO_u8PINNO_7 >= u8PinNoCpy)) &&
		((MDIO_u8PORTNO_A <= u8PortNoCpy) && (MDIO_u8PORTNO_D >= u8PortNoCpy)) &&
         (pu8ValCpy != NullPointer) )
    {

        switch(u8PortNoCpy)
		{
			case MDIO_u8PORTNO_A:
				*pu8ValCpy = BMNP_u8GetBit(PINA_Register,u8PinNoCpy);
                break;
            case MDIO_u8PORTNO_B:
            	*pu8ValCpy = BMNP_u8GetBit(PINB_Register,u8PinNoCpy);
                break;
            case MDIO_u8PORTNO_C:
            	*pu8ValCpy = BMNP_u8GetBit(PINC_Register,u8PinNoCpy);
                break;
            case MDIO_u8PORTNO_D:
            	*pu8ValCpy = BMNP_u8GetBit(PIND_Register,u8PinNoCpy);
                break;
            default:
                break;
        }
    }
    else if( pu8ValCpy == NullPointer )
	{
		ReturnFunState = LSTY_NULL_POINTER;
	}
    else
    {
    	ReturnFunState = LSTY_OUT_OF_RANGE;
    }

	return ReturnFunState;
}

tenumFncErrorState MDIO_enuSetPortDirection(u8 u8PortNoCpy,
                                           u8 u8DirValCpy)
{
	u8 ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	if( ((MDIO_u8PORTNO_A <= u8PortNoCpy) && (MDIO_u8PORTNO_D >= u8PortNoCpy)) &&
		((MDIO_u8DIROUTPUT == u8DirValCpy) || (MDIO_u8DIRINPUT == u8DirValCpy)) )

	{
		switch(u8PortNoCpy)
		{
			case MDIO_u8PORTNO_A:
				DDRA_Register = u8DirValCpy;
			break;
			case MDIO_u8PORTNO_B:
				DDRB_Register = u8DirValCpy;
			break;
			case MDIO_u8PORTNO_C:
				DDRC_Register = u8DirValCpy;
			break;
			case MDIO_u8PORTNO_D:
				DDRD_Register = u8DirValCpy;
			break;
			default:
			break;
		}
	}
	else
	{
		ReturnFunState = LSTY_OUT_OF_RANGE;
	}

	return ReturnFunState;
}


tenumFncErrorState MDIO_enuSetPortValue(u8 u8PortNoCpy,
                                       u8 u8ValCpy)
{
	u8 ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	if( (MDIO_u8PORTNO_A <= u8PortNoCpy) && (MDIO_u8PORTNO_D >= u8PortNoCpy) )
	{
		switch(u8PortNoCpy)
		{
			case MDIO_u8PORTNO_A:
				PORTA_Register = u8ValCpy;
			break;
			case MDIO_u8PORTNO_B:
				PORTB_Register = u8ValCpy;
			break;
			case MDIO_u8PORTNO_C:
				PORTC_Register = u8ValCpy;
			break;
			case MDIO_u8PORTNO_D:
				PORTD_Register = u8ValCpy;
			break;
			default:
			break;
		}
	}
	else
	{
		ReturnFunState = LSTY_OUT_OF_RANGE;
	}

	return ReturnFunState;
}

tenumFncErrorState MDIO_enuGetPortValue(u8 u8PortNoCpy,
                                       pu8 pu8ValCpy)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	if( ((MDIO_u8PORTNO_A <= u8PortNoCpy) && (MDIO_u8PORTNO_D >= u8PortNoCpy)) &&
		( NullPointer != pu8ValCpy ) )
	{
		switch (u8PortNoCpy)
		{
			case MDIO_u8PORTNO_A:
				*pu8ValCpy = PINA_Register;
			break;
			case MDIO_u8PORTNO_B:
				*pu8ValCpy = PINB_Register;
			break;
			case MDIO_u8PORTNO_C:
				*pu8ValCpy = PINC_Register;
			break;
			case MDIO_u8PORTNO_D:
				*pu8ValCpy = PIND_Register;
			break;
			default:
			break;
		}
	}
	else if( NullPointer == pu8ValCpy )
	{
		ReturnFunState = LSTY_NULL_POINTER;
	}
	else
	{
		ReturnFunState = LSTY_OUT_OF_RANGE;
	}

	return ReturnFunState;
}

