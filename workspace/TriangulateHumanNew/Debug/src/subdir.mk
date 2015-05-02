################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Calibration.cpp \
../src/Triangulate.cpp \
../src/TriangulateHuman.cpp 

OBJS += \
./src/Calibration.o \
./src/Triangulate.o \
./src/TriangulateHuman.o 

CPP_DEPS += \
./src/Calibration.d \
./src/Triangulate.d \
./src/TriangulateHuman.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


