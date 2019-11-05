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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=main.c list.c queue.c tasks.c heap_4.c port.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/list.o ${OBJECTDIR}/queue.o ${OBJECTDIR}/tasks.o ${OBJECTDIR}/heap_4.o ${OBJECTDIR}/port.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/list.o.d ${OBJECTDIR}/queue.o.d ${OBJECTDIR}/tasks.o.d ${OBJECTDIR}/heap_4.o.d ${OBJECTDIR}/port.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/list.o ${OBJECTDIR}/queue.o ${OBJECTDIR}/tasks.o ${OBJECTDIR}/heap_4.o ${OBJECTDIR}/port.o

# Source Files
SOURCEFILES=main.c list.c queue.c tasks.c heap_4.c port.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../../../../Program Files (x86)/Microchip/mplabc18/v3.47/h" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/include" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/portable/MPLAB/PIC18F" -I"C:/Program Files (x86)/Microchip/mplabc18/v3.47/h" -ml -oa- -Ls  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/list.o: list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/list.o.d 
	@${RM} ${OBJECTDIR}/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../../../../Program Files (x86)/Microchip/mplabc18/v3.47/h" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/include" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/portable/MPLAB/PIC18F" -I"C:/Program Files (x86)/Microchip/mplabc18/v3.47/h" -ml -oa- -Ls  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/list.o   list.c 
	@${DEP_GEN} -d ${OBJECTDIR}/list.o 
	@${FIXDEPS} "${OBJECTDIR}/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/queue.o: queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/queue.o.d 
	@${RM} ${OBJECTDIR}/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../../../../Program Files (x86)/Microchip/mplabc18/v3.47/h" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/include" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/portable/MPLAB/PIC18F" -I"C:/Program Files (x86)/Microchip/mplabc18/v3.47/h" -ml -oa- -Ls  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/queue.o   queue.c 
	@${DEP_GEN} -d ${OBJECTDIR}/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/tasks.o: tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tasks.o.d 
	@${RM} ${OBJECTDIR}/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../../../../Program Files (x86)/Microchip/mplabc18/v3.47/h" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/include" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/portable/MPLAB/PIC18F" -I"C:/Program Files (x86)/Microchip/mplabc18/v3.47/h" -ml -oa- -Ls  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/tasks.o   tasks.c 
	@${DEP_GEN} -d ${OBJECTDIR}/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/heap_4.o: heap_4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/heap_4.o.d 
	@${RM} ${OBJECTDIR}/heap_4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../../../../Program Files (x86)/Microchip/mplabc18/v3.47/h" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/include" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/portable/MPLAB/PIC18F" -I"C:/Program Files (x86)/Microchip/mplabc18/v3.47/h" -ml -oa- -Ls  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/heap_4.o   heap_4.c 
	@${DEP_GEN} -d ${OBJECTDIR}/heap_4.o 
	@${FIXDEPS} "${OBJECTDIR}/heap_4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/port.o: port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/port.o.d 
	@${RM} ${OBJECTDIR}/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../../../../Program Files (x86)/Microchip/mplabc18/v3.47/h" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/include" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/portable/MPLAB/PIC18F" -I"C:/Program Files (x86)/Microchip/mplabc18/v3.47/h" -ml -oa- -Ls  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/port.o   port.c 
	@${DEP_GEN} -d ${OBJECTDIR}/port.o 
	@${FIXDEPS} "${OBJECTDIR}/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../../Program Files (x86)/Microchip/mplabc18/v3.47/h" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/include" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/portable/MPLAB/PIC18F" -I"C:/Program Files (x86)/Microchip/mplabc18/v3.47/h" -ml -oa- -Ls  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/list.o: list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/list.o.d 
	@${RM} ${OBJECTDIR}/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../../Program Files (x86)/Microchip/mplabc18/v3.47/h" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/include" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/portable/MPLAB/PIC18F" -I"C:/Program Files (x86)/Microchip/mplabc18/v3.47/h" -ml -oa- -Ls  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/list.o   list.c 
	@${DEP_GEN} -d ${OBJECTDIR}/list.o 
	@${FIXDEPS} "${OBJECTDIR}/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/queue.o: queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/queue.o.d 
	@${RM} ${OBJECTDIR}/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../../Program Files (x86)/Microchip/mplabc18/v3.47/h" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/include" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/portable/MPLAB/PIC18F" -I"C:/Program Files (x86)/Microchip/mplabc18/v3.47/h" -ml -oa- -Ls  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/queue.o   queue.c 
	@${DEP_GEN} -d ${OBJECTDIR}/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/tasks.o: tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tasks.o.d 
	@${RM} ${OBJECTDIR}/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../../Program Files (x86)/Microchip/mplabc18/v3.47/h" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/include" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/portable/MPLAB/PIC18F" -I"C:/Program Files (x86)/Microchip/mplabc18/v3.47/h" -ml -oa- -Ls  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/tasks.o   tasks.c 
	@${DEP_GEN} -d ${OBJECTDIR}/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/heap_4.o: heap_4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/heap_4.o.d 
	@${RM} ${OBJECTDIR}/heap_4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../../Program Files (x86)/Microchip/mplabc18/v3.47/h" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/include" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/portable/MPLAB/PIC18F" -I"C:/Program Files (x86)/Microchip/mplabc18/v3.47/h" -ml -oa- -Ls  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/heap_4.o   heap_4.c 
	@${DEP_GEN} -d ${OBJECTDIR}/heap_4.o 
	@${FIXDEPS} "${OBJECTDIR}/heap_4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/port.o: port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/port.o.d 
	@${RM} ${OBJECTDIR}/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../../Program Files (x86)/Microchip/mplabc18/v3.47/h" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/include" -I"../FreeRTOSv10.2.1/FreeRTOS/Source/portable/MPLAB/PIC18F" -I"C:/Program Files (x86)/Microchip/mplabc18/v3.47/h" -ml -oa- -Ls  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/port.o   port.c 
	@${DEP_GEN} -d ${OBJECTDIR}/port.o 
	@${FIXDEPS} "${OBJECTDIR}/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    18f452.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "18f452.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   18f452.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "18f452.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/ecng3006-project.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
