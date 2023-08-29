#include "CAN_MCP2515.h"

// Define the operation modeS of the MCP2515 interfacing with the MCP2515
typedef enum
{
    MCP2515_RESET = 0xC0,
    MCP2515_READ = 0x03,
    MCP2515_READ_RX_BUFFER_0 = 0x92,
    MCP2515_READ_RX_BUFFER_1 = 0x96,
    MCP2515_WRITE = 0x02,
    MCP2515_LOAD_TX_BUFFER_0 = 0x41,
    MCP2515_LOAD_TX_BUFFER_1 = 0x43,
    MCP2515_LOAD_TX_BUFFER_2 = 0x45,
    MCP2515_RTS_BUFFER_0 = 0x81,
    MCP2515_RTS_BUFFER_1 = 0x82,
    MCP2515_RTS_BUFFER_2 = 0x84,
    MCP2515_READ_STATUS = 0xA0,
    MCP2515_READ_RX_STATUS = 0xB0,
    MCP2515_BIT_MODIFY = 0X05
}MPC2515_MODE;

// ---------------------------------------------- Static functions hidden from users --------------------------------------------------

// Function to request to send the specific transmit buffer in the MCP2515 CAN controller
static void MCP2515_RequesttoSend(uint8_t buff)
{
    uint8_t req_buff;
    switch(buff)
    {
        case 0:
            req_buff = MCP2515_RTS_BUFFER_0;
            break;
        case 1:
            req_buff = MCP2515_RTS_BUFFER_1;
            break;
        case 2:
            req_buff = MCP2515_RTS_BUFFER_2;
            break;
        default:
            return;
    }
    SPI1_Open(SPI1_DEFAULT);
    CS_SetLow();
    SPI1_ExchangeByte(req_buff);
    CS_SetHigh(); 
    SPI1_Close();
}

// Function to reset the sensor
static void MCP2515_Reset()
{
    SPI1_Open(SPI1_DEFAULT);
    CS_SetLow();
    SPI1_ExchangeByte(MCP2515_RESET);
    CS_SetHigh(); 
    SPI1_Close();
}

// Function to load data into the TX buffers
static void MCP2515_Load_Tx_Buffer(uint8_t buff_num, uint8_t* data, uint8_t len)
{
    SPI1_Open(SPI1_DEFAULT);
    CS_SetLow(); 
    if(buff_num == 0)
        SPI1_ExchangeByte(MCP2515_LOAD_TX_BUFFER_0);
    else if(buff_num == 1)
        SPI1_ExchangeByte(MCP2515_LOAD_TX_BUFFER_1);
    else if(buff_num == 2)
        SPI1_ExchangeByte(MCP2515_LOAD_TX_BUFFER_2);
    else
    {
        CS_SetHigh(); 
        SPI1_Close();
        return;
    }
    for(int i = 0; i < len; ++i)
        SPI1_ExchangeByte(data[i]);
    CS_SetHigh(); 
    SPI1_Close();
}

// Function to read the status of the MCP2515 CAN controller
static uint8_t MCP2515_Read_Status()
{
    SPI1_Open(SPI1_DEFAULT);
    CS_SetLow();
    SPI1_ExchangeByte(MCP2515_READ_STATUS);
    uint8_t data = SPI1_ExchangeByte(0x00);
    CS_SetHigh(); 
    SPI1_Close();
    return data;
}

// Function to load the RX buffer
static void MCP2515_Load_Rx_Buffer(uint8_t buff, uint8_t* rcv_buffer, uint8_t len)
{
    SPI1_Open(SPI1_DEFAULT);
    CS_SetLow();
    if(buff == 0)
        SPI1_ExchangeByte(MCP2515_READ_RX_BUFFER_0);
    else if(buff == 1)
        SPI1_ExchangeByte(MCP2515_READ_RX_BUFFER_1);
    else
    {
        CS_SetHigh(); 
        SPI1_Close();
        return;
    }
    for(uint8_t i = 0; i < len; ++i)
        rcv_buffer[i] = SPI1_ExchangeByte(0x00);
    CS_SetHigh(); 
    SPI1_Close();
}

// --------------------------------------------- General functions interfacing with users ------------------------------------------------

