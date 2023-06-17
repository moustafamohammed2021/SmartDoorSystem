/* 
 * File:   application.c
 * Author: MOUSTAFA
 *
 * Created on June 4, 2023, 9:17 PM
 */

#include "application.h"

/*
 * 
 */
volatile uint16 SessionCounter=0;//Counter The Interrupt of Timer1 every 10Milli Seconds 
uint8 BlockModeFlag=FALSE;//The Block Flag if User Input The Pass Wrong up To The Tries
uint8 PassTriesCount=0;//The Tries of Entering The Password
/**************The Main Function Entry Point Of The System ***************/
int main(void) {
    /*************************Initialization Of The Modules In The System*****************/
    ADCON1bits.PCFG=0x0F;
    keypad_initialize(&Keypad_Obj);//Initialize For The Keypad
    lcd_4bit_initialize(&Lcd_Obj);//Initialize For The Liquid Character Display
    dc_motor_initialize(&DC_Obj);//Intialize For The DC Motor Module
        /***************The Global Variables In The System******************/
    uint8 u8KeyPadPressed=NOT_PRESSED;//Store The Current Value of The Keypad
        /***********************Welcome Screen For The First Time***************************************/
    lcd_4bit_send_string_data(&Lcd_Obj,"Welcome to Smart");//Show The The First Message of Welcome The System
    set_cursor_4bit_mode(&Lcd_Obj,2,3);//Set The Cursor On The Second Row And The First Column 
    lcd_4bit_send_string_data(&Lcd_Obj,"Door System");
    _TimerDelay_ms(2000);//Halt The System For two Second
    lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
    /***********************Starting Of The System To Set The Password of The Guest And The Admin ***************/
         /**Check if The password Is set Or Not */
    if(PASS_SET !=u8PassIsSetOrNotSet(PASS_ADDRESS_STATUS)){
        lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
        lcd_4bit_send_string_data(&Lcd_Obj,"Login For The");//Show The Login For The First Time 
        set_cursor_4bit_mode(&Lcd_Obj,2,3);//Set The Cursor On The Second Row And The Third Column 
        lcd_4bit_send_string_data(&Lcd_Obj,"First Time");
        _TimerDelay_ms(2000);//Halt The System For two Second
        lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
        lcd_4bit_send_string_data(&Lcd_Obj,"Set Pass ");//Display Message To Set The Admin Pass
        set_cursor_4bit_mode(&Lcd_Obj,2,1);//Set The Cursor On The Second Row And The First Column 
        lcd_4bit_send_string_data(&Lcd_Obj,"The Pass :");//Display Message To Set The Admin Pass
        /*************************To Set The Password for The Admin And The Guest******************************/
        uint8 PassCounter=0;//Iterator For Setting The Password That Stored in The EEPROM
        uint8 Pass[PASS_SIZE]={NOT_STORD,NOT_STORD,NOT_STORD,NOT_STORD};//The Array That Stored The Password That The User will Enter
        while (PassCounter < PASS_SIZE){
            u8KeyPadPressed=NOT_PRESSED;
            while(u8KeyPadPressed == NOT_PRESSED){//Loop TO Make The user To Enter The Specific Password
                keypad_get_value(&Keypad_Obj,&u8KeyPadPressed);//Get The Value And Sore it In u8KeyPadPressed
            }
            Pass[PassCounter]=u8KeyPadPressed;//Store The Password In The Array of The Password
            lcd_4bit_send_char_data(&Lcd_Obj,u8KeyPadPressed);//Display The Character in The LCD
            _TimerDelay_ms(CHARACTER_REVIEW_TIME);//Halt The System For Half Second
            set_cursor_4bit_mode(&Lcd_Obj,2,11+PassCounter);//Set The Cursor On The Second Row And The Column in The Password Digit is In
            lcd_4bit_send_char_data(&Lcd_Obj,PASSWORD_SYMBOL);//Display The Character '*' in The LCD
            _TimerDelay_ms(50);//Halt The System Here for Given Time in Milli Seconds
            PassCounter++;//Increment The Pass Offset In LOOP
        }
        vWriteBlockOnEEPROM(PASS_ADDRESS,Pass,PASS_SIZE);//Store The Pass Array in EEPROM
        eeprom_WriteDataByte(PASS_ADDRESS_STATUS,PASS_SET);//Store in The Address That The Password Is Set (Indication)
        lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
        lcd_4bit_send_string_data(&Lcd_Obj,"Pass Saved");//Display Message To User That The Password Is Saved
        _TimerDelay_ms(1000);//Halt The System Here for Given Time in Milli Seconds
        }
    else {//Run Only When The Pass Is Set And Saved in The EEPROM
        BlockModeFlag=u8PassIsSetOrNotSet(BLOCK_PASS_ADDRESS_STATUS);//Read The Status of The Block Mode in The EEPROM
        lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
        lcd_4bit_send_string_data(&Lcd_Obj,"Set The Pass:");//Display The Mode Option To User
    }
    while(1){
        u8KeyPadPressed=NOT_PRESSED;
        uint8 PassCounter=0;//Iterator For Setting The Password That Stored in The EEPROM
        uint8 Pass[PASS_SIZE]={NOT_STORD,NOT_STORD,NOT_STORD,NOT_STORD};//The Array That Stored The Password That The User will Enter
        uint8 PassStored[PASS_SIZE]={NOT_STORD,NOT_STORD,NOT_STORD,NOT_STORD};//Array That Store The Pass Entered To check it with the Pass in EEPROM
        if(BlockModeFlag==TRUE){//if User Enter The Password Wrong upper The Allowed Tries
                lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
                lcd_4bit_send_string_data(&Lcd_Obj,"Login Blocked");//Display Message To User That The login Blocked
                set_cursor_4bit_mode(&Lcd_Obj,2,1);//Set The Cursor On The Second Row And The First Column
                lcd_4bit_send_string_data(&Lcd_Obj,"Wait 20 Seconds");//Display Message To User That Waiting 20 Seconds
                _TimerDelay_ms(BLOCK_MODE_TIME);//Halt The System Here for Given Time in Milli Seconds
                lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
                lcd_4bit_send_string_data(&Lcd_Obj,"Set The Pass:");//Display The Mode Option To User
                PassTriesCount=0;//Reset The Pass Tries
                BlockModeFlag=FALSE;//Return The Block Flag To Zero
                u8KeyPadPressed=NOT_PRESSED;//Put Keypad NOT_PRESSED
                eeprom_WriteDataByte(BLOCK_PASS_ADDRESS_STATUS,FALSE);//Put The Status Of The Block Mode That is Not BLocked
            }
        while (PassCounter < PASS_SIZE){
            u8KeyPadPressed=NOT_PRESSED;
            while(u8KeyPadPressed == NOT_PRESSED){//Loop TO Make The user To Enter The Specific Password
                keypad_get_value(&Keypad_Obj,&u8KeyPadPressed);//Get The Value And Sore it In u8KeyPadPressed
            }
            if((u8KeyPadPressed < '0') || (u8KeyPadPressed > '9') ){//Check if User Input Wrong Input
                lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
                lcd_4bit_send_string_data(&Lcd_Obj,"Wrong Input");//Display The Mode Option To User
                _TimerDelay_ms(1000);//Halt The System Here for Given Time in Milli Seconds
                lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
                lcd_4bit_send_string_data(&Lcd_Obj,"Set The Pass:");//Display The Mode Option To User
                PassCounter=0;//Reset The Pass Counter
                continue;//Return To The main Loop of PassCounter < PassSize
            }
            else {
                Pass[PassCounter]=u8KeyPadPressed;//Store The Pass In The Array To Check it Correct or Not
                lcd_4bit_send_char_data(&Lcd_Obj,u8KeyPadPressed);//Display The Character in The LCD
                _TimerDelay_ms(CHARACTER_REVIEW_TIME);//Halt The System For Half Second
                set_cursor_4bit_mode(&Lcd_Obj,1,14+PassCounter);//Set The Cursor On The Second Row And The Column in The Password Digit is In
                lcd_4bit_send_char_data(&Lcd_Obj,PASSWORD_SYMBOL);//Display The Character '*' in The LCD
                _TimerDelay_ms(100);//Halt The System Here for Given Time in Milli Seconds
                PassCounter++;//Increment The Pass Offset In LOOP
            } 
        }
         vReadBlockOnEEPROM(PASS_ADDRESS,PassStored,PASS_SIZE);//Store The Pass From EEPROM
        /*Check The Pass Is Correct Or Not */
         if(TRUE==u8ComparePass(PassStored,Pass,PASS_SIZE)){
                PassTriesCount=0;//Clear The Pass Tries If The User May Enter Wrong Pass
                lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
                lcd_4bit_send_string_data(&Lcd_Obj,"Correct Pass");//Display The Admin Mode To User
                _TimerDelay_ms(1000);//Halt The System Here for Given Time in Milli Seconds
                set_cursor_4bit_mode(&Lcd_Obj,2,1);//Set The Cursor In The Second Row And First Column
                lcd_4bit_send_string_data(&Lcd_Obj,"Wait until The Door");//Display The Correct Pass For The User
                set_cursor_4bit_mode(&Lcd_Obj,3,1);//Set The Cursor In The Second Row And First Column
                lcd_4bit_send_string_data(&Lcd_Obj,"Open And Close");//Display The Correct Pass For The User
                dc_motor_move_right(&DC_Obj);//Move The Motor Right
                _TimerDelay_ms(5000);//Halt The System Here for Given Time in Milli Seconds
                dc_motor_move_left(&DC_Obj);//Move The Motor Right
                _TimerDelay_ms(5000);//Halt The System Here for Given Time in Milli Seconds
                dc_motor_stop(&DC_Obj);//Stop The Motor
                lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
                lcd_4bit_send_string_data(&Lcd_Obj,"Set The Pass:");//Display The Mode Option To User
                }
        else if (FALSE==u8ComparePass(PassStored,Pass,PASS_SIZE)){
                PassTriesCount++;//Increment PassTries By on 
                lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
                lcd_4bit_send_string_data(&Lcd_Obj,"Wrong Pass");//Display Wrong Pass of The Admin Mode To User
                set_cursor_4bit_mode(&Lcd_Obj,2,1);//Set The Cursor In The Row2 And Column 1
                lcd_4bit_send_string_data(&Lcd_Obj,"Tries Left");//Display Wrong Pass of The Admin Mode To User
                lcd_4bit_send_char_data(&Lcd_Obj,TRIES_ALLOWD-PassTriesCount+ASSCI_ZERO);//Display The Tries Left
                 _TimerDelay_ms(1000);//Halt The System Here for Given Time in Milli Seconds
                lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
                lcd_4bit_send_string_data(&Lcd_Obj,"Set The Pass:");//Display The Mode Option To User
                if(PassTriesCount >= TRIES_ALLOWD){
                eeprom_WriteDataByte(BLOCK_PASS_ADDRESS_STATUS,TRUE);//Put The Status Of The Block Mode That is Not BLocked
                BlockModeFlag=TRUE;//Set The Block Mode To User
         }
       }                
    }
    return (0);
}




