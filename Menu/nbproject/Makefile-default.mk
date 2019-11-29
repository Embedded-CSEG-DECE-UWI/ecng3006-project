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
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Menu.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Menu.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HRV.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HeartRate.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/LCD.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/Speaker.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/Temperature.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/busyxlcd.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/keypad.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/mainfile.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/openxlcd.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/putrxlcd.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/putsxlcd.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/readaddr.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/readdata.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/setcgram.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/setddram.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/wcmdxlcd.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/writdata.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HRVandGlucose.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/914006711/HRV.o ${OBJECTDIR}/_ext/914006711/HeartRate.o ${OBJECTDIR}/_ext/914006711/LCD.o ${OBJECTDIR}/_ext/914006711/Speaker.o ${OBJECTDIR}/_ext/914006711/Temperature.o ${OBJECTDIR}/_ext/914006711/busyxlcd.o ${OBJECTDIR}/_ext/914006711/keypad.o ${OBJECTDIR}/_ext/914006711/mainfile.o ${OBJECTDIR}/_ext/914006711/openxlcd.o ${OBJECTDIR}/_ext/914006711/putrxlcd.o ${OBJECTDIR}/_ext/914006711/putsxlcd.o ${OBJECTDIR}/_ext/914006711/readaddr.o ${OBJECTDIR}/_ext/914006711/readdata.o ${OBJECTDIR}/_ext/914006711/setcgram.o ${OBJECTDIR}/_ext/914006711/setddram.o ${OBJECTDIR}/_ext/914006711/wcmdxlcd.o ${OBJECTDIR}/_ext/914006711/writdata.o ${OBJECTDIR}/_ext/914006711/HRVandGlucose.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/914006711/HRV.o.d ${OBJECTDIR}/_ext/914006711/HeartRate.o.d ${OBJECTDIR}/_ext/914006711/LCD.o.d ${OBJECTDIR}/_ext/914006711/Speaker.o.d ${OBJECTDIR}/_ext/914006711/Temperature.o.d ${OBJECTDIR}/_ext/914006711/busyxlcd.o.d ${OBJECTDIR}/_ext/914006711/keypad.o.d ${OBJECTDIR}/_ext/914006711/mainfile.o.d ${OBJECTDIR}/_ext/914006711/openxlcd.o.d ${OBJECTDIR}/_ext/914006711/putrxlcd.o.d ${OBJECTDIR}/_ext/914006711/putsxlcd.o.d ${OBJECTDIR}/_ext/914006711/readaddr.o.d ${OBJECTDIR}/_ext/914006711/readdata.o.d ${OBJECTDIR}/_ext/914006711/setcgram.o.d ${OBJECTDIR}/_ext/914006711/setddram.o.d ${OBJECTDIR}/_ext/914006711/wcmdxlcd.o.d ${OBJECTDIR}/_ext/914006711/writdata.o.d ${OBJECTDIR}/_ext/914006711/HRVandGlucose.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/914006711/HRV.o ${OBJECTDIR}/_ext/914006711/HeartRate.o ${OBJECTDIR}/_ext/914006711/LCD.o ${OBJECTDIR}/_ext/914006711/Speaker.o ${OBJECTDIR}/_ext/914006711/Temperature.o ${OBJECTDIR}/_ext/914006711/busyxlcd.o ${OBJECTDIR}/_ext/914006711/keypad.o ${OBJECTDIR}/_ext/914006711/mainfile.o ${OBJECTDIR}/_ext/914006711/openxlcd.o ${OBJECTDIR}/_ext/914006711/putrxlcd.o ${OBJECTDIR}/_ext/914006711/putsxlcd.o ${OBJECTDIR}/_ext/914006711/readaddr.o ${OBJECTDIR}/_ext/914006711/readdata.o ${OBJECTDIR}/_ext/914006711/setcgram.o ${OBJECTDIR}/_ext/914006711/setddram.o ${OBJECTDIR}/_ext/914006711/wcmdxlcd.o ${OBJECTDIR}/_ext/914006711/writdata.o ${OBJECTDIR}/_ext/914006711/HRVandGlucose.o

