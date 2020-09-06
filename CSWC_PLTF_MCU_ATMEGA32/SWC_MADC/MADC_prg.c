#ifndef CSWC_PLTF_BSW_ATMEGA32_CSWC_PLTF_MCU_ATMEGA32_SWC_MADC_MADC_PRG_C_
#define CSWC_PLTF_BSW_ATMEGA32_CSWC_PLTF_MCU_ATMEGA32_SWC_MADC_MADC_PRG_C_

//main avr libraries
#include "util/delay.h"
//#include "avr/io.h"
//used libraries
#include "../../LIB_STDTypes/LIB_stdTypes.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../Platform/ATMega32_Features.h"
//MADC
#include "MADC_int.h"
#include "MADC_cfg.h"


tenumFncErrorState MADC_enuInit(void)
{
	tenumFncErrorState ReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	// Set ADC channel

    #if MADC_CHANNEL == MADC_Channel_0
	ADMUX &=~(1<<MUX0);
	ADMUX &=~(1<<MUX1);
	ADMUX &=~(1<<MUX2);
    #elif MADC_CHANNEL == MADC_Channel_1
	ADMUX |=(1 << MUX0);
	ADMUX &=~(1<<MUX1);
	ADMUX &=~(1<<MUX2);
    #elif MADC_CHANNEL == MADC_Channel_2
	ADMUX &=~(1<<MUX0);
	ADMUX |=(1 << MUX1);
	ADMUX &=~(1<<MUX2);
    #elif MADC_CHANNEL == MADC_Channel_3
	ADMUX |=(1 << MUX1) | (1 << MUX0);
	ADMUX &=~(1<<MUX2);
    #elif MADC_CHANNEL == MADC_Channel_4
	ADMUX &=~(1<<MUX1);
	ADMUX &=~(1<<MUX0);
	ADMUX |= (1 << MUX2);
    #elif MADC_CHANNEL == MADC_Channel_5
	ADMUX |= (1 << MUX2) | (1 << MUX0);
	ADMUX &=~(1<<MUX1);
    #elif MADC_CHANNEL == MADC_Channel_6
	ADMUX |= (1 << MUX2) | (1 << MUX1);
	ADMUX &=~(1<<MUX0);
    #elif MADC_CHANNEL == MADC_Channel_7
	ADMUX |= (1 << MUX2) | (1 << MUX1) | (1 << MUX0);
    #endif

	// Set ADC reference

	#if MADC_REF == MADC_AREF
	ADMUX &=~(1<<REFS1); // AREF, Internal Vref turned off
	ADMUX &=~(1<<REFS0);
	#elif MADC_REF == MADC_AVCC
	ADMUX |=(1 << REFS0); // AVCC with external capacitor at AREF pin
	ADMUX &=~(1<<REFS1);
	#elif MADC_REF == MADC_IREF
	ADMUX |= (1 << REFS1) | (1 << REFS0); // Internal 2.56V Voltage Reference with external cap at AREF
	#endif

	// Set ADC prescaler
	#if MADC_PRESCALER ==  MADC_PS_2 // Prescaler 2
	ADCSRA &=~(0 << ADPS0);
	ADCSRA &=~(0 << ADPS1);
	ADCSRA &=~(0 << ADPS2);
	#elif MADC_PRESCALER == MADC_PS_4 // Prescaler 4
	ADCSRA &=~(0 << ADPS0);
	ADCSRA |=(1 << ADPS1);
	ADCSRA &=~(0 << ADPS2);
	#elif MADC_PRESCALER ==  MADC_PS_8 // Prescaler 8
	ADCSRA |=(1 << ADPS1) | (1 << ADPS0);
	ADCSRA &=~(0 << ADPS2);
	#elif MADC_PRESCALER ==  MADC_PS_16 // Prescaler 16
	ADCSRA &=~(1<<ADPS0);
	ADCSRA &=~(1<<ADPS1);
	ADCSRA |= (1 << ADPS2);
	#elif MADC_PRESCALER ==  MADC_PS_32 // Prescaler 32
	ADCSRA |= (1 << ADPS2) |(1 << ADPS0);
	ADCSRA &=~(1<<ADPS1);
	#elif MADC_PRESCALER ==  MADC_PS_64 // Prescaler 64
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1);
	ADCSRA &=~(1<<ADPS0);
	#elif MADC_PRESCALER ==  MADC_PS_128 // Prescaler 128
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	#endif

	// Set ADC justify
	#if MADC_JUSTIFY == MADC_8BIT
	ADMUX |= (1 << ADLAR); // Left adjust ADC result to allow easy 8 bit reading
	#elif MADC_JUSTIFY == MADC_10BIT
	ADMUX &= ~(1 << ADLAR); // Right adjust ADC result to allow easy 10 bit reading
	#endif

	// Enable ADC
	ADCSRA |= (1 << ADEN);

	//ADC Auto Trigger Disable
	BMNP_u8ClearBit(ADCSRA, 5);
    //disable interrupt
	BMNP_u8ClearBit(ADCSRA, 3);
	BMNP_u8SetBit(ADCSRA, 4); //check interrupt flag

	return ReturnFncState;
}



tenumFncErrorState MADC_enuStartConversion(pu16 pu16ADCCpy)
{
	tenumFncErrorState ReturnFncState = LSTY_EXECUTED_SUCCESSFULLY;

	if ((LSTY_NULL != pu16ADCCpy))
	{

		ADCSRA |= (1 << ADSC); // Start conversion

		while(!BMNP_u8GetBit(ADCSRA, ADIF)); // Wait for conversion to complete (polling)

		ADCSRA |= (1 << ADIF); // Clear ADIF by writing one to it

		#if MADC_JUSTIFY == MADC_8BIT
		*pu16ADCCpy = ADCH; // Left adjust ADC result to allow easy 8 bit reading
		#elif MADC_JUSTIFY == MADC_10BIT
		*pu16ADCCpy = ADCW; // Right adjust ADC result to allow easy 10 bit reading
		#endif

	}
	else
	{
		ReturnFncState = LSTY_NULL_POINTER;
	}
	return ReturnFncState;
}


/*in main function
____________________

	MADC_enuInit();

	u16 analogVal,Val=0;
	pu16 pu16Val=&Val;

	while(1)
	{
		MADC_enuStartConversion(pu16Val);
		analogVal = ((Val * 5) / 256);
	}
*/

#endif /* CSWC_PLTF_BSW_ATMEGA32_CSWC_PLTF_MCU_ATMEGA32_SWC_MADC_MADC_PRG_C_ */
