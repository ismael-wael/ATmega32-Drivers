#ifndef CSWC_PLTF_BSW_ATMEGA32_CSWC_PLTF_MCU_ATMEGA32_SWC_MADC_MADC_INT_H_
#define CSWC_PLTF_BSW_ATMEGA32_CSWC_PLTF_MCU_ATMEGA32_SWC_MADC_MADC_INT_H_

#include"../../LIB_BMNP/LIB_BMNP.h"
#include"../../LIB_STDTypes/LIB_STDTypes.h"
#include"../../Platform/ATMEGA32_Features.h"

//channel names
#define MADC_Channel_0     0
#define MADC_Channel_1     1
#define MADC_Channel_2     2
#define MADC_Channel_3     3
#define MADC_Channel_4     4
#define MADC_Channel_5     5
#define MADC_Channel_6     6
#define MADC_Channel_7     7

//Justify modes
#define MADC_8BIT          0
#define MADC_10BIT         1

//Refrence modes
#define MADC_AREF          0
#define MADC_AVCC          1
#define MADC_IREF          3

//Prescaler modes
#define MADC_PS_2          2
#define MADC_PS_4          4
#define MADC_PS_8          8
#define MADC_PS_16         16
#define MADC_PS_32         32
#define MADC_PS_64         64
#define MADC_PS_128        128


tenumFncErrorState MADC_enuInit(void);

tenumFncErrorState MADC_enuStartConversion(pu16 );


#endif /* CSWC_PLTF_BSW_ATMEGA32_CSWC_PLTF_MCU_ATMEGA32_SWC_MADC_MADC_INT_H_ */
