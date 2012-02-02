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
CND_CONF=Debug
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
CCFLAGS=-DWINDOWS -DBUILD_DLL
CXXFLAGS=-DWINDOWS -DBUILD_DLL

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/lib ../Image-Stack-Compressor/image_stack_compressor.lib -lcv -lcxcore -lhighgui ../yaml-cpp/./libyaml-cpp.lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk ./mwt2mmf.exe

./mwt2mmf.exe: ../Image-Stack-Compressor/image_stack_compressor.lib

./mwt2mmf.exe: ../yaml-cpp/./libyaml-cpp.lib

./mwt2mmf.exe: ${OBJECTFILES}
	${MKDIR} -p .
	${LINK.cc} -o ./mwt2mmf ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1360890869/MWT_Library.o: ../DLL/MWT_Library.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Library.o ../DLL/MWT_Library.cc

${OBJECTDIR}/_ext/1360890869/MWT_Blob.o: ../DLL/MWT_Blob.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Blob.o ../DLL/MWT_Blob.cc

${OBJECTDIR}/_ext/1360890869/MWT_Model.o: ../DLL/MWT_Model.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Model.o ../DLL/MWT_Model.cc

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/MMF_MWT_Processor.o: MMF_MWT_Processor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/MMF_MWT_Processor.o MMF_MWT_Processor.cpp

${OBJECTDIR}/_ext/1360890869/MWT_Geometry.o: ../DLL/MWT_Geometry.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Geometry.o ../DLL/MWT_Geometry.cc

${OBJECTDIR}/_ext/1360890869/MWT_Image.o: ../DLL/MWT_Image.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Image.o ../DLL/MWT_Image.cc

${OBJECTDIR}/_ext/1360890869/MWT_DLL.o: ../DLL/MWT_DLL.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_DLL.o ../DLL/MWT_DLL.cc

${OBJECTDIR}/_ext/1360890869/MWT_Lists.o: ../DLL/MWT_Lists.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Lists.o ../DLL/MWT_Lists.cc

${OBJECTDIR}/_ext/1360890869/MWT_Storage.o: ../DLL/MWT_Storage.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Storage.o ../DLL/MWT_Storage.cc

${OBJECTDIR}/MWT_Image_CV.o: MWT_Image_CV.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/MWT_Image_CV.o MWT_Image_CV.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} ./mwt2mmf.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
