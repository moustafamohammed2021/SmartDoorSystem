/* 
 * File:   hal_timer0.c
 * Author: MOUSTAFA
 *
 * Created on March 6, 2023, 7:20 AM
 */

#include "hal_timer0.h"

#if TIMER0_INTERRUPT_FEATURE==INTERRUPT_FREATUERE_ENABLE
static void(*TIMER0_interruptHandler)(void)=NULL;
#endif
static uint16 preload_timer=ZERO_INIT;
static inline void Timer0_prescaler_selcet(const timer0_config_t *_timer);
static inline void Timer0_mode_of_register_size_selcet(const timer0_config_t *_timer);
static inline void Timer0_mode_timer_or_counter_selcet(const timer0_config_t *_timer);

/**
 * @brief this routine initialize the timer0
 * @preconditions none 
 * @param _timer pointer  @ref timer0_config_t
 * @return 
 */
Std_ReturnType Timer0_Init(const timer0_config_t *_timer){
    Std_ReturnType ret=E_OK;
        if (NULL==_timer){
            ret=E_NOT_OK;
        }
        else {
            /*disable the timer0 module*/
            TIMER0_MODULE_DISABLE();
            /*configuration of the prescaler  */
            Timer0_prescaler_selcet(_timer);
           /*select the register size of the timer0 register*/
            Timer0_mode_of_register_size_selcet(_timer);
            /*select the mode of the timer (timer or counter ) and select the edge\
              if the mode is counter mode */
            Timer0_mode_timer_or_counter_selcet(_timer);
            /*write value to register of the timer */
            TMR0H=(_timer->timer0_preloaded_value) >> 8;
            TMR0L=(uint8)(_timer->timer0_preloaded_value);  
            
            /*enable the interrupt feature if you want to  enable it  */
            
 #if TIMER0_INTERRUPT_FEATURE==INTERRUPT_FREATUERE_ENABLE
      preload_timer=_timer->timer0_preloaded_value;
       TIMER0_INTERRUPT_ENABLE();
       TIMER0_FLAG_INTERRUPT_CLEAR();
#if  INTERRUPT_PRIORITY_LEVELS==INTERRUPT_FREATUERE_ENABLE
            INTERRUPT_PRIORITY_LEVEVLS_ENABLE();
     if (INTERRUPT_HIGH_PRIORITY==_timer->priority){
        INTERRUPT_PRIORITY_HIGH_LEVEVL_ENABLE();
             TIMER0_INTERRUPT_HIGHY_PRIORITY();
          }
    else if (INTERRUPT_LOW_PRIORITY==_timer->priority){
        INTERRUPT_PRIORITY_LOW_LEVEVL_ENABLE();
         TIMER0_INTERRUPT_LOW_PRIORITY();
         }
    else {/* nothing */}
#else 
            INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
            INTERRUPT_PERiPHERALS_INTERRUPT_ENABLE();
#endif
           TIMER0_interruptHandler =_timer->TIMER0_HandlerInterrupt;
#endif        
            
        /*enable the timer0 module */
            TIMER0_MODULE_ENABLE();
            ret=E_OK;
        }
    return ret; 
}
/**
 * @brief this routine disable the timer0
 * @preconditions none 
 * @param _timer pointer  @ref timer0_config_t
 * @return 
 */
Std_ReturnType Timer0_DeInit(const timer0_config_t *_timer){
   Std_ReturnType ret=E_OK;
        if (NULL==_timer){
            ret=E_NOT_OK;
        }
        else {
          TIMER0_MODULE_DISABLE();
 #if TIMER0_INTERRUPT_FEATURE==INTERRUPT_FREATUERE_ENABLE
   TIMER0_INTERRUPT_DISABLE();
#endif 
             ret=E_OK;
        }
    return ret; 
}
/**
 * @brief this routine write in the register of timer0
 * @preconditions needs to call function Timer0_Init()
 * @param _timer pointer  @ref timer0_config_t
 * @param _value the value will write to register of the timer 
 * @return 
 */
Std_ReturnType Timer0_write_value(const timer0_config_t *_timer,uint16 _value){
    Std_ReturnType ret=E_OK;
        if (NULL==_timer){
            ret=E_NOT_OK;
        }
        else {
            TMR0H=(_value) >> 8;
            TMR0L=(uint8)(_value);
            ret=E_OK;
        }
    return ret; 
}
/**
 * @brief this routine read in the register of timer0
 * @preconditions needs to call function Timer0_Init()
 * @param _timer pointer  @ref timer0_config_t
 * @param _value the value will read from register of the timer
 * @return 
 */
Std_ReturnType Timer0_read_value(const timer0_config_t *_timer,uint16 *_value){
    Std_ReturnType ret=E_OK;
    uint8 L_Read_low=ZERO_INIT,L_Read_high=ZERO_INIT;
        if ((NULL==_timer) || (NULL==_value)){
            ret=E_NOT_OK;
        }
        else {
            L_Read_low=TMR0L;
            L_Read_high=TMR0H;
            *_value=(uint16)((L_Read_high <<8 )+L_Read_low);
            ret=E_OK;
        }
    
    return ret; 
}

static inline void Timer0_prescaler_selcet(const timer0_config_t *_timer){
    if (TIMER0_PRESCALER_ENABLE_CFG==_timer->timer0_prescaler_enable){
        TIMER0_PRESCALER_ENABLE();
        T0CONbits.T0PS=_timer->_prescaler_value;
    }
    else if (TIMER0_PRESCALER_DISABLE_CFG==_timer->timer0_prescaler_enable){
        TIMER0_PRESCALER_DISABLE();
    }
    else {}
}

static inline void Timer0_mode_of_register_size_selcet(const timer0_config_t *_timer){
    if (TIMER0_8BIT_MODE_CFG==_timer->timer0_mode_register_size){
        TIMER0_8BIT_MODE_ENABLE();
    }
    else if (TIMER0_16BIT_MODE_CFG==_timer->timer0_mode_register_size){
      TIMER0_16BIT_MODE_ENABLE();
    }
     else {}
}

static inline void Timer0_mode_timer_or_counter_selcet(const timer0_config_t *_timer){
    if (TIMER0_TIMER_MODE_CFG==_timer->timer0_mode_timer_or_counter){
        TIMER0_TIMER_MODE_ENABLE();
    }
    else if (TIMER0_COUNTER_MODE_CFG==_timer->timer0_mode_timer_or_counter){
      TIMER0_COUNTER_MODE_ENABLE();
      if (TIMER0_COUNTER_RISING_EDGE_CFG==_timer->timer0_counter_edge){
          TIMER0_COUNTER_RISING_EDGE();
      }
      else if (TIMER0_COUNTER_FALLING_EDGE_CFG==_timer->timer0_counter_edge){
          TIMER0_COUNTER_FALLING_EDGE();
      }
          
    }
     else {}
}
#if TIMER0_INTERRUPT_FEATURE==INTERRUPT_FREATUERE_ENABLE
void TIMER0_ISR(void){
    /*clear the flag */
    TIMER0_FLAG_INTERRUPT_CLEAR();
    TMR0H=(preload_timer) >> 8;
    TMR0L=(uint8)(preload_timer);
    if (TIMER0_interruptHandler){
        TIMER0_interruptHandler();
    }
}
#endif