/*
 * File: config.h
 * Date: 31.08.2012
 * Denis Zheleznyakov http://ziblog.ru
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#define STM32F40_41xxx
#define HSE_VALUE    		((uint32_t)8000000)

#define assert_param(expr) ((void)0)

#define PIN_LED			D, 12, HIGH, MODE_OUTPUT_PUSH_PULL_PULL_DOWN, SPEED_2MHZ, AF_NO

#define PIN_BUTTON		A,  0, HIGH, MODE_INPUT_FLOATING, SPEED_2MHZ, AF_NO

#endif /* CONFIG_H_ */
