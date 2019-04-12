#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This make file is the recipe for building the final exe for MSP432 and also
# HOST machine
#
# Use: make [TARGET] [PLATFORM]
# ex: make build PLATFORM=MSP432
# ex; make build PLATFORM=HOST
#
# Build Targets:
#     make <src_file>.i: generates preprocessor file
#	    make <src_file>.o: generates compiled file
#     make <src_file>.asm: generates assembly file
#
# Platform Overrides:
#      MSP432: for masp432 embedded board
#			 HOST: for host machine
# Author: Hrishikesh Adigal
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

#output target
TARGET = course1

# Architectures Specific Flags
LINKER_FILE =
CPU =
ARCH =
SPECS =

LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE)
CPPFLAGs = $(INCLUDES)

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
CC = gcc -DHOST
LD = ld
CPU = native
CFLAGS = -Wall -Werror -g -O0 -std=c99 -DVERBOSE
SOURCES = $(SOURCES_HOST)
SIZE = size -Atd
else
CC = arm-none-eabi-gcc -DMSP432
LD = arm-none-eabi-ld
LINKER_FILE = -T ./msp432p401r.lds
ARCH = thumb
SPECS = nosys.specs
CPU = cortex-m4
CFLAGS = -g -O0 -std=c99 -Wall -Werror -mcpu=$(CPU) -m$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -march=armv7e-m  --specs=$(SPECS) -DVERBOSE
LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE)
SIZE = arm-none-eabi-size -Atd
endif

%.i:%.c
	$(CC) -E $(CFLAGS) $(CPPFLAGs) -o $@ $^

ASM_FILE = $(SOURCES:.c=.s)
%.asm:%.c
	$(CC) -S $(CFLAGS) $(CPPFLAGs) -o $@ $^

OBJS = $(SOURCES:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) $(CPPFLAGs) -c $^ -o $@
	$(CC) -MM $(CFLAGS) $(CPPFLAGs) $*.c > $*.d

.PHONY: compile-all
compile-all:$(OBJS)

DEPS = $(SOURCES:.c=.d)

.PHONY:build
build:compile-all
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGs) $(LDFLAGS) -o $(TARGET).out
	$(SIZE) $(TARGET).out

.PHONY: clean
clean:
	rm -f ./src/*.out ./src/*.o ./src/*.asm ./src/*.i ./src/*.d ./src/*.map ./src/*.s ./src/*.map ./*.map ./*.out
