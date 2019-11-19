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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/keypad1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/keypad1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=F:/ECNG3006/Group_Project/keypad1/openxlcd.c F:/ECNG3006/Group_Project/keypad1/putrxlcd.c F:/ECNG3006/Group_Project/keypad1/putsxlcd.c F:/ECNG3006/Group_Project/keypad1/readaddr.c F:/ECNG3006/Group_Project/keypad1/readdata.c F:/ECNG3006/Group_Project/keypad1/setcgram.c F:/ECNG3006/Group_Project/keypad1/setddram.c F:/ECNG3006/Group_Project/keypad1/wcmdxlcd.c F:/ECNG3006/Group_Project/keypad1/writdata.c F:/ECNG3006/Group_Project/keypad1/busyxlcd.c F:/ECNG3006/Group_Project/keypad1/lab1lcd.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1255283963/openxlcd.o ${OBJECTDIR}/_ext/1255283963/putrxlcd.o ${OBJECTDIR}/_ext/1255283963/putsxlcd.o ${OBJECTDIR}/_ext/1255283963/readaddr.o ${OBJECTDIR}/_ext/1255283963/readdata.o ${OBJECTDIR}/_ext/1255283963/setcgram.o ${OBJECTDIR}/_ext/1255283963/setddram.o ${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o ${OBJECTDIR}/_ext/1255283963/writdata.o ${OBJECTDIR}/_ext/1255283963/busyxlcd.o ${OBJECTDIR}/_ext/1255283963/lab1lcd.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1255283963/openxlcd.o.d ${OBJECTDIR}/_ext/1255283963/putrxlcd.o.d ${OBJECTDIR}/_ext/1255283963/putsxlcd.o.d ${OBJECTDIR}/_ext/1255283963/readaddr.o.d ${OBJECTDIR}/_ext/1255283963/readdata.o.d ${OBJECTDIR}/_ext/1255283963/setcgram.o.d ${OBJECTDIR}/_ext/1255283963/setddram.o.d ${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o.d ${OBJECTDIR}/_ext/1255283963/writdata.o.d ${OBJECTDIR}/_ext/1255283963/busyxlcd.o.d ${OBJECTDIR}/_ext/1255283963/lab1lcd.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1255283963/openxlcd.o ${OBJECTDIR}/_ext/1255283963/putrxlcd.o ${OBJECTDIR}/_ext/1255283963/putsxlcd.o ${OBJECTDIR}/_ext/1255283963/readaddr.o ${OBJECTDIR}/_ext/1255283963/readdata.o ${OBJECTDIR}/_ext/1255283963/setcgram.o ${OBJECTDIR}/_ext/1255283963/setddram.o ${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o ${OBJECTDIR}/_ext/1255283963/writdata.o ${OBJECTDIR}/_ext/1255283963/busyxlcd.o ${OBJECTDIR}/_ext/1255283963/lab1lcd.o

# Source Files
SOURCEFILES=F:/ECNG3006/Group_Project/keypad1/openxlcd.c F:/ECNG3006/Group_Project/keypad1/putrxlcd.c F:/ECNG3006/Group_Project/keypad1/putsxlcd.c F:/ECNG3006/Group_Project/keypad1/readaddr.c F:/ECNG3006/Group_Project/keypad1/readdata.c F:/ECNG3006/Group_Project/keypad1/setcgram.c F:/ECNG3006/Group_Project/keypad1/setddram.c F:/ECNG3006/Group_Project/keypad1/wcmdxlcd.c F:/ECNG3006/Group_Project/keypad1/writdata.c F:/ECNG3006/Group_Project/keypad1/busyxlcd.c F:/ECNG3006/Group_Project/keypad1/lab1lcd.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/keypad1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/1255283963/openxlcd.o: F:/ECNG3006/Group_Project/keypad1/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/openxlcd.o   F:/ECNG3006/Group_Project/keypad1/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/putrxlcd.o: F:/ECNG3006/Group_Project/keypad1/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/putrxlcd.o   F:/ECNG3006/Group_Project/keypad1/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/putsxlcd.o: F:/ECNG3006/Group_Project/keypad1/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/putsxlcd.o   F:/ECNG3006/Group_Project/keypad1/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/readaddr.o: F:/ECNG3006/Group_Project/keypad1/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/readaddr.o   F:/ECNG3006/Group_Project/keypad1/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/readdata.o: F:/ECNG3006/Group_Project/keypad1/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/readdata.o   F:/ECNG3006/Group_Project/keypad1/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/setcgram.o: F:/ECNG3006/Group_Project/keypad1/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/setcgram.o   F:/ECNG3006/Group_Project/keypad1/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/setddram.o: F:/ECNG3006/Group_Project/keypad1/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/setddram.o   F:/ECNG3006/Group_Project/keypad1/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o: F:/ECNG3006/Group_Project/keypad1/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o   F:/ECNG3006/Group_Project/keypad1/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/writdata.o: F:/ECNG3006/Group_Project/keypad1/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/writdata.o   F:/ECNG3006/Group_Project/keypad1/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/busyxlcd.o: F:/ECNG3006/Group_Project/keypad1/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/busyxlcd.o   F:/ECNG3006/Group_Project/keypad1/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/lab1lcd.o: F:/ECNG3006/Group_Project/keypad1/lab1lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/lab1lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/lab1lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/lab1lcd.o   F:/ECNG3006/Group_Project/keypad1/lab1lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/lab1lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/lab1lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1255283963/openxlcd.o: F:/ECNG3006/Group_Project/keypad1/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/openxlcd.o   F:/ECNG3006/Group_Project/keypad1/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/putrxlcd.o: F:/ECNG3006/Group_Project/keypad1/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/putrxlcd.o   F:/ECNG3006/Group_Project/keypad1/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/putsxlcd.o: F:/ECNG3006/Group_Project/keypad1/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/putsxlcd.o   F:/ECNG3006/Group_Project/keypad1/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/readaddr.o: F:/ECNG3006/Group_Project/keypad1/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/readaddr.o   F:/ECNG3006/Group_Project/keypad1/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/readdata.o: F:/ECNG3006/Group_Project/keypad1/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/readdata.o   F:/ECNG3006/Group_Project/keypad1/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/setcgram.o: F:/ECNG3006/Group_Project/keypad1/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/setcgram.o   F:/ECNG3006/Group_Project/keypad1/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/setddram.o: F:/ECNG3006/Group_Project/keypad1/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/setddram.o   F:/ECNG3006/Group_Project/keypad1/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o: F:/ECNG3006/Group_Project/keypad1/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o   F:/ECNG3006/Group_Project/keypad1/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/writdata.o: F:/ECNG3006/Group_Project/keypad1/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/writdata.o   F:/ECNG3006/Group_Project/keypad1/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/busyxlcd.o: F:/ECNG3006/Group_Project/keypad1/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/busyxlcd.o   F:/ECNG3006/Group_Project/keypad1/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1255283963/lab1lcd.o: F:/ECNG3006/Group_Project/keypad1/lab1lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1255283963" 
	@${RM} ${OBJECTDIR}/_ext/1255283963/lab1lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255283963/lab1lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1255283963/lab1lcd.o   F:/ECNG3006/Group_Project/keypad1/lab1lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1255283963/lab1lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1255283963/lab1lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/keypad1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    F:/ECNG3006/Group_Project/keypad1/lab1_i.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "F:\ECNG3006\Group_Project\keypad1\lab1_i.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_SIMULATOR=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/keypad1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/keypad1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   F:/ECNG3006/Group_Project/keypad1/lab1_i.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "F:\ECNG3006\Group_Project\keypad1\lab1_i.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/keypad1.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
