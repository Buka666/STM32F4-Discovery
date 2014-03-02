/*
 * File: bmp085.h
 * Date: 02.03.2014
 * Denis Zheleznyakov aka ZiB @ http://ziblog.ru
 */

#ifndef BMP085_H_
#define BMP085_H_

void bmp085_init(void);
int16_t bmp085_read_temperature(void);
int32_t bmp085_read_pressure(void);

#endif /* BMP085_H_ */
