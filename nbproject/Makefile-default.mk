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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/GroupFProject.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/GroupFProject.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=C:/ECNG3006/Group_Project/GroupFProject/busyxlcd.c C:/ECNG3006/Group_Project/GroupFProject/openxlcd.c C:/ECNG3006/Group_Project/GroupFProject/putrxlcd.c C:/ECNG3006/Group_Project/GroupFProject/putsxlcd.c C:/ECNG3006/Group_Project/GroupFProject/readaddr.c C:/ECNG3006/Group_Project/GroupFProject/readdata.c C:/ECNG3006/Group_Project/GroupFProject/setcgram.c C:/ECNG3006/Group_Project/GroupFProject/setddram.c C:/ECNG3006/Group_Project/GroupFProject/wcmdxlcd.c C:/ECNG3006/Group_Project/GroupFProject/writdata.c C:/ECNG3006/Group_Project/GroupFProject/Source/3.IR_pulse_sensor_v3.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/805249261/busyxlcd.o ${OBJECTDIR}/_ext/805249261/openxlcd.o ${OBJECTDIR}/_ext/805249261/putrxlcd.o ${OBJECTDIR}/_ext/805249261/putsxlcd.o ${OBJECTDIR}/_ext/805249261/readaddr.o ${OBJECTDIR}/_ext/805249261/readdata.o ${OBJECTDIR}/_ext/805249261/setcgram.o ${OBJECTDIR}/_ext/805249261/setddram.o ${OBJECTDIR}/_ext/805249261/wcmdxlcd.o ${OBJECTDIR}/_ext/805249261/writdata.o ${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/805249261/busyxlcd.o.d ${OBJECTDIR}/_ext/805249261/openxlcd.o.d ${OBJECTDIR}/_ext/805249261/putrxlcd.o.d ${OBJECTDIR}/_ext/805249261/putsxlcd.o.d ${OBJECTDIR}/_ext/805249261/readaddr.o.d ${OBJECTDIR}/_ext/805249261/readdata.o.d ${OBJECTDIR}/_ext/805249261/setcgram.o.d ${OBJECTDIR}/_ext/805249261/setddram.o.d ${OBJECTDIR}/_ext/805249261/wcmdxlcd.o.d ${OBJECTDIR}/_ext/805249261/writdata.o.d ${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/805249261/busyxlcd.o ${OBJECTDIR}/_ext/805249261/openxlcd.o ${OBJECTDIR}/_ext/805249261/putrxlcd.o ${OBJECTDIR}/_ext/805249261/putsxlcd.o ${OBJECTDIR}/_ext/805249261/readaddr.o ${OBJECTDIR}/_ext/805249261/readdata.o ${OBJECTDIR}/_ext/805249261/setcgram.o ${OBJECTDIR}/_ext/805249261/setddram.o ${OBJECTDIR}/_ext/805249261/wcmdxlcd.o ${OBJECTDIR}/_ext/805249261/writdata.o ${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o

# Source Files
SOURCEFILES=C:/ECNG3006/Group_Project/GroupFProject/busyxlcd.c C:/ECNG3006/Group_Project/GroupFProject/openxlcd.c C:/ECNG3006/Group_Project/GroupFProject/putrxlcd.c C:/ECNG3006/Group_Project/GroupFProject/putsxlcd.c C:/ECNG3006/Group_Project/GroupFProject/readaddr.c C:/ECNG3006/Group_Project/GroupFProject/readdata.c C:/ECNG3006/Group_Project/GroupFProject/setcgram.c C:/ECNG3006/Group_Project/GroupFProject/setddram.c C:/ECNG3006/Group_Project/GroupFProject/wcmdxlcd.c C:/ECNG3006/Group_Project/GroupFProject/writdata.c C:/ECNG3006/Group_Project/GroupFProject/Source/3.IR_pulse_sensor_v3.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/GroupFProject.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/805249261/busyxlcd.o: C:/ECNG3006/Group_Project/GroupFProject/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/busyxlcd.o   C:/ECNG3006/Group_Project/GroupFProject/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/openxlcd.o: C:/ECNG3006/Group_Project/GroupFProject/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/openxlcd.o   C:/ECNG3006/Group_Project/GroupFProject/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/putrxlcd.o: C:/ECNG3006/Group_Project/GroupFProject/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/putrxlcd.o   C:/ECNG3006/Group_Project/GroupFProject/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/putsxlcd.o: C:/ECNG3006/Group_Project/GroupFProject/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/putsxlcd.o   C:/ECNG3006/Group_Project/GroupFProject/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/readaddr.o: C:/ECNG3006/Group_Project/GroupFProject/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/readaddr.o   C:/ECNG3006/Group_Project/GroupFProject/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/readdata.o: C:/ECNG3006/Group_Project/GroupFProject/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/readdata.o   C:/ECNG3006/Group_Project/GroupFProject/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/setcgram.o: C:/ECNG3006/Group_Project/GroupFProject/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/setcgram.o   C:/ECNG3006/Group_Project/GroupFProject/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/setddram.o: C:/ECNG3006/Group_Project/GroupFProject/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/setddram.o   C:/ECNG3006/Group_Project/GroupFProject/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/wcmdxlcd.o: C:/ECNG3006/Group_Project/GroupFProject/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/wcmdxlcd.o   C:/ECNG3006/Group_Project/GroupFProject/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/writdata.o: C:/ECNG3006/Group_Project/GroupFProject/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/writdata.o   C:/ECNG3006/Group_Project/GroupFProject/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o: C:/ECNG3006/Group_Project/GroupFProject/Source/3.IR_pulse_sensor_v3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1443285687" 
	@${RM} ${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o   C:/ECNG3006/Group_Project/GroupFProject/Source/3.IR_pulse_sensor_v3.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/805249261/busyxlcd.o: C:/ECNG3006/Group_Project/GroupFProject/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/busyxlcd.o   C:/ECNG3006/Group_Project/GroupFProject/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/openxlcd.o: C:/ECNG3006/Group_Project/GroupFProject/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/openxlcd.o   C:/ECNG3006/Group_Project/GroupFProject/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/putrxlcd.o: C:/ECNG3006/Group_Project/GroupFProject/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/putrxlcd.o   C:/ECNG3006/Group_Project/GroupFProject/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/putsxlcd.o: C:/ECNG3006/Group_Project/GroupFProject/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/putsxlcd.o   C:/ECNG3006/Group_Project/GroupFProject/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/readaddr.o: C:/ECNG3006/Group_Project/GroupFProject/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/readaddr.o   C:/ECNG3006/Group_Project/GroupFProject/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/readdata.o: C:/ECNG3006/Group_Project/GroupFProject/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/readdata.o   C:/ECNG3006/Group_Project/GroupFProject/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/setcgram.o: C:/ECNG3006/Group_Project/GroupFProject/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/setcgram.o   C:/ECNG3006/Group_Project/GroupFProject/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/setddram.o: C:/ECNG3006/Group_Project/GroupFProject/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/setddram.o   C:/ECNG3006/Group_Project/GroupFProject/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/wcmdxlcd.o: C:/ECNG3006/Group_Project/GroupFProject/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/wcmdxlcd.o   C:/ECNG3006/Group_Project/GroupFProject/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/805249261/writdata.o: C:/ECNG3006/Group_Project/GroupFProject/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/805249261" 
	@${RM} ${OBJECTDIR}/_ext/805249261/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/805249261/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/805249261/writdata.o   C:/ECNG3006/Group_Project/GroupFProject/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/805249261/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/805249261/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o: C:/ECNG3006/Group_Project/GroupFProject/Source/3.IR_pulse_sensor_v3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1443285687" 
	@${RM} ${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o   C:/ECNG3006/Group_Project/GroupFProject/Source/3.IR_pulse_sensor_v3.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1443285687/3.IR_pulse_sensor_v3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/GroupFProject.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/GroupFProject.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/GroupFProject.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/GroupFProject.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
