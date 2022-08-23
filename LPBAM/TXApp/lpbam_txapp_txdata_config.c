/* USER CODE BEGIN Header */
/**
  **********************************************************************************************************************
  * @file    lpbam_txapp_txdata_config.c
  * @author  MCD Application Team
  * @brief   Provide LPBAM TXApp application TxData configuration services.
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

/* Private typedef ---------------------------------------------------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define --------------------------------------------------------------------------------------------------*/
#define SPI_GPIO_Q_IDX (0U)
#define UART_Q_IDX (1U)
#define DMA_TIMEOUT_DURATION (0x1000U)

/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -----------------------------------------------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* External variables ------------------------------------------------------------------------------------------------*/
/* IP handler declaration */
extern DMA_HandleTypeDef handle_LPDMA1_Channel0;
extern DMA_HandleTypeDef handle_LPDMA1_Channel1;
extern LPTIM_HandleTypeDef hlptim1;
extern LPTIM_HandleTypeDef hlptim3;
extern UART_HandleTypeDef hlpuart1;
extern SPI_HandleTypeDef hspi3;

/* LPBAM queues declaration */
extern DMA_QListTypeDef SPI_GPIO_Q;
extern DMA_QListTypeDef UART_Q;

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Private function prototypes ---------------------------------------------------------------------------------------*/

/* LPBAM GPIO management APIs */
static void MX_GPIO_Init(void);

/* LPBAM LPDMA1 management APIs */
static void MX_LPDMA1_Init(void);

/* LPBAM LPTIM1 management APIs */
static void MX_LPTIM1_Init(void);
static void MX_LPTIM1_MspInit(LPTIM_HandleTypeDef *hlptim1);
static void MX_LPTIM1_MspDeInit(LPTIM_HandleTypeDef *hlptim1);
static void MX_LPTIM1_DeInit(void);

/* LPBAM LPTIM3 management APIs */
static void MX_LPTIM3_Init(void);
static void MX_LPTIM3_MspInit(LPTIM_HandleTypeDef *hlptim3);
static void MX_LPTIM3_MspDeInit(LPTIM_HandleTypeDef *hlptim3);
static void MX_LPTIM3_DeInit(void);

/* LPBAM LPUART1 management APIs */
static void MX_LPUART1_Init(void);
static void MX_LPUART1_MspInit(UART_HandleTypeDef *hlpuart1);
static void MX_LPUART1_MspDeInit(UART_HandleTypeDef *hlpuart1);
static void MX_LPUART1_DeInit(void);

/* LPBAM SPI3 management APIs */
static void MX_SPI3_Init(void);
static void MX_SPI3_MspInit(SPI_HandleTypeDef *hspi3);
static void MX_SPI3_MspDeInit(SPI_HandleTypeDef *hspi3);
static void MX_SPI3_DeInit(void);

/* LPBAM autonomous mode management APIs */
static void MX_AutonomousMode_Init(void);
static void MX_AutonomousMode_DeInit(void);

/* LPBAM queue linking/unlinking APIs */
static void MX_SPI_GPIO_Q_Link(DMA_HandleTypeDef *hdma);
static void MX_SPI_GPIO_Q_UnLink(DMA_HandleTypeDef *hdma);
static void MX_UART_Q_Link(DMA_HandleTypeDef *hdma);
static void MX_UART_Q_UnLink(DMA_HandleTypeDef *hdma);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Exported functions ----------------------------------------------------------------------------------------------*/
/**
  * @brief  TXApp application TxData scenario initialization
  * @param  None
  * @retval None
  */
void MX_TXApp_TxData_Init(void)
{
  /* LPBAM GPIO initialization */
  MX_GPIO_Init();

  /* LPBAM LPDMA1 initialization */
  MX_LPDMA1_Init();

  /* LPBAM LPTIM1 initialization */
  MX_LPTIM1_Init();

  /* LPBAM LPTIM3 initialization */
  MX_LPTIM3_Init();

  /* LPBAM LPUART1 initialization */
  MX_LPUART1_Init();

  /* LPBAM SPI3 initialization */
  MX_SPI3_Init();

  /* Autonomous Mode initialization */
  MX_AutonomousMode_Init();

  /* USER CODE BEGIN TXApp_TxData_Init */

  /* USER CODE END TXApp_TxData_Init */
}

/**
  * @brief TXApp application TxData scenario de-initialization
  * @param None
  * @retval None
  */
void MX_TXApp_TxData_DeInit(void)
{
  /* LPBAM LPTIM1 De-initialization */
  MX_LPTIM1_DeInit();

  /* LPBAM LPTIM3 De-initialization */
  MX_LPTIM3_DeInit();

  /* LPBAM LPUART1 De-initialization */
  MX_LPUART1_DeInit();

  /* LPBAM SPI3 De-initialization */
  MX_SPI3_DeInit();

  /* Autonomous mode de-initialization */
  MX_AutonomousMode_DeInit();

  /* USER CODE BEGIN TXApp_TxData_DeInit */

  /* USER CODE END TXApp_TxData_DeInit */
}

