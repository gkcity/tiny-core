/**
 *
 * Copyright (C) 2007-2012 jxfengzi
 *
 * @author jxfengzi@gmail.com
 * @date   2010-5-25
 *
 * @file   TinyList.h
 *
 * @version 2010.5.25

 * @remark
 *      set tabstop=4
 *      set shiftwidth=4
 *      set expandtab
 */

#ifndef __TINY_LIST_H__
#define __TINY_LIST_H__

#include <tiny_api.h>
#include <tiny_base.h>

#include "TinyContainerListener.h"

TINY_BEGIN_DECLS

struct _TinyNode;
typedef struct _TinyNode TinyNode;

typedef struct _TinyList
{
    uint32_t                              size;
    TinyNode                            * first;
    TinyContainerItemDeleteListener       data_delete_listener;
    void                                * data_delete_listener_ctx;
    void                                * context;
} TinyList;

TINY_API

TinyRet TinyList_Construct(TinyList *thiz, TinyContainerItemDeleteListener listener, void *ctx);

TINY_API

TinyRet TinyList_Dispose(TinyList *thiz);

TINY_API

TinyList * TinyList_New(TinyContainerItemDeleteListener listener, void *ctx);

TINY_API

void TinyList_Delete(TinyList *thiz);

TINY_API

int TinyList_Foreach(TinyList * thiz, TinyContainerItemVisit visit, void * ctx);

TINY_API

void * TinyList_GetHead(TinyList * thiz);

TINY_API

void * TinyList_GetTail(TinyList * thiz);

TINY_API

TinyRet TinyList_AddHead(TinyList * thiz, void *data);

TINY_API

TinyRet TinyList_AddTail(TinyList * thiz, void *data);

TINY_API

TinyRet TinyList_RemoveAll(TinyList * thiz);

TINY_API

TinyRet TinyList_RemoveHead(TinyList * thiz);

TINY_API

TinyRet TinyList_RemoveTail(TinyList * thiz);

TINY_API

int TinyList_GetHeadPosition(TinyList * thiz);

TINY_API

int TinyList_GetTailPosition(TinyList * thiz);

TINY_API

void * TinyList_GetNext(TinyList * thiz, int pos);

TINY_API

void * TinyList_GetPrev(TinyList * thiz, int pos);

TINY_API

void * TinyList_GetAt(const TinyList * thiz, int pos);

TINY_API

TinyRet TinyList_RemoveAt(TinyList * thiz, int pos);

TINY_API

TinyRet TinyList_SetAt(TinyList * thiz, int pos, void * data);

TINY_API

TinyRet TinyList_InsertAfter(TinyList * thiz, int pos, void * data);

TINY_API

TinyRet TinyList_InsertBefore(TinyList * thiz, int pos, void * data);


TINY_END_DECLS

#endif /* __TINY_LIST_H__ */
