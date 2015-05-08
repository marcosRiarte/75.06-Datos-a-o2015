################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Compresor.cpp \
../src/NDCMatrix.cpp \
../src/TP-7506.cpp \
../src/compresedReview.cpp \
../src/tsvParser.cpp 

OBJS += \
./src/Compresor.o \
./src/NDCMatrix.o \
./src/TP-7506.o \
./src/compresedReview.o \
./src/tsvParser.o 

CPP_DEPS += \
./src/Compresor.d \
./src/NDCMatrix.d \
./src/TP-7506.d \
./src/compresedReview.d \
./src/tsvParser.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