# Source Files
SOURCEFILES=C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HRV.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HeartRate.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/LCD.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/Speaker.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/Temperature.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/busyxlcd.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/keypad.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/mainfile.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/openxlcd.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/putrxlcd.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/putsxlcd.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/readaddr.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/readdata.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/setcgram.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/setddram.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/wcmdxlcd.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/writdata.c C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HRVandGlucose.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Menu.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F452
MP_PROCESSOR_OPTION_LD=18f452
MP_LINKER_DEBUG_OPTION=-r=ROM@0x7DC0:0x7FFF -r=RAM@GPR:0x5F4:0x5FF -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/914006711/HRV.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HRV.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/HRV.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/HRV.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/HRV.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HRV.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/HRV.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/HRV.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/HeartRate.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HeartRate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/HeartRate.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/HeartRate.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/HeartRate.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HeartRate.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/HeartRate.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/HeartRate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/LCD.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/LCD.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/LCD.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/Speaker.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/Speaker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/Speaker.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/Speaker.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/Speaker.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/Speaker.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/Speaker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/Speaker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/Temperature.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/Temperature.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/Temperature.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/Temperature.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/Temperature.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/Temperature.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/Temperature.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/Temperature.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/busyxlcd.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/busyxlcd.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/keypad.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/keypad.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/keypad.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/keypad.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/keypad.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/keypad.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/mainfile.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/mainfile.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/mainfile.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/mainfile.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/mainfile.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/mainfile.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/mainfile.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/mainfile.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/openxlcd.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/openxlcd.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/putrxlcd.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/putrxlcd.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/putsxlcd.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/putsxlcd.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/readaddr.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/readaddr.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/readdata.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/readdata.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/setcgram.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/setcgram.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/setddram.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/setddram.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/wcmdxlcd.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/wcmdxlcd.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/writdata.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/writdata.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/HRVandGlucose.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HRVandGlucose.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/HRVandGlucose.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/HRVandGlucose.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/HRVandGlucose.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HRVandGlucose.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/HRVandGlucose.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/HRVandGlucose.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/914006711/HRV.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HRV.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/HRV.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/HRV.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/HRV.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HRV.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/HRV.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/HRV.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/HeartRate.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HeartRate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/HeartRate.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/HeartRate.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/HeartRate.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HeartRate.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/HeartRate.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/HeartRate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/LCD.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/LCD.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/LCD.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/Speaker.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/Speaker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/Speaker.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/Speaker.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/Speaker.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/Speaker.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/Speaker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/Speaker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/Temperature.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/Temperature.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/Temperature.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/Temperature.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/Temperature.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/Temperature.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/Temperature.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/Temperature.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/busyxlcd.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/busyxlcd.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/keypad.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/keypad.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/keypad.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/keypad.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/keypad.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/keypad.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/mainfile.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/mainfile.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/mainfile.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/mainfile.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/mainfile.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/mainfile.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/mainfile.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/mainfile.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/openxlcd.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/openxlcd.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/putrxlcd.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/putrxlcd.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/putsxlcd.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/putsxlcd.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/readaddr.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/readaddr.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/readdata.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/readdata.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/setcgram.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/setcgram.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/setddram.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/setddram.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/wcmdxlcd.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/wcmdxlcd.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/writdata.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/writdata.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/914006711/HRVandGlucose.o: C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HRVandGlucose.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/914006711" 
	@${RM} ${OBJECTDIR}/_ext/914006711/HRVandGlucose.o.d 
	@${RM} ${OBJECTDIR}/_ext/914006711/HRVandGlucose.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/914006711/HRVandGlucose.o   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/HRVandGlucose.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/914006711/HRVandGlucose.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/914006711/HRVandGlucose.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Menu.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/lab1_i.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "C:\MPLabXProjects\Group_Project\ecng3006-project\Menu\lab1_i.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/Menu.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/Menu.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   C:/MPLabXProjects/Group_Project/ecng3006-project/Menu/lab1_i.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "C:\MPLabXProjects\Group_Project\ecng3006-project\Menu\lab1_i.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/Menu.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
