/*******************************************************************************
*Led Pin B5 tac dong muc thap
*Chip: STM8S103F3P6
*******************************************************************************/

#include "stm8s.h"
#include "stm8s_clock.h"

#define USE_RES

void Delay (uint16_t nCount);

void main(void)
{
  #ifdef USE_RES
    /* cau hinh PB5 la output
     * che do push-pull
     * tan so lam viec toi da 2MHz After reset, the microcontroller restarts by default with an internal 2 MHz clock (HSI/8)
     *Trang 15 datasheet STM8S   
    */
    
    GPIOB->DDR |= GPIO_PIN_5;//data direction registor thanh ghi dinh huong du lieu cua tung chan i/o  cu the, th nay la out put
    GPIOB->CR1 |= GPIO_PIN_5;//lua chon cau hinh lam viec cua chan io che do push pull do DDR=1
    /*CR2 o che do input cac bit duoc cau hinh ngat ngoai,output cac bit duoc lam viec toi da do bit CR2=0 nen 
    chay max 2Mhz con neu CR2=1 chay max 10Mhz reference 101 page */
    GPIOB->CR2 &= ~GPIO_PIN_5;//=0 chon o che do output push pull xem bang 17/page101 reference
  #else
    GPIO_Init(GPIOB, (GPIO_Pin_TypeDef)GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
  #endif                          
  while(1)
  {
    Delay(30000);
    #ifdef USE_RES
      GPIOB->ODR ^= GPIO_PIN_5;
    #else
      GPIO_WriteReverse(GPIOB, (GPIO_Pin_TypeDef)GPIO_PIN_5); 
    #endif
  }
  
}

void Delay(uint16_t nCount)
{
  while (nCount != 0)
  {
    nCount--;
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
