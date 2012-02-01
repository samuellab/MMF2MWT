#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1360890869/MWT_Library.o \
	${OBJECTDIR}/_ext/1360890869/MWT_Blob.o \
	${OBJECTDIR}/_ext/1360890869/MWT_Model.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/MMF_MWT_Processor.o \
	${OBJECTDIR}/_ext/1360890869/MWT_Geometry.o \
	${OBJECTDIR}/_ext/1360890869/MWT_Image.o \
	${OBJECTDIR}/_ext/1360890869/MWT_DLL.o \
	${OBJECTDIR}/_ext/1360890869/MWT_Lists.o \
	${OBJECTDIR}/_ext/1360890869/MWT_Storage.o \
	${OBJECTDIR}/MWT_Image_CV.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Release.mk dist/Release/MinGW-Windows/mwtmmf.exe

dist/Release/MinGW-Windows/mwtmmf.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Release/MinGW-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mwtmmf ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1360890869/MWT_Library.o: ../DLL/MWT_Library.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Library.o ../DLL/MWT_Library.cc

${OBJECTDIR}/_ext/1360890869/MWT_Blob.o: ../DLL/MWT_Blob.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Blob.o ../DLL/MWT_Blob.cc

${OBJECTDIR}/_ext/1360890869/MWT_Model.o: ../DLL/MWT_Model.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Model.o ../DLL/MWT_Model.cc

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/MMF_MWT_Processor.o: MMF_MWT_Processor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/MMF_MWT_Processor.o MMF_MWT_Processor.cpp

${OBJECTDIR}/_ext/1360890869/MWT_Geometry.o: ../DLL/MWT_Geometry.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Geometry.o ../DLL/MWT_Geometry.cc

${OBJECTDIR}/_ext/1360890869/MWT_Image.o: ../DLL/MWT_Image.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Image.o ../DLL/MWT_Image.cc

${OBJECTDIR}/_ext/1360890869/MWT_DLL.o: ../DLL/MWT_DLL.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_DLL.o ../DLL/MWT_DLL.cc

${OBJECTDIR}/_ext/1360890869/MWT_Lists.o: ../DLL/MWT_Lists.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Lists.o ../DLL/MWT_Lists.cc

${OBJECTDIR}/_ext/1360890869/MWT_Storage.o: ../DLL/MWT_Storage.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Storage.o ../DLL/MWT_Storage.cc

${OBJECTDIR}/MWT_Image_CV.o: MWT_Image_CV.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/MWT_Image_CV.o MWT_Image_CV.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/MinGW-Windows/mwtmmf.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
