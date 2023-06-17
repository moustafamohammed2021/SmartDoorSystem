#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/SmartDoorBasedOn_Pic18f4620.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/SmartDoorBasedOn_Pic18f4620.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=application.c ECUAL_LAYER/char_lcd/ecu_char_lcd.c ECUAL_LAYER/DC_Motor/ecu_motor.c ECUAL_LAYER/key_pad/ecu_keypad.c MCAL_LAYER/Delay/M_Delay.c MCAL_LAYER/device_config.c MCAL_LAYER/EEPROM/hal_eeprom.c MCAL_LAYER/GPIO/hal_gpio.c MCAL_LAYER/interrupt/mcal_internal_interrupt.c MCAL_LAYER/interrupt/mcal_interrupt_manager.c MCAL_LAYER/TIMER0/hal_timer0.c MCAL_LAYER/TIMER1/hal_timer1.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/application.p1 ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1 ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1 ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1 ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1 ${OBJECTDIR}/MCAL_LAYER/device_config.p1 ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/application.p1.d ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1.d ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1.d ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1.d ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1.d ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/application.p1 ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1 ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1 ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1 ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1 ${OBJECTDIR}/MCAL_LAYER/device_config.p1 ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1

# Source Files
SOURCEFILES=application.c ECUAL_LAYER/char_lcd/ecu_char_lcd.c ECUAL_LAYER/DC_Motor/ecu_motor.c ECUAL_LAYER/key_pad/ecu_keypad.c MCAL_LAYER/Delay/M_Delay.c MCAL_LAYER/device_config.c MCAL_LAYER/EEPROM/hal_eeprom.c MCAL_LAYER/GPIO/hal_gpio.c MCAL_LAYER/interrupt/mcal_internal_interrupt.c MCAL_LAYER/interrupt/mcal_interrupt_manager.c MCAL_LAYER/TIMER0/hal_timer0.c MCAL_LAYER/TIMER1/hal_timer1.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/SmartDoorBasedOn_Pic18f4620.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1: ECUAL_LAYER/char_lcd/ecu_char_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_LAYER/char_lcd" 
	@${RM} ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1 ECUAL_LAYER/char_lcd/ecu_char_lcd.c 
	@-${MV} ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.d ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1: ECUAL_LAYER/DC_Motor/ecu_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_LAYER/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1 ECUAL_LAYER/DC_Motor/ecu_motor.c 
	@-${MV} ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.d ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1: ECUAL_LAYER/key_pad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_LAYER/key_pad" 
	@${RM} ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1 ECUAL_LAYER/key_pad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.d ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1: MCAL_LAYER/Delay/M_Delay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Delay" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1 MCAL_LAYER/Delay/M_Delay.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.d ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/device_config.p1: MCAL_LAYER/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/device_config.p1 MCAL_LAYER/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/device_config.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1: MCAL_LAYER/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 MCAL_LAYER/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1: MCAL_LAYER/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 MCAL_LAYER/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1: MCAL_LAYER/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1 MCAL_LAYER/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1: MCAL_LAYER/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1 MCAL_LAYER/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1: MCAL_LAYER/TIMER0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1 MCAL_LAYER/TIMER0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.d ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1: MCAL_LAYER/TIMER1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1 MCAL_LAYER/TIMER1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.d ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1: ECUAL_LAYER/char_lcd/ecu_char_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_LAYER/char_lcd" 
	@${RM} ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1 ECUAL_LAYER/char_lcd/ecu_char_lcd.c 
	@-${MV} ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.d ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_LAYER/char_lcd/ecu_char_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1: ECUAL_LAYER/DC_Motor/ecu_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_LAYER/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1 ECUAL_LAYER/DC_Motor/ecu_motor.c 
	@-${MV} ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.d ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_LAYER/DC_Motor/ecu_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1: ECUAL_LAYER/key_pad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_LAYER/key_pad" 
	@${RM} ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1 ECUAL_LAYER/key_pad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.d ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_LAYER/key_pad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1: MCAL_LAYER/Delay/M_Delay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Delay" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1 MCAL_LAYER/Delay/M_Delay.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.d ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Delay/M_Delay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/device_config.p1: MCAL_LAYER/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/device_config.p1 MCAL_LAYER/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/device_config.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1: MCAL_LAYER/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 MCAL_LAYER/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1: MCAL_LAYER/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 MCAL_LAYER/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1: MCAL_LAYER/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1 MCAL_LAYER/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1: MCAL_LAYER/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1 MCAL_LAYER/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1: MCAL_LAYER/TIMER0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1 MCAL_LAYER/TIMER0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.d ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1: MCAL_LAYER/TIMER1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1 MCAL_LAYER/TIMER1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.d ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/SmartDoorBasedOn_Pic18f4620.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/SmartDoorBasedOn_Pic18f4620.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/SmartDoorBasedOn_Pic18f4620.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/SmartDoorBasedOn_Pic18f4620.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/SmartDoorBasedOn_Pic18f4620.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/SmartDoorBasedOn_Pic18f4620.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/SmartDoorBasedOn_Pic18f4620.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
