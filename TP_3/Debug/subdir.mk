################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Controller.c \
../Employee.c \
../files.c \
../input.c \
../main.c \
../menu.c \
../myStr.c \
../parser.c 

OBJS += \
./Controller.o \
./Employee.o \
./files.o \
./input.o \
./main.o \
./menu.o \
./myStr.o \
./parser.o 

C_DEPS += \
./Controller.d \
./Employee.d \
./files.d \
./input.d \
./main.d \
./menu.d \
./myStr.d \
./parser.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


