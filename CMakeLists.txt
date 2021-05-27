CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(TinyCore C)

SET(PROJ_NAME "TinyCore")

#---------------------------------------------------------------------------------------
#
# include dir
#
#---------------------------------------------------------------------------------------
SET(SOURCE_ROOT ${PROJECT_SOURCE_DIR}/src)

INCLUDE_DIRECTORIES(${SOURCE_ROOT}/TinyBase)
INCLUDE_DIRECTORIES(${SOURCE_ROOT}/TinyPortable)
INCLUDE_DIRECTORIES(${SOURCE_ROOT}/TinyLog)
INCLUDE_DIRECTORIES(${SOURCE_ROOT}/TinyContainer)
INCLUDE_DIRECTORIES(${SOURCE_ROOT}/TinyStringUtil)
INCLUDE_DIRECTORIES(${SOURCE_ROOT}/ByteBuffer)
INCLUDE_DIRECTORIES(${SOURCE_ROOT}/Json)

#---------------------------------------------------------------------------------------
#
# link dir
#
#---------------------------------------------------------------------------------------
LINK_DIRECTORIES(${TINY_LOG_ROOT}/target)
LINK_DIRECTORIES(${TINY_MALLOC_ROOT}/target)

#-------------------------------------------------------------------------------------
# output dir
#-------------------------------------------------------------------------------------
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target)
MESSAGE(STATUS "executable output:  ${EXECUTABLE_OUTPUT_PATH}")
MESSAGE(STATUS "library output: ${LIBRARY_OUTPUT_PATH}")

#-------------------------------------------------------------------------------------
#
# Source
#
#-------------------------------------------------------------------------------------

#---------------------------
# TinyBase
#---------------------------

SET(TinyBase_Header
        ${SOURCE_ROOT}/TinyBase/tiny_api.h
        ${SOURCE_ROOT}/TinyBase/tiny_base.h
        ${SOURCE_ROOT}/TinyBase/tiny_define.h
        ${SOURCE_ROOT}/TinyBase/tiny_debug.h
        ${SOURCE_ROOT}/TinyBase/tiny_ret.h
        ${SOURCE_ROOT}/TinyBase/tiny_typedef.h
        )

SET(TinyBase_Source
        ${SOURCE_ROOT}/TinyBase/tiny_ret.c
        )

#---------------------------
# TinyPortable
#---------------------------

SET(TinyPortable_Header
        ${SOURCE_ROOT}/TinyPortable/tiny_inet.h
        ${SOURCE_ROOT}/TinyPortable/tiny_inline.h
        ${SOURCE_ROOT}/TinyPortable/tiny_malloc.h
        ${SOURCE_ROOT}/TinyPortable/tiny_snprintf.h
        ${SOURCE_ROOT}/TinyPortable/tiny_strdup.h
        ${SOURCE_ROOT}/TinyPortable/tiny_time.h
        )

SET(TinyPortable_Source
        ${SOURCE_ROOT}/TinyPortable/tiny_malloc.c
        ${SOURCE_ROOT}/TinyPortable/tiny_strdup.c
        ${SOURCE_ROOT}/TinyPortable/tiny_time.c
        )

#---------------------------
# TinyContainer
#---------------------------

SET(TinyContainer_Header
        ${SOURCE_ROOT}/TinyContainer/TinyContainerListener.h
        ${SOURCE_ROOT}/TinyContainer/TinyList.h
        ${SOURCE_ROOT}/TinyContainer/TinyMap.h
        ${SOURCE_ROOT}/TinyContainer/TinyMapItem.h
        ${SOURCE_ROOT}/TinyContainer/TinyQueue.h
        )

SET(TinyContainer_Source
        ${SOURCE_ROOT}/TinyContainer/TinyList.c
        ${SOURCE_ROOT}/TinyContainer/TinyMap.c
        ${SOURCE_ROOT}/TinyContainer/TinyMapItem.c
        ${SOURCE_ROOT}/TinyContainer/TinyQueue.c
        )

#---------------------------
# TinyStringUtil
#---------------------------

SET(TinyStringUtil_Header
        ${SOURCE_ROOT}/TinyStringUtil/tiny_char_util.h
        ${SOURCE_ROOT}/TinyStringUtil/tiny_str_equal.h
        ${SOURCE_ROOT}/TinyStringUtil/tiny_str_split.h
        ${SOURCE_ROOT}/TinyStringUtil/tiny_url_split.h
        ${SOURCE_ROOT}/TinyStringUtil/tiny_buffer_append.h
        ${SOURCE_ROOT}/TinyStringUtil/tiny_strnlen.h
        )

SET(TinyStringUtil_Source
        ${SOURCE_ROOT}/TinyStringUtil/tiny_char_util.c
        ${SOURCE_ROOT}/TinyStringUtil/tiny_str_equal.c
        ${SOURCE_ROOT}/TinyStringUtil/tiny_str_split.c
        ${SOURCE_ROOT}/TinyStringUtil/tiny_url_split.c
        ${SOURCE_ROOT}/TinyStringUtil/tiny_buffer_append.c
        ${SOURCE_ROOT}/TinyStringUtil/tiny_strnlen.c
        )

