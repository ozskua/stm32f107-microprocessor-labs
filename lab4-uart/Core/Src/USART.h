/*
 * USART.h
 *
 *  Created on: Jun 9, 2026
 *      Author: ozgur
 */

#ifndef SRC_USART_H_
#define SRC_USART_H_

#include "stm32f1xx_hal.h"

void USART_SendChar(uint8_t ch);
void USART_SendString(uint8_t *mesaj, int len);

#endif /* SRC_USART_H_ */

