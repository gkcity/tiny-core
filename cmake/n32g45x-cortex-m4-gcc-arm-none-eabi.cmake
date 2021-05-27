MESSAGE(STATUS "make for n32g45x")
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_VERSION 1)
SET(CMAKE_SYSTEM_PROCESSOR arm)
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

#----------------------------------------------------------------------------
#
# Toolchain Settings
#
#----------------------------------------------------------------------------
SET(CMAKE_C_COMPILER /home/ouyang/works/opt/cortex-m4/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER /home/ouyang/works/opt/cortex-m4/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-g++)
SET(CMAKE_RANLIB /home/ouyang/works/opt/cortex-m4/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-ranlib)
SET(CMAKE_AR /home/ouyang/works/opt/cortex-m4/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-ar)
SET(CMAKE_STRIP /home/ouyang/works/opt/cortex-m4/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-strip)
#SET(CMAKE_C_FLAGS "-nostdlib -Wall -Werror -Os" CACHE STRING "" FORCE)

SET(CMAKE_C_FLAGS "-nostdlib -DN32G45X -mcpu=cortex-m4 -mthumb -Wall -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -ffunction-sections -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS "-nostdlib -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,--gc-sections --specs=nosys.specs -Xlinker")
SET(CMAKE_STATIC_LINKER_FLAGS "-nostdlib -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,--gc-sections --specs=nosys.specs -Xlinker")
SET(CMAKE_SHARED_LINKER_FLAGS "-nostdlib -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,--gc-sections --specs=nosys.specs -Xlinker")
SET(CMAKE_MODULE_LINKER_FLAGS "-nostdlib -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,--gc-sections --specs=nosys.specs -Xlinker")

#ADD_DEFINITIONS(-DN32G45X)
#ADD_DEFINITIONS(-mcpu=cortex-m4)
#ADD_DEFINITIONS(-mthumb)
#ADD_DEFINITIONS(-Wall)
#ADD_DEFINITIONS(-mfloat-abi=hard)
#ADD_DEFINITIONS(-mfpu=fpv4-sp-d16)
#ADD_DEFINITIONS(-Os)
#ADD_DEFINITIONS(-ffunction-sections)
#ADD_DEFINITIONS(-fdata-sections)

#----------------------------------------------------------------------------
#
# DEBUG INFORMATION
#
#----------------------------------------------------------------------------
ADD_DEFINITIONS(-DTINY_DEBUG)

#----------------------------------------------------------------------------
#
# Export library
#
#----------------------------------------------------------------------------
SET(EXPORT_STATIC_LIBRARY 1)
SET(EXPORT_SHARED_LIBRARY 0)
