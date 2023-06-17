/* 
 * File:   ecu_char_lcd_config.h
 * Author: MOUSTAFA
 *
 * Created on February 25, 2023, 1:33 AM
 */
#include "ecu_char_lcd.h"

             /*****functions Declarations */
static Std_ReturnType send_data_4bit_mode (const lcd_4bit_mode_t *_lcd,uint8 data);
static Std_ReturnType send_4bit_mode_enable(const lcd_4bit_mode_t *_lcd);
static Std_ReturnType send_8bit_mode_enable(const lcd_8bit_mode_t *_lcd);
static Std_ReturnType set_cursor_8bit_mode (const lcd_8bit_mode_t *_lcd,uint8 row,uint8 column);


/***************************************4 bit mode******************************************************/

/**
 * 
 * @param _lcd
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
Std_ReturnType lcd_4bit_initialize( const lcd_4bit_mode_t *_lcd){
        Std_ReturnType ret=E_OK;
        uint8 l_counter=ZERO_INIT;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            ret=gpio_Pin_Intialize(&(_lcd->lcd_rs));
            ret=gpio_Pin_Intialize(&(_lcd->lcd_en));
            for (l_counter=ZERO_INIT;l_counter<4;l_counter++){
                ret=gpio_Pin_Intialize(&(_lcd->lcd_data[l_counter]));
            }
             __delay_ms(20);
           ret= lcd_4bit_send_command(_lcd,LCD_8BIT_MODE);
           __delay_ms(5);
           ret= lcd_4bit_send_command(_lcd,LCD_8BIT_MODE);
           __delay_us(150);
           ret= lcd_4bit_send_command(_lcd,LCD_8BIT_MODE);
           
           ret=lcd_4bit_send_command(_lcd,DISPLAY_CLEAR);
           ret=lcd_4bit_send_command(_lcd,RETURN_CURSOR_HOME);
           ret=lcd_4bit_send_command(_lcd,ENTRY_SET_INC_SHIFT_OFF);
           ret=lcd_4bit_send_command(_lcd,DISPLAY_ON_UNDER_LINE_ON_BLINKING_OFF);
           ret= lcd_4bit_send_command(_lcd,LCD_4BIT_MODE);
           ret=lcd_4bit_send_command(_lcd,DDRAM_START_ADDRESS);
            
        }
        return ret;
    
}

/**
 * 
 * @param _lcd
 * @param command
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
 
Std_ReturnType lcd_4bit_send_command(const lcd_4bit_mode_t *_lcd,uint8 command){
     Std_ReturnType ret=E_OK;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            /* r/w connect to the logic 0 hard wired */
            /* made rs=0 to select the instruction register */
           ret=gpio_Pin_Write_Logic(&(_lcd->lcd_rs),GPIO_LOW);  
           /* send the msb bits in the command*/
           ret=send_data_4bit_mode(_lcd,command>>4); 
            /* send enable signal to the lcd */
           ret=send_4bit_mode_enable(_lcd);         
            /* send the lsb bits in the command*/
           ret=send_data_4bit_mode(_lcd,command);  
            /* send enable signal to the lcd */
           ret=send_4bit_mode_enable(_lcd);        
        }
        return ret;
    
}
/**
 * 
 * @param _lcd
 * @param data
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
Std_ReturnType lcd_4bit_send_char_data(const lcd_4bit_mode_t *_lcd,uint8 data){
    Std_ReturnType ret=E_OK;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            /* r/w connect to the logic 0 hard wired */
            /* made rs=1 to select the DATA register */
           ret=gpio_Pin_Write_Logic(&(_lcd->lcd_rs),GPIO_HIGH);  
           /* send the msb bits in the DATA*/
           ret=send_data_4bit_mode(_lcd,data>>4); 
            /* send enable signal to the lcd */
           ret=send_4bit_mode_enable(_lcd);         
            /* send the lsb bits in the DATA*/
           ret=send_data_4bit_mode(_lcd,data);  
            /* send enable signal to the lcd */
           ret=send_4bit_mode_enable(_lcd);  
        }
        return ret;
    
}

