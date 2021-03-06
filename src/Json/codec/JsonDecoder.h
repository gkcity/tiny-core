/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   JsonDecoder.h
 *
 * @remark
 *
 */

#ifndef __JSON_DECODER_COMPACT_H__
#define __JSON_DECODER_COMPACT_H__

#include <tiny_base.h>
#include <tiny_api.h>

#include "JsonTokenizer.h"
#include "JsonObject.h"

TINY_BEGIN_DECLS


typedef struct _JsonDecoder
{
    JsonTokenizer   tokenizer;
} JsonDecoder;

typedef enum _JsonDecoderMode
{
    JSON_DECODE_NORMAL      = 0,
    JSON_DECODE_LOW_MEMORY  = 1,
} JsonDecoderMode;


TINY_API
TinyRet JsonDecoder_Construct(_IN_ JsonDecoder *thiz);


TINY_API
void JsonDecoder_Dispose(_IN_ JsonDecoder *thiz);


TINY_API
JsonObject * JsonDecoder_Parse(_IN_ JsonDecoder *thiz, _IN_ const char *string, _IN_ JsonDecoderMode mode);


TINY_END_DECLS

#endif /* __JSON_DECODER_COMPACT_H__ */
