/* 
 * File:   M_Delay.h
 * Author: MOUSTAFA
 *
 * Created on June 9, 2023, 3:14 AM
 */
#include "M_Delay.h"
volatile uint16 u16DelayCounter=0;
void Timer0Interrupt(void);

/* Configure Timer0*/
timer0_config_t TimerDelay={.TIMER0_HandlerInterrupt=Timer0Interrupt,
                            ._prescaler_value=TIMER0_PRESCALER_DIV_2,
                            .timer0_mode_register_size=TIMER0_16BIT_MODE_CFG,
                            .timer0_mode_timer_or_counter=TIMER0_TIMER_MODE_CFG,
                            .timer0_preloaded_value=65436,
                            .timer0_prescaler_enable=TIMER0_PRESCALER_ENABLE_CFG};


void _TimerDelay_ms(uint16 u16CopyDelay){
    Timer0_Init(&TimerDelay);//Initialize The Timer0
    while(u16DelayCounter!=u16CopyDelay);//Compare The Value To Achieve The Delay
    if(u16DelayCounter==u16CopyDelay){
        u16DelayCounter=0;
    }
    Timer0_DeInit(&TimerDelay);//Stop The Timer0
}

void _TimerDelay_us(uint32 u32CopyDelay){//Initialize The Timer0
    Timer0_Init(&TimerDelay);
    u32CopyDelay=(u32CopyDelay/1000);
    while(u16DelayCounter!=u32CopyDelay);//Compare The Value To Achieve The Delay
    if(u16DelayCounter==u32CopyDelay){
        u16DelayCounter=0;
    }
    Timer0_DeInit(&TimerDelay);//Stop The Timer0
}


void Timer0Interrupt(void){
    u16DelayCounter++;//Increment Every 1 Milli Second
}