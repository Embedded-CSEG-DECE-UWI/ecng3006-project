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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/heartrate.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/keypad.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/main.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/speaker.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/temperature.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/DelayFunctions.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/busyxlcd.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/openxlcd.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/putrxlcd.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/putsxlcd.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/readaddr.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/readdata.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/setcgram.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/setddram.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/wcmdxlcd.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/writdata.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2close.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2open.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2read.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2write.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1close.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1open.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1setdc.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1setoc.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0close.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0open.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0read.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0write.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1close.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1open.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1read.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1write.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1177338910/heartrate.o ${OBJECTDIR}/_ext/1177338910/keypad.o ${OBJECTDIR}/_ext/1177338910/main.o ${OBJECTDIR}/_ext/1177338910/speaker.o ${OBJECTDIR}/_ext/1177338910/temperature.o ${OBJECTDIR}/_ext/1177338910/DelayFunctions.o ${OBJECTDIR}/_ext/1177338910/busyxlcd.o ${OBJECTDIR}/_ext/1177338910/openxlcd.o ${OBJECTDIR}/_ext/1177338910/putrxlcd.o ${OBJECTDIR}/_ext/1177338910/putsxlcd.o ${OBJECTDIR}/_ext/1177338910/readaddr.o ${OBJECTDIR}/_ext/1177338910/readdata.o ${OBJECTDIR}/_ext/1177338910/setcgram.o ${OBJECTDIR}/_ext/1177338910/setddram.o ${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o ${OBJECTDIR}/_ext/1177338910/writdata.o ${OBJECTDIR}/_ext/1177338910/t2close.o ${OBJECTDIR}/_ext/1177338910/t2open.o ${OBJECTDIR}/_ext/1177338910/t2read.o ${OBJECTDIR}/_ext/1177338910/t2write.o ${OBJECTDIR}/_ext/1177338910/pw1close.o ${OBJECTDIR}/_ext/1177338910/pw1open.o ${OBJECTDIR}/_ext/1177338910/pw1setdc.o ${OBJECTDIR}/_ext/1177338910/pw1setoc.o ${OBJECTDIR}/_ext/1177338910/t0close.o ${OBJECTDIR}/_ext/1177338910/t0open.o ${OBJECTDIR}/_ext/1177338910/t0read.o ${OBJECTDIR}/_ext/1177338910/t0write.o ${OBJECTDIR}/_ext/1177338910/t1close.o ${OBJECTDIR}/_ext/1177338910/t1open.o ${OBJECTDIR}/_ext/1177338910/t1read.o ${OBJECTDIR}/_ext/1177338910/t1write.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1177338910/heartrate.o.d ${OBJECTDIR}/_ext/1177338910/keypad.o.d ${OBJECTDIR}/_ext/1177338910/main.o.d ${OBJECTDIR}/_ext/1177338910/speaker.o.d ${OBJECTDIR}/_ext/1177338910/temperature.o.d ${OBJECTDIR}/_ext/1177338910/DelayFunctions.o.d ${OBJECTDIR}/_ext/1177338910/busyxlcd.o.d ${OBJECTDIR}/_ext/1177338910/openxlcd.o.d ${OBJECTDIR}/_ext/1177338910/putrxlcd.o.d ${OBJECTDIR}/_ext/1177338910/putsxlcd.o.d ${OBJECTDIR}/_ext/1177338910/readaddr.o.d ${OBJECTDIR}/_ext/1177338910/readdata.o.d ${OBJECTDIR}/_ext/1177338910/setcgram.o.d ${OBJECTDIR}/_ext/1177338910/setddram.o.d ${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o.d ${OBJECTDIR}/_ext/1177338910/writdata.o.d ${OBJECTDIR}/_ext/1177338910/t2close.o.d ${OBJECTDIR}/_ext/1177338910/t2open.o.d ${OBJECTDIR}/_ext/1177338910/t2read.o.d ${OBJECTDIR}/_ext/1177338910/t2write.o.d ${OBJECTDIR}/_ext/1177338910/pw1close.o.d ${OBJECTDIR}/_ext/1177338910/pw1open.o.d ${OBJECTDIR}/_ext/1177338910/pw1setdc.o.d ${OBJECTDIR}/_ext/1177338910/pw1setoc.o.d ${OBJECTDIR}/_ext/1177338910/t0close.o.d ${OBJECTDIR}/_ext/1177338910/t0open.o.d ${OBJECTDIR}/_ext/1177338910/t0read.o.d ${OBJECTDIR}/_ext/1177338910/t0write.o.d ${OBJECTDIR}/_ext/1177338910/t1close.o.d ${OBJECTDIR}/_ext/1177338910/t1open.o.d ${OBJECTDIR}/_ext/1177338910/t1read.o.d ${OBJECTDIR}/_ext/1177338910/t1write.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1177338910/heartrate.o ${OBJECTDIR}/_ext/1177338910/keypad.o ${OBJECTDIR}/_ext/1177338910/main.o ${OBJECTDIR}/_ext/1177338910/speaker.o ${OBJECTDIR}/_ext/1177338910/temperature.o ${OBJECTDIR}/_ext/1177338910/DelayFunctions.o ${OBJECTDIR}/_ext/1177338910/busyxlcd.o ${OBJECTDIR}/_ext/1177338910/openxlcd.o ${OBJECTDIR}/_ext/1177338910/putrxlcd.o ${OBJECTDIR}/_ext/1177338910/putsxlcd.o ${OBJECTDIR}/_ext/1177338910/readaddr.o ${OBJECTDIR}/_ext/1177338910/readdata.o ${OBJECTDIR}/_ext/1177338910/setcgram.o ${OBJECTDIR}/_ext/1177338910/setddram.o ${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o ${OBJECTDIR}/_ext/1177338910/writdata.o ${OBJECTDIR}/_ext/1177338910/t2close.o ${OBJECTDIR}/_ext/1177338910/t2open.o ${OBJECTDIR}/_ext/1177338910/t2read.o ${OBJECTDIR}/_ext/1177338910/t2write.o ${OBJECTDIR}/_ext/1177338910/pw1close.o ${OBJECTDIR}/_ext/1177338910/pw1open.o ${OBJECTDIR}/_ext/1177338910/pw1setdc.o ${OBJECTDIR}/_ext/1177338910/pw1setoc.o ${OBJECTDIR}/_ext/1177338910/t0close.o ${OBJECTDIR}/_ext/1177338910/t0open.o ${OBJECTDIR}/_ext/1177338910/t0read.o ${OBJECTDIR}/_ext/1177338910/t0write.o ${OBJECTDIR}/_ext/1177338910/t1close.o ${OBJECTDIR}/_ext/1177338910/t1open.o ${OBJECTDIR}/_ext/1177338910/t1read.o ${OBJECTDIR}/_ext/1177338910/t1write.o

# Source Files
SOURCEFILES=C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/heartrate.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/keypad.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/main.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/speaker.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/temperature.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/DelayFunctions.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/busyxlcd.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/openxlcd.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/putrxlcd.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/putsxlcd.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/readaddr.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/readdata.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/setcgram.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/setddram.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/wcmdxlcd.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/writdata.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2close.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2open.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2read.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2write.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1close.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1open.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1setdc.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1setoc.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0close.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0open.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0read.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0write.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1close.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1open.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1read.c C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1write.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F452
MP_PROCESSOR_OPTION_LD=18f452
MP_LINKER_DEBUG_OPTION=  -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1177338910/heartrate.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/heartrate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/heartrate.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/heartrate.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/heartrate.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/heartrate.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/heartrate.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/heartrate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/keypad.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/keypad.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/keypad.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/keypad.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/keypad.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/keypad.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/main.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/main.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/speaker.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/speaker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/speaker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/speaker.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/speaker.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/speaker.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/speaker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/speaker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/temperature.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/temperature.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/temperature.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/temperature.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/temperature.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/temperature.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/temperature.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/temperature.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/DelayFunctions.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/DelayFunctions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/DelayFunctions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/DelayFunctions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/DelayFunctions.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/DelayFunctions.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/DelayFunctions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/DelayFunctions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/busyxlcd.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/busyxlcd.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/openxlcd.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/openxlcd.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/putrxlcd.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/putrxlcd.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/putsxlcd.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/putsxlcd.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/readaddr.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/readaddr.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/readdata.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/readdata.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/setcgram.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/setcgram.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/setddram.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/setddram.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/writdata.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/writdata.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t2close.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2close.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2close.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2close.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t2close.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2close.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t2close.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t2close.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t2open.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2open.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2open.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2open.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t2open.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2open.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t2open.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t2open.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t2read.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2read.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2read.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2read.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t2read.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2read.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t2read.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t2read.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t2write.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2write.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2write.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t2write.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2write.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t2write.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t2write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/pw1close.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1close.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1close.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1close.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/pw1close.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1close.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/pw1close.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/pw1close.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/pw1open.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1open.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1open.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1open.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/pw1open.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1open.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/pw1open.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/pw1open.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/pw1setdc.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1setdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1setdc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1setdc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/pw1setdc.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1setdc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/pw1setdc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/pw1setdc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/pw1setoc.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1setoc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1setoc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1setoc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/pw1setoc.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1setoc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/pw1setoc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/pw1setoc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t0close.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0close.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0close.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0close.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t0close.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0close.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t0close.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t0close.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t0open.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0open.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0open.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0open.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t0open.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0open.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t0open.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t0open.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t0read.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0read.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0read.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0read.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t0read.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0read.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t0read.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t0read.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t0write.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0write.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0write.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t0write.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0write.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t0write.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t0write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t1close.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1close.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1close.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1close.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t1close.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1close.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t1close.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t1close.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t1open.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1open.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1open.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1open.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t1open.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1open.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t1open.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t1open.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t1read.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1read.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1read.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1read.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t1read.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1read.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t1read.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t1read.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t1write.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1write.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1write.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t1write.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1write.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t1write.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t1write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1177338910/heartrate.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/heartrate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/heartrate.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/heartrate.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/heartrate.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/heartrate.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/heartrate.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/heartrate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/keypad.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/keypad.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/keypad.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/keypad.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/keypad.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/keypad.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/main.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/main.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/speaker.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/speaker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/speaker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/speaker.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/speaker.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/speaker.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/speaker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/speaker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/temperature.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/temperature.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/temperature.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/temperature.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/temperature.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/temperature.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/temperature.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/temperature.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/DelayFunctions.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/DelayFunctions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/DelayFunctions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/DelayFunctions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/DelayFunctions.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/DelayFunctions.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/DelayFunctions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/DelayFunctions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/busyxlcd.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/busyxlcd.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/openxlcd.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/openxlcd.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/putrxlcd.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/putrxlcd.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/putsxlcd.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/putsxlcd.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/readaddr.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/readaddr.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/readdata.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/readdata.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/setcgram.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/setcgram.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/setddram.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/setddram.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/writdata.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/writdata.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t2close.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2close.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2close.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2close.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t2close.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2close.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t2close.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t2close.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t2open.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2open.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2open.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2open.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t2open.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2open.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t2open.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t2open.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t2read.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2read.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2read.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2read.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t2read.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2read.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t2read.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t2read.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t2write.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2write.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t2write.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t2write.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t2write.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t2write.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t2write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/pw1close.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1close.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1close.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1close.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/pw1close.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1close.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/pw1close.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/pw1close.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/pw1open.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1open.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1open.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1open.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/pw1open.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1open.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/pw1open.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/pw1open.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/pw1setdc.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1setdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1setdc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1setdc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/pw1setdc.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1setdc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/pw1setdc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/pw1setdc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/pw1setoc.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1setoc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1setoc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/pw1setoc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/pw1setoc.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/pw1setoc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/pw1setoc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/pw1setoc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t0close.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0close.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0close.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0close.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t0close.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0close.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t0close.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t0close.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t0open.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0open.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0open.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0open.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t0open.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0open.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t0open.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t0open.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t0read.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0read.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0read.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0read.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t0read.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0read.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t0read.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t0read.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t0write.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0write.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t0write.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t0write.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t0write.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t0write.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t0write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t1close.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1close.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1close.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1close.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t1close.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1close.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t1close.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t1close.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t1open.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1open.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1open.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1open.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t1open.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1open.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t1open.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t1open.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t1read.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1read.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1read.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1read.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t1read.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1read.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t1read.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t1read.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1177338910/t1write.o: C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1177338910" 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1write.o.d 
	@${RM} ${OBJECTDIR}/_ext/1177338910/t1write.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1177338910/t1write.o   C:/Users/vasis/Documents/ECNG3006/ecng3006-project2/t1write.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1177338910/t1write.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1177338910/t1write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_SIMULATOR=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project2.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
