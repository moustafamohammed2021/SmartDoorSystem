/* 
 * File:   ecu_keypad.c
 * Author: MOUSTAFA
 *
 * Created on February 23, 2023, 4:00 AM
 */

#include "ecu_keypad.h"

static const uint8 btn_keypad_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS]={ {'7','8','9','/'},
                                                                            {'4','5','6','*'},
                                                                            {'1','2','3','-'},
                                                                            {'#','0','=','+'}};


/**
 * 
 * @brief  function that initialize the columns and rows
 * @param _keypad_obj pointer to pins of the keypad rows and columns @ref keypad_t
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj){
       Std_ReturnType ret=E_OK;
       uint8 keypad_rows=ZERO_INIT,keypad_colums=ZERO_INIT;
        if (NULL==_keypad_obj){
            ret=E_NOT_OK;
        }
        else {
            for (keypad_rows=ZERO_INIT;keypad_rows<ECU_KEYPAD_ROWS;keypad_rows++){
             ret=gpio_Pin_Intialize(&(_keypad_obj->pin_keypad_rows[keypad_rows]));
            }
            for (keypad_colums=ZERO_INIT;keypad_colums<ECU_KEYPAD_COLUMNS;keypad_colums++){
               ret= gpio_Pin_Derction_Intialize(&(_keypad_obj->pin_keypad_colums[keypad_colums]));
            }
        }
    return ret;
}

/**
 * 
 * @brief function that get the value of the getting of pressed 
 * @param _keypad_obj _keypad_obj pointer to pins of the keypad rows and columns @ref keypad_t
 * @param value the value that get from the keypad pressed 
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
Std_ReturnType keypad_get_value( const keypad_t *_keypad_obj,uint8 *value){
        Std_ReturnType ret=E_OK;
        uint8 counter_rows=ZERO_INIT,counter_colums=ZERO_INIT;
        uint8 l_counter=ZERO_INIT;
        uint8 column_logic_pin=ZERO_INIT;
        if ((NULL==_keypad_obj) || (NULL==value)){
            ret=E_NOT_OK;
        }
        else {
            for (counter_rows=ZERO_INIT;counter_rows<ECU_KEYPAD_ROWS;counter_rows++){
                
                for (l_counter=ZERO_INIT;l_counter<ECU_KEYPAD_ROWS;l_counter++){
                  ret=gpio_Pin_Write_Logic(&(_keypad_obj->pin_keypad_rows[l_counter]),GPIO_LOW);
                }
                ret=gpio_Pin_Write_Logic(&(_keypad_obj->pin_keypad_rows[counter_rows]),GPIO_HIGH);
              
            for (counter_colums=ZERO_INIT;counter_colums<ECU_KEYPAD_COLUMNS;counter_colums++){
                ret=gpio_Pin_Read_Logic(&(_keypad_obj->pin_keypad_colums[counter_colums]),&column_logic_pin);
                if (column_logic_pin==GPIO_HIGH){
                    *value=btn_keypad_values[counter_rows][counter_colums];
                }
            }  
              
            }
            
        }
    return ret;
}