/**
  * @brief TXApp application TxData scenario link
  * @param None
  * @retval None
  */
void MX_TXApp_TxData_Link(DMA_HandleTypeDef *hdma)
{
  /* USER CODE BEGIN TXApp_TxData_Link 0 */

  /* USER CODE END TXApp_TxData_Link 0 */

  /* Link SPI_GPIO queue to DMA channel */
  MX_SPI_GPIO_Q_Link(&hdma[SPI_GPIO_Q_IDX]);

  /* USER CODE BEGIN LINK SPI_GPIO_Q_IDX */

  /* USER CODE END LINK SPI_GPIO_Q_IDX */

  /* Link UART queue to DMA channel */
  MX_UART_Q_Link(&hdma[UART_Q_IDX]);

  /* USER CODE BEGIN LINK UART_Q_IDX */

  /* USER CODE END LINK UART_Q_IDX */

  /* USER CODE BEGIN TXApp_TxData_Link 1 */

  /* USER CODE END TXApp_TxData_Link 1 */
}

/**
  * @brief TXApp application TxData scenario unlink
  * @param hdma :Pointer to a DMA_HandleTypeDef structure that contains the configuration information for the specified
  *              DMA Channel
  * @retval None
  */
void MX_TXApp_TxData_UnLink(DMA_HandleTypeDef *hdma)
{
  /* USER CODE BEGIN TXApp_TxData_UnLink 0 */

  /* USER CODE END TXApp_TxData_UnLink 0 */

  /* LPBAM unLink SPI_GPIO queue to DMA channel */
  MX_SPI_GPIO_Q_UnLink(&hdma[SPI_GPIO_Q_IDX]);

  /* USER CODE BEGIN UNLINK SPI_GPIO_Q_IDX */

  /* USER CODE END UNLINK SPI_GPIO_Q_IDX */

  /* LPBAM unLink UART queue to DMA channel */
  MX_UART_Q_UnLink(&hdma[UART_Q_IDX]);

  /* USER CODE BEGIN UNLINK UART_Q_IDX */

  /* USER CODE END UNLINK UART_Q_IDX */

  /* USER CODE BEGIN TXApp_TxData_UnLink 1 */

  /* USER CODE END TXApp_TxData_UnLink 1 */
}

/**
  * @brief TXApp application TxData scenario start
  * @retval None
  */