/**
 * 
 * @param _lcd
 * @param row
 * @param column
 * @param data
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
Std_ReturnType lcd_4bit_send_char_data_pos(const lcd_4bit_mode_t *_lcd,uint8 row,uint8 column,uint8 data){
    Std_ReturnType ret=E_OK;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            ret=set_cursor_4bit_mode(_lcd,row,column);
            ret=lcd_4bit_send_char_data(_lcd,data);
        }
        return ret;
    
}

/**
 * 
 * @param _lcd
 * @param str
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
Std_ReturnType lcd_4bit_send_string_data(const lcd_4bit_mode_t *_lcd,uint8 *str){
    Std_ReturnType ret=E_OK;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            while(*str){
               ret= lcd_4bit_send_char_data(_lcd,*str++);
            }
            
        }
        return ret;
    
}

/**
 * 
 * @param _lcd
 * @param row
 * @param column
 * @param str
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
Std_ReturnType lcd_4bit_send_string_data_pos(const lcd_4bit_mode_t *_lcd,uint8 row,uint8 column,uint8 *str){
    Std_ReturnType ret=E_OK;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            ret=set_cursor_4bit_mode(_lcd,row,column);
            while(*str){
               ret= lcd_4bit_send_char_data(_lcd,*str++);
            }
        }
        return ret;
    
}
/**
 * 
 * @param _lcd
 * @param row
 * @param column
 * @param _char
 * @param mem_pos
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
Std_ReturnType lcd_4bit_send_custome_char(const lcd_4bit_mode_t *_lcd,uint8 row,uint8 column,
                                            const uint8 _char[],uint8 mem_pos){
      Std_ReturnType ret=E_OK;
      uint8 l_counter=ZERO_INIT;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            ret=lcd_4bit_send_command(_lcd,(CGRAM_START_ADDRESS+(mem_pos*8)));
            for (l_counter=ZERO_INIT;l_counter<8;l_counter++){
                ret=lcd_4bit_send_char_data(_lcd,_char[l_counter]);
            }
            ret=lcd_4bit_send_char_data_pos(_lcd,row,column,mem_pos);
            
        }
        return ret;
    
}

/***************************************8 bit mode******************************************************/
Std_ReturnType lcd_8bit_initialize(const lcd_8bit_mode_t *_lcd){
      Std_ReturnType ret=E_OK;
      uint8 l_counter=ZERO_INIT;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            ret=gpio_Pin_Intialize(&(_lcd->lcd_rs));
            ret=gpio_Pin_Intialize(&(_lcd->lcd_en));
            for (l_counter=ZERO_INIT;l_counter<8;l_counter++){
                ret=gpio_Pin_Intialize(&(_lcd->lcd_data[l_counter]));
            }
            __delay_ms(20);
           ret= lcd_8bit_send_command(_lcd,LCD_8BIT_MODE);
           __delay_ms(5);
           ret= lcd_8bit_send_command(_lcd,LCD_8BIT_MODE);
           __delay_us(150);
           ret= lcd_8bit_send_command(_lcd,LCD_8BIT_MODE);
           
           ret=lcd_8bit_send_command(_lcd,DISPLAY_CLEAR);
           ret=lcd_8bit_send_command(_lcd,RETURN_CURSOR_HOME);
           ret=lcd_8bit_send_command(_lcd,ENTRY_SET_INC_SHIFT_OFF);
           ret=lcd_8bit_send_command(_lcd,DISPLAY_ON_UNDER_LINE_OFF_BLINKING_OFF);
           ret= lcd_8bit_send_command(_lcd,LCD_8BIT_MODE);
           ret=lcd_8bit_send_command(_lcd,DDRAM_START_ADDRESS);
        }
        return ret;
    
}
Std_ReturnType lcd_8bit_send_command( const lcd_8bit_mode_t *_lcd,uint8 command){
      Std_ReturnType ret=E_OK;
      uint8 l_counter=ZERO_INIT;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            /* r/w connect to the logic 0 hard wired */
            /* made rs=0 to select the instruction register */
           ret=gpio_Pin_Write_Logic(&(_lcd->lcd_rs),GPIO_LOW); 
              /* put the command to the instruction register */
            for (l_counter=ZERO_INIT;l_counter<8;l_counter++){
            ret=gpio_Pin_Write_Logic(&(_lcd->lcd_data[l_counter]),(command>>l_counter) & (uint8)0x01);
            }
           ret=send_8bit_mode_enable(_lcd);
        }
        return ret;
    
}
Std_ReturnType lcd_8bit_send_char_data(const lcd_8bit_mode_t *_lcd,uint8 data){
    Std_ReturnType ret=E_OK;
    uint8 l_counter=ZERO_INIT;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            /* r/w connect to the logic 0 hard wired */
            /* made rs=0 to select the DATA register */
           ret=gpio_Pin_Write_Logic(&(_lcd->lcd_rs),GPIO_HIGH); 
              /* put the DATA to the DATA register */
            for (l_counter=ZERO_INIT;l_counter<8;l_counter++){
            ret=gpio_Pin_Write_Logic(&(_lcd->lcd_data[l_counter]),(data>>l_counter) & (uint8)0x01);
            }
           ret=send_8bit_mode_enable(_lcd);
        }
        return ret;
    
}
Std_ReturnType lcd_8bit_send_char_data_pos(const lcd_8bit_mode_t *_lcd,uint8 row,uint8 column,uint8 data){
    Std_ReturnType ret=E_OK;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            ret=set_cursor_8bit_mode(_lcd,row,column);
            ret=lcd_8bit_send_char_data(_lcd,data);
            
        }
        return ret;
    
}
Std_ReturnType lcd_8bit_send_string_data(const lcd_8bit_mode_t *_lcd,uint8 *str){
    Std_ReturnType ret=E_OK;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            
            while(*str){
               ret= lcd_8bit_send_char_data(_lcd,*str++);
            }
        }
        return ret;
    
}
Std_ReturnType lcd_8bit_send_string_data_pos( const lcd_8bit_mode_t *_lcd,uint8 row,uint8 column,uint8 *str){
    Std_ReturnType ret=E_OK;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            ret=set_cursor_8bit_mode(_lcd,row,column);
            while(*str){
               ret= lcd_8bit_send_char_data(_lcd,*str++);
            }
        }
        return ret;
    
}
Std_ReturnType lcd_8bit_send_custome_char(const lcd_8bit_mode_t *_lcd,uint8 row,uint8 column,
                                            const uint8 _char[],uint8 mem_pos){
      Std_ReturnType ret=E_OK;
      uint8 l_counter=ZERO_INIT;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            ret=lcd_8bit_send_command(_lcd,(CGRAM_START_ADDRESS+(mem_pos*8)));
            for (l_counter=ZERO_INIT;l_counter<8;l_counter++){
                ret=lcd_8bit_send_char_data(_lcd,_char[l_counter]);
            }
            ret=lcd_8bit_send_char_data_pos(_lcd,row,column,mem_pos);
            
        }
        return ret;
    
}

