#include "SRXL2.h"
#include "eusart.h"
#include "globals.h"

// inline void SetSRLX2Interrupt(void)
// {
// 	EUSART_SetRxInterruptHandler(SRXL2_StateMachine);
// }

void SRXL2_StateMachine(void)
{
	if (EUSART_is_rx_ready())
	{
		uint8_t val = EUSART_Read();
		uint8_t dontRunCRC = 0;
		switch(glbComm.state)
		{
			case STATE_START_1:
				if (val == 0xA6)
	            {
					glbComm.state++;
	                glbComm.crc = 0;
	            }

			break;
			
			case STATE_START_2:
				if (val == 0xCD)
					glbComm.state++;			
				else
					glbComm.state = STATE_START_1;
			break;
			
			case STATE_LENGTH:
				//calculate the number of channels we're processing
	            //subtract start byte, packet type, lenght, rssi, frame loss, crc
	            //then divid e by 2 (channel data is a uint16, 2 bytes)
				
				glbComm.numChannels = (val - 14) >> 1; 
				glbComm.state++;
			break;
			
			case STATE_COMMAND:
				//for now, only going to be able to support channel data
				if (val == 0x00)
				{
					glbComm.state++;
					
					//use this glbComm.state to reset all variables we'll need in the future
					glbComm.payloadCh = 0;
					glbComm.channelMask = 0;
					glbComm.tempValue = 0;				
				}
				else
				{
					glbComm.state = STATE_START_1;
				}
			break;
			
			case STATE_REPLYID:
				//might need to implement this if we only respond to
				//certain addresses
			case STATE_RSSI:
			case STATE_FRAMELOSS_1:
			case STATE_FRAMELOSS_2:
				//do nothing
				if (glbComm.state == STATE_FRAMELOSS_2 && glbComm.numChannels == 0)
					glbComm.state = STATE_CRC_1;
				else
					glbComm.state++;
			break;
			
			case STATE_CHANNELMASK_1:
				glbComm.channelMask = 0;
			case STATE_CHANNELMASK_2:
			case STATE_CHANNELMASK_3:
			case STATE_CHANNELMASK_4:

				glbComm.channelMask |= (uint32_t)(val << (8 * (glbComm.state - STATE_CHANNELMASK_1)));
				
				//make a copy of the channel mask
				//then separate out the channels of interest
				if (glbComm.state == STATE_CHANNELMASK_4)
				{			
					glbComm.UARTCallbackChannels = glbComm.channelMask & (1 | (1 << glbComm.auxChannel) ); 
				}
				glbComm.state++;
			break;
			
			//CRC after payload_2 
			case STATE_CRC_1:
				dontRunCRC = 1;
			case STATE_PAYLOAD_1:
				glbComm.tempValue = (uint16_t)val;
				glbComm.state++;
			break;

			case STATE_PAYLOAD_2:
				glbComm.tempValue |= (uint16_t)(val << 8);

				//stuff temp value into temp channel if appropriate
				
				//if current channelMask is 0, increment until we get to a valid channel
				while( !(glbComm.channelMask & 0x01))
				{
					glbComm.channelMask >>= 0x01;	
					glbComm.UARTCallbackChannels >>= 0x01;
					//glbComm.payloadCh++;
				}

				if (((glbComm.channelMask & glbComm.UARTCallbackChannels) & 0x01)
				 	&& glbComm.payloadCh < 2)
				{
					glbComm.UART_CH[glbComm.payloadCh] = glbComm.tempValue;
					glbComm.payloadCh++;
				}

				//increment to next channel
				glbComm.channelMask >>= 0x01;
				glbComm.UARTCallbackChannels >>= 0x01;
				
				if (--glbComm.numChannels)
				{
					glbComm.state = STATE_PAYLOAD_1;
				}
				else
				{
					glbComm.state++;
				}
			break;

			case STATE_CRC_2:
				dontRunCRC = 1;
	            glbComm.tempValue <<= 8;
				glbComm.tempValue |= (uint16_t)(val);
				//compare glbComm.messageCRC vs calculated CRC
				if (glbComm.tempValue == glbComm.crc)
				{
					//set callback, make temp vars valid if channels 1-3 were set
					if (glbComm.payloadCh)
						glbComm.UARTCallback = 1;
				}
				glbComm.state = STATE_START_1;
			break;
		}

		if (!dontRunCRC)
			CalcCRC(val);
	}
}


void CalcCRC(uint8_t crc_val)
{
	glbComm.crc ^= ((uint16_t)(crc_val << 8));
    
    for( uint8_t b = 0; b < 8; b++ )
    {
        if( glbComm.crc & 0x8000 )
            glbComm.crc = (glbComm.crc << 1) ^ 0x1021;
        else
            glbComm.crc <<= 1;
    }
}


void ConvertUARTValues(void)
{
	const uint16_t validChModes[2] = {	0x07FF,
										//0b00011110000//,
										0x070F
									};
	for (uint8_t i = 0; i < glbComm.payloadCh; i++)
	{
		if ( validChModes[i] & (1 << glbMode.mode) )
		{
			if (i == 0)
			{
				//divide by 4 and offset to neutral
				glbInt.pulseTime_CH1 = (glbComm.UART_CH[i] >> 2) + 3808;
				glbInt.callbackFlag_CH1 = 1;
			}
			else
			{
				glbInt.pulseTime_CH2 = (glbComm.UART_CH[i] >> 2) + 3808;
				glbInt.callbackFlag_CH2 = 2;
			}
		}
	}
	//glbComm.payloadCh = 0;
}

