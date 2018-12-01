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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/integrate2_2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/integrate2_2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=C:/Users/Abigail/MPLABXProjects/integrate2_2/busyxlcd.c C:/Users/Abigail/MPLABXProjects/integrate2_2/openxlcd.c C:/Users/Abigail/MPLABXProjects/integrate2_2/please.c C:/Users/Abigail/MPLABXProjects/integrate2_2/putrxlcd.c C:/Users/Abigail/MPLABXProjects/integrate2_2/putsxlcd.c C:/Users/Abigail/MPLABXProjects/integrate2_2/readaddr.c C:/Users/Abigail/MPLABXProjects/integrate2_2/readdata.c C:/Users/Abigail/MPLABXProjects/integrate2_2/setcgram.c C:/Users/Abigail/MPLABXProjects/integrate2_2/setddram.c C:/Users/Abigail/MPLABXProjects/integrate2_2/t0close.c C:/Users/Abigail/MPLABXProjects/integrate2_2/t0open.c C:/Users/Abigail/MPLABXProjects/integrate2_2/t0read.c C:/Users/Abigail/MPLABXProjects/integrate2_2/t0write.c C:/Users/Abigail/MPLABXProjects/integrate2_2/wcmdxlcd.c C:/Users/Abigail/MPLABXProjects/integrate2_2/writdata.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/869029182/busyxlcd.o ${OBJECTDIR}/_ext/869029182/openxlcd.o ${OBJECTDIR}/_ext/869029182/please.o ${OBJECTDIR}/_ext/869029182/putrxlcd.o ${OBJECTDIR}/_ext/869029182/putsxlcd.o ${OBJECTDIR}/_ext/869029182/readaddr.o ${OBJECTDIR}/_ext/869029182/readdata.o ${OBJECTDIR}/_ext/869029182/setcgram.o ${OBJECTDIR}/_ext/869029182/setddram.o ${OBJECTDIR}/_ext/869029182/t0close.o ${OBJECTDIR}/_ext/869029182/t0open.o ${OBJECTDIR}/_ext/869029182/t0read.o ${OBJECTDIR}/_ext/869029182/t0write.o ${OBJECTDIR}/_ext/869029182/wcmdxlcd.o ${OBJECTDIR}/_ext/869029182/writdata.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/869029182/busyxlcd.o.d ${OBJECTDIR}/_ext/869029182/openxlcd.o.d ${OBJECTDIR}/_ext/869029182/please.o.d ${OBJECTDIR}/_ext/869029182/putrxlcd.o.d ${OBJECTDIR}/_ext/869029182/putsxlcd.o.d ${OBJECTDIR}/_ext/869029182/readaddr.o.d ${OBJECTDIR}/_ext/869029182/readdata.o.d ${OBJECTDIR}/_ext/869029182/setcgram.o.d ${OBJECTDIR}/_ext/869029182/setddram.o.d ${OBJECTDIR}/_ext/869029182/t0close.o.d ${OBJECTDIR}/_ext/869029182/t0open.o.d ${OBJECTDIR}/_ext/869029182/t0read.o.d ${OBJECTDIR}/_ext/869029182/t0write.o.d ${OBJECTDIR}/_ext/869029182/wcmdxlcd.o.d ${OBJECTDIR}/_ext/869029182/writdata.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/869029182/busyxlcd.o ${OBJECTDIR}/_ext/869029182/openxlcd.o ${OBJECTDIR}/_ext/869029182/please.o ${OBJECTDIR}/_ext/869029182/putrxlcd.o ${OBJECTDIR}/_ext/869029182/putsxlcd.o ${OBJECTDIR}/_ext/869029182/readaddr.o ${OBJECTDIR}/_ext/869029182/readdata.o ${OBJECTDIR}/_ext/869029182/setcgram.o ${OBJECTDIR}/_ext/869029182/setddram.o ${OBJECTDIR}/_ext/869029182/t0close.o ${OBJECTDIR}/_ext/869029182/t0open.o ${OBJECTDIR}/_ext/869029182/t0read.o ${OBJECTDIR}/_ext/869029182/t0write.o ${OBJECTDIR}/_ext/869029182/wcmdxlcd.o ${OBJECTDIR}/_ext/869029182/writdata.o