/********Helper Function TO Check if The Pass of the Guest And The Admin Is Set Or Not**********/
uint8 u8PassIsSetOrNotSet(uint16 Address){
    uint8 u8LocDataAdd;
    eeprom_ReadDataByte(Address,&u8LocDataAdd);
    return u8LocDataAdd;
}
/********Helper Function For Write Bytes in The EEPROM*************/
void vWriteBlockOnEEPROM(uint16 u16TheStartAddress,uint8 *Pass,uint8 Size){
    int LOC_Iterator=0;
    for(LOC_Iterator=0;LOC_Iterator<Size;LOC_Iterator++){
        eeprom_WriteDataByte((u16TheStartAddress +LOC_Iterator),*(Pass+LOC_Iterator));
    }
}
/********Helper Function For Read Bytes in The EEPROM*************/
void vReadBlockOnEEPROM(uint16 u16TheStartAddress,uint8 *Pass,uint8 Size){
    int LOC_Iterator=0;
    for(LOC_Iterator=0;LOC_Iterator<Size;LOC_Iterator++){
        eeprom_ReadDataByte((u16TheStartAddress +LOC_Iterator),(Pass+LOC_Iterator));
    }
}

uint8 u8ComparePass(const uint8 *Pass1,const uint8 *Pass2,uint8 Size){
    uint8 PassCounter=0;//The offset of The Array  
    uint8 PassFlag=TRUE;
    while(PassCounter < Size ){ //loop in The Array To Check in it 
        if(*(Pass1+PassCounter) != *(Pass2+PassCounter)){
            PassFlag=FALSE;//put The Flag False Indicate That The Pass is not true
            break;//break The Loop if on Element is not Equal to anther one  
        }
        PassCounter++;//Increment The Offset of The Array
    }
    return PassFlag;//return The Flag it may be True or False 
}