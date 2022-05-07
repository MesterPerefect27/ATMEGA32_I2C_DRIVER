/*
 * I2C_program.c
 *
 *  Created on: Apr 18, 2022
 *      Author: INTEL
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include "../I2C_Master/I2C_config.h"
#include "../I2C_Master/I2C_interface.h"
#include "../I2C_Master/I2C_privet.h"
void I2C_voidInit(void)
{

	TWBR_REG=I2C_Bit_Rate;/*generat_Speed-->100Kbps*/
	TWSR_REG&=(~(1<<TWPS0))&(~(1<<TWPS1));/*Set_prescullar*/
#if I2C_Interrupt==I2C_Interrupt_Enable
	TWCR_REG|=(1<<TWIE);
#elif I2C_Interrupt==I2C_Interrupt_Disable
	TWCR_REG&=~(1<<TWIE);
#endif
    TWCR_REG|=(1<<TWEA);/*Enable_Ack*/
	TWCR_REG|=(1<<TWEN);/*Enable_TWI*/
}
void I2C_voidSlaveInit(U8 Copy_u8Adress)
{
	TWAR_REG=Copy_u8Adress;/*Assign Address in TWI Address Register*/
	TWCR_REG=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);/*Enable_TWI*/
}
I2C_ErrorStatus I2C_enumStartCondition(void)
{

	TWCR_REG=(1<<TWSTA)|(1<<TWINT)|(1<<TWEN);/*generat_Start,Clear_Flag*/
	while(!GET_BIT(TWCR_REG,TWINT));/*Wait_Flag*/
	if((TWSR_REG&0XF8)==I2C_START_condition_Status){/*Cheak_Status*/
		return I2C_OK;
	}else{
		return I2C_DOK;
	}

}
I2C_ErrorStatus I2C_enumRepeatedStart(void)
{

	TWCR_REG|=(1<<TWSTA)|(1<<TWINT)|(1<<TWEN);/*generat_Start,Clear_Flag*/
	while(!GET_BIT(TWCR_REG,TWINT));/*Wait_Flag*/
	if((TWSR_REG&0XF8)==I2C_repeated_START_Status){/*Cheak_Status*/
		return I2C_OK;
	}else{
		return I2C_DOK;
	}

}
void I2C_voidStopCondition(void)
{
	TWCR_REG=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);/*generat_Stop,Clear_Flag*/
	while(TWCR_REG&(1<<TWSTO));/*wait until stop condition execute*/

}
I2C_ErrorStatus I2C_enum_Master_Send_Slave_Address_With_Write(U8 Copy_u8Address)
{
	TWDR_REG=(Copy_u8Address<<TWD1);/*Assign Slave Address in Data Register*/
	TWCR_REG&=~(1<<TWSTA);/*Clear_Start_Condition*/
	TWCR_REG|=(1<<TWINT)|(1<<TWEN);/*Clear_Flag*/
	while(!GET_BIT(TWCR_REG,TWINT));/*Wait_Flag*/
	if((TWSR_REG&0XF8)==I2C_SLA_W_has_been_transmitted_ACK){/*Cheak_Status*/
		return I2C_OK;
	}else{
		return I2C_DOK;
	}

}
I2C_ErrorStatus I2C_enum_Master_Send_Slave_Address_With_Read(U8 Copy_u8Address)
{
	TWDR_REG=(Copy_u8Address<<TWD1);/*Assign Slave Address in Data Register*/
	TWDR_REG|=(1<<TWD0);/*Set Read Bit*/
	TWCR_REG&=~(1<<TWSTA);/*Clear_Start_Condition*/
	TWCR_REG|=(1<<TWINT)|(1<<TWEN);/*Clear_Flag*/
	while(!GET_BIT(TWCR_REG,TWINT));/*Wait_Flag*/
	if((TWSR_REG&0XF8)==I2C_SLA_R_has_been_transmitted_ACK){/*Cheak_Status*/
		return I2C_OK;
	}else{
		return I2C_DOK;
	}
}
I2C_ErrorStatus I2C_enum_Master_Write_Byte_TO_Slave(U8 Copy_u8Data)
{
	TWDR_REG=Copy_u8Data;/*Assign Data in Data Register*/
	TWCR_REG=(1<<TWINT)|(1<<TWEN);/*Clear_Flag*/
	while(!GET_BIT(TWCR_REG,TWINT));/*Wait_Flag*/
	if((TWSR_REG&0XF8)==I2C_Data_byte_has_been_transmitted_ACK){/*Cheak_Status*/
		return I2C_OK;
	}else{
		return I2C_DOK;
	}

}
I2C_ErrorStatus I2C_enum_Master_Read_Byte_From_Slave_NAK(U8 *Copy_Ptr)
{

	TWCR_REG|=(1<<TWINT)|(1<<TWEN);/*Clear_Flag*/
	while(!GET_BIT(TWCR_REG,TWINT));/*Wait_Flag*/
	if((TWSR_REG&0XF8)==I2C_Data_byte_has_been_received_NOT_ACK){/*Cheak_Status*/

		*Copy_Ptr=TWDR_REG;
		return I2C_OK;
	}else{
		return I2C_DOK;
	}

}
I2C_ErrorStatus I2C_enum_Slave_Listen_His_Address_With_Write(void)
{

	TWCR_REG|=(1<<TWEA)|(1<<TWINT)|(1<<TWEN);/*Enable_ACknowledge_Bit,Clear_Flag*/
	while(!GET_BIT(TWCR_REG,TWINT));/*Wait_Flag*/
	if((TWSR_REG&0XF8)==I2C_SLA_W_has_been_received_ACK){/*Cheak_Status*/
		return I2C_OK;
	}else{
		return I2C_DOK;
	}

}
I2C_ErrorStatus I2C_enum_Slave_Listen_His_Address__With_Read(void)
{

	TWCR_REG|=(1<<TWEA)|(1<<TWINT)|(1<<TWEN);/*Enable_ACknowledge_Bit,Clear_Flag*/
	while(!GET_BIT(TWCR_REG,TWINT));/*Wait_Flag*/
	if((TWSR_REG&0XF8)==I2C_SLA_R_has_been_received_ACK){/*Cheak_Status*/
		return I2C_OK;

	}else{
		return I2C_DOK;

	}

}
I2C_ErrorStatus I2C_enum_Slave_Write_Byte_TO_Master_NAK(U8 Copy_u8Data)
{
	TWDR_REG=Copy_u8Data;
	TWCR_REG|=(1<<TWINT)|(1<<TWEN);/*Clear_Flag*/
	while(!GET_BIT(TWCR_REG,TWINT));/*Wait_Flag*/
	if((TWSR_REG&0XF8)==I2C_Data_byte_in_TWDR_has_been_transmitted_NOT_ACK){/*Cheak_Status*/
		return I2C_OK;

	}else{
		return I2C_DOK;
	}

}
I2C_ErrorStatus I2C_enum_Slave_Read_Byte_From_Master(U8 *Copy_Ptr)
{
	TWCR_REG|=(1<<TWINT)|(1<<TWEN);/*Clear_Flag*/
	while(!GET_BIT(TWCR_REG,TWINT));/*Wait_Flag*/
	if((TWSR_REG&0XF8)==I2C_SLA_W_data_has_been_received_ACK){/*Cheak_Status*/

		*Copy_Ptr=TWDR_REG;
		return I2C_OK;
	}else{
		return I2C_DOK;
	}

}
