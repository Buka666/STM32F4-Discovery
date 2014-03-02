/*
 * File: macros.c
 * Date: 01.03.2014
 * Denis Zheleznyakov aka ZiB @ http://ziblog.ru
 */

#include "main.h"

void delay_ms(uint16_t value)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;

	TIM14->CNT = 0;

	if (value > 1)
	{
		TIM14->PSC = (1000 * MCU_APB1_MHZ) - 1;
		TIM14->ARR = value - 1;
	}
	else
	{
		TIM14->PSC = (500 * MCU_APB1_MHZ) - 1;
		TIM14->ARR = 1;
	}
	TIM14->EGR = TIM_EGR_UG;
	TIM14->SR &= ~TIM_SR_UIF;
	TIM14->CR1 = TIM_CR1_ARPE | TIM_CR1_CEN | TIM_CR1_OPM;

	while (!(TIM14->SR & TIM_SR_UIF))
	{
	}

	RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;
}
