/* 
 * File:   MainConfig.h
 * Author: MOUSTAFA
 *
 * Created on June 14, 2023, 10:47 AM
 */

#ifndef MAINCONFIG_H
#define	MAINCONFIG_H

/* Section : Macros Declarations  */
#define NOT_STORD    0XFF
#define NOT_SELECTED 0XFF

#define CHARACTER_REVIEW_TIME (uint16)300
#define BLOCK_MODE_TIME       (uint32)20000

/***********************PIN Configuration****************************************/
#define PASS_SIZE  (uint8)4
#define TRIES_ALLOWD (uint8)3
#define PASSWORD_SYMBOL (uint8)'*'
#define ASSCI_ZERO (uint8)'0'

/***********************Configuration For The Password **************************/
#define PASS_NOT_SET  (uint8)0XFF
#define PASS_SET      (uint8)0X00

#define PASS_ADDRESS               (uint16)0X0000
#define PASS_ADDRESS_STATUS        (uint16)0X0005
#define BLOCK_PASS_ADDRESS_STATUS  (uint16)0X0006
/***********Logic Configuration ****************/
#define FALSE (uint8)0
#define TRUE  (uint8)1

#define LOGIN_TIMEOUT (uint16)3000


#define NOT_PRESSED 0XFF


#endif	/* MAINCONFIG_H */

