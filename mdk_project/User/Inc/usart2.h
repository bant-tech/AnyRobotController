/*----------------------------------------------------------------------------*/
//版权所有：    班特科技
//文件名：      usart2.h
//版本：    1.0
//作者:        paul        
//修订记录:    
//2026-08-08----单个电机版本
/*----------------------------------------------------------------------------*/
#ifndef __usart2_h__
#define __usart2_h__

//----------------------- Include files ------------------------//

#include "stm32h7xx_hal.h"

//--------------------------- Define ---------------------------//

#define UART_BUFFER_SIZE 200

//------------------------- Data struct ------------------------//
typedef struct{
	char receive_buffer[UART_BUFFER_SIZE];
	char receive_data;
	int counter;
	
	int receive_ok_flag;
	int baudrate;
	int error;
	int(* initialize)(unsigned long int);
	int(* send_string)(char *);
	int(* printf)(const char * ,...);
}USART2_T;
//----------------------- Extern function ----------------------//

extern void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle);
extern void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle);
extern UART_HandleTypeDef huart2;
extern USART2_T usart2;

//----------------------- Extern variable ----------------------//
#endif // __uart2_h__
