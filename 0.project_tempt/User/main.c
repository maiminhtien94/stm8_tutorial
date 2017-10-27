#include "stm8s.h"
#include "stm8s_clock.h"
#include <stdio.h>

#define PUTCHAR_PROTOTYPE int putchar (int c)
#define GETCHAR_PROTOTYPE int getchar (void)

uint32_t parameter_clock = 0;

void Delay(uint16_t nCount);

void main(void)
{
    /* khoi tao thach anh noi toc do cao HSI 16MHz*/
    CLK_HSI_16MHz_Init();
    /* khoi tao thach anh ngoai toc do cao HSE 16MHz*/
    //CLK_HSE_16MHz_Init();
    /* khoi tao thach anh noi toc do thap LSI 128kHz*/
    //CLK_LSI_128kHz_Init();
    
    UART1_DeInit();
    UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
    UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);

    printf("uart run susscesful \n\r");
    while (1)
    {
        parameter_clock = CLK_GetClockFreq();             // use debug to watch the master clock frequency
        printf("\n\rHello. uart run ok. clock cpu=%ld \n\r", parameter_clock);
        Delay(0xFFFF);
    }
}

void Delay(uint16_t nCount)
{
    /* Decrement nCount value */
    while (nCount != 0)
    {
        nCount--;
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

GETCHAR_PROTOTYPE
{
#ifdef _COSMIC_
  char c = 0;
#else
  int c = 0;
#endif
  /* Loop until the Read data register flag is SET */
  while (UART1_GetFlagStatus(UART1_FLAG_RXNE) == RESET);
    c = UART1_ReceiveData8();
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
