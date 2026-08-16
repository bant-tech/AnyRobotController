
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
     PH0-OSC_IN (PH0)   ------> RCC_OSC_IN
     PH1-OSC_OUT (PH1)   ------> RCC_OSC_OUT
*/
void MX_GPIO_Init(void)
{

 	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitTypeDef  GPIO_InitStructure;

	////////////////      LED	   ////////////////
	/*����LED��ص�GPIO����ʱ��*/
	LED1_GPIO_CLK_ENABLE();
	LED2_GPIO_CLK_ENABLE();
	LED3_GPIO_CLK_ENABLE();
	LED4_GPIO_CLK_ENABLE();
	LED5_GPIO_CLK_ENABLE();
	LED6_GPIO_CLK_ENABLE();
	LED7_GPIO_CLK_ENABLE();
	LED8_GPIO_CLK_ENABLE();
	
	ETH_RST_GPIO_CLK_ENABLE();

	/*ѡ��Ҫ���Ƶ�GPIO����*/															   
	GPIO_InitStruct.Pin = LED1_PIN;	

	/*�������ŵ��������Ϊ�������*/
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  

	/*��������Ϊ����ģʽ*/
	GPIO_InitStruct.Pull  = GPIO_PULLUP;

	/*������������Ϊ���� */   
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH; 

	/*���ÿ⺯����ʹ���������õ�GPIO_InitStructure��ʼ��GPIO*/
	HAL_GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);	

	/*ѡ��Ҫ���Ƶ�GPIO����*/															   
	GPIO_InitStruct.Pin = LED2_PIN;	
	HAL_GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);	

	/*ѡ��Ҫ���Ƶ�GPIO����*/															   
	GPIO_InitStruct.Pin = LED3_PIN;	
	HAL_GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStruct);	
	
		/*ѡ��Ҫ���Ƶ�GPIO����*/															   
	GPIO_InitStruct.Pin = LED4_PIN;	
	HAL_GPIO_Init(LED4_GPIO_PORT, &GPIO_InitStruct);	
	
		/*ѡ��Ҫ���Ƶ�GPIO����*/															   
	GPIO_InitStruct.Pin = LED5_PIN;	
	HAL_GPIO_Init(LED5_GPIO_PORT, &GPIO_InitStruct);	
	
		/*ѡ��Ҫ���Ƶ�GPIO����*/															   
	GPIO_InitStruct.Pin = LED6_PIN;	
	HAL_GPIO_Init(LED6_GPIO_PORT, &GPIO_InitStruct);	
	
		/*ѡ��Ҫ���Ƶ�GPIO����*/															   
	GPIO_InitStruct.Pin = LED7_PIN;	
	HAL_GPIO_Init(LED7_GPIO_PORT, &GPIO_InitStruct);	
	
		/*ѡ��Ҫ���Ƶ�GPIO����*/															   
	GPIO_InitStruct.Pin = LED8_PIN;	
	HAL_GPIO_Init(LED8_GPIO_PORT, &GPIO_InitStruct);	
	
		/*ѡ��Ҫ���Ƶ�GPIO����*/															   
	GPIO_InitStruct.Pin = ETH_RST;	
	HAL_GPIO_Init(ETH_RST_GPIO_PORT, &GPIO_InitStruct);	
	
//	__HAL_RCC_GPIOC_CLK_ENABLE();
//	GPIO_InitStruct.Pin = GPIO_PIN_0;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_PULLUP;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	
	LED_ALLOFF;
//	ETH_RST_OFF;
	
		////////////////      KEY	   ////////////////
	/*��������GPIO�ڵ�ʱ��*/
	KEY1_GPIO_CLK_ENABLE();
	KEY2_GPIO_CLK_ENABLE();
	KEY3_GPIO_CLK_ENABLE();
	KEY4_GPIO_CLK_ENABLE();
	KEY5_GPIO_CLK_ENABLE();
	KEY6_GPIO_CLK_ENABLE();
	KEY7_GPIO_CLK_ENABLE();
	KEY8_GPIO_CLK_ENABLE();
	/*ѡ�񰴼�������*/	
	GPIO_InitStructure.Pin = KEY1_PIN; 
	/*��������Ϊ����ģʽ*/
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT; 
	/*�������Ų�����Ҳ������*/
	GPIO_InitStructure.Pull = GPIO_PULLDOWN;
	/*ʹ������Ľṹ���ʼ������*/
	HAL_GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	/*ѡ�񰴼�������*/
	GPIO_InitStructure.Pin = KEY2_PIN; 
	/*ʹ������Ľṹ���ʼ������*/
	HAL_GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);  
	/*ѡ�񰴼�������*/
	GPIO_InitStructure.Pin = KEY3_PIN; 
	/*ʹ������Ľṹ���ʼ������*/
	HAL_GPIO_Init(KEY3_GPIO_PORT, &GPIO_InitStructure);  
	/*ѡ�񰴼�������*/
	GPIO_InitStructure.Pin = KEY4_PIN; 
	/*ʹ������Ľṹ���ʼ������*/
	HAL_GPIO_Init(KEY4_GPIO_PORT, &GPIO_InitStructure);  
	/*ѡ�񰴼�������*/
	GPIO_InitStructure.Pin = KEY5_PIN; 
	/*ʹ������Ľṹ���ʼ������*/
	HAL_GPIO_Init(KEY5_GPIO_PORT, &GPIO_InitStructure); 
	
	/*ѡ�񰴼�������*/
	GPIO_InitStructure.Pin = KEY6_PIN; 
	/*ʹ������Ľṹ���ʼ������*/
	HAL_GPIO_Init(KEY6_GPIO_PORT, &GPIO_InitStructure); 
	
	/*ѡ�񰴼�������*/
	GPIO_InitStructure.Pin = KEY7_PIN; 
	/*ʹ������Ľṹ���ʼ������*/
	HAL_GPIO_Init(KEY7_GPIO_PORT, &GPIO_InitStructure); 
	
	/*ѡ�񰴼�������*/
	GPIO_InitStructure.Pin = KEY8_PIN; 
	/*ʹ������Ľṹ���ʼ������*/
	HAL_GPIO_Init(KEY8_GPIO_PORT, &GPIO_InitStructure); 
	
	ETH_RST_ON;
	HAL_Delay(10);
	ETH_RST_OFF;
	HAL_Delay(10);
	ETH_RST_ON;

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
