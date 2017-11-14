################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\guillotl\Arduino\libraries\I2C_LCD_Library\I2C_LCD.cpp 

LINK_OBJ += \
.\libraries\I2C_LCD_Library\I2C_LCD.cpp.o 

CPP_DEPS += \
.\libraries\I2C_LCD_Library\I2C_LCD.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\I2C_LCD_Library\I2C_LCD.cpp.o: C:\Users\guillotl\Arduino\libraries\I2C_LCD_Library\I2C_LCD.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Eclipse_Arduino\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Eclipse_Arduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\Eclipse_Arduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"C:\Eclipse_Arduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\Eclipse_Arduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\guillotl\Arduino\libraries\TinyGPSPlus-master" -I"C:\Users\guillotl\Arduino\libraries\TinyGPSPlus-master\src" -I"C:\Users\guillotl\Arduino\libraries\I2C_LCD_Library" -I"C:\Eclipse_Arduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\Eclipse_Arduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


