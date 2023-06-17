/* 
 * File:   hal_eeprom.h
 * Author: MOUSTAFA
 *
 * Created on March 2, 2023, 3:40 PM
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H
/* Section : Includes  */
#include "../mcal_std_types.h"
#include <./pic18f4620.h>
#include "../interrupt/mcal_interrupt_config.h"

/* Section : Macros Declarations  */
/*falsh or eeprom*/
#define ACCESS_FALSH_PROGRAM_MEMORY  1
#define ACCESS_EEPROM_DATA_MEMORY    0
/*configuration bit or EEPROM MAEMORY*/
#define CONFIGURATION_BITS_ACCESS    1
#define ACCESS_EEPROM_MEMORY         0
/*enable write cycles or stop it */
#define WRITE_CYCLES_EEPROM          1
#define INHIBITS_CYCLES_EEPROM       0
/*start write cycle*/
#define INITIATE_WRITE_ERASE         1
/*enable read bit */
#define START_READ_EANBLE                  1
/* Section : macros Function Declarations */

/* Data types Declarations */

/* Function Declarations*/

/**
 * 
 * @brief function write data to specific address in the eeprom 
 * @param badd address of the data in the eeprom
 * @param data that will be written 
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
Std_ReturnType eeprom_WriteDataByte(uint16 badd,uint8 data);
/**
 * 
 * @brief read data to specific address in the eeprom 
 * @param badd address of the data in the eeprom
 * @param data that will be read    
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
Std_ReturnType eeprom_ReadDataByte(uint16 badd, uint8 *data);
#endif	/* HAL_EEPROM_H */

