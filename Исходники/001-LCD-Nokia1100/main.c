/*
 * File: main.c
 * Date: 31.08.2012
 * Denis Zheleznyakov http://ziblog.ru
 */

#include "main.h"

inline void gpio_init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIOEEN | RCC_AHB1ENR_GPIODEN, ENABLE);

	// светодиод
	PIN_CONFIGURATION(PIN_LED);

	// кнопка
	PIN_CONFIGURATION(PIN_BUTTON);

	// ЖКИ индикатор
	PIN_CONFIGURATION(LCD_NOKIA_1100_CS);
	PIN_CONFIGURATION(LCD_NOKIA_1100_RST);
	PIN_CONFIGURATION(LCD_NOKIA_1100_SCLK);
	PIN_CONFIGURATION(LCD_NOKIA_1100_SDA);
}

void main(void)
{
	gpio_init();

	lcd_nokia1100_init();
	lcd_nokia1100_set_position(7, 0);
	lcd_nokia1100_print_string((uint8_t *) "ZiBlog.ru @ 2014");
	lcd_nokia1100_set_position(0, 0);
	lcd_nokia1100_print_string((uint8_t *) "STM32F4Discovery");
	lcd_nokia1100_set_position(4, 1);
	lcd_nokia1100_print_string((uint8_t *) "LCD Nokia 1100");

	while (1)
	{
		if (PIN_SIGNAL(PIN_BUTTON))
		{
			PIN_ON(PIN_LED);
		}
		else
		{
			PIN_OFF(PIN_LED);
		}
	}
}
