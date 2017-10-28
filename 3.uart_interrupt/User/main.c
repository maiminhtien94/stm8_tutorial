/*******************************************************************************
*PD5(TX)
*PD6(RX)
********************************************************************************/

#include "stm8s.h"
#include "stm8s_clock.h"
#include <stdio.h>

#define PUTCHAR_PROTOTYPE int putchar (int c)
uint8_t temp;
uint8_t enable =0;

void main(void)
{
    CLK_HSI_16MHz_Init();
    GPIO_Init(GPIOB,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_SLOW );
    UART1_DeInit();
    /* USART configured as follow:
    - BaudRate = 115200 baud  
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - Receive and transmit enabled
    - UART Clock disabled
    */
    UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D,UART1_STOPBITS_1, UART1_PARITY_NO,
    UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
    /* Enable the UART Receive interrupt: this interrupt is generated when the UART receive data register is not empty */
    UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);
    /* Enable UART */
    UART1_Cmd(ENABLE);
    /* Enable general interrupts */
    enableInterrupts();
    printf("Interrupt UART1");
    while (1)
    {
        if(enable)
        {
            UART1_SendData8(temp);
            enable = 0;
        }
    }
}

PUTCHAR_PROTOTYPE
{
    /* Write a character to the UART1 */
    UART1_SendData8(c);
    /* Loop until the end of transmission */
    while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);

    return (c);
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
