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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Group_Proj.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Group_Proj.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/main.c C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/pulseCounter.c C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/keypad.c C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/tempSense.c C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/speaker.c C:/Users/Aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/glucose.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1329427504/main.o ${OBJECTDIR}/_ext/1329427504/pulseCounter.o ${OBJECTDIR}/_ext/1329427504/keypad.o ${OBJECTDIR}/_ext/1329427504/tempSense.o ${OBJECTDIR}/_ext/1329427504/speaker.o ${OBJECTDIR}/_ext/541835344/glucose.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1329427504/main.o.d ${OBJECTDIR}/_ext/1329427504/pulseCounter.o.d ${OBJECTDIR}/_ext/1329427504/keypad.o.d ${OBJECTDIR}/_ext/1329427504/tempSense.o.d ${OBJECTDIR}/_ext/1329427504/speaker.o.d ${OBJECTDIR}/_ext/541835344/glucose.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1329427504/main.o ${OBJECTDIR}/_ext/1329427504/pulseCounter.o ${OBJECTDIR}/_ext/1329427504/keypad.o ${OBJECTDIR}/_ext/1329427504/tempSense.o ${OBJECTDIR}/_ext/1329427504/speaker.o ${OBJECTDIR}/_ext/541835344/glucose.o

# Source Files
SOURCEFILES=C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/main.c C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/pulseCounter.c C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/keypad.c C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/tempSense.c C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/speaker.c C:/Users/Aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/glucose.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Group_Proj.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/1329427504/main.o: C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329427504" 
	@${RM} ${OBJECTDIR}/_ext/1329427504/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329427504/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1329427504/main.o   C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1329427504/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1329427504/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1329427504/pulseCounter.o: C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/pulseCounter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329427504" 
	@${RM} ${OBJECTDIR}/_ext/1329427504/pulseCounter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329427504/pulseCounter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1329427504/pulseCounter.o   C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/pulseCounter.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1329427504/pulseCounter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1329427504/pulseCounter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1329427504/keypad.o: C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329427504" 
	@${RM} ${OBJECTDIR}/_ext/1329427504/keypad.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329427504/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1329427504/keypad.o   C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/keypad.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1329427504/keypad.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1329427504/keypad.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1329427504/tempSense.o: C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/tempSense.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329427504" 
	@${RM} ${OBJECTDIR}/_ext/1329427504/tempSense.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329427504/tempSense.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1329427504/tempSense.o   C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/tempSense.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1329427504/tempSense.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1329427504/tempSense.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1329427504/speaker.o: C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/speaker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329427504" 
	@${RM} ${OBJECTDIR}/_ext/1329427504/speaker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329427504/speaker.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1329427504/speaker.o   C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/speaker.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1329427504/speaker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1329427504/speaker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/541835344/glucose.o: C:/Users/Aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/glucose.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/541835344" 
	@${RM} ${OBJECTDIR}/_ext/541835344/glucose.o.d 
	@${RM} ${OBJECTDIR}/_ext/541835344/glucose.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/541835344/glucose.o   C:/Users/Aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/glucose.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/541835344/glucose.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/541835344/glucose.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1329427504/main.o: C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329427504" 
	@${RM} ${OBJECTDIR}/_ext/1329427504/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329427504/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1329427504/main.o   C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1329427504/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1329427504/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1329427504/pulseCounter.o: C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/pulseCounter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329427504" 
	@${RM} ${OBJECTDIR}/_ext/1329427504/pulseCounter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329427504/pulseCounter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1329427504/pulseCounter.o   C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/pulseCounter.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1329427504/pulseCounter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1329427504/pulseCounter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1329427504/keypad.o: C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329427504" 
	@${RM} ${OBJECTDIR}/_ext/1329427504/keypad.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329427504/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1329427504/keypad.o   C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/keypad.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1329427504/keypad.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1329427504/keypad.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1329427504/tempSense.o: C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/tempSense.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329427504" 
	@${RM} ${OBJECTDIR}/_ext/1329427504/tempSense.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329427504/tempSense.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1329427504/tempSense.o   C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/tempSense.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1329427504/tempSense.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1329427504/tempSense.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1329427504/speaker.o: C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/speaker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329427504" 
	@${RM} ${OBJECTDIR}/_ext/1329427504/speaker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329427504/speaker.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1329427504/speaker.o   C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/speaker.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1329427504/speaker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1329427504/speaker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/541835344/glucose.o: C:/Users/Aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/glucose.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/541835344" 
	@${RM} ${OBJECTDIR}/_ext/541835344/glucose.o.d 
	@${RM} ${OBJECTDIR}/_ext/541835344/glucose.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ml -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/541835344/glucose.o   C:/Users/Aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/glucose.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/541835344/glucose.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/541835344/glucose.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Group_Proj.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/lab1_i.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "C:\Users\aasif\Dropbox\Year_3\3006\Project\Group_Proj.X\lab1_i.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_SIMULATOR=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/Group_Proj.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/Group_Proj.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   C:/Users/aasif/Dropbox/Year_3/3006/Project/Group_Proj.X/lab1_i.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "C:\Users\aasif\Dropbox\Year_3\3006\Project\Group_Proj.X\lab1_i.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/Group_Proj.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
