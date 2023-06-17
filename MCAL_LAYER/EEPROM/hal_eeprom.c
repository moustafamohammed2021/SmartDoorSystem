/* 
 * File:   hal_eeprom.c
 * Author: MOUSTAFA
 *
 * Created on March 2, 2023, 3:40 PM
 */
#include  "hal_eeprom.h"
/**
 * 
 * @brief function write data to specific address in the eeprom 
 * @param badd address of the data in the eeprom
 * @param data that will be written 
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
Std_ReturnType eeprom_WriteDataByte(uint16 badd,uint8 data){
      Std_ReturnType ret=E_OK;
      /*save the status of the interrupt before disable it*/
      uint8 interrupt_status=INTCONbits.GIE;
      /*write the address to the address register */
      EEADRH=(uint8)((badd >>8)&0x03);
      EEADR= (uint8)((badd)&0xFF); 
      /*write data to the data register */
      EEDATA=data;
      /*select access data eeprom memory(flash or eeprom ) EEPGD bit  */
      EECON1bits.EEPGD=ACCESS_EEPROM_DATA_MEMORY;
      /*access the data eeprom not(configuration bits)  CFGS bit */
      EECON1bits.CFGS=ACCESS_EEPROM_MEMORY;
      /*enable write bit to write data to eeprom   WREN bit */
      EECON1bits.WREN=WRITE_CYCLES_EEPROM;
      /*disable the global interrupt bit  */
      INTERRUPT_GLOBAL_INTERRUPT_DISABLE();
      /*write the sequence of 0x55 then 0xAA to EECON2 */
      EECON2=0x55;
      EECON2=0xAA;
      /*set wr bit to begin write */
      EECON1bits.WR=INITIATE_WRITE_ERASE;
      /*wait when the write finished */
      while(EECON1bits.WR);
      /*disable the wren bit  */
      EECON1bits.WREN=INHIBITS_CYCLES_EEPROM;
      /*restore the status of the interrupt */
      INTCONbits.GIE=interrupt_status;
      return ret;
}
/**
 * 
 * @brief read data to specific address in the eeprom 
 * @param badd address of the data in the eeprom
 * @param data that will be read
 * @return the status of the function 
 *          (E_OK) the function done successfully
 *           (E_NOT_OK) the function don't done successfully
 */
Std_ReturnType eeprom_ReadDataByte(uint16 badd, uint8 *data){
        Std_ReturnType ret=E_OK;
        if (NULL==data){
            ret=E_NOT_OK;
        }
        else {
     /*write the address to the address register */
      EEADRH=(uint8)((badd >>8)&0x03);
      EEADR= (uint8)((badd)&0xFF); 
      /*select access data eeprom memory(flash or eeprom ) EEPGD bit  */
      EECON1bits.EEPGD=ACCESS_EEPROM_DATA_MEMORY;
      /*access the data eeprom not(configuration bits)  CFGS bit */
      EECON1bits.CFGS=ACCESS_EEPROM_MEMORY;
      /*enable the rd bit*/
      EECON1bits.RD=START_READ_EANBLE;
      NOP();
      NOP();
      *data=EEDATA;
      ret=E_OK;
            
        }
      
      return ret;
}

