#!/bin/bash

export PATH=~/kernel_build/arm-eabi-4.6/bin/:$PATH
export ARCH=arm
export SUBARCH=arm
export CROSS_COMPILE=~/kernel_build/arm-eabi-4.6/bin/arm-eabi-
export LOCALVERSION=+
#export INSTALL_MOD_PATH=~/kernel_build/rk3188/mod_fw

#board name
./mk.sh "mp92_1021"


