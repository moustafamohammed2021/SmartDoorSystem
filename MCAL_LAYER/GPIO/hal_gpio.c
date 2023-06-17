/* 
 * File:   gpio.h
 * Author: MOUSTAFA
 *
 * Created on February 14, 2023, 7:36 AM
 */
#include "hal_gpio.h"
     /* references data direction control registers  */
volatile uint8 *tris_registers[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
     /*   references to the data latch registers to read or write */
volatile uint8 *lat_registers[]={&LATA,&LATB,&LATC,&LATD,&LATE};
      /*references to the port status registers  */
volatile uint8 *port_registers[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};

/**
 * 
 * @brief function to initialize the direction of the pin  @ref direction_t
 * @param pin_config pointer to data of the pin @ref pin_config_t
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *          (E_NOT_OK) the function don't done successfully
 */
#if GPIO_PORT_PIN_CONFIGRATION==CONFIG_ENABLE
Std_ReturnType gpio_Pin_Derction_Intialize(const pin_config_t *pin_config){
    Std_ReturnType ret=E_OK;
    if ((NULL==pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER-1)){
        ret=E_NOT_OK;
    }
    else {
        switch(pin_config->direction){
            case GPIO_DIRECTION_OUTPUT:
                CLEAR_BIT(*tris_registers[pin_config->port],pin_config->pin);
             break; 
            case GPIO_DIRECTION_INPUT:
                SET_BIT(*tris_registers[pin_config->port],pin_config->pin);
                break;
            default:ret=E_NOT_OK;   
        }
    }
    return ret;
}
#endif
/**
 * 
 * @brief function to get the direction of pin @ref direction_t
 * @param pin_config pointer to data of the pin @ref pin_config_t
 * @param direction_status 
 * @return  the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
#if GPIO_PORT_PIN_CONFIGRATION==CONFIG_ENABLE
Std_ReturnType gpio_Pin_Get_Derction_Status(const pin_config_t *pin_config,direction_t *direction_status){
    Std_ReturnType ret=E_OK;
    if (NULL==pin_config || NULL==direction_status || pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret=E_NOT_OK;
    }
    else {
         *direction_status=READ_BIT(*tris_registers[pin_config->port],pin_config->pin);
    }
    
  return ret;  
}
#endif
/**
 * 
 * @brief function write logic in pin @ref logic_t
 * @param pin_config pointer to data of @ref pin_config_t
 * @param logic
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
#if GPIO_PORT_PIN_CONFIGRATION==CONFIG_ENABLE
Std_ReturnType gpio_Pin_Write_Logic(const pin_config_t *pin_config,logic_t logic ){
    Std_ReturnType ret=E_OK;
    if (NULL==pin_config || pin_config->pin > PORT_PIN_MAX_NUMBER-1 ){
        ret=E_NOT_OK;
    }
    switch (logic){
        case GPIO_LOW:
            CLEAR_BIT(*lat_registers[pin_config->port],pin_config->pin);
            break;
        case GPIO_HIGH:
            SET_BIT(*lat_registers[pin_config->port],pin_config->pin);
            break;
    }
    return ret;
}
#endif
/**
 * 
 * function read logic in pin @ref logic_t
 * @param pin_config pointer to data of @ref pin_config_t
 * @param logic
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
#if GPIO_PORT_PIN_CONFIGRATION==CONFIG_ENABLE
Std_ReturnType gpio_Pin_Read_Logic (const pin_config_t *pin_config,logic_t *logic){
    Std_ReturnType ret=E_OK;
    if (NULL==pin_config || NULL==logic || pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret=E_NOT_OK;
    }
    else {
        *logic=READ_BIT(*port_registers[pin_config->port],pin_config->pin);
    }
    return ret;
}
#endif
/**
 * 
 * function toggle logic in pin
 * @param pin_config pointer to data of @ref pin_config_t
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
#if GPIO_PORT_PIN_CONFIGRATION==CONFIG_ENABLE
Std_ReturnType gpio_Pin_Toggle_Logic (const pin_config_t *pin_config){
    Std_ReturnType ret=E_OK;
    if (NULL==pin_config || pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret=E_NOT_OK;
    }
    TOGGLE_BIT(*lat_registers[pin_config->port],pin_config->pin);
    return ret;
}
#endif


/**
 * 
 * @brief function that initialize the pin  
 * @param pin_config pointer to data of @ref pin_config_t
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
#if GPIO_PORT_PIN_CONFIGRATION==CONFIG_ENABLE
Std_ReturnType gpio_Pin_Intialize (const pin_config_t *pin_config){
    Std_ReturnType ret=E_OK;
    if (NULL==pin_config || pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret=E_NOT_OK;
    }
    ret=gpio_Pin_Derction_Intialize(pin_config);
    ret=gpio_Pin_Write_Logic(pin_config,pin_config->logic);
    
    return ret;
}
#endif

/**
 * 
 * @breif function that initialize direction of the port (input or output) 
 * @param port the number of the port @ref port_index_t
 * @param direction 
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
#if GPIO_PORT_CONFIGRATION==CONFIG_ENABLE
Std_ReturnType gpio_Port_Derction_Intialize(port_index_t  port ,uint8 direction){
    Std_ReturnType ret=E_OK;
    if (port > PORT_MAX_NUMBER){
        ret=E_NOT_OK;
    }
    else {
        *tris_registers[port]=direction;
    }
    return ret;
}
#endif

/**
 * 
 * function get the status of the register 
 * @param port the number of the port @ref port_index_t
 * @param direction_status get the direction status 
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
#if GPIO_PORT_CONFIGRATION==CONFIG_ENABLE
Std_ReturnType gpio_Port_Get_Derction_Status(port_index_t port,uint8 *direction_status){
    Std_ReturnType ret=E_OK;
    if (NULL==direction_status || port > PORT_MAX_NUMBER){
        ret=E_NOT_OK;
    }
    else {
        *direction_status= *tris_registers[port];
    }
    return ret;
}
#endif
/**
 * 
 * function that write in the port 
 * @param port the number of the port @ref port_index_t
 * @param logic
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
#if GPIO_PORT_CONFIGRATION==CONFIG_ENABLE
Std_ReturnType gpio_Port_Write_Logic(port_index_t port,uint8 logic ){
    Std_ReturnType ret=E_OK;
    if (port > PORT_MAX_NUMBER){
        ret=E_NOT_OK;
    }
    else {
        *lat_registers[port]=logic;
    }
    return ret;
}
#endif
/**
 * 
 * function read the logic in the port 
 * @param port the number of the port @ref port_index_t
 * @param logic
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
#if GPIO_PORT_CONFIGRATION==CONFIG_ENABLE
Std_ReturnType gpio_Port_Read_Logic (port_index_t port,uint8 *logic){
    Std_ReturnType ret=E_OK;
    if (NULL==logic || port > PORT_MAX_NUMBER){
        ret=E_NOT_OK;
    }
    else {
        *logic=*lat_registers[port];
    }
    return ret;
}
#endif
/**
 * 
 * function that toggle the pins of the port 
 * @param port the number of the port @ref port_index_t
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
#if GPIO_PORT_CONFIGRATION==CONFIG_ENABLE
Std_ReturnType gpio_Port_Toggle_Logic (port_index_t port){
    Std_ReturnType ret=E_OK;
    if (port > PORT_MAX_NUMBER){
        ret=E_NOT_OK;
    }
    else {
        (*lat_registers[port] ^= PORT_MASK);
    }
    return ret;
}
#endif