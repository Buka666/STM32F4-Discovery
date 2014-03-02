/*
 * File: main.c
 * Date: 31.08.2012
 * Denis Zheleznyakov http://ziblog.ru
 */

#include "main.h"

int32_t temperature;
int32_t pressure;

inline void gpio_init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIODEN, ENABLE);

	// светодиод
	PIN_CONFIGURATION(PIN_LED);

	// кнопка
	PIN_CONFIGURATION(PIN_BUTTON);

	// I2C
	PIN_CONFIGURATION(PIN_I2C1_SCL);
	PIN_CONFIGURATION(PIN_I2C1_SDA);

	// BMP085
	PIN_CONFIGURATION(PIN_BMP085_EOC);
	PIN_CONFIGURATION(PIN_BMP085_XCLR);
}

void main(void)
{
	gpio_init();

	mcu_i2c_init();

	bmp085_init();

	while (1)
	{
		temperature = bmp085_read_temperature();
		pressure = bmp085_read_pressure();

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
