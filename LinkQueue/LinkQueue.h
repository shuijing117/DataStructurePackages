/*************************************************************************
    > File Name: LinkQueue.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Wed 11 Nov 2015 07:49:39 PM CST
 ************************************************************************/
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include <malloc.h>

#define		TRUE	1
#define		FALSE	0

typedef int BOOL;

typedef int datatype;

typedef struct _NODE{
	datatype data;
	struct _NODE *next;
}Node;

typedef struct _HEAD {
	struct _NODE *front;
	struct _NODE *rear;
}LinkQueue;

BOOL InitLinkQueue(LinkQueue *q);
BOOL DestoryLinkQueue(LinkQueue *q);
BOOL ClearLinkQueue(LinkQueue *q);
BOOL IsEmpty(LinkQueue q);
BOOL EnLinkQueue(LinkQueue *q, datatype data);
BOOL DeLinkQueue(LinkQueue *q, datatype *data);

#endif
