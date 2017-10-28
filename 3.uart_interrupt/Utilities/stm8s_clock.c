#include "stm8s_clock.h"

/* @Brief	: 	Initialize clock module, run in mode external crystal HSE 16MHz
 * @Para	:	None
 * @Return	:	None
 * @Note	:       None
 */
void CLK_HSE_16MHz_Init(void)
{
  CLK_DeInit();
  CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSE, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
}


/* @Brief	: 	Initialize clock module, run in mode internal crystal HSI 16MHz
 * @Para	:	None
 * @Return	:	None
 * @Note	:       None
 */
void CLK_HSI_16MHz_Init(void)
{
	CLK_DeInit();
	CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
	CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);
	CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
}

/* @Brief	: 	Initialize clock module, run in mode internal crystal HSI 128kHz
 * @Para	:	None
 * @Return	:	None
 * @Note	:       None
 */
void CLK_LSI_128kHz_Init(void)
{
	CLK_DeInit();
	CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
	CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_LSI, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/