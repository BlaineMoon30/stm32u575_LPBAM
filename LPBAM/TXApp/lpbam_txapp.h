/* USER CODE BEGIN Header */
/**
  **********************************************************************************************************************
  * @file    lpbam_txapp.h
  * @author  MCD Application Team
  * @brief   Header for LPBAM TXApp application
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
/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/
#ifndef LPBAM_TXAPP_H
#define LPBAM_TXAPP_H

/* Includes ----------------------------------------------------------------------------------------------------------*/
#include "main.h"
#include "stm32_lpbam.h"

/* Exported functions ------------------------------------------------------------------------------------------------*/
/* TXApp application initialization */
void MX_TXApp_Init(void);

/* TXApp application TxData scenario initialization */
void MX_TXApp_TxData_Init(void);

/* TXApp application TxData scenario de-initialization */
void MX_TXApp_TxData_DeInit(void);

/* TXApp application TxData scenario build */
void MX_TXApp_TxData_Build(void);

/* TXApp application TxData scenario link */
void MX_TXApp_TxData_Link(DMA_HandleTypeDef *hdma);

/* TXApp application TxData scenario unlink */
void MX_TXApp_TxData_UnLink(DMA_HandleTypeDef *hdma);

/* TXApp application TxData scenario start */
void MX_TXApp_TxData_Start(DMA_HandleTypeDef *hdma);

/* TXApp application TxData scenario stop */
void MX_TXApp_TxData_Stop(DMA_HandleTypeDef *hdma);

#endif /* LPBAM_TXAPP_H */
