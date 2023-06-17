/* 
 * File:   hal_timer0.h
 * Author: MOUSTAFA
 *
 * Created on March 6, 2023, 7:20 AM
 */

#ifndef HAL_TIMER0_H
#define	HAL_TIMER0_H

/* Section: Includes */
#include "../GPIO/hal_gpio.h"
#include "../mcal_std_types.h"
#include <./pic18f4620.h>
#include "../interrupt/mcal_internal_interrupt.h"

/* Section : Macros Declarations  */
#define TIMER0_8BIT_MODE_CFG    1
#define TIMER0_16BIT_MODE_CFG   0

#define TIMER0_TIMER_MODE_CFG   1
#define TIMER0_COUNTER_MODE_CFG 0

#define TIMER0_COUNTER_RISING_EDGE_CFG   1
#define TIMER0_COUNTER_FALLING_EDGE_CFG  0

#define TIMER0_PRESCALER_ENABLE_CFG       1
#define TIMER0_PRESCALER_DISABLE_CFG      0
/* Section : macros Function Declarations */
/*enable timer0 module */
#define TIMER0_MODULE_ENABLE()          (T0CONbits.TMR0ON=1)
/*diable timer0 module*/
#define TIMER0_MODULE_DISABLE()         (T0CONbits.TMR0ON=0)
/*enable timer0 8bit mode */
#define TIMER0_8BIT_MODE_ENABLE()       (T0CONbits.T08BIT=1)
/*enable timer0 16bit mode */
#define TIMER0_16BIT_MODE_ENABLE()      (T0CONbits.T08BIT=0)
/*enable timer mode */
#define TIMER0_TIMER_MODE_ENABLE()       (T0CONbits.T0CS=0)
/*enable counter mode */
#define TIMER0_COUNTER_MODE_ENABLE()     (T0CONbits.T0CS=1)
/*for counter mode enable rising edge */
#define TIMER0_COUNTER_RISING_EDGE()     (T0CONbits.T0SE=0)
/*for counter mode enable rising edge */
#define TIMER0_COUNTER_FALLING_EDGE()    (T0CONbits.T0SE=1)
/*enable prescaler int timer0 */
#define TIMER0_PRESCALER_ENABLE()        (T0CONbits.PSA=0)
/*disable prescaler int timer0 */
#define TIMER0_PRESCALER_DISABLE()        (T0CONbits.PSA=1)
/* Data types Declarations */
typedef enum {
  TIMER0_PRESCALER_DIV_2=0, 
  TIMER0_PRESCALER_DIV_4,
  TIMER0_PRESCALER_DIV_8,
  TIMER0_PRESCALER_DIV_16,
  TIMER0_PRESCALER_DIV_32, 
  TIMER0_PRESCALER_DIV_64,
  TIMER0_PRESCALER_DIV_128,
  TIMER0_PRESCALER_DIV_256,         
}timer0_prescaler_select_t;
typedef struct {
#if TIMER0_INTERRUPT_FEATURE==INTERRUPT_FREATUERE_ENABLE
    void(*TIMER0_HandlerInterrupt)(void);
#if  INTERRUPT_PRIORITY_LEVELS==INTERRUPT_FREATUERE_ENABLE
    interrupt_priority_t priority;
#endif
#endif
    timer0_prescaler_select_t _prescaler_value;
    uint16 timer0_preloaded_value;
    uint8 timer0_mode_register_size:1;
    uint8 timer0_mode_timer_or_counter:1;
    uint8 timer0_counter_edge:1;
    uint8 timer0_prescaler_enable:1;
    uint8 preserved_bits:4; 
}timer0_config_t;

/* Function Declarations*/
/**
 * @brief this routine initialize the timer0
 * @preconditions none 
 * @param _timer pointer  @ref timer0_config_t
 * @return 
 */
Std_ReturnType Timer0_Init(const timer0_config_t *_timer);
/**
 * @brief this routine disable the timer0
 * @preconditions none 
 * @param _timer pointer  @ref timer0_config_t
 * @return 
 */
Std_ReturnType Timer0_DeInit(const timer0_config_t *_timer);
/**
 * @brief this routine write in the register of timer0
 * @preconditions needs to call function Timer0_Init()
 * @param _timer pointer  @ref timer0_config_t
 * @param _value the value will write to register of the timer 
 * @return 
 */
Std_ReturnType Timer0_write_value(const timer0_config_t *_timer,uint16 _value);
/**
 * @brief this routine read in the register of timer0
 * @preconditions needs to call function Timer0_Init()
 * @param _timer pointer  @ref timer0_config_t
 * @param _value the value will read from register of the timer
 * @return 
 */
Std_ReturnType Timer0_read_value(const timer0_config_t *_timer,uint16 *_value);
#endif	/* HAL_TIMER0_H */

