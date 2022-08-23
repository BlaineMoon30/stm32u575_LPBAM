/* USER CODE BEGIN Header */
/**
  **********************************************************************************************************************
  * @file   lpbam_txapp_txdata_build.c
  * @author MCD Application Team
  * @brief  Provides LPBAM TXApp application TxData scenario build services
  **********************************************************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  **********************************************************************************************************************
  */
/* USER CODE END Header */
/* Includes ----------------------------------------------------------------------------------------------------------*/
#include "lpbam_txapp.h"

/* Private variables -------------------------------------------------------------------------------------------------*/
/* LPBAM variables declaration */
static LPBAM_SPI_TxDataDesc_t SPI_GPIO_Q_SPI_TX_Desc;
static LPBAM_GPIO_WritePinFullDesc_t SPI_GPIO_Q_PinSet_Desc;
static LPBAM_GPIO_WritePinFullDesc_t SPI_GPIO_Q_PinReset_Desc;
static LPBAM_UART_TxDataDesc_t UART_Q_UART_TX_Desc;

/* Exported variables ------------------------------------------------------------------------------------------------*/
/* LPBAM queues declaration */
DMA_QListTypeDef SPI_GPIO_Q;
DMA_QListTypeDef UART_Q;

/* External variables ------------------------------------------------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Private function prototypes ---------------------------------------------------------------------------------------*/
static void MX_SPI_GPIO_Q_Build(void);
static void MX_UART_Q_Build(void);

/* USER CODE BEGIN PFP */
extern uint8_t SPIBuff[];
extern uint8_t UARTBuff[];
/* USER CODE END PFP */

/* Exported functions ------------------------------------------------------------------------------------------------*/
/**
  * @brief TXApp application TxData scenario build
  * @param None
  * @retval None
  */
void MX_TXApp_TxData_Build(void)
{
  /* USER CODE BEGIN TXApp_TxData_Build 0 */

  /* USER CODE END TXApp_TxData_Build 0 */

  /* LPBAM build SPI_GPIO queue */
  MX_SPI_GPIO_Q_Build();
  /* LPBAM build UART queue */
  MX_UART_Q_Build();

  /* USER CODE BEGIN TXApp_TxData_Build 1 */

  /* USER CODE END TXApp_TxData_Build 1 */
}

/* Private functions -------------------------------------------------------------------------------------------------*/

/**
  * @brief  TXApp application TxData scenario SPI_GPIO queue build
  * @param  None
  * @retval None
  */