# Source Files
SOURCEFILES=C:/Users/Abigail/MPLABXProjects/integrate2_2/busyxlcd.c C:/Users/Abigail/MPLABXProjects/integrate2_2/openxlcd.c C:/Users/Abigail/MPLABXProjects/integrate2_2/please.c C:/Users/Abigail/MPLABXProjects/integrate2_2/putrxlcd.c C:/Users/Abigail/MPLABXProjects/integrate2_2/putsxlcd.c C:/Users/Abigail/MPLABXProjects/integrate2_2/readaddr.c C:/Users/Abigail/MPLABXProjects/integrate2_2/readdata.c C:/Users/Abigail/MPLABXProjects/integrate2_2/setcgram.c C:/Users/Abigail/MPLABXProjects/integrate2_2/setddram.c C:/Users/Abigail/MPLABXProjects/integrate2_2/t0close.c C:/Users/Abigail/MPLABXProjects/integrate2_2/t0open.c C:/Users/Abigail/MPLABXProjects/integrate2_2/t0read.c C:/Users/Abigail/MPLABXProjects/integrate2_2/t0write.c C:/Users/Abigail/MPLABXProjects/integrate2_2/wcmdxlcd.c C:/Users/Abigail/MPLABXProjects/integrate2_2/writdata.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/integrate2_2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/869029182/busyxlcd.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/busyxlcd.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/openxlcd.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/openxlcd.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/please.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/please.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/please.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/please.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/please.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/please.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/please.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/please.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/putrxlcd.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/putrxlcd.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/putsxlcd.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/putsxlcd.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/readaddr.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/readaddr.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/readdata.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/readdata.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/setcgram.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/setcgram.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/setddram.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/setddram.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/t0close.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/t0close.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0close.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0close.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/t0close.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/t0close.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/t0close.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/t0close.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/t0open.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/t0open.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0open.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0open.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/t0open.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/t0open.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/t0open.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/t0open.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/t0read.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/t0read.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0read.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0read.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/t0read.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/t0read.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/t0read.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/t0read.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/t0write.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/t0write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0write.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0write.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/t0write.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/t0write.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/t0write.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/t0write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/wcmdxlcd.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/wcmdxlcd.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/writdata.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/writdata.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/869029182/busyxlcd.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/busyxlcd.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/openxlcd.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/openxlcd.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/please.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/please.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/please.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/please.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/please.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/please.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/please.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/please.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/putrxlcd.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/putrxlcd.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/putsxlcd.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/putsxlcd.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/readaddr.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/readaddr.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/readdata.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/readdata.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/setcgram.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/setcgram.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/setddram.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/setddram.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/t0close.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/t0close.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0close.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0close.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/t0close.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/t0close.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/t0close.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/t0close.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/t0open.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/t0open.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0open.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0open.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/t0open.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/t0open.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/t0open.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/t0open.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/t0read.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/t0read.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0read.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0read.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/t0read.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/t0read.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/t0read.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/t0read.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/t0write.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/t0write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0write.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/t0write.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/t0write.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/t0write.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/t0write.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/t0write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/wcmdxlcd.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/wcmdxlcd.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/869029182/writdata.o: C:/Users/Abigail/MPLABXProjects/integrate2_2/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869029182" 
	@${RM} ${OBJECTDIR}/_ext/869029182/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/869029182/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Users/Abigail/MPLABXProjects/integrate2_2" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/869029182/writdata.o   C:/Users/Abigail/MPLABXProjects/integrate2_2/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/869029182/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/869029182/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/integrate2_2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/integrate2_2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/integrate2_2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/integrate2_2.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
