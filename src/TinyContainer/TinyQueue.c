/**
 *
 * Copyright (C) 2007-2012 coding.tom
 *
 * @author jxfengzi@gmail.com
 * @date   2013-5-25
 *
 * @file   queue.c
 *
 * @version 2013.8.6

 * @remark
 *      set tabstop=4
 *      set shiftwidth=4
 *      set expandtab
 */

#include "TinyQueue.h"


TinyRet TinyQueue_Construct(TinyQueue *thiz, TinyContainerItemDeleteListener listener, void *ctx)
{
    return TinyList_Construct(thiz, listener, ctx);
}


TinyRet TinyQueue_Dispose(TinyQueue *thiz)
{
    return TinyList_Dispose(thiz);
}


void * TinyQueue_Head(TinyQueue *thiz)
{
    return TinyList_GetHead(thiz);
}


TinyRet TinyQueue_Push(TinyQueue *thiz, void *data)
{
    return TinyList_AddTail(thiz, data);
}


void TinyQueue_Pop(TinyQueue *thiz)
{
    TinyList_RemoveHead(thiz);
}