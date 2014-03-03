/*
 * File: lcd_nokia1100.h
 * Date: 17.01.2011
 * Denis Zheleznyakov aka ZiB @ http://ziblog.ru
 */

#ifndef LCD_NOKIA1100_H_
#define LCD_NOKIA1100_H_

void lcd_nokia1100_init(void);
void lcd_nokia1100_print_dec_xx(uint8_t data);
void lcd_nokia1100_print_dec_xxx(uint8_t data);
void lcd_nokia1100_print_hex_xx(uint8_t data);
void lcd_nokia1100_print_string(uint8_t * string);
void lcd_nokia1100_print_char(uint8_t simbol);
void lcd_nokia1100_set_position(uint8_t row, uint8_t column);
void lcd_nokia1100_clear(void);

#endif /* LCD_NOKIA1100_H_ */
