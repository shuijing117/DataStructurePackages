/*************************************************************************
    > File Name: Queue/Queue.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Tue 22 Dec 2015 10:17:12 AM CST
 ************************************************************************/

#include "Queue.h"

BOOL GetHead(Queue q, datatype *data)
{
	if(IsEmpty(q)) {
		return FALSE;
	}

	*data = q.data[q.front];

	return TRUE;
}

BOOL DeQueue(Queue *q, datatype *data)
{
	if(q == NULL) {
		return FALSE;
	}

	if(IsEmpty(*q)) {
		return FALSE;
	}

	*data = q->data[q->front];
	q->front = (q->front + 1) % q->size;

	return TRUE;
}

BOOL EnQueue(Queue *q, datatype data)
{
	if(q == NULL) {
		return FALSE;
	}

	if(IsFull(*q)) {
		return FALSE;
	}

	q->data[q->rear] = data;
	q->rear = (q->rear+1) % q->size;

	return TRUE;
}

BOOL IsFull(Queue q)
{
	return (q.rear+1) % q.size == q.front;
}

BOOL IsEmpty(Queue q)
{
	return q.front == q.rear;
}

BOOL ClearQueue(Queue *q)
{
	if(q == NULL) {
		return FALSE;
	}

	q->front = 0;
	q->rear = 0;

	return TRUE;
}

BOOL DestoryQueue(Queue *q)
{
	if(q == NULL) {
		return FALSE;
	}

	free(q->data);

	return TRUE;
}

BOOL InitQueue(Queue *q, int size)
{
	if(q == NULL) {
		return FALSE;
	}

	q->data = (datatype *)malloc(sizeof(datatype) * size);
	if(q->data == NULL) {
		return FALSE;
	}

	q->size = size;
	q->front = 0;
	q->rear = 0;

	return TRUE;
}