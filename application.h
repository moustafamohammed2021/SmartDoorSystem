/* 
 * File:   application.h
 * Author: MOUSTAFA
 *
 * Created on June 4, 2023, 9:19 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H
#include "MCAL_LAYER/GPIO/hal_gpio.h"
#include "ECUAL_LAYER/DC_Motor/ecu_dc_motor.h"
#include "ECUAL_LAYER/char_lcd/ecu_char_lcd.h"
#include "ECUAL_LAYER/key_pad/ecu_keypad.h"
#include "MCAL_LAYER/EEPROM/hal_eeprom.h"
#include "MCAL_LAYER/Delay/M_Delay.h"
#include "MainConfig.h"

uint8 u8PassIsSetOrNotSet(uint16 Address);//Deceleration of The Function of The Read certain Address
void vReadBlockOnEEPROM(uint16 u16TheStartAddress,uint8 *Pass,uint8 Size);//Deceleration of The Read Block in The EEPROM
void  vWriteBlockOnEEPROM(uint16 u16TheStartAddress,uint8 *Pass,uint8 Size);//Deceleration of The Write Block in The EEPROM
uint8 u8ComparePass(const uint8 *Pass1,const uint8 *Pass2,uint8 Size);
/************Structure Of The Keypad Definition ******************/
keypad_t Keypad_Obj={.pin_keypad_rows[0].port=PORTA_INDEX,.pin_keypad_rows[0].pin=GPIO_PIN0,
                     .pin_keypad_rows[0].direction=GPIO_DIRECTION_OUTPUT,.pin_keypad_rows[0].logic=GPIO_LOW,
                     .pin_keypad_rows[1].port=PORTA_INDEX,.pin_keypad_rows[1].pin=GPIO_PIN1,
                     .pin_keypad_rows[1].direction=GPIO_DIRECTION_OUTPUT,.pin_keypad_rows[1].logic=GPIO_LOW,
                     .pin_keypad_rows[2].port=PORTA_INDEX,.pin_keypad_rows[2].pin=GPIO_PIN2,
                     .pin_keypad_rows[2].direction=GPIO_DIRECTION_OUTPUT,.pin_keypad_rows[2].logic=GPIO_LOW,
                     .pin_keypad_rows[3].port=PORTA_INDEX,.pin_keypad_rows[3].pin=GPIO_PIN3,
                     .pin_keypad_rows[3].direction=GPIO_DIRECTION_OUTPUT,.pin_keypad_rows[3].logic=GPIO_LOW,
                     .pin_keypad_colums[0].port=PORTA_INDEX,.pin_keypad_colums[0].pin=GPIO_PIN4,
                     .pin_keypad_colums[0].direction=GPIO_DIRECTION_INPUT,.pin_keypad_colums[0].logic=GPIO_LOW,
                     .pin_keypad_colums[1].port=PORTA_INDEX,.pin_keypad_colums[1].pin=GPIO_PIN5,
                     .pin_keypad_colums[1].direction=GPIO_DIRECTION_INPUT,.pin_keypad_colums[1].logic=GPIO_LOW,
                     .pin_keypad_colums[2].port=PORTA_INDEX,.pin_keypad_colums[2].pin=GPIO_PIN6,
                     .pin_keypad_colums[2].direction=GPIO_DIRECTION_INPUT,.pin_keypad_colums[2].logic=GPIO_LOW,
                     .pin_keypad_colums[3].port=PORTA_INDEX,.pin_keypad_colums[3].pin=GPIO_PIN7,
                     .pin_keypad_colums[3].direction=GPIO_DIRECTION_INPUT,.pin_keypad_colums[3].logic=GPIO_LOW};

/************Structure Of The DC Motor Definition ******************/
dc_motor_t DC_Obj={.dc_motor_pin[0].port=PORTD_INDEX,.dc_motor_pin[0].pin=GPIO_PIN0,
                   .dc_motor_pin[0].direction=GPIO_DIRECTION_OUTPUT,
                   .dc_motor_pin[1].port=PORTD_INDEX,.dc_motor_pin[1].pin=GPIO_PIN1,
                   .dc_motor_pin[1].direction=GPIO_DIRECTION_OUTPUT};
/************Structure Of The LCD Module Definition ******************/
lcd_4bit_mode_t Lcd_Obj={.lcd_rs.port=PORTC_INDEX,.lcd_rs.pin=GPIO_PIN0,.lcd_rs.direction=GPIO_DIRECTION_OUTPUT,
                         .lcd_en.port=PORTC_INDEX,.lcd_en.pin=GPIO_PIN1,.lcd_rs.direction=GPIO_DIRECTION_OUTPUT,
                         .lcd_data[0].port=PORTC_INDEX,.lcd_data[0].pin=GPIO_PIN2,.lcd_data[0].direction=GPIO_DIRECTION_OUTPUT,
                         .lcd_data[1].port=PORTC_INDEX,.lcd_data[1].pin=GPIO_PIN3,.lcd_data[1].direction=GPIO_DIRECTION_OUTPUT,
                         .lcd_data[2].port=PORTC_INDEX,.lcd_data[2].pin=GPIO_PIN4,.lcd_data[2].direction=GPIO_DIRECTION_OUTPUT,
                         .lcd_data[3].port=PORTC_INDEX,.lcd_data[3].pin=GPIO_PIN5,.lcd_data[3].direction=GPIO_DIRECTION_OUTPUT};
#endif	/* APPLICATION_H */

