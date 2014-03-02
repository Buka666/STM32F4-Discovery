/*
 * File: config.h
 * Date: 31.08.2012
 * Denis Zheleznyakov http://ziblog.ru
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#define STM32F40_41xxx
#define HSE_VALUE    			((uint32_t)8000000)

#define	MCU_HCLK_MHZ			((uint32_t)8)
#define	MCU_APB1_MHZ			((uint32_t)8)

#define assert_param(expr) ((void)0)

#define PIN_LED					D, 12, HIGH, MODE_OUTPUT_PUSH_PULL_PULL_DOWN, SPEED_2MHZ, AF_NO

#define PIN_BUTTON				A,  0, HIGH, MODE_INPUT_FLOATING, SPEED_2MHZ, AF_NO

#define PIN_I2C1_SDA 			B, 7, HIGH, MODE_AF_OPEN_DRAIN_PULL_UP, SPEED_2MHZ, AF4
#define PIN_I2C1_SCL 			B, 8, HIGH, MODE_AF_OPEN_DRAIN_PULL_UP, SPEED_2MHZ, AF4

#define PIN_BMP085_XCLR    		B, 14,  LOW, MODE_OUTPUT_PUSH_PULL_PULL_DOWN, SPEED_2MHZ, AF_NO
#define PIN_BMP085_EOC     		B, 15,  LOW, MODE_INPUT_FLOATING, SPEED_2MHZ, AF_NO

#endif /* CONFIG_H_ */
