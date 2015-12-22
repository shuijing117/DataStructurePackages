/*************************************************************************
    > File Name: Queue.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Fri 09 Oct 2015 10:22:05 PM CST
 ************************************************************************/
#ifndef _QUEUE_
#define _QUEUE_

#include <malloc.h>

#define		TRUE	1
#define		FALSE	0

typedef int BOOL;
typedef int datatype;

typedef struct _QUEUE {
	datatype *data;
	int front;
	int rear;
	int size;
}Queue;

BOOL InitQueue(Queue *q, int size);
BOOL DestoryQueue(Queue *q);
BOOL ClearQueue(Queue *q);
BOOL IsEmpty(Queue q);
BOOL IsFull(Queue q);
BOOL EnQueue(Queue *q, datatype data);
BOOL DeQueue(Queue *q, datatype *data);
BOOL GetHead(Queue q, datatype *data);

#endif
