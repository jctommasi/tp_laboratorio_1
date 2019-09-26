################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/arrayEmployee.c \
../src/arrayf.c \
../src/main.c \
../src/stuff.c \
../src/utn.c 

OBJS += \
./src/arrayEmployee.o \
./src/arrayf.o \
./src/main.o \
./src/stuff.o \
./src/utn.o 

C_DEPS += \
./src/arrayEmployee.d \
./src/arrayf.d \
./src/main.d \
./src/stuff.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


