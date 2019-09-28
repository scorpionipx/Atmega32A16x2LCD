/*
 * lcd_driver.c
 *
 * Created: 28-Sep-19 19:07:25
 *  Author: ScorpionIPX
 */ 


/*
 * IPX_LCD_Display.c
 *
 * Created: 22.03.2016 16:53:29
 *  Author: Dan
 */ 

#include "Global.h"
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "lcd_driver.h"

#define MAX_CHARS_PER_ROW 16


void lcd_display_init(void)
{
	DDRC = 0xFF;
	lcd_display_send_byte(0x03, 0);
	_delay_ms(LCD_INIT_DELAY_MS);
	lcd_display_send_byte(0x03, 0);
	_delay_ms(LCD_INIT_DELAY_MS);
	lcd_display_send_byte(0x03, 0);
	_delay_ms(LCD_INIT_DELAY_MS);
	lcd_display_send_byte(0x02, 0);
	_delay_ms(LCD_INIT_DELAY_MS);
	lcd_display_send_byte(0x0C, 0);
	_delay_ms(LCD_INIT_DELAY_MS);
	lcd_display_send_byte(0x01, 0);
	_delay_ms(LCD_INIT_DELAY_MS);
	lcd_display_send_byte(0x80, 0);
	_delay_ms(LCD_INIT_DELAY_MS);
	lcd_display_send_byte(0x01, 0);  //clear display
}

void lcd_display_send_byte(unsigned char byte, unsigned char is_data)
{
	PORTC = (PORTC & 0x0F) | (byte & 0xF0);
	PORTC = (PORTC & 0xFE) | (is_data & 0x01);
	PORTC = PORTC | 0x02;
	_delay_ms(LCD_DELAY_MS);
	
	PORTC &= 0xFC;
	PORTC = (PORTC & 0x0F) | ((byte << 4) & 0xF0);
	PORTC = (PORTC & 0xFE) | (is_data & 0x01);
	PORTC = PORTC | 0x02;
	_delay_ms(LCD_DELAY_MS);
	
	PORTC &= 0xFC;
}


// display string
void lcd_display_put_string(const char *_string)
{
	int ch_index;
	for(ch_index = 0; ch_index < strlen(_string); ch_index ++)
	{
		lcd_display_send_byte(_string[ch_index], 1);
	}
}
