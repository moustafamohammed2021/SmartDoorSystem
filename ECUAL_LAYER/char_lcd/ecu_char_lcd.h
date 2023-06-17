/* 
 * File:   ecu_char_lcd.h
 * Author: MOUSTAFA
 *
 * Created on February 25, 2023, 1:32 AM
 */

#ifndef ECU_CHAR_LCD_H
#define	ECU_CHAR_LCD_H


/* Section : Includes  */
#include "ecu_char_lcd_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section : Macros Declarations  */
#define DISPLAY_CLEAR                0x01  /* it put in ddram spaces and the cursor to adderess to 0x80  */
#define RETURN_CURSOR_HOME           0x02  /* it made the cursor in address 0x80 the begining but don't change the ddram */
#define ENTRY_SET_DEC_SHIFT_OFF      0x04  /* evrey write data the cursor will decrement and shift is off */
#define ENTRY_SET_DEC_SHIFT_ON       0x05  /* evrey write data the cursor will decrement and shift(right) is on   */ 
#define ENTRY_SET_INC_SHIFT_OFF      0x06  /* evrey write data the cursor will increment and shift is off */
#define ENTRY_SET_INC_SHIFT_ON       0x07  /* evrey write data the cursor will increment and shift(left) is on  */
#define DISPLAY_OFF        0x08            /* the lcd not display any thing but the ddram not change */
#define DISPLAY_ON_UNDER_LINE_OFF_BLINKING_OFF 0x0C  /*display is on under line is off and blinking is off*/ 
#define DISPLAY_ON_UNDER_LINE_OFF_BLINKING_ON  0x0D  /*display is on under line is off and blinking is on*/ 
#define DISPLAY_ON_UNDER_LINE_ON_BLINKING_OFF  0x0E  /*display is on under line is on and blinking is off*/ 
#define DISPLAY_ON_UNDER_LINE_ON_BLINKING_ON   0x0F  /*display is on under line is on and blinking is on*/ 
#define SHIFT_CURSOR_LEFT    0x10     /* it shift the cursor on time left*/
#define SHIFT_CURSOR_RIGHT   0x14     /* it shift the cursor on time right*/
#define DISPLSY_SHIFT_LEFT   0x18       /* it shift the display on time left*/
#define DISPLSY_SHIFT_RIGHT  0x1C       /* it shift the display  on time right */
#define LCD_8BIT_MODE        0x38
#define LCD_4BIT_MODE        0x28 
 
#define CGRAM_START_ADDRESS  0x40
#define DDRAM_START_ADDRESS  0x80

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4
/* Section : macros Function Declarations */

/* Data types Declarations */
typedef struct {
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[4];
}lcd_4bit_mode_t;
typedef struct {
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[8];
}lcd_8bit_mode_t;


/* Function Declarations*/
Std_ReturnType lcd_4bit_initialize(const lcd_4bit_mode_t *_lcd);
Std_ReturnType lcd_4bit_send_command(const lcd_4bit_mode_t *_lcd,uint8 command);
Std_ReturnType lcd_4bit_send_char_data(const lcd_4bit_mode_t *_lcd,uint8 data);
Std_ReturnType lcd_4bit_send_char_data_pos(const lcd_4bit_mode_t *_lcd,uint8 row,uint8 column,uint8 data);
Std_ReturnType lcd_4bit_send_string_data(const lcd_4bit_mode_t *_lcd,uint8 *str);
Std_ReturnType lcd_4bit_send_string_data_pos(const lcd_4bit_mode_t *_lcd,uint8 row,uint8 column,uint8 *str);
Std_ReturnType lcd_4bit_send_custome_char(const lcd_4bit_mode_t *_lcd,uint8 row,uint8 column,
                                            const uint8 _char[],uint8 mem_pos);
Std_ReturnType set_cursor_4bit_mode (const lcd_4bit_mode_t *_lcd,uint8 row,uint8 column);


Std_ReturnType lcd_8bit_initialize(const lcd_8bit_mode_t *_lcd);
Std_ReturnType lcd_8bit_send_command(const lcd_8bit_mode_t *_lcd,uint8 command);
Std_ReturnType lcd_8bit_send_char_data(const lcd_8bit_mode_t *_lcd,uint8 data);
Std_ReturnType lcd_8bit_send_char_data_pos(const lcd_8bit_mode_t *_lcd,uint8 row,uint8 column,uint8 data);
Std_ReturnType lcd_8bit_send_string_data(const lcd_8bit_mode_t *_lcd,uint8 *str);
Std_ReturnType lcd_8bit_send_string_data_pos(const lcd_8bit_mode_t *_lcd,uint8 row,uint8 column,uint8 *str);
Std_ReturnType lcd_8bit_send_custome_char(const lcd_8bit_mode_t *_lcd,uint8 row,uint8 column,
                                            const uint8 _char[],uint8 mem_pos);

Std_ReturnType lcd_convert_uint8_to_string(uint8 value,uint8 *str);
Std_ReturnType lcd_convert_uint16_to_string(uint16 value,uint8 *str);
Std_ReturnType lcd_convert_uint32_to_string(uint32 value,uint8 *str);
#endif	/* ECU_CHAR_LCD_H */

