/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   JsonToken.h
 *
 * @remark
 *
 */

#ifndef __JSON_TOKEN_H__
#define __JSON_TOKEN_H__

#include <tiny_base.h>

TINY_BEGIN_DECLS


typedef enum _JsonTokenType
{
    JSON_TOKEN_OBJECT_START     = 1,
    JSON_TOKEN_OBJECT_END       = 2,
    JSON_TOKEN_ARRAY_START      = 3,
    JSON_TOKEN_ARRAY_END        = 4,
    JSON_TOKEN_COMMA            = 5,
    JSON_TOKEN_COLON            = 6,
    JSON_TOKEN_NULL             = 7,
    JSON_TOKEN_TRUE             = 8,
    JSON_TOKEN_FALSE            = 9,
    JSON_TOKEN_STRING           = 10,
    JSON_TOKEN_NUMBER           = 11,
} JsonTokenType;

typedef struct _JsonToken
{
    JsonTokenType   type;
    uint32_t        offset;
    uint32_t        length;
} JsonToken;


JsonToken * JsonToken_New(_IN_ JsonTokenType type, _IN_ uint32_t offset, _IN_ uint32_t length);


void JsonToken_Delete(_IN_ JsonToken *thiz);


TINY_END_DECLS

#endif /* __JSON_TOKEN_H__ */
