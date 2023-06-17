/* 
 * File:   ecu_keypad.h
 * Author: MOUSTAFA
 *
 * Created on February 23, 2023, 3:58 AM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H
/* Section : Includes  */
#include "ecu_keypad_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section : Macros Declarations  */
#define ECU_KEYPAD_ROWS 4
#define ECU_KEYPAD_COLUMNS 4


/* Section : macros Function Declarations */

/* Data types Declarations */
typedef struct {
    pin_config_t pin_keypad_rows[ECU_KEYPAD_ROWS];
    pin_config_t pin_keypad_colums[ECU_KEYPAD_COLUMNS];
}keypad_t;
/* Function Declarations*/
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj);
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj,uint8 *value);

#endif	/* ECU_KEYPAD_H */

