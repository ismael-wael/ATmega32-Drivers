/*
 * CSWC_MDIO_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef CSWC_MDIO_INT_H_
#define CSWC_MDIO_INT_H_

#ifndef CSWC_PLTF_BSW_ATMEGA32_CSWC_PLTF_MCU_ATMEGA32_MDIO_MDIO_INT_H_
#define CSWC_PLTF_BSW_ATMEGA32_CSWC_PLTF_MCU_ATMEGA32_MDIO_MDIO_INT_H_

#define MDIO_u8PINNO_0    ((u8)0) //start of PORT A
#define MDIO_u8PINNO_1    ((u8)1)
#define MDIO_u8PINNO_2    ((u8)2)
#define MDIO_u8PINNO_3    ((u8)3)
#define MDIO_u8PINNO_4    ((u8)4)
#define MDIO_u8PINNO_5    ((u8)5)
#define MDIO_u8PINNO_6    ((u8)6)
#define MDIO_u8PINNO_7    ((u8)7)
#define MDIO_u8PINNO_8    ((u8)8) //start of PORT B
#define MDIO_u8PINNO_9    ((u8)9)
#define MDIO_u8PINNO_10   ((u8)10)
#define MDIO_u8PINNO_11   ((u8)11)
#define MDIO_u8PINNO_12   ((u8)12)
#define MDIO_u8PINNO_13   ((u8)13)
#define MDIO_u8PINNO_14   ((u8)14)
#define MDIO_u8PINNO_15   ((u8)15)
#define MDIO_u8PINNO_16   ((u8)16) //start of PORT C
#define MDIO_u8PINNO_17   ((u8)17)
#define MDIO_u8PINNO_18   ((u8)18)
#define MDIO_u8PINNO_19   ((u8)19)
#define MDIO_u8PINNO_20   ((u8)20)
#define MDIO_u8PINNO_21   ((u8)21)
#define MDIO_u8PINNO_22   ((u8)22)
#define MDIO_u8PINNO_23   ((u8)23)
#define MDIO_u8PINNO_24   ((u8)24) //start of PORT D
#define MDIO_u8PINNO_25   ((u8)25)
#define MDIO_u8PINNO_26   ((u8)26)
#define MDIO_u8PINNO_27   ((u8)27)
#define MDIO_u8PINNO_28   ((u8)28)
#define MDIO_u8PINNO_29   ((u8)29)
#define MDIO_u8PINNO_30   ((u8)30)
#define MDIO_u8PINNO_31   ((u8)31)

#define MDIO_u8PORTNO_A   ((u8)0)
#define MDIO_u8PORTNO_B   ((u8)1)
#define MDIO_u8PORTNO_C   ((u8)2)
#define MDIO_u8PORTNO_D   ((u8)3)

#define MDIO_u8DIROUTPUT  ((u8)1)
#define MDIO_u8DIRINPUT   ((u8)0)

#define MDIO_DIROUTPUT  1
#define MDIO_DIRINPUT   0

#define MDIO_u8DIRMAXVAL  ((u8)0xFF)
#define MDIO_u8DIRMINVAL  ((u8)0x00)

#define MDIO_u8PORTMAXVAL  ((u8)0xFF)
#define MDIO_u8PORTMINVAL  ((u8)0x00)

#define MDIO_u8OUTPUTHIGH ((u8)1)
#define MDIO_u8OUTPUTLOW   ((u8)0)

#define MDIO_OUTPUTHIGH 1
#define MDIO_OUTPUTLOW  0

#define MDIO_u8INPUTPULLUP ((u8)1)
#define MDIO_u8INPUTHIGHIMPEDANCE ((u8)0)

#define MDIO_INPUTPULLUP 1
#define MDIO_INPUTHIGHIMPEDANCE 0

#define NullPointer     ((void*)0x00)

#define u8RegisterSize    ((u8)8)


tenumFncErrorState MDIO_Init(void);

tenumFncErrorState MDIO_enuSetPinDirection(u8 u8PinNoCpy,
						                  u8 u8DirValCpy);

tenumFncErrorState MDIO_enuSetPinValue(u8 u8PinNoCpy,
                                      u8 u8ValCpy);

tenumFncErrorState MDIO_enuGetPinValue(u8 u8PinNoCpy,
                                      pu8 pu8ValCpy);

tenumFncErrorState MDIO_enuSetPortDirection(u8 u8PortNoCpy,
                                           u8 u8DirValCpy);


tenumFncErrorState MDIO_enuSetPortValue(u8 u8PortNoCpy,
                                       u8 u8ValCpy);


tenumFncErrorState MDIO_enuGetPortValue(u8 u8PortNoCpy,
                                       pu8 pu8ValCpy);


#endif /* CSWC_PLTF_BSW_ATMEGA32_CSWC_PLTF_MCU_ATMEGA32_MDIO_MDIO_INT_H_ */
#endif /* CSWC_MDIO_INT_H_ */
