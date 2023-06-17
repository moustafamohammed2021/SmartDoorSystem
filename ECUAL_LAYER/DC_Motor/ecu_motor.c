/* 
 * File:   ecu_dc_motor.c
 * Author: MOUSTAFA
 *
 * Created on February 22, 2023, 1:47 AM
 */



#include "ecu_dc_motor.h"

/**
 * @brief Initialize the assigned pins to be OUTPUT and turn the motor OFF or ON.
 * @param _dc_motor pointer to the motor configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType dc_motor_initialize(dc_motor_t *dc_motor){
    Std_ReturnType ret=E_OK;
     if (NULL==dc_motor){
        ret=E_NOT_OK;  
     }
     else {
           ret=gpio_Pin_Intialize(&(dc_motor->dc_motor_pin[PIN1_MOTOR]));
           ret=gpio_Pin_Intialize(&(dc_motor->dc_motor_pin[PIN2_MOTOR]));
     }
     return ret;
}

/**
 * @brief Move the motor to the right direction
 * @param _dc_motor pointer to the motor configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType dc_motor_move_right(dc_motor_t *dc_motor){
    Std_ReturnType ret=E_OK;
     if (NULL==dc_motor){
        ret=E_NOT_OK;  
     }
     else {
         ret=gpio_Pin_Write_Logic(&(dc_motor->dc_motor_pin[PIN1_MOTOR]),GPIO_HIGH);
         ret=gpio_Pin_Write_Logic(&(dc_motor->dc_motor_pin[PIN2_MOTOR]),GPIO_LOW);
     }
     return ret;
}

/**
 * @brief Move the motor to the left direction
 * @param _dc_motor pointer to the motor configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType dc_motor_move_left(dc_motor_t *dc_motor){
    Std_ReturnType ret=E_OK;
     if (NULL==dc_motor){
        ret=E_NOT_OK;  
     }
     else {
        ret=gpio_Pin_Write_Logic(&(dc_motor->dc_motor_pin[PIN1_MOTOR]),GPIO_LOW);
        ret=gpio_Pin_Write_Logic(&(dc_motor->dc_motor_pin[PIN2_MOTOR]),GPIO_HIGH);
     }
     return ret;
}

/**
 * @brief stop the motor movement
 * @param _dc_motor pointer to the motor configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType dc_motor_stop(dc_motor_t *dc_motor){
    Std_ReturnType ret=E_OK;
     if (NULL==dc_motor){
        ret=E_NOT_OK;  
     }
     else {
        ret=gpio_Pin_Write_Logic(&(dc_motor->dc_motor_pin[PIN1_MOTOR]),GPIO_LOW);
        ret=gpio_Pin_Write_Logic(&(dc_motor->dc_motor_pin[PIN2_MOTOR]),GPIO_LOW);
     }
     return ret;
}