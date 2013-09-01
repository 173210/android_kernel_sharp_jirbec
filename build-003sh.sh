#!/bin/bash

# set kernel version
export TARGET_DEVICE=003SH

# set kernel option
export KERNEL_DEFCONFIG=jir_defconfig

time ./_build-bootimg.sh $1

