#!/bin/bash

KERNEL_DIR=$PWD
IMAGE_NAME=boot

BIN_DIR=out/$TARGET_DEVICE/bin
OBJ_DIR=out/$TARGET_DEVICE/obj
mkdir -p $BIN_DIR
mkdir -p $OBJ_DIR

. cross_compile

# set build env
export ARCH=arm
export CROSS_COMPILE=$BUILD_CROSS_COMPILE

# kernel vesion
KERNEL_VERSION=`grep '^VERSION = ' ./Makefile | cut -d' ' -f3`
KERNEL_PATCHLEVEL=`grep '^PATCHLEVEL = ' ./Makefile | cut -d' ' -f3`
KERNEL_SUBLEVEL=`grep '^SUBLEVEL = ' ./Makefile | cut -d' ' -f3`
export BUILD_KERNELVERSION="$KERNEL_VERSION.$KERNEL_PATCHLEVEL.$KERNEL_SUBLEVEL"

echo ""
echo "====================================================================="
echo "    BUILD START (KERNEL VERSION $BUILD_KERNELVERSION)"
echo "====================================================================="

if [ ! -n "$1" ]; then
  echo ""
  read -p "select build? [(a)ll/(u)pdate/(i)mage default:update] " BUILD_SELECT
else
  BUILD_SELECT=$1
fi

# make start
if [ "$BUILD_SELECT" = 'all' -o "$BUILD_SELECT" = 'a' ]; then
  echo ""
  echo "=====> CLEANING..."
  make mrproper
  cp -f ./arch/arm/configs/$KERNEL_DEFCONFIG $OBJ_DIR/.config
  make -C $PWD O=$OBJ_DIR oldconfig || exit -1
fi

if [ "$BUILD_SELECT" != 'image' -a "$BUILD_SELECT" != 'i' ]; then
  if [ -e make.log ]; then
    mv make.log make_old.log
  fi
  echo ""
  echo "=====> MAKE KERNEL MODULE.."
  nice -n 10 make O=$OBJ_DIR -j12 modules 2>&1 | tee make.log
fi

# check compile error
COMPILE_ERROR=`grep 'error:' ./make.log`
if [ "$COMPILE_ERROR" ]; then
  echo ""
  echo "=====> ERROR"
  grep 'error:' ./make.log
  exit -1
fi

# *.ko install
echo ""
echo "=====> INSTALL KERNEL MODULES"
rm -rf /tmp/ramdisk
mkdir -p /tmp/ramdisk/lib/modules
find -name '*.ko' -exec cp -av {} /tmp/ramdisk/lib/modules/ \;
STRIP=strip
$CROSS_COMPILE$STRIP --strip-unneeded /tmp/ramdisk/lib/modules/*

echo ""
echo "=====> MAKE KERNEL IMAGE"
nice -n 10 make O=$OBJ_DIR -j12 2>&1 | tee make.log

echo ""
echo "=====> CREATE RELEASE IMAGE"
# clean release dir
if [ `find $BIN_DIR -type f | wc -l` -gt 0 ]; then
  rm -rf $BIN_DIR/*
fi
mkdir -p $BIN_DIR

# copy zImage -> kernel
cp $OBJ_DIR/arch/arm/boot/zImage $BIN_DIR/custombuild.zImage

# create modules package
tar zcvf $BIN_DIR/modules.tar.gz -C /tmp/ramdisk lib

cd $KERNEL_DIR

echo ""
echo "====================================================================="
echo "    BUILD COMPLETED"
echo "====================================================================="
exit 0
