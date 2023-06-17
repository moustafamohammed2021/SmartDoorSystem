/* 
 * File:   hal_timer1.c
 * Author: MOUSTAFA
 *
 * Created on March 7, 2023, 4:40 AM
 */
#include "hal_timer1.h"
#if TIMER1_INTERRUPT_FEATURE==INTERRUPT_FREATUERE_ENABLE
static void(*TIMER1_interruptHandler)(void)=NULL;
#endif
static inline void timer1_select_mode_timer_or_counter(const timer1_config_t *_timer);
static inline void timer1_oscillator_enable(const timer1_config_t *_timer);
static inline void timer1_select_reg_mode(const timer1_config_t *_timer);

static uint16 preload_timer1=ZERO_INIT;
/**
 * @brief this routine initialize the timer1
 * @preconditions none 
 * @param _timer pointer  @ref timer1_config_t
 * @return 
 */
Std_ReturnType Timer1_Init(const timer1_config_t *_timer){
    Std_ReturnType ret=E_OK;
        if (NULL==_timer){
            ret=E_NOT_OK;
        }
        else {
            /*disable timer1 */
            TIMER1_MODULE_DISABLE();
            /*define the pre_scaler_value*/
            TIMER1_INPUT_CLK_PRESCALER_REGISTER(_timer->timer1_pre_scaler_val);
            /*configure if timer1 timer mode or counter mode and configure the synchronization of \
                                           counter mode */
            timer1_select_mode_timer_or_counter(_timer);
            /*enable the clock oscillator of timer1 */
            timer1_oscillator_enable(_timer);
            /*select the mode of the wr register */
            timer1_select_reg_mode(_timer);
            /*write the pre-loaded value  */
            TMR1H=(_timer->preloaded_value) >>8;
            TMR1L=(uint8)(_timer->preloaded_value);
            preload_timer1=_timer->preloaded_value;
            /*enable the timer1 interrupt*/
#if TIMER1_INTERRUPT_FEATURE==INTERRUPT_FREATUERE_ENABLE
       TIMER1_INTERRUPT_ENABLE();
       TIMER1_FLAG_INTERRUPT_CLEAR();
#if  INTERRUPT_PRIORITY_LEVELS==INTERRUPT_FREATUERE_ENABLE
            INTERRUPT_PRIORITY_LEVEVLS_ENABLE();
     if (INTERRUPT_HIGH_PRIORITY==_timer->priority){
        INTERRUPT_PRIORITY_HIGH_LEVEVL_ENABLE();
             TIMER1_INTERRUPT_HIGHY_PRIORITY();
          }
    else if (INTERRUPT_LOW_PRIORITY==_timer->priority){
        INTERRUPT_PRIORITY_LOW_LEVEVL_ENABLE();
         TIMER1_INTERRUPT_LOW_PRIORITY();
         }
    else {/* nothing */}
#else 
            INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
            INTERRUPT_PERiPHERALS_INTERRUPT_ENABLE();
#endif
           TIMER1_interruptHandler =_timer->TIMER1_HandlerInterrupt;
#endif        
            /*enable timer1*/
            TIMER1_MODULE_ENABLE();
            ret=E_OK;
            
        }
    return ret;
}
/**
 * @brief this routine disable the timer1
 * @preconditions none 
 * @param _timer pointer  @ref timer1_config_t
 * @return 
 */
Std_ReturnType Timer1_DeInit(const timer1_config_t *_timer){
   Std_ReturnType ret=E_OK;
        if (NULL==_timer){
            ret=E_NOT_OK;
        }
        else {
            /*disable timer1 */
            TIMER1_MODULE_DISABLE();
#if TIMER1_INTERRUPT_FEATURE==INTERRUPT_FREATUERE_ENABLE
   TIMER1_INTERRUPT_DISABLE();
#endif 
          ret=E_OK;  
        }
    return ret;
}
/**
 * @brief this routine write in the register of timer0
 * @preconditions needs to call function Timer1_Init()
 * @param _timer pointer  @ref timer1_config_t
 * @param _value the value will write to register of the timer 
 * @return 
 */
Std_ReturnType Timer1_write_value(const timer1_config_t *_timer,uint16 _value){
   Std_ReturnType ret=E_OK;
        if (NULL==_timer){
            ret=E_NOT_OK;
        }
        else {
            TMR1H=(_value) >> 8;
            TMR1L=(uint8)(_value);
            ret=E_OK;
        }
    return ret;
}
/**
 * @brief this routine read in the register of timer0
 * @preconditions needs to call function Timer1_Init()
 * @param _timer pointer  @ref timer1_config_t
 * @param _value the value will read from register of the timer
 * @return 
 */
Std_ReturnType Timer1_read_value(const timer1_config_t *_timer,uint16 *_value){
    Std_ReturnType ret=E_OK;
     uint8 L_Read_low=ZERO_INIT,L_Read_high=ZERO_INIT;
        if ((NULL==_timer) || (NULL==_value)){
            ret=E_NOT_OK;
        }
        else {
            L_Read_low=TMR1L;
            L_Read_high=TMR1H;
            *_value=(uint16)((L_Read_high <<8 )+L_Read_low);
            ret=E_OK;            
        }
    return ret;
}

static inline void timer1_select_mode_timer_or_counter(const timer1_config_t *_timer){
    if (TIMER1_TIMER_MODE_CFG==_timer->timer1_mode_timer_or_counter){
        TIMER1_TIMER_MODE();
    }
    else if (TIMER1_COUNTER_MODE_CFG==_timer->timer1_mode_timer_or_counter){
        TIMER1_COUNTER_MODE();
        if (TIMER1_COUNTER_MODE_SYNCHRONIZE_CFG ==_timer->timer1_counter_mode_sync){
            TIMER1_COUNTER_MODE_SYNCHRONIZE();
        }
        else if (TIMER1_COUNTER_MODE_NOT_SYNCHRONIZE_CFG==_timer->timer1_counter_mode_sync){
            TIMER1_COUNTER_MODE_NOT_SYNCHRONIZE();
        }
        else {/*NOTHING*/}
    }
    else {/*NOTHING*/}
}
static inline void timer1_oscillator_enable(const timer1_config_t *_timer){
    if (TIMER1_OSCILLATOR_ENABLE_CFG==_timer->timer1_oscillator_enable){
        TIMER1_OSCILLATOR_ENABLE();
    }
    else if(TIMER1_OSCILLATOR_DISABLE_CFG==_timer->timer1_oscillator_enable) {
        TIMER1_OSCILLATOR_DISABLE();
    }
    else {/*NOTHING*/}
    
}
static inline void timer1_select_reg_mode(const timer1_config_t *_timer){
    if (TIMER1_8BIT_MODE_CFG==_timer->timer1_mode_wr_reg){
        TIMER1_8BIT_MODE();
    }
    else if (TIMER1_16BIT_MODE_CFG==_timer->timer1_mode_wr_reg){
        TIMER1_16BIT_MODE();
    }
     else {/*NOTHING*/}
}
#if TIMER1_INTERRUPT_FEATURE==INTERRUPT_FREATUERE_ENABLE
void TIMER1_ISR(void){
    /*clear the flag */
    TIMER1_FLAG_INTERRUPT_CLEAR();
    TMR1H=(preload_timer1) >>8;
    TMR1L=(uint8)(preload_timer1);
    if (TIMER1_interruptHandler){
        TIMER1_interruptHandler();
    }
}
#endif