/* 
 * File:   mcal_interrupt_manager.h
 * Author: MOUSTAFA
 *
 * Created on February 28, 2023, 5:30 AM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H


/* Section: Includes */
#include "mcal_interrupt_config.h"


/* Section : Macros Declarations  */

/* Section : macros Function Declarations */

/* Data types Declarations */

/* Function Declarations*/

#if TIMER0_INTERRUPT_FEATURE==INTERRUPT_FREATUERE_ENABLE 
    void TIMER0_ISR(void);
 #endif
#if TIMER1_INTERRUPT_FEATURE==INTERRUPT_FREATUERE_ENABLE 
    void TIMER1_ISR(void);
 #endif

#endif	/* MCAL_INTERRUPT_MANAGER_H */

