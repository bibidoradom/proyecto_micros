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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Proyecto_Final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Proyecto_Final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=servo.c sensores.c UART1.c BitWhacker.c actuadores.c mainpruebas.c config.c timers.c Pic32Ini.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/servo.o ${OBJECTDIR}/sensores.o ${OBJECTDIR}/UART1.o ${OBJECTDIR}/BitWhacker.o ${OBJECTDIR}/actuadores.o ${OBJECTDIR}/mainpruebas.o ${OBJECTDIR}/config.o ${OBJECTDIR}/timers.o ${OBJECTDIR}/Pic32Ini.o
POSSIBLE_DEPFILES=${OBJECTDIR}/servo.o.d ${OBJECTDIR}/sensores.o.d ${OBJECTDIR}/UART1.o.d ${OBJECTDIR}/BitWhacker.o.d ${OBJECTDIR}/actuadores.o.d ${OBJECTDIR}/mainpruebas.o.d ${OBJECTDIR}/config.o.d ${OBJECTDIR}/timers.o.d ${OBJECTDIR}/Pic32Ini.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/servo.o ${OBJECTDIR}/sensores.o ${OBJECTDIR}/UART1.o ${OBJECTDIR}/BitWhacker.o ${OBJECTDIR}/actuadores.o ${OBJECTDIR}/mainpruebas.o ${OBJECTDIR}/config.o ${OBJECTDIR}/timers.o ${OBJECTDIR}/Pic32Ini.o

# Source Files
SOURCEFILES=servo.c sensores.c UART1.c BitWhacker.c actuadores.c mainpruebas.c config.c timers.c Pic32Ini.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Proyecto_Final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX230F064D
MP_LINKER_FILE_OPTION=
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
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/servo.o: servo.c  .generated_files/flags/default/1eb23e12a92934fc429553e0b84e5b4f4be4ad9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/servo.o.d 
	@${RM} ${OBJECTDIR}/servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/servo.o.d" -o ${OBJECTDIR}/servo.o servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/sensores.o: sensores.c  .generated_files/flags/default/b547c2d3687bc5f7fb750a17d51758b89603176 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sensores.o.d 
	@${RM} ${OBJECTDIR}/sensores.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/sensores.o.d" -o ${OBJECTDIR}/sensores.o sensores.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/UART1.o: UART1.c  .generated_files/flags/default/b7cb5653523ba9cd1b97d4afebde059d728e9a7d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART1.o.d 
	@${RM} ${OBJECTDIR}/UART1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/UART1.o.d" -o ${OBJECTDIR}/UART1.o UART1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BitWhacker.o: BitWhacker.c  .generated_files/flags/default/ef094d3a2ee57a0704912af18b81155780ce33fa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BitWhacker.o.d 
	@${RM} ${OBJECTDIR}/BitWhacker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/BitWhacker.o.d" -o ${OBJECTDIR}/BitWhacker.o BitWhacker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/actuadores.o: actuadores.c  .generated_files/flags/default/3fa86e755e11094f03545519c0e169ced8e56fc5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/actuadores.o.d 
	@${RM} ${OBJECTDIR}/actuadores.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/actuadores.o.d" -o ${OBJECTDIR}/actuadores.o actuadores.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mainpruebas.o: mainpruebas.c  .generated_files/flags/default/60d095561cf19fd86264cdec559b6c5051b9ee2e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mainpruebas.o.d 
	@${RM} ${OBJECTDIR}/mainpruebas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mainpruebas.o.d" -o ${OBJECTDIR}/mainpruebas.o mainpruebas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/config.o: config.c  .generated_files/flags/default/c6883f5b5268aa094abefa8882c8e0cfd1376705 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/config.o.d 
	@${RM} ${OBJECTDIR}/config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/config.o.d" -o ${OBJECTDIR}/config.o config.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/timers.o: timers.c  .generated_files/flags/default/cd24ec8c719ecd3696793e7ff142a14e79c7200a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timers.o.d 
	@${RM} ${OBJECTDIR}/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/timers.o.d" -o ${OBJECTDIR}/timers.o timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Pic32Ini.o: Pic32Ini.c  .generated_files/flags/default/9f77aec7245dcbbeb19d52533303bfd13fa4fcba .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Pic32Ini.o.d 
	@${RM} ${OBJECTDIR}/Pic32Ini.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Pic32Ini.o.d" -o ${OBJECTDIR}/Pic32Ini.o Pic32Ini.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/servo.o: servo.c  .generated_files/flags/default/afb5308af012a05ebfd65dccdb63fb5196f91e35 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/servo.o.d 
	@${RM} ${OBJECTDIR}/servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/servo.o.d" -o ${OBJECTDIR}/servo.o servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/sensores.o: sensores.c  .generated_files/flags/default/4bba787aea407dfadfc60cd4039b207b3cf84b5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sensores.o.d 
	@${RM} ${OBJECTDIR}/sensores.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/sensores.o.d" -o ${OBJECTDIR}/sensores.o sensores.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/UART1.o: UART1.c  .generated_files/flags/default/8ca2830b52fa72ede1ceb9be30226a5542de47bb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART1.o.d 
	@${RM} ${OBJECTDIR}/UART1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/UART1.o.d" -o ${OBJECTDIR}/UART1.o UART1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BitWhacker.o: BitWhacker.c  .generated_files/flags/default/16783ea307562d6dd69cc3e86d66b56346d125f1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BitWhacker.o.d 
	@${RM} ${OBJECTDIR}/BitWhacker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/BitWhacker.o.d" -o ${OBJECTDIR}/BitWhacker.o BitWhacker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/actuadores.o: actuadores.c  .generated_files/flags/default/d25970f7522c065d54c4658524a3fa7100d70746 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/actuadores.o.d 
	@${RM} ${OBJECTDIR}/actuadores.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/actuadores.o.d" -o ${OBJECTDIR}/actuadores.o actuadores.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mainpruebas.o: mainpruebas.c  .generated_files/flags/default/e380ae80f32fb0827dc6a1547f49c0a29b8dc1b9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mainpruebas.o.d 
	@${RM} ${OBJECTDIR}/mainpruebas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mainpruebas.o.d" -o ${OBJECTDIR}/mainpruebas.o mainpruebas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/config.o: config.c  .generated_files/flags/default/6bcde124fe4cab953804f96b941d5b39cb3c3580 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/config.o.d 
	@${RM} ${OBJECTDIR}/config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/config.o.d" -o ${OBJECTDIR}/config.o config.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/timers.o: timers.c  .generated_files/flags/default/efc9ec3f0c693ff0419c6d1434e9e58f3cdcf3d2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timers.o.d 
	@${RM} ${OBJECTDIR}/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/timers.o.d" -o ${OBJECTDIR}/timers.o timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Pic32Ini.o: Pic32Ini.c  .generated_files/flags/default/de45aea4c0cdb45b46d65b79396cf0e54f5e14cc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Pic32Ini.o.d 
	@${RM} ${OBJECTDIR}/Pic32Ini.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Pic32Ini.o.d" -o ${OBJECTDIR}/Pic32Ini.o Pic32Ini.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Proyecto_Final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_SIMULATOR=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Proyecto_Final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Proyecto_Final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Proyecto_Final.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex ${DISTDIR}/Proyecto_Final.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
