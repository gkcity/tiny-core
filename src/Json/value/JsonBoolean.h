/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   JsonBoolean.h
 *
 * @remark
 *
 */

#ifndef __JSON_BOOLEAN_H__
#define __JSON_BOOLEAN_H__

#include <tiny_base.h>
#include "JsonDefinitions.h"

TINY_BEGIN_DECLS



JsonBoolean * JsonBoolean_New(_IN_ bool value);


void JsonBoolean_Delete(_IN_ JsonBoolean *thiz);


TINY_END_DECLS

#endif /* __JSON_BOOLEAN_H__ */
