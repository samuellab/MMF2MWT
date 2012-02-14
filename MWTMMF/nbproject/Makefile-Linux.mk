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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Linux
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

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
CCFLAGS=-static-libgcc -static-libstdc++
CXXFLAGS=-static-libgcc -static-libstdc++

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/linuxlib ../Image-Stack-Compressor/LinuxBinaries/image_stack_compressor.lib -lcv -lcxcore -lhighgui ../yaml-cpp/./LinuxBinaries/libyaml-cpp.lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ./LinuxBinaries/mmf2mwt.exe

./LinuxBinaries/mmf2mwt.exe: ../Image-Stack-Compressor/LinuxBinaries/image_stack_compressor.lib

./LinuxBinaries/mmf2mwt.exe: ../yaml-cpp/./LinuxBinaries/libyaml-cpp.lib

./LinuxBinaries/mmf2mwt.exe: ${OBJECTFILES}
	${MKDIR} -p ./LinuxBinaries
	${LINK.cc} -static-libgcc -static-libstdc++ -o ./LinuxBinaries/mmf2mwt.exe ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1360890869/MWT_Library.o: nbproject/Makefile-${CND_CONF}.mk ../DLL/MWT_Library.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Library.o ../DLL/MWT_Library.cc

${OBJECTDIR}/_ext/1360890869/MWT_Blob.o: nbproject/Makefile-${CND_CONF}.mk ../DLL/MWT_Blob.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Blob.o ../DLL/MWT_Blob.cc

${OBJECTDIR}/_ext/1360890869/MWT_Model.o: nbproject/Makefile-${CND_CONF}.mk ../DLL/MWT_Model.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Model.o ../DLL/MWT_Model.cc

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/MMF_MWT_Processor.o: nbproject/Makefile-${CND_CONF}.mk MMF_MWT_Processor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/MMF_MWT_Processor.o MMF_MWT_Processor.cpp

${OBJECTDIR}/_ext/1360890869/MWT_Geometry.o: nbproject/Makefile-${CND_CONF}.mk ../DLL/MWT_Geometry.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Geometry.o ../DLL/MWT_Geometry.cc

${OBJECTDIR}/_ext/1360890869/MWT_Image.o: nbproject/Makefile-${CND_CONF}.mk ../DLL/MWT_Image.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Image.o ../DLL/MWT_Image.cc

${OBJECTDIR}/_ext/1360890869/MWT_DLL.o: nbproject/Makefile-${CND_CONF}.mk ../DLL/MWT_DLL.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_DLL.o ../DLL/MWT_DLL.cc

${OBJECTDIR}/_ext/1360890869/MWT_Lists.o: nbproject/Makefile-${CND_CONF}.mk ../DLL/MWT_Lists.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Lists.o ../DLL/MWT_Lists.cc

${OBJECTDIR}/_ext/1360890869/MWT_Storage.o: nbproject/Makefile-${CND_CONF}.mk ../DLL/MWT_Storage.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360890869
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360890869/MWT_Storage.o ../DLL/MWT_Storage.cc

${OBJECTDIR}/MWT_Image_CV.o: nbproject/Makefile-${CND_CONF}.mk MWT_Image_CV.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../DLL -I../Image-Stack-Compressor -I../Image-Stack-Compressor/Necessary\ Libraries\ and\ Includes/CV/headers -I../yaml-cpp/include/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/MWT_Image_CV.o MWT_Image_CV.cpp

# Subprojects
.build-subprojects:
	cd ../Image-Stack-Compressor && ${MAKE}  -f Makefile CONF=linux
	cd ../yaml-cpp && ${MAKE}  -f Makefile CONF=Linux

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ./LinuxBinaries/mmf2mwt.exe

# Subprojects
.clean-subprojects:
	cd ../Image-Stack-Compressor && ${MAKE}  -f Makefile CONF=linux clean
	cd ../yaml-cpp && ${MAKE}  -f Makefile CONF=Linux clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
