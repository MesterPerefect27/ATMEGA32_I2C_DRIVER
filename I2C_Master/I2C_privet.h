/*
 * I2C_privet.h
 *
 *  Created on: Apr 18, 2022
 *      Author: INTEL
 */

#ifndef MCAL_I2C_MASTER_I2C_PRIVET_H_
#define MCAL_I2C_MASTER_I2C_PRIVET_H_

#define TWBR_REG *((volatile U8*)0X20)
#define TWCR_REG *((volatile U8*)0X56)
#define TWSR_REG *((volatile U8*)0X21)
#define TWDR_REG *((volatile U8*)0X23)
#define TWAR_REG *((volatile U8*)0X22)
/**************************TWBR_REG**************************/
#define TWBR7   7
#define TWBR6   6
#define TWBR5   5
#define TWBR4   4
#define TWBR3   3
#define TWBR2   2
#define TWBR1   1
#define TWBR0   0
/****************************TWCR_REG***********************/
#define  TWINT   7
#define  TWEA    6
#define  TWSTA   5
#define  TWSTO   4
#define  TWWC    3
#define  TWEN    2
#define  TWIE    0
/*****************************TWSR_REG**********************/
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
#define TWPS1   1
#define TWPS0   0
/*****************************TWDR_REG***********************/
#define  TWD7   7
#define  TWD6   6
#define  TWD5   5
#define  TWD4   4
#define  TWD3   3
#define  TWD2   2
#define  TWD1   1
#define  TWD0   0
/*TWAR_REG*/
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0
/****************************Status_Codes_for_Master_Transmitter_Mode***************/
#define I2C_START_condition_Status             0X08
#define I2C_repeated_START_Status              0X10
#define I2C_SLA_W_has_been_transmitted_ACK     0X18
#define I2C_Data_byte_has_been_transmitted_ACK 0X28
/****************************Status_Codes_for_Master_Receiver_Mode*****************/
#define I2C_SLA_R_has_been_transmitted_ACK        0X40
#define I2C_Data_byte_has_been_received_NOT_ACK   0X58
/***************************Status_Codes_for_Slave_Receiver_Mode******************/
#define I2C_SLA_W_has_been_received_ACK       0X60
#define I2C_SLA_W_data_has_been_received_ACK  0X80
/***************************Status_Codes_for_Slave_Transmitter_Mode***************/
#define I2C_SLA_R_has_been_received_ACK                      0XA8
#define I2C_Data_byte_in_TWDR_has_been_transmitted_NOT_ACK   0XC0
#endif /* MCAL_I2C_MASTER_I2C_PRIVET_H_ */
