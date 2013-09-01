#!/bin/bash

# set kernel version
export TARGET_DEVICE=005SH

# set kernel option
export KERNEL_DEFCONFIG=bec_defconfig

time ./_build-bootimg.sh $1

