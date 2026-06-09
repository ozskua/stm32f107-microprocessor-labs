/*
 * USART.c
 *
 *  Created on: Jun 9, 2026
 *      Author: ozgur
 */


#include "USART.h"

extern UART_HandleTypeDef huart1;

void USART_SendChar(uint8_t ch){
	HAL_UART_Transmit(&huart1, &ch, 1, 0xffff);
}

void USART_SendString(uint8_t *mesaj, int len){
	HAL_UART_Transmit(&huart1, mesaj, len, 0xffff);
}
