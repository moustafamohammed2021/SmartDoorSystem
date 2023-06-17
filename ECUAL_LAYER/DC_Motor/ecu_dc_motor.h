/* 
 * File:   ecu_dc_motor.h
 * Author: MOUSTAFA
 *
 * Created on February 22, 2023, 1:46 AM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section : Includes  */
#include "ecu_dc_motor_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"


/* Section : Macros Declarations  */
#define DC_MOTOR_ON_STATUS  0x01U
#define DC_MOTOR_OFF_STATUS  0x00U 

#define PIN1_MOTOR     0x00U
#define PIN2_MOTOR     0x01U
/* Section : macros Function Declarations */

/* Data types Declarations */
typedef struct {
    pin_config_t dc_motor_pin[2];
}dc_motor_t;
/* Function Declarations*/
Std_ReturnType dc_motor_initialize(dc_motor_t *dc_motor);
Std_ReturnType dc_motor_move_right(dc_motor_t *dc_motor);
Std_ReturnType dc_motor_move_left(dc_motor_t *dc_motor);
Std_ReturnType dc_motor_stop(dc_motor_t *dc_motor);


#endif	/* ECU_DC_MOTOR_H */

