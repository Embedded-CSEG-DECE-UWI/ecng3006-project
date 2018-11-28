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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/groupcode.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/groupcode.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED="C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/busyxlcd.c" "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/openxlcd.c" "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/putrxlcd.c" "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/putsxlcd.c" "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/readaddr.c" "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/readdata.c" "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/setcgram.c" "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/setddram.c" "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/wcmdxlcd.c" "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/writdata.c" "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/menu2.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1978994463/busyxlcd.o ${OBJECTDIR}/_ext/1978994463/openxlcd.o ${OBJECTDIR}/_ext/1978994463/putrxlcd.o ${OBJECTDIR}/_ext/1978994463/putsxlcd.o ${OBJECTDIR}/_ext/1978994463/readaddr.o ${OBJECTDIR}/_ext/1978994463/readdata.o ${OBJECTDIR}/_ext/1978994463/setcgram.o ${OBJECTDIR}/_ext/1978994463/setddram.o ${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o ${OBJECTDIR}/_ext/1978994463/writdata.o ${OBJECTDIR}/_ext/1978994463/menu2.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1978994463/busyxlcd.o.d ${OBJECTDIR}/_ext/1978994463/openxlcd.o.d ${OBJECTDIR}/_ext/1978994463/putrxlcd.o.d ${OBJECTDIR}/_ext/1978994463/putsxlcd.o.d ${OBJECTDIR}/_ext/1978994463/readaddr.o.d ${OBJECTDIR}/_ext/1978994463/readdata.o.d ${OBJECTDIR}/_ext/1978994463/setcgram.o.d ${OBJECTDIR}/_ext/1978994463/setddram.o.d ${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o.d ${OBJECTDIR}/_ext/1978994463/writdata.o.d ${OBJECTDIR}/_ext/1978994463/menu2.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1978994463/busyxlcd.o ${OBJECTDIR}/_ext/1978994463/openxlcd.o ${OBJECTDIR}/_ext/1978994463/putrxlcd.o ${OBJECTDIR}/_ext/1978994463/putsxlcd.o ${OBJECTDIR}/_ext/1978994463/readaddr.o ${OBJECTDIR}/_ext/1978994463/readdata.o ${OBJECTDIR}/_ext/1978994463/setcgram.o ${OBJECTDIR}/_ext/1978994463/setddram.o ${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o ${OBJECTDIR}/_ext/1978994463/writdata.o ${OBJECTDIR}/_ext/1978994463/menu2.o

# Source Files
SOURCEFILES=C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/busyxlcd.c C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/openxlcd.c C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/putrxlcd.c C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/putsxlcd.c C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/readaddr.c C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/readdata.c C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/setcgram.c C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/setddram.c C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/wcmdxlcd.c C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/writdata.c C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/menu2.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/groupcode.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/1978994463/busyxlcd.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/busyxlcd.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/busyxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/openxlcd.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/openxlcd.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/openxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/putrxlcd.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/putrxlcd.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/putrxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/putsxlcd.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/putsxlcd.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/putsxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/readaddr.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/readaddr.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/readaddr.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/readdata.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/readdata.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/readdata.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/setcgram.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/setcgram.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/setcgram.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/setddram.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/setddram.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/setddram.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/wcmdxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/writdata.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/writdata.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/writdata.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/menu2.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/menu2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/menu2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/menu2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/menu2.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/menu2.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/menu2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/menu2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1978994463/busyxlcd.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/busyxlcd.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/busyxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/openxlcd.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/openxlcd.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/openxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/putrxlcd.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/putrxlcd.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/putrxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/putsxlcd.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/putsxlcd.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/putsxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/readaddr.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/readaddr.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/readaddr.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/readdata.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/readdata.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/readdata.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/setcgram.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/setcgram.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/setcgram.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/setddram.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/setddram.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/setddram.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/wcmdxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/writdata.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/writdata.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/writdata.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1978994463/menu2.o: C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/menu2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1978994463" 
	@${RM} ${OBJECTDIR}/_ext/1978994463/menu2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1978994463/menu2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1978994463/menu2.o   "C:/Users/amarp/Desktop/ECNG 3006/group project/ecng3006-project/groupcode/menu2.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1978994463/menu2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1978994463/menu2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/groupcode.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/lab1_i.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "C:\Users\amarp\Desktop\ECNG 3006\group project\ecng3006-project\groupcode\lab1_i.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_SIMULATOR=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/groupcode.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/groupcode.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   C:/Users/amarp/Desktop/ECNG\ 3006/group\ project/ecng3006-project/groupcode/lab1_i.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "C:\Users\amarp\Desktop\ECNG 3006\group project\ecng3006-project\groupcode\lab1_i.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/groupcode.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
