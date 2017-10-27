#include "stm8s.h"
#include "stm8s_clock.h"
uint32_t parameter_clock = 0;
void main(void)
{
    /* khoi tao thach anh noi toc do cao HSI 16MHz*/
    CLK_HSI_16MHz_Init();
    
    /* khoi tao thach anh ngoai toc do cao HSE 16MHz*/
    //CLK_HSE_16MHz_Init();
    
    /* khoi tao thach anh noi toc do thap LSI 128kHz*/
    //CLK_LSI_128kHz_Init();
    
    while (1)
    {
      parameter_clock = CLK_GetClockFreq();             // use debug to watch the master clock frequency
    }
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
