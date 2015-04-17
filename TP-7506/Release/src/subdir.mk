################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TP-7506.cpp 

C_SRCS += \
../src/adler32.c \
../src/blocksort.c \
../src/bzlib.c \
../src/compress.c \
../src/crc32.c \
../src/crctable.c \
../src/decompress.c \
../src/deflate.c \
../src/gzclose.c \
../src/gzlib.c \
../src/gzread.c \
../src/gzwrite.c \
../src/huffman.c \
../src/infback.c \
../src/inffast.c \
../src/inflate.c \
../src/inftrees.c \
../src/randtable.c \
../src/trees.c \
../src/uncompr.c \
../src/zutil.c 

OBJS += \
./src/TP-7506.o \
./src/adler32.o \
./src/blocksort.o \
./src/bzlib.o \
./src/compress.o \
./src/crc32.o \
./src/crctable.o \
./src/decompress.o \
./src/deflate.o \
./src/gzclose.o \
./src/gzlib.o \
./src/gzread.o \
./src/gzwrite.o \
./src/huffman.o \
./src/infback.o \
./src/inffast.o \
./src/inflate.o \
./src/inftrees.o \
./src/randtable.o \
./src/trees.o \
./src/uncompr.o \
./src/zutil.o 

C_DEPS += \
./src/adler32.d \
./src/blocksort.d \
./src/bzlib.d \
./src/compress.d \
./src/crc32.d \
./src/crctable.d \
./src/decompress.d \
./src/deflate.d \
./src/gzclose.d \
./src/gzlib.d \
./src/gzread.d \
./src/gzwrite.d \
./src/huffman.d \
./src/infback.d \
./src/inffast.d \
./src/inflate.d \
./src/inftrees.d \
./src/randtable.d \
./src/trees.d \
./src/uncompr.d \
./src/zutil.d 

CPP_DEPS += \
./src/TP-7506.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


