/* 
 * File:   hal_timer1.h
 * Author: MOUSTAFA
 *
 * Created on March 7, 2023, 4:40 AM
 */

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H

/* **************** Section: Includes **************** */
#include "../GPIO/hal_gpio.h"
#include "../mcal_std_types.h"
#include <./pic18f4620.h>
#include "../interrupt/mcal_internal_interrupt.h"

/**************** Section : Macros Declarations*****************/
/*enable timer1 */
#define TIMER1_MODULE_ENABLE_CFG     1
/*disable timer1 */
#define TIMER1_MODULE_DISABLE_CFG    0
/*timer1 timer_mode */
#define TIMER1_TIMER_MODE_CFG      0
/*timer1 counter_mode */
#define TIMER1_COUNTER_MODE_CFG    1
/*configure synchronization of the counter mode 1-for  synchronize  IF TMR1CS=1*/
#define TIMER1_COUNTER_MODE_SYNCHRONIZE_CFG      0
/*configure synchronization of the counter mode 1-for  asynchronize  IF TMR1CS=1*/
#define TIMER1_COUNTER_MODE_NOT_SYNCHRONIZE_CFG   1
/* TIMER1 oscillator enabled if using timer mode */
#define TIMER1_OSCILLATOR_ENABLE_CFG           1
/* TIMER1 oscillator diabled  if using timer mode */
#define TIMER1_OSCILLATOR_DISABLE_CFG          0
/* macros that define the pre-scaler of the timer1*/
#define TIMER1_INPUT_CLK_PRESCALER_DIV_1      0
#define TIMER1_INPUT_CLK_PRESCALER_DIV_2      1
#define TIMER1_INPUT_CLK_PRESCALER_DIV_4      2
#define TIMER1_INPUT_CLK_PRESCALER_DIV_8      3
/*enable the 8BIT wr mode two steps  */
#define TIMER1_8BIT_MODE_CFG      0
/*enable the 16BIT wr mode once */
#define TIMER1_16BIT_MODE_CFG      1
/**************** Section : macros Function Declarations************* */
/*macro enable timer1 */
#define TIMER1_MODULE_ENABLE()        (T1CONbits.TMR1ON=1)
/*macro disable timer1 */
#define TIMER1_MODULE_DISABLE()       (T1CONbits.TMR1ON=0)
/*timer1 timer_mode */
#define TIMER1_TIMER_MODE()           (T1CONbits.TMR1CS=0)
/*timer1 counter_mode */
#define TIMER1_COUNTER_MODE()          (T1CONbits.TMR1CS=1)
/*configure synchronization of the counter mode 1-for  synchronize  IF TMR1CS=1*/
#define TIMER1_COUNTER_MODE_SYNCHRONIZE()      (T1CONbits.T1SYNC=0)
/*configure synchronization of the counter mode 1-for  asynchronize  IF TMR1CS=1*/
#define TIMER1_COUNTER_MODE_NOT_SYNCHRONIZE()   (T1CONbits.T1SYNC=1)
/* TIMER1 oscillator enabled if using timer mode */
#define TIMER1_OSCILLATOR_ENABLE()           (T1CONbits.T1OSCEN=1)
/* TIMER1 oscillator diabled  if using timer mode */
#define TIMER1_OSCILLATOR_DISABLE()          (T1CONbits.T1OSCEN=0)
/* function like macros that select the pre-scaler of the timer1*/
#define TIMER1_INPUT_CLK_PRESCALER_REGISTER(_REGISTER)   (T1CONbits.T1CKPS=_REGISTER)
/*read if the MCU clock derived from timer1 oscillator or not */
#define TIMER1_OSCILLATOR_STATUS_BIT()      (T1CONbits.T1RUN)
/*enable the 8BIT wr mode two steps  */
#define TIMER1_8BIT_MODE()       (T1CONbits.RD16=0)
/*enable the 16BIT wr mode once */
#define TIMER1_16BIT_MODE()      (T1CONbits.RD16=1)


/***************** Data types Declarations *****************/
typedef struct {
 #if TIMER1_INTERRUPT_FEATURE==INTERRUPT_FREATUERE_ENABLE
    void(*TIMER1_HandlerInterrupt)(void);
#if  INTERRUPT_PRIORITY_LEVELS==INTERRUPT_FREATUERE_ENABLE
    interrupt_priority_t priority;
#endif
#endif
    uint16 preloaded_value;
    uint8 timer1_pre_scaler_val:2;
    uint8 timer1_mode_timer_or_counter :1;
    uint8 timer1_counter_mode_sync:1;
    uint8 timer1_oscillator_enable:1;
    uint8 timer1_mode_wr_reg:1; 
    uint8 preserved_bits:2;
}timer1_config_t;
/***************** Function Declarations*****************/
/**
 * @brief this routine initialize the timer1
 * @preconditions none 
 * @param _timer pointer  @ref timer1_config_t
 * @return 
 */
Std_ReturnType Timer1_Init(const timer1_config_t *_timer);
/**
 * @brief this routine disable the timer1
 * @preconditions none 
 * @param _timer pointer  @ref timer1_config_t
 * @return 
 */
Std_ReturnType Timer1_DeInit(const timer1_config_t *_timer);
/**
 * @brief this routine write in the register of timer0
 * @preconditions needs to call function Timer1_Init()
 * @param _timer pointer  @ref timer1_config_t
 * @param _value the value will write to register of the timer 
 * @return 
 */
Std_ReturnType Timer1_write_value(const timer1_config_t *_timer,uint16 _value);
/**
 * @brief this routine read in the register of timer0
 * @preconditions needs to call function Timer1_Init()
 * @param _timer pointer  @ref timer1_config_t
 * @param _value the value will read from register of the timer
 * @return 
 */
Std_ReturnType Timer1_read_value(const timer1_config_t *_timer,uint16 *_value);

#endif	/* HAL_TIMER1_H */

