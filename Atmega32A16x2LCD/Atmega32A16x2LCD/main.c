/*
 * Atmega32A16x2LCD.c
 *
 * Created: 28-Sep-19 18:52:34
 * Author : ScorpionIPX
 */ 

#include "global.h"
#include <avr/io.h>
#include "lcd_driver.h"



int main(void)
{
	lcd_display_init();
	lcd_display_put_string("ScorpionIPX");
		
    while (1) 
    {
    }
}