// Function to initiate the MCP2515 CAN controller
void MCP2515_Init(CAN_MODE mode, uint16_t* identifier)
{
    // Reset the controller
    MCP2515_Reset();
    // Clear the TXREQ buffer before load any data into TX buffers
    MCP2515_Write_Register(0x30, 0x00);
    MCP2515_Write_Register(0x40, 0x00);
    MCP2515_Write_Register(0x50, 0x00);
    // Set the filter identifier value for the RX buffer 0
    if(mode == STANDARD_CAN)
    {
        identifier[0] = (identifier[0] << 5) & 0xFFFF;
        MCP2515_Write_Register(0x00, (identifier[0] >> 8) & 0xFF);
        MCP2515_Write_Register(0x01, identifier[0] & 0xFF);
    }
    else if(mode == EXTENDED_CAN)
    {
        identifier[0] = (identifier[0] << 3) & 0xFFFF;
        MCP2515_Write_Register(0x00, (identifier[0] >> 8) & 0xFF);
        uint8_t right_3_msb = identifier[0] & 0xE0;
        right_3_msb |= 0x08;
        right_3_msb += (identifier[0] & 0x18) >> 3;
        MCP2515_Write_Register(0x01, right_3_msb);
        MCP2515_Write_Register(0x02, (identifier[1] >> 8) & 0xFF);
        MCP2515_Write_Register(0x03, identifier[1] & 0xFF);
    }
    // Configure the mask of the RX buffer 0 to full bit
    if(mode == STANDARD_CAN)
    {
        MCP2515_Write_Register(0x20, 0xFF);
        MCP2515_Write_Register(0x21, 0xE0);
    }
    else if(mode == EXTENDED_CAN)
    {
        MCP2515_Write_Register(0x20, 0xFF);
        MCP2515_Write_Register(0x21, 0xE3);
        MCP2515_Write_Register(0x22, 0xFF);
        MCP2515_Write_Register(0x23, 0xFF);
    }
    // Configure the timing synchronization of the controller
    MCP2515_Write_Register(0x2A, 0x0F);
    // Configure the interrupt of the controller for receive buffer 0 & 1 only
    MCP2515_Write_Register(0x2B, 0x03);
    // Change the operation mode into normal mode and begin communication
    MCP2515_Write_Register(0x0F, 0x10);
}

// Function to write data to a register in MCP2515 CAN controller
void MCP2515_Write_Register(uint8_t reg, uint8_t data)
{
    SPI1_Open(SPI1_DEFAULT);
    CS_SetLow();
    SPI1_ExchangeByte(MCP2515_WRITE); 
    SPI1_ExchangeByte(reg); 
    SPI1_ExchangeByte(data); 
    CS_SetHigh(); 
    SPI1_Close();    
}

// Function to modify a single bit in MCP2515 CAN controller
void MCP2515_Bit_Modify(uint8_t reg, uint8_t mask, uint8_t data)
{
    SPI1_Open(SPI1_DEFAULT);
    CS_SetLow();
    SPI1_ExchangeByte(MCP2515_BIT_MODIFY); 
    SPI1_ExchangeByte(reg); 
    SPI1_ExchangeByte(mask);
    SPI1_ExchangeByte(data); 
    CS_SetHigh(); 
    SPI1_Close();
}

