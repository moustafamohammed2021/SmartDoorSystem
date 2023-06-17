/* 
 * File:   M_Delay.h
 * Author: MOUSTAFA
 *
 * Created on June 9, 2023, 3:14 AM
 */

#ifndef M_DELAY_H
#define	M_DELAY_H
/************************Includes*********************/

#include "../TIMER0/hal_timer0.h"

/**
 * Function Name : _TimerDelay_ms
 * Function Return : void
 * Function Description : This Function Halt System in Milli Seconds That the user Wanted 
 * @param _Delay
 */
void _TimerDelay_ms(uint16 u16CopyDelay);
/**
 * Function Name : _TimerDelay_ms
 * Function Return : void
 * Function Description : This Function Halt System in Micro Seconds That the user Wanted 
 * @param _Delay
 */
void _TimerDelay_us(uint32 u32CopyDelay);
#endif	/* M_DELAY_H */

