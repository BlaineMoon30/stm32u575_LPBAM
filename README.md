# stm32u575_LPBAM

STM32U575 Nucleo board with LPBAM

Enter the STOP2 mode.

[ LPTIM1 ] <br />
500Hz with LSI (32kHz). <br /><br />
[ SPI3 ] <br />
Transmit Data, trigged Hardware Signal by LPTIM1 CH1 <br /> <br />

[ LPDMA1 CH 0 ] <br />
Linked-list mode <br /> <br />

[ LPGPIO SetPin ] <br /> <br />
[ LPGPIO ResetPin ] <br /> <br />

STOP2 -> LPTIM1 CH1 trigger -> SPI3 transmit data with LPDMA1 CH 0 -> LPGPIO Set Pin -> LPGPIO Reset Pin <br /><br />

[ Source Code ] <br /><br />

/* Modify STM32U575ITXQ_FLASH.ld / <br />
MEMORY <br />
{ <br />
  RAM(xrw): ORIGIN = 0x28000000,LENGTH = 16K <br />
  FLASH(rx): ORIGIN = 0x08000000,LENGTH = 2048K <br />
} <br /><br />

/ main.c USER CODE BEGIN Includes / <br />
#include "lpbam_txapp.h" <br /><br />

/ main.c USER CODE BEGIN PV / <br /><br />
uint8_t SPIBuff[] = {0x12}; <br />
uint8_t UARTBuff[] = {'!'}; <br />
DMA_HandleTypeDef *LPDMA_Handlers[2] = <br />
{ <br />
    &handle_LPDMA1_Channel0, <br />
    &handle_LPDMA1_Channel1 <br />
};<br /><br />

/ lpbam_txapp_txdata_build.c USER CODE BEGIN EV / <br />
extern uint8_t SPIBuff[]; <br />
extern uint8_t UARTBuff[];<br /><br />

/ main.c USER CODE BEGIN 2 / <br />
MX_TXApp_Init(); <br />
MX_TXApp_TxData_Init(); <br />
MX_TXApp_TxData_Build(); <br />
MX_TXApp_TxData_Link(LPDMA_Handlers[0]); <br />
MX_TXApp_TxData_Start(LPDMA_Handlers[0]); <br />
__HAL_RCC_PWR_CLK_ENABLE(); <br />
HAL_PWREx_EnterSTOP2Mode(PWR_STOPENTRY_WFI); <br /><br />


// lpbam_txapp_txdata_config.c USER CODE BEGIN TXApp_TxData_Start  <br />
 
if (HAL_LPTIM_PWM_Start(&hlptim1, LPTIM_CHANNEL_1) != HAL_OK) <br />
{ <br />
  Error_Handler(); <br />
} <br />
if (HAL_LPTIM_PWM_Start(&hlptim3, LPTIM_CHANNEL_1) != HAL_OK) <br />
{ <br />
  Error_Handler(); <br />
}<br /><br />


  
