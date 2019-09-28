/*
 * lcd_driver.h
 *
 * Created: 28-Sep-19 19:08:26
 *  Author: ScorpionIPX
 */ 

/*PIN CONFIGURATION*/
/* D4 -> PC4          */
/* D5 -> PC5          */
/* D6 -> PC6          */
/* D7 -> PC7          */
/* RS -> PC0          */
/* E  -> PC1          */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#define LCD_DELAY_MS 3         // DELAY BETWEEN DATA SENT TO LCD
#define LCD_INIT_DELAY_MS 8    // DELAY BETWEEN DATA SENT TO LCD WHEN INITIALIZING

void lcd_display_send_byte(unsigned char byte, unsigned char is_data);
void lcd_display_init(void);
void lcd_display_put_string(const char *_string);

#endif /* LCD_DRIVER_H_ */