#---------------------------
# ByteBuffer
#---------------------------

SET(ByteBuffer_Header
        ${SOURCE_ROOT}/ByteBuffer/ByteBuffer.h
        )

SET(ByteBuffer_Source
        ${SOURCE_ROOT}/ByteBuffer/ByteBuffer.c
        )

#---------------------------
# Json
#---------------------------

SET(Json_Header
        ${SOURCE_ROOT}/Json/JsonObject.h
        ${SOURCE_ROOT}/Json/JsonArray.h
        ${SOURCE_ROOT}/Json/JsonValue.h
        ${SOURCE_ROOT}/Json/JsonDefinitions.h
        ${SOURCE_ROOT}/Json/codec/JsonDecoder.h
        ${SOURCE_ROOT}/Json/codec/JsonEncoder.h
        ${SOURCE_ROOT}/Json/codec/JsonToken.h
        ${SOURCE_ROOT}/Json/codec/JsonTokenizer.h
        ${SOURCE_ROOT}/Json/value/JsonNumber.h
        ${SOURCE_ROOT}/Json/value/JsonBoolean.h
        ${SOURCE_ROOT}/Json/value/JsonString.h
        )

SET(Json_Source
        ${SOURCE_ROOT}/Json/JsonObject.c
        ${SOURCE_ROOT}/Json/JsonArray.c
        ${SOURCE_ROOT}/Json/JsonValue.c
        ${SOURCE_ROOT}/Json/JsonDefinitions.c
        ${SOURCE_ROOT}/Json/codec/JsonDecoder.c
        ${SOURCE_ROOT}/Json/codec/JsonEncoder.c
        ${SOURCE_ROOT}/Json/codec/JsonToken.c
        ${SOURCE_ROOT}/Json/codec/JsonTokenizer.c
        ${SOURCE_ROOT}/Json/value/JsonString.c
        ${SOURCE_ROOT}/Json/value/JsonNumber.c
        ${SOURCE_ROOT}/Json/value/JsonBoolean.c
        )

SOURCE_GROUP(TinyBase\\headers FILES ${TinyBase_Header})
SOURCE_GROUP(TinyBase\\sources FILES ${TinyBase_Source})
SOURCE_GROUP(TinyPortable\\headers FILES ${TinyPortable_Header})
SOURCE_GROUP(TinyPortable\\sources FILES ${TinyPortable_Source})
SOURCE_GROUP(TinyLog\\headers FILES ${TinyLog_Header})
SOURCE_GROUP(TinyLog\\sources FILES ${TinyLog_Source})
SOURCE_GROUP(TinyContainer\\headers FILES ${TinyContainer_Header})
SOURCE_GROUP(TinyContainer\\sources FILES ${TinyContainer_Source})
SOURCE_GROUP(TinyStringUtil\\headers FILES ${TinyStringUtil_Header})
SOURCE_GROUP(TinyStringUtil\\sources FILES ${TinyStringUtil_Source})
SOURCE_GROUP(ByteBuffer\\headers FILES ${ByteBuffer_Header})
SOURCE_GROUP(ByteBuffer\\sources FILES ${ByteBuffer_Source})
SOURCE_GROUP(Json\\headers FILES ${Json_Header})
SOURCE_GROUP(Json\\sources FILES ${Json_Source})


SET(SRC
        ${TinyBase_Header}
        ${TinyBase_Source}
        ${TinyContainer_Header}
        ${TinyContainer_Source}
        ${TinyStringUtil_Header}
        ${TinyStringUtil_Source}
        ${ByteBuffer_Header}
        ${ByteBuffer_Source}
        ${Json_Header}
        ${Json_Source}
        )

#----------------------------------------------------------------------------
# static library
#----------------------------------------------------------------------------
IF (EXPORT_STATIC_LIBRARY EQUAL 1)
ADD_LIBRARY(tinycore_static STATIC ${SRC})
SET_TARGET_PROPERTIES(tinycore_static PROPERTIES OUTPUT_NAME "tinycore_static")
SET_TARGET_PROPERTIES(tinycore_static PROPERTIES LINKER_LANGUAGE C)
ENDIF ()

#----------------------------------------------------------------------------
# shared library
#----------------------------------------------------------------------------
IF (EXPORT_SHARED_LIBRARY EQUAL 1)
MESSAGE(STATUS "link library: ${DEPENDENCE_LIB}")
ADD_LIBRARY(tinycore SHARED ${SRC})
SET_TARGET_PROPERTIES(tinycore PROPERTIES OUTPUT_NAME "tinycore")
SET_TARGET_PROPERTIES(tinycore PROPERTIES LINKER_LANGUAGE C)
TARGET_LINK_LIBRARIES(tinycore ${DEPENDENCE_LIB})
ENDIF ()
