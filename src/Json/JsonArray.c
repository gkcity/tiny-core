/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   JsonArray.h
 *
 * @remark
 *
 */

#include <tiny_malloc.h>
#include <tiny_log.h>
#include <codec/JsonEncoder.h>
#include "JsonArray.h"
#include "JsonValue.h"

#define TAG     "JsonArray"


static void _OnJsonValueDelete (void * data, void *ctx)
{
    JsonValue_Delete((JsonValue *)data);
}


TinyRet JsonArray_Construct(JsonArray *thiz)
{
    TinyRet ret = TINY_RET_OK;

    RETURN_VAL_IF_FAIL(thiz, TINY_RET_E_ARG_NULL);

    do 
    {
        memset(thiz, 0, sizeof(JsonArray));
        thiz->string = NULL;

        ret = TinyList_Construct(&thiz->values, _OnJsonValueDelete, thiz);
        if (RET_FAILED(ret))
        {
            break;
        }
    } while (false);

    return ret;
}


void JsonArray_Dispose(JsonArray *thiz)
{
    RETURN_IF_FAIL(thiz);

    if (thiz->string != NULL)
    {
        tiny_free(thiz->string);
        thiz->string = NULL;
    }

    TinyList_Dispose(&thiz->values);
}


JsonArray * JsonArray_New(void)
{
    JsonArray * thiz = NULL;

    do
    {
        thiz = (JsonArray *) tiny_malloc(sizeof(JsonArray));
        if (thiz == NULL)
        {
            break;
        }

        if (RET_FAILED(JsonArray_Construct(thiz)))
        {
            LOG_E(TAG, "JsonArray_Construct FAILED");
            JsonArray_Delete(thiz);
            thiz = NULL;
            break;
        }
    } while (false);

    return thiz;
}


void JsonArray_Delete(JsonArray *thiz)
{
    JsonArray_Dispose(thiz);
    tiny_free(thiz);
}


JsonArray * JsonArray_NewFrom(JsonArray *src)
{
    JsonArray * thiz = NULL;

    do
    {
        if (src == NULL)
        {
            break;
        }

        thiz = JsonArray_New();
        if (thiz == NULL)
        {
            break;
        }

        if (RET_FAILED(JsonArray_Copy(thiz, src)))
        {
            LOG_D(TAG, "JsonArray_Copy failed");
            JsonArray_Delete(thiz);
            thiz = NULL;
            break;
        }
    } while (false);

    return thiz;
}


TinyRet JsonArray_AddString(JsonArray *thiz, const char *value)
{
    TinyRet ret = TINY_RET_OK;

    RETURN_VAL_IF_FAIL(thiz, TINY_RET_E_ARG_NULL);
    RETURN_VAL_IF_FAIL(value, TINY_RET_E_ARG_NULL);

    do
    {
        JsonValue * v = JsonValue_NewString(value);
        if (v == NULL)
        {
            LOG_E(TAG, "JsonValue_NewString FAILED!");
            ret = TINY_RET_E_NEW;
            break;
        }

        ret = TinyList_AddTail(&thiz->values, v);
        if (RET_FAILED(ret))
        {
            JsonValue_Delete(v);
        }
    } while (false);

    return ret;
}


TinyRet JsonArray_AddInteger(JsonArray *thiz, int value)
{
    TinyRet ret = TINY_RET_OK;

    RETURN_VAL_IF_FAIL(thiz, TINY_RET_E_ARG_NULL);

    do
    {
        JsonValue * v = JsonValue_NewInteger(value);
        if (v == NULL)
        {
            LOG_E(TAG, "JsonValue_NewInteger FAILED!");
            ret = TINY_RET_E_NEW;
            break;
        }

        ret = TinyList_AddTail(&thiz->values, v);
        if (RET_FAILED(ret))
        {
            JsonValue_Delete(v);
        }
    } while (false);

    return ret;
}


