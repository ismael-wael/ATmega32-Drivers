#ifndef MTWI_INT_H_
#define MTWI_INT_H_

#define MTWI_MSTR_MODE		0
#define MTWI_SLV_MODE		1

#define MTWI_clk_50_KHZ		0
#define MTWI_clk_100_KHZ	1
#define MTWI_clk_160_KHZ	2
#define MTWI_clk_200_KHZ	3

typedef enum
{
	ERROR,
	SUCCESS
}state;

typedef enum
{
    MTWI_START            = 0x08,
	MTWI_REP_START        = 0x10,
	MTWI_MT_SLA_ACK       = 0x18,
	MTWI_MT_SLA_NOT_ACK   = 0x20,
	MTWI_MT_DATA_ACK      = 0x28,
	MTWI_MT_DATA_NOT_ACK  = 0x30,
	MTWI_MT_ARB_LOST      = 0x38,
	MTWI_MR_ARB_LOST      = 0x38,
	MTWI_MR_SLA_ACK       = 0x40,
	MTWI_MR_SLA_NOT_ACK   = 0x48,
	MTWI_MR_DATA_ACK      = 0x50,
	MTWI_MR_DATA_NOT_ACK  = 0x58,
	MTWI_SR_SLA_W_ACK     = 0x60, // Slave Received ( slave address + Write request ) + ACK Transmit from slave
	MTWI_SR_GCALL_ACK     = 0x70, // Slave Received General Call + ACK Transmit from slave
	MTWI_SR_DATA_ACK      = 0x80, // Previously addressed with own SLA+W; data has been received; ACK has been returned
	MTWI_SR_DATA_NACK     = 0x88, // Previously addressed with own SLA+W; data has been received; NOT ACK has been returned
	MTWI_SR_GC_DATA_ACK   = 0x90, // Previously addressed with General Call; data has been received; ACK has been returned
	MTWI_SR_GC_DATA_NACK  = 0x98, // Previously addressed with General Call; data has been received; NOT ACK has been returned
	MTWI_STOP             = 0xA0, // STOP condition or repeated START condition has been received while still addressed as slave

	MTWI_SR_SLA_R_ACK     = 0xA8, // Slave Received ( slave address + Read request ) + ACK Transmit from slave
	MTWI_ST_DATA_ACK      = 0xB8, // Slave Transmit data and ACK has been received
	MTWI_ST_DATA_NACK     = 0xC0, // Slave Transmit data and NOT ACK has been received
	MTWI_ST_LAST_DATA     = 0xC8// Slave Transmit LAST data and ACK has been received

}tenumI2CErrorState ;

tenumFncErrorState MTWI_enuInit(void);
void MTWI_voidStartCond(void);
void MTWI_voidStopCond(void);
void MTWI_voidWriteByte(u8 u8data);
u8 MTWI_enuReadStatus(void);
u8 MTWI_enuReadByteACK(void);
u8 MTWI_enuReadByteNACK(void);
state MTWI_enuSendString(u8 address,const pu8 str_ptr);
void MTWI_voidReceiveString(pu8 buffer);
void MTWI_Callback(void(*function_ptr) (void));

#endif /* MTWI_INT_H_ */