static void MX_SPI_GPIO_Q_Build(void)
{
  /* LPBAM build variable */
  LPBAM_DMAListInfo_t pDMAListInfo_SPI = {0};
  LPBAM_SPI_DataAdvConf_t pTxDataStruct_SPI = {0};
  LPBAM_COMMON_TrigAdvConf_t pTrigConfig_SPI = {0};
  LPBAM_DMAListInfo_t pDMAListInfo_LPGPIO = {0};
  LPBAM_GPIO_WritePinFullAdvConf_t pWritePinFull_LPGPIO = {0};
  LPBAM_COMMON_TrigAdvConf_t pTrigConfig_LPGPIO = {0};

  /**
    * SPI_GPIO queue SPI_TX build
    */
  pDMAListInfo_SPI.QueueType = LPBAM_LINEAR_ADDRESSING_Q;
  pDMAListInfo_SPI.pInstance = LPDMA1;
  pTxDataStruct_SPI.AutoModeConf.TriggerState = LPBAM_SPI_AUTO_MODE_ENABLE;
  pTxDataStruct_SPI.DataSize = LPBAM_SPI_DATASIZE_8BIT;
  pTxDataStruct_SPI.Size = 1;
  pTxDataStruct_SPI.pTxData = (uint8_t*)&SPIBuff[0];
  if (ADV_LPBAM_SPI_Tx_SetDataQ(SPI3, &pDMAListInfo_SPI, &pTxDataStruct_SPI, &SPI_GPIO_Q_SPI_TX_Desc, &SPI_GPIO_Q) != LPBAM_OK)
  {
    Error_Handler();
  }
  pTrigConfig_SPI.TriggerConfig.TriggerMode = LPBAM_DMA_TRIGM_BLOCK_TRANSFER;
  pTrigConfig_SPI.TriggerConfig.TriggerPolarity = LPBAM_DMA_TRIG_POLARITY_RISING;
  pTrigConfig_SPI.TriggerConfig.TriggerSelection = LPBAM_LPDMA1_TRIGGER_LPTIM1_CH1;
  if (ADV_LPBAM_Q_SetTriggerConfig(&pTrigConfig_SPI, LPBAM_SPI_TX_DATAQ_CONFIG_NODE, &SPI_GPIO_Q_SPI_TX_Desc) != LPBAM_OK)
  {
    Error_Handler();
  }

  /**
    * SPI_GPIO queue PinSet build
    */
  pDMAListInfo_LPGPIO.QueueType = LPBAM_LINEAR_ADDRESSING_Q;
  pDMAListInfo_LPGPIO.pInstance = LPDMA1;
  pWritePinFull_LPGPIO.Pin = LPBAM_GPIO_PIN_0;
  pWritePinFull_LPGPIO.PinState = LPBAM_GPIO_PIN_SET;
  if (ADV_LPBAM_GPIO_WritePin_SetFullQ(LPGPIO1, &pDMAListInfo_LPGPIO, &pWritePinFull_LPGPIO, &SPI_GPIO_Q_PinSet_Desc, &SPI_GPIO_Q) != LPBAM_OK)
  {
    Error_Handler();
  }
  pTrigConfig_LPGPIO.TriggerConfig.TriggerMode = LPBAM_DMA_TRIGM_SINGLE_BURST_TRANSFER;
  pTrigConfig_LPGPIO.TriggerConfig.TriggerPolarity = LPBAM_DMA_TRIG_POLARITY_RISING;
  pTrigConfig_LPGPIO.TriggerConfig.TriggerSelection = LPBAM_LPDMA1_TRIGGER_LPTIM1_CH1;
  if (ADV_LPBAM_Q_SetTriggerConfig(&pTrigConfig_LPGPIO, LPBAM_GPIO_WRITEPIN_FULLQ_DATA_NODE, &SPI_GPIO_Q_PinSet_Desc) != LPBAM_OK)
  {
    Error_Handler();
  }

  /**
    * SPI_GPIO queue PinReset build
    */
  pWritePinFull_LPGPIO.PinState = LPBAM_GPIO_PIN_RESET;
  if (ADV_LPBAM_GPIO_WritePin_SetFullQ(LPGPIO1, &pDMAListInfo_LPGPIO, &pWritePinFull_LPGPIO, &SPI_GPIO_Q_PinReset_Desc, &SPI_GPIO_Q) != LPBAM_OK)
  {
    Error_Handler();
  }
  if (ADV_LPBAM_Q_SetTriggerConfig(&pTrigConfig_LPGPIO, LPBAM_GPIO_WRITEPIN_FULLQ_DATA_NODE, &SPI_GPIO_Q_PinReset_Desc) != LPBAM_OK)
  {
    Error_Handler();
  }

  /**
    * Set circular mode
    */
  if (ADV_LPBAM_Q_SetCircularMode(&SPI_GPIO_Q_SPI_TX_Desc, LPBAM_SPI_TX_DATAQ_CONFIG_NODE, &SPI_GPIO_Q) != LPBAM_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  TXApp application TxData scenario UART queue build
  * @param  None
  * @retval None
  */
static void MX_UART_Q_Build(void)
{
  /* LPBAM build variable */
  LPBAM_DMAListInfo_t pDMAListInfo_LPUART = {0};
  LPBAM_UART_DataAdvConf_t pTxData_LPUART = {0};
  LPBAM_COMMON_TrigAdvConf_t pTrigConfig_LPUART = {0};

  /**
    * UART queue UART_TX build
    */
  pDMAListInfo_LPUART.QueueType = LPBAM_LINEAR_ADDRESSING_Q;
  pDMAListInfo_LPUART.pInstance = LPDMA1;
  pTxData_LPUART.pData = (uint8_t*)&UARTBuff[0];
  pTxData_LPUART.Size = 1;
  if (ADV_LPBAM_UART_Transmit_SetDataQ(LPUART1, &pDMAListInfo_LPUART, &pTxData_LPUART, &UART_Q_UART_TX_Desc, &UART_Q) != LPBAM_OK)
  {
    Error_Handler();
  }
  pTrigConfig_LPUART.TriggerConfig.TriggerMode = LPBAM_DMA_TRIGM_BLOCK_TRANSFER;
  pTrigConfig_LPUART.TriggerConfig.TriggerPolarity = LPBAM_DMA_TRIG_POLARITY_RISING;
  pTrigConfig_LPUART.TriggerConfig.TriggerSelection = LPBAM_LPDMA1_TRIGGER_LPTIM3_CH1;
  if (ADV_LPBAM_Q_SetTriggerConfig(&pTrigConfig_LPUART, LPBAM_UART_TX_DATAQ_CONFIG_NODE, &UART_Q_UART_TX_Desc) != LPBAM_OK)
  {
    Error_Handler();
  }

  /**
    * Set circular mode
    */
  if (ADV_LPBAM_Q_SetCircularMode(&UART_Q_UART_TX_Desc, LPBAM_UART_TX_DATAQ_DATA_NODE, &UART_Q) != LPBAM_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN TXApp_TxData_Build */

/* USER CODE END TXApp_TxData_Build */
