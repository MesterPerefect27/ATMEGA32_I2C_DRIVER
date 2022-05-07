/*
 * I2C_config.h
 *
 *  Created on: Apr 18, 2022
 *      Author: INTEL
 */

#ifndef MCAL_I2C_MASTER_I2C_CONFIG_H_
#define MCAL_I2C_MASTER_I2C_CONFIG_H_
/*option
 * I2C_Enable_Acknowledge_Bit
 * I2C_Disable_Acknowledge_Bit */
#define I2C_Acknowledge_Bit   I2C_Enable_Acknowledge_Bit
/*option
 * I2C_Interrupt_Enable
 * I2C_Interrupt_Disable*/
#define I2C_Interrupt   I2C_Interrupt_Disable
/*option
 * I2C_Master_Mode
 * I2C_Slave_Mode */
#define I2C_Mode  I2C_Master_Mode
/*Bit_Rate*/
#define I2C_Bit_Rate    32
#endif /* MCAL_I2C_MASTER_I2C_CONFIG_H_ */
