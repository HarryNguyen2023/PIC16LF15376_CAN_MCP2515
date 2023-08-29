#include "mcc_generated_files/mcc.h"
#include <string.h>
#include "CAN_MCP2515.h"

uint8_t press = 0;
uint8_t sendframe1[8] = "abcdefgh";
uint8_t sendframe2[8] = "ijklmnop";
uint8_t sendframe3[8] = "qrstuvwx";
uint8_t rcv_buffer[9] = {0,0,0,0,0,0,0,0,0};
// Identifier of the node
uint16_t node_identifier[] = {1365};

// Function to handle the interrupt on change caused by the INT pin of the MCP2515
void MCP2515_Receive_ISR(void)
{
    LED3_Toggle();
    MCP2515_Read_Message(rcv_buffer);
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    // Initiate the MCP2515 CAN controller
    MCP2515_Init(STANDARD_CAN,node_identifier);
    
    // Enable the interrupt on change at pin connected to the MCP2515 INT pin
    cSTBY_SetLow(); //Careful on this line
    IOCCF7_SetInterruptHandler(MCP2515_Receive_ISR);
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    // Enable global interrupt
    INTERRUPT_GlobalInterruptEnable();

    while (1)
    {
        CLRWDT();

        if(SW1_GetValue() == 0 && press == 0)
        {
            MCP2515_Send_DataFrame(STANDARD_CAN, node_identifier, 0, (uint8_t*)sendframe1, 8);
            press = 1;
        }
        else if(SW2_GetValue() == 0 && press == 0)
        {
            MCP2515_Send_DataFrame(STANDARD_CAN, node_identifier, 1, (uint8_t*)sendframe2, 8);
            press = 1;
        }
        else if (SW3_GetValue() == 0 && press == 0)
        {
            MCP2515_Send_DataFrame(STANDARD_CAN, node_identifier, 2, (uint8_t*)sendframe3, 8);
            press = 1;
        }
        else if(SW1_GetValue() == 1 && SW2_GetValue() == 1 && SW3_GetValue() == 1)
        {
            press=0;
        }
        
        if(strcmp((char*)rcv_buffer,"abcdefgh")==0)
        {
            LED1_SetHigh();
            LED2_SetLow();
            LED3_SetLow();
        }
        else if (strcmp((char*)rcv_buffer,"ijklmnop")==0)
        {
            LED1_SetLow();
            LED2_SetHigh();
            LED3_SetLow();
        }
        else if (strcmp((char*)rcv_buffer,"qrstuvwx")==0)
        {
            LED1_SetLow();
            LED2_SetLow();
            LED3_SetLow();
        }
    }
}

