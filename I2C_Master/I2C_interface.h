/*
 * I2C_interface.h
 *
 *  Created on: Apr 18, 2022
 *      Author: INTEL
 */

#ifndef MCAL_I2C_MASTER_I2C_INTERFACE_H_
#define MCAL_I2C_MASTER_I2C_INTERFACE_H_
/*I2C_Acknowledge_Bit*/
#define I2C_Enable_Acknowledge_Bit   0
#define I2C_Disable_Acknowledge_Bit  1
/*I2C_Interrupt*/
#define I2C_Interrupt_Enable   0
#define I2C_Interrupt_Disable  1
/*I2C_Modes*/
#define I2C_Master_Mode 0
#define I2C_Slave_Mode  1
typedef enum{
	I2C_DOK,
	I2C_OK
}I2C_ErrorStatus;


void I2C_voidInit(void);
void I2C_voidSlaveInit(U8 Copy_u8Adress);
I2C_ErrorStatus I2C_enumStartCondition(void);
I2C_ErrorStatus I2C_enumRepeatedStart(void);
void I2C_voidStopCondition(void);
/*********************************Master_Node************************************/
I2C_ErrorStatus I2C_enum_Master_Send_Slave_Address_With_Write(U8 Copy_u8Address);
I2C_ErrorStatus I2C_enum_Master_Send_Slave_Address_With_Read(U8 Copy_u8Address);
I2C_ErrorStatus I2C_enum_Master_Write_Byte_TO_Slave(U8 Copy_u8Data);
I2C_ErrorStatus I2C_enum_Master_Read_Byte_From_Slave_NAK(U8 *Copy_Ptr);
/*********************************Slave_Node*************************************/
I2C_ErrorStatus I2C_enum_Slave_Listen_His_Address_With_Write(void);
I2C_ErrorStatus I2C_enum_Slave_Listen_His_Address__With_Read(void);
I2C_ErrorStatus I2C_enum_Slave_Write_Byte_TO_Master_NAK(U8 Copy_u8Data);
I2C_ErrorStatus I2C_enum_Slave_Read_Byte_From_Master(U8 *Copy_Ptr);












#endif /* MCAL_I2C_MASTER_I2C_INTERFACE_H_ */
