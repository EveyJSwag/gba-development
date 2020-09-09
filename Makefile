#####################################################################
#                    *** DISCLAIMER ***                             #
# MANY ASPECTS OF THIS MAKEFILE ARE BORROWED FROM 'www.coranac.com' #
#####################################################################

##############################################
#              *** GUIDE ***                 #
# ~~~ HOW MAKE FILES WORK AT A HIGH LEVEL~~~ #
# target [target...] : [dependent ....]      #
# [ command ...]                             #
##############################################

###################
# PROJECT DETAILS #
###################
PROJ := sprite_test
TARGET := $(PROJ)
TITLE := $(PROJ)
$(info $(TITLE))
SOURCE_DIR := source
TOOLS_DIR := tools
SPECS	:= -specs=gba.specs
COBJS := $(SOURCE_DIR)/sprite_test.o $(TOOLS_DIR)/input.o $(TOOLS_DIR)/mem_util.o $(TOOLS_DIR)/game_properties.o $(TOOLS_DIR)/game_characters.o
OBJS := $(COBJS)

#########################
# COMPILATION VARIABLES #
#########################
CROSS	?= /opt/devkitpro/devkitARM/bin/arm-none-eabi-
AS		:= $(CROSS)as
CC		:= $(CROSS)gcc
LD		:= $(CROSS)gcc
OBJCOPY	:= $(CROSS)objcopy

ARCH	:= -mthumb-interwork -mthumb

ASFLAGS	:= -mthumb-interwork
CFLAGS	:= $(ARCH) -O2 -Wall -fno-strict-aliasing
LDFLAGS	:= $(ARCH) $(SPECS)

.PHONY : build clean

#######################
# THE ACTUAL COMMANDS #
#######################

$(TARGET).gba : $(TARGET).elf
	$(OBJCOPY) -v -O binary $< $@
	-@gbafix $@ -t$(TITLE)

$(TARGET).elf : $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

$(COBJS) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ACTUAL COMMANDS:
# arm-none-eabi-gcc -mthumb-interwork -mthumb -O2 -Wall -fno-strict-aliasing -c FIRST_ARG.c -o NEEDED_REQ.o
