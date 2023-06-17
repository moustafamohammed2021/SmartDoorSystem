/* 
 * File:   mcal_interrupt_config.h
 * Author: MOUSTAFA
 *
 * Created on February 28, 2023, 5:31 AM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H


/* Section: Includes */
#include "mcal_interrupt_gen_config.h"
#include "../mcal_std_types.h"
#include <./pic18f4620.h>
#include"../GPIO/hal_gpio.h"


/* Section : Macros Declarations  */
#define INTERRUPT_ENABLE           1
#define INTERRUPT_DISABLE          0 
#define INTERRPT_OCCURE            1
#define INTERRUPT_NOT_OCCURE       0
#define INTERRUPT_PRIORITY_ENABLE  1
#define INTERRUPT_PRIORITY_DISABLE 0

/* Section : macros Function Declarations */
#if INTERRUPT_PRIORITY_LEVELS==INTERRUPT_FREATUERE_ENABLE
/*this macro will enable the priority of the interrupt*/
#define INTERRUPT_PRIORITY_LEVEVLS_ENABLE()  (RCONbits.IPEN=1)
/* this macro will disable the priority of the interrupt*/
#define INTERRUPT_PRIORITY_LEVEVLS_DISABLE()  (RCONbits.IPEN=0)


/* this macro will enable the high level of the interrupt*/
#define INTERRUPT_PRIORITY_HIGH_LEVEVL_ENABLE()  (INTCONbits.GIEH=1)
/* this macro will disable the high level of the interrupt*/
#define INTERRUPT_PRIORITY_HIGH_LEVEVL_DISABLE()  (INTCONbits.GIEH=0)

/* this macro will enable the low level of the interrupt*/
#define INTERRUPT_PRIORITY_LOW_LEVEVL_ENABLE()  (INTCONbits.GIEL=1)
/* this macro will disable the low level of the interrupt*/
#define INTERRUPT_PRIORITY_LOW_LEVEVL_DISABLE()  (INTCONbits.GIEL=0)
#else 
/* this macro enable the global interrupt if IPEN =0*/
#define INTERRUPT_GLOBAL_INTERRUPT_ENABLE()  (INTCONbits.GIE=1)
/* this macro disable the global interrupt if IPEN =0*/
#define INTERRUPT_GLOBAL_INTERRUPT_DISABLE()  (INTCONbits.GIE=0)

/* this macro enable the peripherals interrupt if IPEN =0*/
#define INTERRUPT_PERiPHERALS_INTERRUPT_ENABLE() (INTCONbits.PEIE=1)
/* this macro disable the peripherals interrupt if IPEN =0*/
#define INTERRUPT_PERiPHERALS_INTERRUPT_DISABLE() (INTCONbits.PEIE=0)

#endif 
/* Data types Declarations */
typedef enum {
    INTERRUPT_LOW_PRIORITY=0,
    INTERRUPT_HIGH_PRIORITY        
}interrupt_priority_t;
/* Function Declarations*/

#endif	/* MCAL_INTERRUPT_CONFIG_H */

