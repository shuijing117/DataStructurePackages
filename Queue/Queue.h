/*************************************************************************
    > File Name: Queue.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Fri 09 Oct 2015 10:22:05 PM CST
 ************************************************************************/
#ifndef _QUEUE_

#include <malloc.h>

typedef int datatype;

typedef struct _QUEUE {
	datatype *data;
	int front;
	int rear;
	int size;
}Queue;

int InitQueue(Queue *q, int size);
int DestoryQueue(Queue *q);
int ClearQueue(Queue *q);
int IsEmpty(Queue q);
int IsFull(Queue q);
int EnQueue(Queue *q, datatype data);
int DeQueue(Queue *q, datatype *data);
int GetHead(Queue q, datatype *data);

int GetHead(Queue q, datatype *data)
{
	if(IsEmpty(q)) {
		return -1;
	}

	*data = q.data[q.front];

	return 0;
}

int DeQueue(Queue *q, datatype *data)
{
	if(q == NULL) {
		return -1;
	}

	if(IsEmpty(*q)) {
		return -2;
	}

	*data = q->data[q->front];
	q->front = (q->front + 1) % q->size;

	return 0;
}

int EnQueue(Queue *q, datatype data)
{
	if(q == NULL) {
		return -1;
	}

	if(IsFull(*q)) {
		return -2;
	}

	q->data[q->rear] = data;
	q->rear = (q->rear+1) % q->size;

	return 0;
}

int IsFull(Queue q)
{
	return (q.rear+1) % q.size == q.front;
}

int IsEmpty(Queue q)
{
	return q.front == q.rear;
}

int ClearQueue(Queue *q)
{
	if(q == NULL) {
		return -1;
	}

	q->front = 0;
	q->rear = 0;

	return 0;
}

int DestoryQueue(Queue *q)
{
	if(q == NULL) {
		return -1;
	}

	free(q->data);

	return 0;
}

int InitQueue(Queue *q, int size)
{
	if(q == NULL) {
		return -1;
	}

	q->data = (datatype *)malloc(sizeof(datatype) * size);
	if(q->data == NULL) {
		return -2;
	}

	q->size = size;
	q->front = 0;
	q->rear = 0;

	return 0;
}

#endif
