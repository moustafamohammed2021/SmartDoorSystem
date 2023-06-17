/* 
 * File:   gpio.h
 * Author: MOUSTAFA
 *
 * Created on February 14, 2023, 7:36 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H
   /* Section : Includes  */
#include <./pic18f4620.h>
#include "../mcal_std_types.h"
#include "./../device_config.h"
#include "hal_gpio_config.h"

/* Section : Macros Declarations  */
#define BIT_MASK     (uint8)1
#define PORT_PIN_MAX_NUMBER  8
#define PORT_MAX_NUMBER      5

#define PORT_MASK    0xFF


/* Section : macros Function Declarations */
#define HARREG(_X)                (*((volatile uint8*)(_X)))  
#define SET_BIT(REG,BIT_POSN)     (REG |=(BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)   (REG &=~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN)  (REG ^=(BIT_MASK << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)    ((REG >> BIT_POSN) & BIT_MASK)

/* Data types Declarations */
typedef enum{
    GPIO_LOW=0,
    GPIO_HIGH        
}logic_t;

typedef enum{
   GPIO_DIRECTION_OUTPUT=0,
   GPIO_DIRECTION_INPUT        
}direction_t;

typedef enum {
     GPIO_PIN0=0,
     GPIO_PIN1,
     GPIO_PIN2,
     GPIO_PIN3,
     GPIO_PIN4,
     GPIO_PIN5,
     GPIO_PIN6,
     GPIO_PIN7        
}gpio_index_t;

typedef enum {
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX        
}port_index_t;

typedef struct{
    uint8 port :3;        /* @ref port_index_t*/
    uint8 pin  :3;        /* @ref gpio_index_t*/
    uint8 direction :1;    /* @ref direction_t*/
    uint8 logic  :1;       /*@ref logic_t*/
}pin_config_t;
/* Function Declarations*/
Std_ReturnType gpio_Pin_Derction_Intialize(const pin_config_t *pin_config);
Std_ReturnType gpio_Pin_Get_Derction_Status(const pin_config_t *pin_config,direction_t *direction_status);
Std_ReturnType gpio_Pin_Write_Logic(const pin_config_t *pin_config,logic_t logic );
Std_ReturnType gpio_Pin_Read_Logic (const pin_config_t *pin_config,logic_t *logic);
Std_ReturnType gpio_Pin_Toggle_Logic (const pin_config_t *pin_config);
Std_ReturnType gpio_Pin_Intialize (const pin_config_t *pin_config);

Std_ReturnType gpio_Port_Derction_Intialize(port_index_t  port ,uint8 direction);
Std_ReturnType gpio_Port_Get_Derction_Status(port_index_t port,uint8 *direction_status);
Std_ReturnType gpio_Port_Write_Logic(port_index_t port,uint8 logic );
Std_ReturnType gpio_Port_Read_Logic (port_index_t port,uint8 *logic);
Std_ReturnType gpio_Port_Toggle_Logic (port_index_t port);
Std_ReturnType gpio_Port_Intialize (port_index_t port);

#endif	/* HAL_GPIO_H */