TinyRet JsonArray_AddFloat(JsonArray *thiz, float value)
{
    TinyRet ret = TINY_RET_OK;

    RETURN_VAL_IF_FAIL(thiz, TINY_RET_E_ARG_NULL);

    do
    {
        JsonValue * v = JsonValue_NewFloat(value);
        if (v == NULL)
        {
            LOG_E(TAG, "JsonValue_NewInteger FAILED!");
            ret = TINY_RET_E_NEW;
            break;
        }

        ret = TinyList_AddTail(&thiz->values, v);
        if (RET_FAILED(ret))
        {
            JsonValue_Delete(v);
        }
    } while (false);

    return ret;
}


TinyRet JsonArray_AddObject(JsonArray *thiz, JsonObject *value)
{
    TinyRet ret = TINY_RET_OK;

    RETURN_VAL_IF_FAIL(thiz, TINY_RET_E_ARG_NULL);
    RETURN_VAL_IF_FAIL(value, TINY_RET_E_ARG_NULL);

    do
    {
        JsonValue * v = JsonValue_NewValue(JSON_OBJECT, value);
        if (v == NULL)
        {
            LOG_E(TAG, "JsonValue_NewInteger FAILED!");
            ret = TINY_RET_E_NEW;
            break;
        }

        ret = TinyList_AddTail(&thiz->values, v);
        if (RET_FAILED(ret))
        {
            JsonValue_Delete(v);
        }
    } while (false);

    return ret;
}


TinyRet JsonArray_AddArray(JsonArray *thiz, JsonArray *value)
{
    TinyRet ret = TINY_RET_OK;

    RETURN_VAL_IF_FAIL(thiz, TINY_RET_E_ARG_NULL);
    RETURN_VAL_IF_FAIL(value, TINY_RET_E_ARG_NULL);

    do
    {
        JsonValue * v = JsonValue_NewValue(JSON_ARRAY, value);
        if (v == NULL)
        {
            LOG_E(TAG, "JsonValue_NewValue FAILED!");
            ret = TINY_RET_E_NEW;
            break;
        }

        ret = TinyList_AddTail(&thiz->values, v);
        if (RET_FAILED(ret))
        {
            JsonValue_Delete(v);
        }
    } while (false);

    return ret;
}


TinyRet JsonArray_AddValue(JsonArray *thiz, JsonValue *value)
{
    RETURN_VAL_IF_FAIL(thiz, TINY_RET_E_ARG_NULL);
    RETURN_VAL_IF_FAIL(value, TINY_RET_E_ARG_NULL);

    return TinyList_AddTail(&thiz->values, value);
}


bool JsonArray_CheckValuesType(JsonArray *thiz, JsonValueType type)
{
    RETURN_VAL_IF_FAIL(thiz, false);

    for (uint32_t i = 0; i < thiz->values.size; ++i)
    {
        JsonValue *v = (JsonValue *) TinyList_GetAt(&thiz->values, i);
        if (v->type != JSON_OBJECT) {
            return false;
        }
    }

    return true;
}


TinyRet JsonArray_Copy(JsonArray *dst, JsonArray *src)
{
    TinyRet ret = TINY_RET_OK;

    RETURN_VAL_IF_FAIL(dst, TINY_RET_E_ARG_NULL);
    RETURN_VAL_IF_FAIL(src, TINY_RET_E_ARG_NULL);

    if (dst != src)
    {
        JsonArray_Clean(dst);

        for (uint32_t i = 0; i < src->values.size; ++i)
        {
            JsonValue *v = (JsonValue *) TinyList_GetAt(&src->values, i);
            JsonValue *newValue = JsonValue_NewFrom(v);
            if (newValue == NULL)
            {
                LOG_D(TAG, "JsonValue_Copy failed");
                ret = TINY_RET_E_NEW;
                break;
            }

            ret = JsonArray_AddValue(dst, newValue);
            if (RET_FAILED(ret))
            {
                break;
            }
        }
    }

    return ret;
}


TinyRet JsonArray_Clean(JsonArray *thiz)
{
    RETURN_VAL_IF_FAIL(thiz, TINY_RET_E_ARG_NULL);

    if (thiz->string != NULL)
    {
        tiny_free(thiz->string);
        thiz->string = NULL;
    }

    return TinyList_RemoveAll(&thiz->values);
}
