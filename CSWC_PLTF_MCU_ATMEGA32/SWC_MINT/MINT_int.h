#ifndef CSWC_PLTF_BSW_ATMEGA32_CSWC_PLTF_MCU_ATMEGA32_SWC_MINT_MINT_INT_H_
#define CSWC_PLTF_BSW_ATMEGA32_CSWC_PLTF_MCU_ATMEGA32_SWC_MINT_MINT_INT_H_

#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../LIB_STDTypes/LIB_STDTypes.h"
#include "../../Platform/ATMEGA32_Features.h"

#define MINT_INT_ENABLE   1
#define MINT_INT_DISABLE  0

#define MINT_ISC_ANYLEVEL  0
#define MINT_ISC_ANYLOGIC  1
#define MINT_ISC_FALLING   2
#define MINT_ISC_RISING    3

#define MINT_EXINT0  ((u8)0)
#define MINT_EXINT1  ((u8)1)
#define MINT_EXINT2  ((u8)2)

#define MINT_INTF_CLEAR ((u8)0)
#define MINT_INTF_SET  ((u8)1)


#  define MINT_ISR(vector)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)); \
    void vector (void)


tenumFncErrorState MINT_enuInit(void);

tenumFncErrorState MINT_enuEnableINTHandler(u8 u8IntNoCpy);
tenumFncErrorState MINT_enuDisableINTHandler(u8 u8IntNoCpy);

void MINT_EnterCriticalSection(void);
void MINT_ExitCriticalSection(void);

tenumFncErrorState MINT_enuGetINT0Flag(pu8 pu8INT0FlagCpy);
tenumFncErrorState MINT_enuGetINT1Flag(pu8 pu8INT1FlagCpy);
tenumFncErrorState MINT_enuGetINT2Flag(pu8 pu8INT2FlagCpy);

tenumFncErrorState MINT_enuSetINT0Flag(u8 u8INT0ValCpy);
tenumFncErrorState MINT_enuSetINT1Flag(u8 u8INT1ValCpy);
tenumFncErrorState MINT_enuSetINT2Flag(u8 u8INT2ValCpy);

/*
GetVar(pu8 ptr);
SetVar(u8 valcpy);
*/

#endif /* CSWC_PLTF_BSW_ATMEGA32_CSWC_PLTF_MCU_ATMEGA32_SWC_MINT_MINT_INT_H_ */