Std_ReturnType lcd_convert_uint8_to_string(uint8 value,uint8 *str){
     Std_ReturnType ret=E_OK;
    if (NULL==str){
        ret=E_NOT_OK;
    }
    else {
         memset((char*)str,'\0',4);
         sprintf(str,"%i",value);
    }  
     return ret;
}
Std_ReturnType lcd_convert_uint16_to_string(uint16 value,uint8  *str){
    Std_ReturnType ret = E_OK;
    uint8 Temp_String[6] = {0};
    uint8 DataCounter = 0;
    if(NULL == str){
        ret = E_NOT_OK;
    }
    else{    
        memset(str, ' ', 5);
        str[5] = '\0';
        sprintf((char *)Temp_String, "%i", value);
        while(Temp_String[DataCounter] != '\0'){
            str[DataCounter] = Temp_String[DataCounter]; 
            DataCounter++;
        }
    }
    return ret;
}

Std_ReturnType lcd_convert_uint32_to_string(uint32 value,uint8 *str){
    Std_ReturnType ret=E_OK;
    if (NULL==str){
        ret=E_NOT_OK;
    }
    else {
         memset((char*)str,'\0',11);
         sprintf(str,"%i",value);
    }  
     return ret;
}



static Std_ReturnType send_data_4bit_mode ( const lcd_4bit_mode_t *_lcd,uint8 data){
     Std_ReturnType ret=E_OK;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            ret=gpio_Pin_Write_Logic(&(_lcd->lcd_data[0]),(data >> 0) & (uint8)0x01);
            ret=gpio_Pin_Write_Logic(&(_lcd->lcd_data[1]),(data >> 1) & (uint8)0x01);
            ret=gpio_Pin_Write_Logic(&(_lcd->lcd_data[2]),(data >> 2) & (uint8)0x01);
            ret=gpio_Pin_Write_Logic(&(_lcd->lcd_data[3]),(data >> 3) & (uint8)0x01);
        }
        return ret;
}

static Std_ReturnType send_4bit_mode_enable(const lcd_4bit_mode_t *_lcd){
    Std_ReturnType ret=E_OK;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            ret=gpio_Pin_Write_Logic(&(_lcd->lcd_en),GPIO_HIGH);
            __delay_us(5);
            ret=gpio_Pin_Write_Logic(&(_lcd->lcd_en),GPIO_LOW);
        }
        return ret;
} 
static Std_ReturnType send_8bit_mode_enable(const lcd_8bit_mode_t *_lcd){
    Std_ReturnType ret=E_OK;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            ret=gpio_Pin_Write_Logic(&(_lcd->lcd_en),GPIO_HIGH);
            __delay_us(5);
            ret=gpio_Pin_Write_Logic(&(_lcd->lcd_en),GPIO_LOW);
        }
        return ret;
} 
Std_ReturnType set_cursor_4bit_mode (const lcd_4bit_mode_t *_lcd,uint8 row,uint8 column){
    Std_ReturnType ret=E_OK;
    column--;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            switch(row){
                case ROW1 : ret=lcd_4bit_send_command(_lcd,(0x80+column));break;
                case ROW2 : ret=lcd_4bit_send_command(_lcd,(0xC0+column));break;
                case ROW3 : ret=lcd_4bit_send_command(_lcd,(0x94+column));break;
                case ROW4 : ret=lcd_4bit_send_command(_lcd,(0xD4+column));break;
                default:;
            }
            
        }
        return ret;
    
}
static Std_ReturnType set_cursor_8bit_mode (const lcd_8bit_mode_t *_lcd,uint8 row,uint8 column){
    Std_ReturnType ret=E_OK;
    column--;
        if (NULL==_lcd){
            ret=E_NOT_OK;
        }
        else {
            switch(row){
                case ROW1 : ret=lcd_8bit_send_command(_lcd,(0x80+column));break;
                case ROW2 : ret=lcd_8bit_send_command(_lcd,(0xC0+column));break;
                case ROW3 : ret=lcd_8bit_send_command(_lcd,(0x94+column));break;
                case ROW4 : ret=lcd_8bit_send_command(_lcd,(0xD4+column));break;
                default:;
            }
            
        }
        return ret;
    
}