void MX_TXApp_TxData_Start(DMA_HandleTypeDef *hdma)
{
  /* LPBAM start DMA channel in linked-list mode */
  if (HAL_DMAEx_List_Start(&hdma[SPI_GPIO_Q_IDX]) != HAL_OK)
  {
    Error_Handler();
  }

  /* LPBAM start DMA channel in linked-list mode */
  if (HAL_DMAEx_List_Start(&hdma[UART_Q_IDX]) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN TXApp_TxData_Start */
  if (HAL_LPTIM_PWM_Start(&hlptim1, LPTIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_LPTIM_PWM_Start(&hlptim3, LPTIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE END TXApp_TxData_Start */
}

/**
  * @brief TXApp application TxData scenario stop
  * @retval None
  */
void MX_TXApp_TxData_Stop(DMA_HandleTypeDef *hdma)
{
  /* LPBAM stop DMA channel in linked-list mode */
  if ((hdma[SPI_GPIO_Q_IDX].State == HAL_DMA_STATE_BUSY) && (hdma[SPI_GPIO_Q_IDX].LinkedListQueue->FirstCircularNode != 0U))
  {
    if (HAL_DMA_Abort(&hdma[SPI_GPIO_Q_IDX]) != HAL_OK)
    {
      Error_Handler();
    }
  }

  /* Check if DMA channel interrupt is enabled */
  if ((hdma[SPI_GPIO_Q_IDX].State == HAL_DMA_STATE_BUSY) && (__HAL_DMA_GET_IT_SOURCE(&hdma[SPI_GPIO_Q_IDX], DMA_IT_TC) == 0U))
  {
    if (HAL_DMA_PollForTransfer(&hdma[SPI_GPIO_Q_IDX], HAL_DMA_FULL_TRANSFER, DMA_TIMEOUT_DURATION) != HAL_OK)
    {
      Error_Handler();
    }
  }
  /* LPBAM stop DMA channel in linked-list mode */
  if ((hdma[UART_Q_IDX].State == HAL_DMA_STATE_BUSY) && (hdma[UART_Q_IDX].LinkedListQueue->FirstCircularNode != 0U))
  {
    if (HAL_DMA_Abort(&hdma[UART_Q_IDX]) != HAL_OK)
    {
      Error_Handler();
    }
  }

  /* Check if DMA channel interrupt is enabled */
  if ((hdma[UART_Q_IDX].State == HAL_DMA_STATE_BUSY) && (__HAL_DMA_GET_IT_SOURCE(&hdma[UART_Q_IDX], DMA_IT_TC) == 0U))
  {
    if (HAL_DMA_PollForTransfer(&hdma[UART_Q_IDX], HAL_DMA_FULL_TRANSFER, DMA_TIMEOUT_DURATION) != HAL_OK)
    {
      Error_Handler();
    }
  }

  /* USER CODE BEGIN TXApp_TxData_Stop */

  /* USER CODE END TXApp_TxData_Stop */
}

/**
  * @brief TXApp application TxData autonomous mode init
  * @param None
  * @retval None
  */
static void MX_AutonomousMode_Init(void)
{
  /* Enable LPDMA1 Sleep Clock */
  __HAL_RCC_LPDMA1_CLK_SLEEP_ENABLE();
  /* Enable LPDMA1 Autonomous Mode */
  __HAL_RCC_LPDMA1_CLKAM_ENABLE();

  /* Enable SRAM4 Sleep Clock */
  __HAL_RCC_SRAM4_CLK_SLEEP_ENABLE();
  /* Enable SRAM4 Autonomous Mode */
  __HAL_RCC_SRAM4_CLKAM_ENABLE();

  /* Enable LPGPIO1 Sleep Clock */
  __HAL_RCC_LPGPIO1_CLK_SLEEP_ENABLE();
  /* Enable LPGPIO1 Autonomous Mode */
  __HAL_RCC_LPGPIO1_CLKAM_ENABLE();

  /* Enable LPTIM1 Sleep Clock */
  __HAL_RCC_LPTIM1_CLK_SLEEP_ENABLE();
  /* Enable LPTIM1 Autonomous Mode */
  __HAL_RCC_LPTIM1_CLKAM_ENABLE();

  /* Enable LPTIM3 Sleep Clock */
  __HAL_RCC_LPTIM3_CLK_SLEEP_ENABLE();
  /* Enable LPTIM3 Autonomous Mode */
  __HAL_RCC_LPTIM3_CLKAM_ENABLE();

  /* Enable LPUART1 Sleep Clock */
  __HAL_RCC_LPUART1_CLK_SLEEP_ENABLE();
  /* Enable LPUART1 Autonomous Mode */
  __HAL_RCC_LPUART1_CLKAM_ENABLE();

  /* Enable SPI3 Sleep Clock */
  __HAL_RCC_SPI3_CLK_SLEEP_ENABLE();
  /* Enable SPI3 Autonomous Mode */
  __HAL_RCC_SPI3_CLKAM_ENABLE();

  /* USER CODE BEGIN AutonomousMode_Init */

  /* USER CODE END AutonomousMode_Init */
}

/**
  * @brief  TXApp application TxData autonomous mode deinit
  * @param  None
  * @retval None
  */
static void MX_AutonomousMode_DeInit(void)
{
  /* Disable LPDMA1 Sleep Clock */
  __HAL_RCC_LPDMA1_CLK_SLEEP_DISABLE();
  /* Disable LPDMA1 Autonomous Mode */
  __HAL_RCC_LPDMA1_CLKAM_DISABLE();

  /* Disable SRAM4 Sleep Clock */
  __HAL_RCC_SRAM4_CLK_SLEEP_DISABLE();
  /* Disable SRAM4 Autonomous Mode */
  __HAL_RCC_SRAM4_CLKAM_DISABLE();

  /* Disable LPGPIO1 Sleep Clock */
  __HAL_RCC_LPGPIO1_CLK_SLEEP_DISABLE();
  /* Disable LPGPIO1 Autonomous Mode */
  __HAL_RCC_LPGPIO1_CLKAM_DISABLE();

  /* Disable LPTIM1 Sleep Clock */
  __HAL_RCC_LPTIM1_CLK_SLEEP_DISABLE();
  /* Disable LPTIM1 Autonomous Mode */
  __HAL_RCC_LPTIM1_CLKAM_DISABLE();

  /* Disable LPTIM3 Sleep Clock */
  __HAL_RCC_LPTIM3_CLK_SLEEP_DISABLE();
  /* Disable LPTIM3 Autonomous Mode */
  __HAL_RCC_LPTIM3_CLKAM_DISABLE();

  /* Disable LPUART1 Sleep Clock */
  __HAL_RCC_LPUART1_CLK_SLEEP_DISABLE();
  /* Disable LPUART1 Autonomous Mode */
  __HAL_RCC_LPUART1_CLKAM_DISABLE();

  /* Disable SPI3 Sleep Clock */
  __HAL_RCC_SPI3_CLK_SLEEP_DISABLE();
  /* Disable SPI3 Autonomous Mode */
  __HAL_RCC_SPI3_CLKAM_DISABLE();

  /* USER CODE BEGIN AutonomousMode_DeInit */

  /* USER CODE END AutonomousMode_DeInit */
}

/**
  * @brief LPDMA1 initialization.
  * @param None
  * @retval None
  */
static void MX_LPDMA1_Init(void)
{
  /* USER CODE BEGIN LPDMA1_Init 0 */

  /* USER CODE END LPDMA1_Init 0 */

  /* USER CODE BEGIN LPDMA1_Init 1 */

  /* USER CODE END LPDMA1_Init 1 */

  /* Set LPDMA1 instance */
  handle_LPDMA1_Channel0.Instance = LPDMA1_Channel0;
  handle_LPDMA1_Channel0.InitLinkedList.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_LPDMA1_Channel0.InitLinkedList.LinkStepMode = DMA_LSM_FULL_EXECUTION;
  handle_LPDMA1_Channel0.InitLinkedList.TransferEventMode = DMA_TCEM_LAST_LL_ITEM_TRANSFER;
  handle_LPDMA1_Channel0.InitLinkedList.LinkedListMode = DMA_LINKEDLIST_CIRCULAR;
  if (HAL_DMAEx_List_Init(&handle_LPDMA1_Channel0) != HAL_OK)
  {
    Error_Handler();
  }
  handle_LPDMA1_Channel1.Instance = LPDMA1_Channel1;
  handle_LPDMA1_Channel1.InitLinkedList.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_LPDMA1_Channel1.InitLinkedList.LinkStepMode = DMA_LSM_FULL_EXECUTION;
  handle_LPDMA1_Channel1.InitLinkedList.TransferEventMode = DMA_TCEM_LAST_LL_ITEM_TRANSFER;
  handle_LPDMA1_Channel1.InitLinkedList.LinkedListMode = DMA_LINKEDLIST_CIRCULAR;
  if (HAL_DMAEx_List_Init(&handle_LPDMA1_Channel1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LPDMA1_Init 2 */

  /* USER CODE END LPDMA1_Init 2 */

}

/**
  * @brief LPTIM1 initialization.
  * @param None
  * @retval None
  */
static void MX_LPTIM1_Init(void)
{
  /* USER CODE BEGIN LPTIM1_Init 0 */

  /* USER CODE END LPTIM1_Init 0 */

  LPTIM_OC_ConfigTypeDef sConfig1 = {0};

  /* USER CODE BEGIN LPTIM1_Init 1 */

  /* USER CODE END LPTIM1_Init 1 */

  /* Set LPTIM1 instance */
  hlptim1.Instance = LPTIM1;

  /* Register LPTIM msp callbacks */
  if (HAL_LPTIM_RegisterCallback(&hlptim1, HAL_LPTIM_MSPINIT_CB_ID, MX_LPTIM1_MspInit) != HAL_OK)
  {
    Error_Handler();
  }
  /* Register LPTIM msp callbacks */
  if (HAL_LPTIM_RegisterCallback(&hlptim1, HAL_LPTIM_MSPDEINIT_CB_ID, MX_LPTIM1_MspDeInit) != HAL_OK)
  {
    Error_Handler();
  }
  hlptim1.Instance = LPTIM1;
  hlptim1.Init.Clock.Source = LPTIM_CLOCKSOURCE_APBCLOCK_LPOSC;
  hlptim1.Init.Clock.Prescaler = LPTIM_PRESCALER_DIV1;
  hlptim1.Init.Trigger.Source = LPTIM_TRIGSOURCE_SOFTWARE;
  hlptim1.Init.Period = 63;
  hlptim1.Init.UpdateMode = LPTIM_UPDATE_IMMEDIATE;
  hlptim1.Init.CounterSource = LPTIM_COUNTERSOURCE_INTERNAL;
  hlptim1.Init.Input1Source = LPTIM_INPUT1SOURCE_GPIO;
  hlptim1.Init.Input2Source = LPTIM_INPUT2SOURCE_GPIO;
  hlptim1.Init.RepetitionCounter = 0;
  if (HAL_LPTIM_Init(&hlptim1) != HAL_OK)
  {
    Error_Handler();
  }
  sConfig1.Pulse = 31;
  sConfig1.OCPolarity = LPTIM_OCPOLARITY_HIGH;
  if (HAL_LPTIM_OC_ConfigChannel(&hlptim1, &sConfig1, LPTIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LPTIM1_Init 2 */

  /* USER CODE END LPTIM1_Init 2 */

}

/**
  * @brief LPTIM1 de-initialization.
  * @param None
  * @retval None
  */
static void MX_LPTIM1_DeInit(void)
{
  /* USER CODE BEGIN LPTIM1_DeInit 0 */

  /* USER CODE END LPTIM1_DeInit 0 */

  /* Set LPTIM1 instance */
  hlptim1.Instance = LPTIM1;

  /* UnRegister LPTIM msp callbacks */
  if (HAL_LPTIM_UnRegisterCallback(&hlptim1, HAL_LPTIM_MSPINIT_CB_ID) != HAL_OK)
  {
    Error_Handler();
  }
  /* UnRegister LPTIM msp callbacks */
  if (HAL_LPTIM_UnRegisterCallback(&hlptim1, HAL_LPTIM_MSPDEINIT_CB_ID) != HAL_OK)
  {
    Error_Handler();
  }
  /* Init LPTIM1 peripheral */
  if (HAL_LPTIM_DeInit(&hlptim1) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN LPTIM1_DeInit 1 */

  /* USER CODE END LPTIM1_DeInit 1 */
}

/**
  * @brief LPTIM1 MSP initialization.
  * @retval None
  */
static void MX_LPTIM1_MspInit(LPTIM_HandleTypeDef* lptimHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(lptimHandle->Instance==LPTIM1)
  {
  /* USER CODE BEGIN LPTIM1_MspInit 0 */

  /* USER CODE END LPTIM1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_LPTIM1;
    PeriphClkInit.Lptim1ClockSelection = RCC_LPTIM1CLKSOURCE_LSI;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* LPTIM1 clock enable */
    __HAL_RCC_LPTIM1_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**LPTIM1 GPIO Configuration
    PB2     ------> LPTIM1_CH1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF1_LPTIM1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN LPTIM1_MspInit 1 */

  /* USER CODE END LPTIM1_MspInit 1 */
  }
}

/**
  * @brief LPTIM1 MSP de-initialization.
  * @retval None
  */
static void MX_LPTIM1_MspDeInit(LPTIM_HandleTypeDef* lptimHandle)
{

  if (lptimHandle->Instance==LPTIM1)
  {
  /* USER CODE BEGIN LPTIM1_MspDeInit 0 */

  /* USER CODE END LPTIM1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_LPTIM1_CLK_DISABLE();

    /**LPTIM1 GPIO Configuration
    PB2     ------> LPTIM1_CH1
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_2);

  /* USER CODE BEGIN LPTIM1_MspDeInit 1 */

  /* USER CODE END LPTIM1_MspDeInit 1 */
  }
}

/**
  * @brief LPTIM3 initialization.
  * @param None
  * @retval None
  */
static void MX_LPTIM3_Init(void)
{
  /* USER CODE BEGIN LPTIM3_Init 0 */

  /* USER CODE END LPTIM3_Init 0 */

  LPTIM_OC_ConfigTypeDef sConfig1 = {0};

  /* USER CODE BEGIN LPTIM3_Init 1 */

  /* USER CODE END LPTIM3_Init 1 */

  /* Set LPTIM3 instance */
  hlptim3.Instance = LPTIM3;

  /* Register LPTIM msp callbacks */
  if (HAL_LPTIM_RegisterCallback(&hlptim3, HAL_LPTIM_MSPINIT_CB_ID, MX_LPTIM3_MspInit) != HAL_OK)
  {
    Error_Handler();
  }
  /* Register LPTIM msp callbacks */
  if (HAL_LPTIM_RegisterCallback(&hlptim3, HAL_LPTIM_MSPDEINIT_CB_ID, MX_LPTIM3_MspDeInit) != HAL_OK)
  {
    Error_Handler();
  }
  hlptim3.Instance = LPTIM3;
  hlptim3.Init.Clock.Source = LPTIM_CLOCKSOURCE_APBCLOCK_LPOSC;
  hlptim3.Init.Clock.Prescaler = LPTIM_PRESCALER_DIV1;
  hlptim3.Init.Trigger.Source = LPTIM_TRIGSOURCE_SOFTWARE;
  hlptim3.Init.Period = 79;
  hlptim3.Init.UpdateMode = LPTIM_UPDATE_IMMEDIATE;
  hlptim3.Init.CounterSource = LPTIM_COUNTERSOURCE_INTERNAL;
  hlptim3.Init.Input1Source = LPTIM_INPUT1SOURCE_GPIO;
  hlptim3.Init.Input2Source = LPTIM_INPUT2SOURCE_GPIO;
  hlptim3.Init.RepetitionCounter = 0;
  if (HAL_LPTIM_Init(&hlptim3) != HAL_OK)
  {
    Error_Handler();
  }
  sConfig1.Pulse = 39;
  sConfig1.OCPolarity = LPTIM_OCPOLARITY_HIGH;
  if (HAL_LPTIM_OC_ConfigChannel(&hlptim3, &sConfig1, LPTIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LPTIM3_Init 2 */

  /* USER CODE END LPTIM3_Init 2 */

}

/**
  * @brief LPTIM3 de-initialization.
  * @param None
  * @retval None
  */
static void MX_LPTIM3_DeInit(void)
{
  /* USER CODE BEGIN LPTIM3_DeInit 0 */

  /* USER CODE END LPTIM3_DeInit 0 */

  /* Set LPTIM3 instance */
  hlptim3.Instance = LPTIM3;

  /* UnRegister LPTIM msp callbacks */
  if (HAL_LPTIM_UnRegisterCallback(&hlptim3, HAL_LPTIM_MSPINIT_CB_ID) != HAL_OK)
  {
    Error_Handler();
  }
  /* UnRegister LPTIM msp callbacks */
  if (HAL_LPTIM_UnRegisterCallback(&hlptim3, HAL_LPTIM_MSPDEINIT_CB_ID) != HAL_OK)
  {
    Error_Handler();
  }
  /* Init LPTIM3 peripheral */
  if (HAL_LPTIM_DeInit(&hlptim3) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN LPTIM3_DeInit 1 */

  /* USER CODE END LPTIM3_DeInit 1 */
}

/**
  * @brief LPTIM3 MSP initialization.
  * @retval None
  */
static void MX_LPTIM3_MspInit(LPTIM_HandleTypeDef* lptimHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(lptimHandle->Instance==LPTIM3)
  {
  /* USER CODE BEGIN LPTIM3_MspInit 0 */

  /* USER CODE END LPTIM3_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_LPTIM34;
    PeriphClkInit.Lptim34ClockSelection = RCC_LPTIM34CLKSOURCE_LSI;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* LPTIM3 clock enable */
    __HAL_RCC_LPTIM3_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**LPTIM3 GPIO Configuration
    PB10     ------> LPTIM3_CH1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_LPTIM3;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN LPTIM3_MspInit 1 */

  /* USER CODE END LPTIM3_MspInit 1 */
  }
}

/**
  * @brief LPTIM3 MSP de-initialization.
  * @retval None
  */
static void MX_LPTIM3_MspDeInit(LPTIM_HandleTypeDef* lptimHandle)
{

  if (lptimHandle->Instance==LPTIM3)
  {
  /* USER CODE BEGIN LPTIM3_MspDeInit 0 */

  /* USER CODE END LPTIM3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_LPTIM3_CLK_DISABLE();

    /**LPTIM3 GPIO Configuration
    PB10     ------> LPTIM3_CH1
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10);

  /* USER CODE BEGIN LPTIM3_MspDeInit 1 */

  /* USER CODE END LPTIM3_MspDeInit 1 */
  }
}

/**
  * @brief LPUART1 initialization.
  * @param None
  * @retval None
  */

static void MX_LPUART1_Init(void)
{
  /* USER CODE BEGIN LPUART1_Init 0 */

  /* USER CODE END LPUART1_Init 0 */

  UART_AutonomousModeConfTypeDef sConfigLpuart1 = {0};

  /* USER CODE BEGIN LPUART1_Init 1 */

  /* USER CODE END LPUART1_Init 1 */

  /* Set LPUART1 instance */
  hlpuart1.Instance = LPUART1;

  /* Register UART msp callbacks */
  if (HAL_UART_RegisterCallback(&hlpuart1, HAL_UART_MSPINIT_CB_ID, MX_LPUART1_MspInit) != HAL_OK)
  {
    Error_Handler();
  }
  /* Register UART msp callbacks */
  if (HAL_UART_RegisterCallback(&hlpuart1, HAL_UART_MSPDEINIT_CB_ID, MX_LPUART1_MspDeInit) != HAL_OK)
  {
    Error_Handler();
  }
  hlpuart1.Instance = LPUART1;
  hlpuart1.Init.BaudRate = 9600;
  hlpuart1.Init.WordLength = UART_WORDLENGTH_8B;
  hlpuart1.Init.StopBits = UART_STOPBITS_1;
  hlpuart1.Init.Parity = UART_PARITY_NONE;
  hlpuart1.Init.Mode = UART_MODE_TX;
  hlpuart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  hlpuart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  hlpuart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  hlpuart1.FifoMode = UART_FIFOMODE_DISABLE;
  if (HAL_UART_Init(&hlpuart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&hlpuart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&hlpuart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&hlpuart1) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigLpuart1.AutonomousModeState = UART_AUTONOMOUS_MODE_ENABLE;
  sConfigLpuart1.TriggerSelection = LPUART_LPTIM3_OUT_TRG;
  sConfigLpuart1.TriggerPolarity = UART_TRIG_POLARITY_RISING;
  sConfigLpuart1.DataSize = 1;
  sConfigLpuart1.IdleFrame = UART_IDLE_FRAME_DISABLE;
  if (HAL_UARTEx_SetConfigAutonomousMode(&hlpuart1, &sConfigLpuart1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configuration in LPBAM context
  */
  if (ADV_LPBAM_UART_EnableDMARequests(LPUART1) != LPBAM_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_EnableStopMode(&hlpuart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LPUART1_Init 2 */

  /* USER CODE END LPUART1_Init 2 */

}

/**
  * @brief LPUART1 de-initialization.
  * @param None
  * @retval None
  */
static void MX_LPUART1_DeInit(void)
{
  /* USER CODE BEGIN LPUART1_DeInit 0 */

  /* USER CODE END LPUART1_DeInit 0 */

  /* Set LPUART1 instance */
  hlpuart1.Instance = LPUART1;

  /* UnRegister UART msp callbacks */
  if (HAL_UART_UnRegisterCallback(&hlpuart1, HAL_UART_MSPINIT_CB_ID) != HAL_OK)
  {
    Error_Handler();
  }
  /* UnRegister UART msp callbacks */
  if (HAL_UART_UnRegisterCallback(&hlpuart1, HAL_UART_MSPDEINIT_CB_ID) != HAL_OK)
  {
    Error_Handler();
  }
  /* Init LPUART1 peripheral */
  if (HAL_UART_DeInit(&hlpuart1) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN LPUART1_DeInit 1 */

  /* USER CODE END LPUART1_DeInit 1 */
}

/**
  * @brief LPUART1 MSP initialization.
  * @retval None
  */
static void MX_LPUART1_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(uartHandle->Instance==LPUART1)
  {
  /* USER CODE BEGIN LPUART1_MspInit 0 */

  /* USER CODE END LPUART1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_LPUART1;
    PeriphClkInit.Lpuart1ClockSelection = RCC_LPUART1CLKSOURCE_MSIK;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* LPUART1 clock enable */
    __HAL_RCC_LPUART1_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**LPUART1 GPIO Configuration
    PC0     ------> LPUART1_RX
    PB11     ------> LPUART1_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_LPUART1;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_LPUART1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* LPUART1 interrupt Init */
    HAL_NVIC_SetPriority(LPUART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(LPUART1_IRQn);
  /* USER CODE BEGIN LPUART1_MspInit 1 */

  /* USER CODE END LPUART1_MspInit 1 */
  }
}

/**
  * @brief LPUART1 MSP de-initialization.
  * @retval None
  */
static void MX_LPUART1_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if (uartHandle->Instance==LPUART1)
  {
  /* USER CODE BEGIN LPUART1_MspDeInit 0 */

  /* USER CODE END LPUART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_LPUART1_CLK_DISABLE();

    /**LPUART1 GPIO Configuration
    PC0     ------> LPUART1_RX
    PB11     ------> LPUART1_TX
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_0);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_11);

    /* LPUART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(LPUART1_IRQn);
  /* USER CODE BEGIN LPUART1_MspDeInit 1 */

  /* USER CODE END LPUART1_MspDeInit 1 */
  }
}

/**
  * @brief SPI3 initialization.
  * @param None
  * @retval None
  */
static void MX_SPI3_Init(void)
{
  /* USER CODE BEGIN SPI3_Init 0 */

  /* USER CODE END SPI3_Init 0 */

  SPI_AutonomousModeConfTypeDef HAL_SPI_AutonomousMode_Cfg_Struct = {0};

  /* USER CODE BEGIN SPI3_Init 1 */

  /* USER CODE END SPI3_Init 1 */

  /* Set SPI3 instance */
  hspi3.Instance = SPI3;

  /* Register SPI msp callbacks */
  if (HAL_SPI_RegisterCallback(&hspi3, HAL_SPI_MSPINIT_CB_ID, MX_SPI3_MspInit) != HAL_OK)
  {
    Error_Handler();
  }
  /* Register SPI msp callbacks */
  if (HAL_SPI_RegisterCallback(&hspi3, HAL_SPI_MSPDEINIT_CB_ID, MX_SPI3_MspDeInit) != HAL_OK)
  {
    Error_Handler();
  }
  hspi3.Instance = SPI3;
  hspi3.Init.Mode = SPI_MODE_MASTER;
  hspi3.Init.Direction = SPI_DIRECTION_2LINES_TXONLY;
  hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi3.Init.NSS = SPI_NSS_SOFT;
  hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
  hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi3.Init.CRCPolynomial = 0x7;
  hspi3.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  hspi3.Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
  hspi3.Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
  hspi3.Init.MasterSSIdleness = SPI_MASTER_SS_IDLENESS_00CYCLE;
  hspi3.Init.MasterInterDataIdleness = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
  hspi3.Init.MasterReceiverAutoSusp = SPI_MASTER_RX_AUTOSUSP_DISABLE;
  hspi3.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_DISABLE;
  hspi3.Init.IOSwap = SPI_IO_SWAP_DISABLE;
  hspi3.Init.ReadyMasterManagement = SPI_RDY_MASTER_MANAGEMENT_INTERNALLY;
  hspi3.Init.ReadyPolarity = SPI_RDY_POLARITY_HIGH;
  if (HAL_SPI_Init(&hspi3) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_SPI_AutonomousMode_Cfg_Struct.TriggerState = SPI_AUTO_MODE_ENABLE;
  HAL_SPI_AutonomousMode_Cfg_Struct.TriggerSelection = SPI_GRP2_LPTIM1_CH1_TRG;
  HAL_SPI_AutonomousMode_Cfg_Struct.TriggerPolarity = SPI_TRIG_POLARITY_RISING;
  if (HAL_SPIEx_SetConfigAutonomousMode(&hspi3, &HAL_SPI_AutonomousMode_Cfg_Struct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configuration in LPBAM context
  */
  if (ADV_LPBAM_SPI_EnableDMARequests(SPI3) != LPBAM_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI3_Init 2 */

  /* USER CODE END SPI3_Init 2 */

}

/**
  * @brief SPI3 de-initialization.
  * @param None
  * @retval None
  */
static void MX_SPI3_DeInit(void)
{
  /* USER CODE BEGIN SPI3_DeInit 0 */

  /* USER CODE END SPI3_DeInit 0 */

  /* Set SPI3 instance */
  hspi3.Instance = SPI3;

  /* UnRegister SPI msp callbacks */
  if (HAL_SPI_UnRegisterCallback(&hspi3, HAL_SPI_MSPINIT_CB_ID) != HAL_OK)
  {
    Error_Handler();
  }
  /* UnRegister SPI msp callbacks */
  if (HAL_SPI_UnRegisterCallback(&hspi3, HAL_SPI_MSPDEINIT_CB_ID) != HAL_OK)
  {
    Error_Handler();
  }
  /* Init SPI3 peripheral */
  if (HAL_SPI_DeInit(&hspi3) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN SPI3_DeInit 1 */

  /* USER CODE END SPI3_DeInit 1 */
}

/**
  * @brief SPI3 MSP initialization.
  * @retval None
  */
static void MX_SPI3_MspInit(SPI_HandleTypeDef* spiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(spiHandle->Instance==SPI3)
  {
  /* USER CODE BEGIN SPI3_MspInit 0 */

  /* USER CODE END SPI3_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_SPI3;
    PeriphClkInit.Spi3ClockSelection = RCC_SPI3CLKSOURCE_MSIK;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* SPI3 clock enable */
    __HAL_RCC_SPI3_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**SPI3 GPIO Configuration
    PC10     ------> SPI3_SCK
    PC12     ------> SPI3_MOSI
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* USER CODE BEGIN SPI3_MspInit 1 */

  /* USER CODE END SPI3_MspInit 1 */
  }
}

/**
  * @brief SPI3 MSP de-initialization.
  * @retval None
  */
static void MX_SPI3_MspDeInit(SPI_HandleTypeDef* spiHandle)
{

  if (spiHandle->Instance==SPI3)
  {
  /* USER CODE BEGIN SPI3_MspDeInit 0 */

  /* USER CODE END SPI3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI3_CLK_DISABLE();

    /**SPI3 GPIO Configuration
    PC10     ------> SPI3_SCK
    PC12     ------> SPI3_MOSI
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_10|GPIO_PIN_12);

  /* USER CODE BEGIN SPI3_MspDeInit 1 */

  /* USER CODE END SPI3_MspDeInit 1 */
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_LPGPIO1_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure LPGPIO pin : Pin0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LPGPIO1, &GPIO_InitStruct);

}

/**
  * @brief  SPI_GPIO queue link
  * @retval None
  */
static void MX_SPI_GPIO_Q_Link(DMA_HandleTypeDef *hdma)
{
  /* Enable LPDMA1 clock */
  __HAL_RCC_LPDMA1_CLK_ENABLE();

  hdma->InitLinkedList.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  hdma->InitLinkedList.LinkStepMode = DMA_LSM_FULL_EXECUTION;
  hdma->InitLinkedList.TransferEventMode = DMA_TCEM_LAST_LL_ITEM_TRANSFER;
  hdma->InitLinkedList.LinkedListMode = DMA_LINKEDLIST_CIRCULAR;
  if (HAL_DMAEx_List_Init(hdma) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DMAEx_List_LinkQ(hdma, &SPI_GPIO_Q) != HAL_OK)
  {
    Error_Handler();
  }

  /* Register DMA channel error callbacks */
}

/**
  * @brief  SPI_GPIO queue unlink
  * @retval None
  */
static void MX_SPI_GPIO_Q_UnLink(DMA_HandleTypeDef *hdma)
{
  /* UnLink SPI_GPIO queue to DMA channel */
  if (HAL_DMAEx_List_UnLinkQ(hdma) != HAL_OK)
  {
    Error_Handler();
  }

  /* DMA linked list de-init */
  if (HAL_DMAEx_List_DeInit(hdma) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  UART queue link
  * @retval None
  */
static void MX_UART_Q_Link(DMA_HandleTypeDef *hdma)
{
  /* Enable LPDMA1 clock */
  __HAL_RCC_LPDMA1_CLK_ENABLE();

  hdma->InitLinkedList.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  hdma->InitLinkedList.LinkStepMode = DMA_LSM_FULL_EXECUTION;
  hdma->InitLinkedList.TransferEventMode = DMA_TCEM_LAST_LL_ITEM_TRANSFER;
  hdma->InitLinkedList.LinkedListMode = DMA_LINKEDLIST_CIRCULAR;
  if (HAL_DMAEx_List_Init(hdma) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DMAEx_List_LinkQ(hdma, &UART_Q) != HAL_OK)
  {
    Error_Handler();
  }

  /* Register DMA channel error callbacks */
}

/**
  * @brief  UART queue unlink
  * @retval None
  */
static void MX_UART_Q_UnLink(DMA_HandleTypeDef *hdma)
{
  /* UnLink UART queue to DMA channel */
  if (HAL_DMAEx_List_UnLinkQ(hdma) != HAL_OK)
  {
    Error_Handler();
  }

  /* DMA linked list de-init */
  if (HAL_DMAEx_List_DeInit(hdma) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN TXApp_TxData_Config */

/* USER CODE END TXApp_TxData_Config */

