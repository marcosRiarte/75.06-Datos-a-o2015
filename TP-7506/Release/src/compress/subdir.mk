################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/compress/adler32.c \
../src/compress/blocksort.c \
../src/compress/bzlib.c \
../src/compress/compress.c \
../src/compress/crc32.c \
../src/compress/crctable.c \
../src/compress/decompress.c \
../src/compress/deflate.c \
../src/compress/gzclose.c \
../src/compress/gzlib.c \
../src/compress/gzread.c \
../src/compress/gzwrite.c \
../src/compress/huffman.c \
../src/compress/infback.c \
../src/compress/inffast.c \
../src/compress/inflate.c \
../src/compress/inftrees.c \
../src/compress/randtable.c \
../src/compress/trees.c \
../src/compress/uncompr.c \
../src/compress/zutil.c 

OBJS += \
./src/compress/adler32.o \
./src/compress/blocksort.o \
./src/compress/bzlib.o \
./src/compress/compress.o \
./src/compress/crc32.o \
./src/compress/crctable.o \
./src/compress/decompress.o \
./src/compress/deflate.o \
./src/compress/gzclose.o \
./src/compress/gzlib.o \
./src/compress/gzread.o \
./src/compress/gzwrite.o \
./src/compress/huffman.o \
./src/compress/infback.o \
./src/compress/inffast.o \
./src/compress/inflate.o \
./src/compress/inftrees.o \
./src/compress/randtable.o \
./src/compress/trees.o \
./src/compress/uncompr.o \
./src/compress/zutil.o 

C_DEPS += \
./src/compress/adler32.d \
./src/compress/blocksort.d \
./src/compress/bzlib.d \
./src/compress/compress.d \
./src/compress/crc32.d \
./src/compress/crctable.d \
./src/compress/decompress.d \
./src/compress/deflate.d \
./src/compress/gzclose.d \
./src/compress/gzlib.d \
./src/compress/gzread.d \
./src/compress/gzwrite.d \
./src/compress/huffman.d \
./src/compress/infback.d \
./src/compress/inffast.d \
./src/compress/inflate.d \
./src/compress/inftrees.d \
./src/compress/randtable.d \
./src/compress/trees.d \
./src/compress/uncompr.d \
./src/compress/zutil.d 


# Each subdirectory must supply rules for building sources it contributes
src/compress/%.o: ../src/compress/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