// Function to send data frame message via CAN
void MCP2515_Send_DataFrame(CAN_MODE mode, uint16_t* identifier, uint8_t buff_num, uint8_t* tx_buffer, uint8_t len)
{
    switch(buff_num)
    {
        case 0:
            // Clear the TXREQ buffer before load any data into TX buffers
            MCP2515_Write_Register(0x30, 0x00);
            // Write the identifier
            if(mode == STANDARD_CAN)
            {
                identifier[0] = (identifier[0] << 5) & 0xFFFF;
                MCP2515_Write_Register(0x31, (identifier[0] >> 8) & 0xFF);
                MCP2515_Write_Register(0x32, identifier[0] & 0xFF);
            }
            else if(mode == EXTENDED_CAN)
            {
                identifier[0] = (identifier[0] << 3) & 0xFFFF;
                MCP2515_Write_Register(0x31, (identifier[0] >> 8) & 0xFF);
                uint8_t right_3_msb = identifier[0] & 0xE0;
                right_3_msb |= 0x08;
                right_3_msb += (identifier[0] & 0x18) >> 3;
                MCP2515_Write_Register(0x32, right_3_msb);
                MCP2515_Write_Register(0x33, (identifier[1] >> 8) & 0xFF);
                MCP2515_Write_Register(0x34, identifier[1] & 0xFF);
            }
            // Set the type of frame and the length
            MCP2515_Write_Register(0x35, len);
            break;
        case 1:
            // Clear the TXREQ buffer before load any data into TX buffers
            MCP2515_Write_Register(0x40, 0x00);
            // Write the identifier
            if(mode == STANDARD_CAN)
            {
                identifier[0] = (identifier[0] << 5) & 0xFFFF;
                MCP2515_Write_Register(0x41, (identifier[0] >> 8) & 0xFF);
                MCP2515_Write_Register(0x42, identifier[0] & 0xFF);
            }
            else if(mode == EXTENDED_CAN)
            {
                identifier[0] = (identifier[0] << 3) & 0xFFFF;
                MCP2515_Write_Register(0x41, (identifier[0] >> 8) & 0xFF);
                uint8_t right_3_msb = identifier[0] & 0xE0;
                right_3_msb |= 0x08;
                right_3_msb += (identifier[0] & 0x18) >> 3;
                MCP2515_Write_Register(0x42, right_3_msb);
                MCP2515_Write_Register(0x43, (identifier[1] >> 8) & 0xFF);
                MCP2515_Write_Register(0x44, identifier[1] & 0xFF);
            }
            // Set the type of frame and the length
            MCP2515_Write_Register(0x45, len);
            break;
        case 2:
            // Clear the TXREQ buffer before load any data into TX buffers
            MCP2515_Write_Register(0x50, 0x00);
            // Write the identifier
            if(mode == STANDARD_CAN)
            {
                identifier[0] = (identifier[0] << 5) & 0xFFFF;
                MCP2515_Write_Register(0x51, (identifier[0] >> 8) & 0xFF);
                MCP2515_Write_Register(0x52, identifier[0] & 0xFF);
            }
            else if(mode == EXTENDED_CAN)
            {
                identifier[0] = (identifier[0] << 3) & 0xFFFF;
                MCP2515_Write_Register(0x51, (identifier[0] >> 8) & 0xFF);
                uint8_t right_3_msb = identifier[0] & 0xE0;
                right_3_msb |= 0x08;
                right_3_msb += (identifier[0] & 0x18) >> 3;
                MCP2515_Write_Register(0x52, right_3_msb);
                MCP2515_Write_Register(0x53, (identifier[1] >> 8) & 0xFF);
                MCP2515_Write_Register(0x54, identifier[1] & 0xFF);
            }
            // Set the type of frame and the length
            MCP2515_Write_Register(0x55, len);
            break;
        default:
            return;
    }
    // Load data in TX buffers
    MCP2515_Load_Tx_Buffer(buff_num, tx_buffer, len);
    // Initiate the transmission
    MCP2515_RequesttoSend(buff_num);
}

