#ifndef CAN_MCP2515_H
#define CAN_MCP2515_H

#include "mcc_generated_files/mcc.h"

// Define the type of CAN to be use
typedef enum
{
    STANDARD_CAN,
    EXTENDED_CAN
}CAN_MODE;

// Function prototypes
void MCP2515_Init(CAN_MODE mode, uint16_t* identifier);
void MCP2515_Write_Register(uint8_t reg, uint8_t data);
void MCP2515_Read_Register(uint8_t reg, uint8_t* data);
void MCP2515_Bit_Modify(uint8_t reg, uint8_t mask, uint8_t data);
void MCP2515_Send_DataFrame(CAN_MODE mode, uint16_t* identifier, uint8_t buff_num, uint8_t* tx_buffer, uint8_t len);
void MCP2515_Send_RemoteFrame(CAN_MODE mode, uint16_t* identifier, uint8_t buff_num, uint8_t len);
void MCP2515_Read_Message(uint8_t* rcv_buffer);

#endif