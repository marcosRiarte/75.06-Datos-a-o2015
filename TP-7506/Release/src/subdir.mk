################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Compresor.cpp \
../src/DataSet.cpp \
../src/FileHandler.cpp \
../src/NCDMatrix.cpp \
../src/Parser.cpp \
../src/PosNCD.cpp \
../src/ReviewCleaner.cpp \
../src/ReviewInformation.cpp \
../src/StopWord.cpp \
../src/TP-7506.cpp \
../src/TestReview.cpp \
../src/TrainReview.cpp 

OBJS += \
./src/Compresor.o \
./src/DataSet.o \
./src/FileHandler.o \
./src/NCDMatrix.o \
./src/Parser.o \
./src/PosNCD.o \
./src/ReviewCleaner.o \
./src/ReviewInformation.o \
./src/StopWord.o \
./src/TP-7506.o \
./src/TestReview.o \
./src/TrainReview.o 

CPP_DEPS += \
./src/Compresor.d \
./src/DataSet.d \
./src/FileHandler.d \
./src/NCDMatrix.d \
./src/Parser.d \
./src/PosNCD.d \
./src/ReviewCleaner.d \
./src/ReviewInformation.d \
./src/StopWord.d \
./src/TP-7506.d \
./src/TestReview.d \
./src/TrainReview.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


