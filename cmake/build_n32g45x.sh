#!/bin/sh

export ARM_CORTEX_M4_GCC_PATH=/home/ouyang/works/opt/cortex-m4/gcc-arm-none-eabi-9-2020-q2-update/bin
export PATH=$PATH:$ARM_CORTEX_M4_GCC_PATH

TARGET=target_n32g45x
rm -fr $TARGET
mkdir $TARGET
cd $TARGET
cmake ../../ -DCMAKE_TOOLCHAIN_FILE=../n32g45x-cortex-m4-gcc-arm-none-eabi.cmake
make
ls -l -h ../../target/