// Function to send the remote frame
void MCP2515_Send_RemoteFrame(CAN_MODE mode, uint16_t* identifier, uint8_t buff_num, uint8_t len)
{
    switch(buff_num)
    {
        case 0:
            // Clear the TXREQ buffer before load any data into TX buffers
            MCP2515_Write_Register(0x30, 0x00);
            // Write the identifier
            if(mode == STANDARD_CAN)
            {
                identifier[0] = (identifier[0] << 5) & 0xFFFF;
                MCP2515_Write_Register(0x31, (identifier[0] >> 8) & 0xFF);
                MCP2515_Write_Register(0x32, identifier[0] & 0xFF);
            }
            else if(mode == EXTENDED_CAN)
            {
                identifier[0] = (identifier[0] << 3) & 0xFFFF;
                MCP2515_Write_Register(0x31, (identifier[0] >> 8) & 0xFF);
                uint8_t right_3_msb = identifier[0] & 0xE0;
                right_3_msb |= 0x08;
                right_3_msb += (identifier[0] & 0x18) >> 3;
                MCP2515_Write_Register(0x32, right_3_msb);
                MCP2515_Write_Register(0x33, (identifier[1] >> 8) & 0xFF);
                MCP2515_Write_Register(0x34, identifier[1] & 0xFF);
            }
            // Set the type of frame and the length
            MCP2515_Write_Register(0x35, len |= 0x40);
        case 1:
            // Clear the TXREQ buffer before load any data into TX buffers
            MCP2515_Write_Register(0x40, 0x00);
            // Write the identifier
            if(mode == STANDARD_CAN)
            {
                identifier[0] = (identifier[0] << 5) & 0xFFFF;
                MCP2515_Write_Register(0x41, (identifier[0] >> 8) & 0xFF);
                MCP2515_Write_Register(0x42, identifier[0] & 0xFF);
            }
            else if(mode == EXTENDED_CAN)
            {
                identifier[0] = (identifier[0] << 3) & 0xFFFF;
                MCP2515_Write_Register(0x41, (identifier[0] >> 8) & 0xFF);
                uint8_t right_3_msb = identifier[0] & 0xE0;
                right_3_msb |= 0x08;
                right_3_msb += (identifier[0] & 0x18) >> 3;
                MCP2515_Write_Register(0x42, right_3_msb);
                MCP2515_Write_Register(0x43, (identifier[1] >> 8) & 0xFF);
                MCP2515_Write_Register(0x44, identifier[1] & 0xFF);
            }
            // Set the type of frame and the length
            MCP2515_Write_Register(0x45, len |= 0x40);
        case 2:
            // Clear the TXREQ buffer before load any data into TX buffers
            MCP2515_Write_Register(0x50, 0x00);
            // Write the identifier
            if(mode == STANDARD_CAN)
            {
                identifier[0] = (identifier[0] << 5) & 0xFFFF;
                MCP2515_Write_Register(0x51, (identifier[0] >> 8) & 0xFF);
                MCP2515_Write_Register(0x52, identifier[0] & 0xFF);
            }
            else if(mode == EXTENDED_CAN)
            {
                identifier[0] = (identifier[0] << 3) & 0xFFFF;
                MCP2515_Write_Register(0x51, (identifier[0] >> 8) & 0xFF);
                uint8_t right_3_msb = identifier[0] & 0xE0;
                right_3_msb |= 0x08;
                right_3_msb += (identifier[0] & 0x18) >> 3;
                MCP2515_Write_Register(0x52, right_3_msb);
                MCP2515_Write_Register(0x53, (identifier[1] >> 8) & 0xFF);
                MCP2515_Write_Register(0x54, identifier[1] & 0xFF);
            }
            // Set the type of frame and the length
            MCP2515_Write_Register(0x55, len |= 0x40);
        default:
            return;
    }
    // Initiate the transmission
    MCP2515_RequesttoSend(buff_num);
}

// Function to read a specific register in MCP2515 CAN controller
void MCP2515_Read_Register(uint8_t reg, uint8_t* data)
{
    SPI1_Open(SPI1_DEFAULT); 
    CS_SetLow(); 
    SPI1_ExchangeByte(MCP2515_READ); 
    SPI1_ExchangeByte(reg); 
    *data = SPI1_ExchangeByte(0x00); 
    CS_SetHigh(); 
    SPI1_Close();
}

// Function to read the data from the MCP2515 CAN controller
void MCP2515_Read_Message(uint8_t* rcv_buffer)
{
    uint8_t data_len = 0;
    // Read the interrupt source
    uint8_t int_status = MCP2515_Read_Status();
    if(int_status & 0x01)
    {
        int_status = 0;
        // Clear the interrupt flag bit
        MCP2515_Bit_Modify(0x2C, 0x01, 0x00);
    }
    else if(int_status & 0x02)
    {
        int_status = 1;
        // Clear the interrupt flag bit
        MCP2515_Bit_Modify(0x2C, 0x02, 0x00);
    }  
    // Read the length of the incoming data
    MCP2515_Read_Register(0x65, &data_len);
    data_len = data_len & 0x0F;
    // Load the data in the RX buffers
    MCP2515_Load_Rx_Buffer(int_status, rcv_buffer, data_len);
}


