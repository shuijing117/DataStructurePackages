/*************************************************************************
    > File Name: LinkQueue/LinkQueue.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Tue 22 Dec 2015 10:17:01 AM CST
 ************************************************************************/

#include "LinkQueue.h"

BOOL DeLinkQueue(LinkQueue *q, datatype *data)
{
	Node *p;

	if(q == NULL) {
		return FALSE;
	}

	if(IsEmpty(*q)) {
		return FALSE;
	}

	p = q->front;
	q->front = p->next;
	if(p->next == NULL) {
		q->rear = NULL;
	}

	*data = p->data;
	free(p);

	return TRUE;
}

BOOL EnLinkQueue(LinkQueue *q, datatype data)
{
	Node *p, *s;

	if(q == NULL) {
		return FALSE;
	}

	s = (Node *)malloc(sizeof(Node));
	if(s == NULL) {
		return FALSE;
	}
	s->data = data;
	s->next = NULL;

	p = q->front;

	if(p == NULL) {
		q->front = s;
		q->rear = s;
	} else {
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = s;
		q->rear = s;
	}

	return TRUE;
}

BOOL IsEmpty(LinkQueue q)
{
	return q.front == NULL && q.rear == NULL;
}

BOOL ClearLinkQueue(LinkQueue *q)
{
	if(q == NULL) {
		return FALSE;
	}

	DestoryLinkQueue(q);

	return TRUE;
}

BOOL DestoryLinkQueue(LinkQueue *q)
{
	Node *p, *t;

	if(q == NULL) {
		return FALSE;
	}

	if(q->front == NULL) {
		return TRUE;
	}

	p = q->front;
	t = p->next;
	while(t) {
		free(p);
		p = t;
		t = p->next;
	}
	free(p);

	q->front = NULL;
	q->rear = NULL;

	return TRUE;
}

BOOL InitLinkQueue(LinkQueue *q) 
{
	if(q == NULL) {
		return FALSE;
	}

	q->front = NULL;
	q->rear = NULL;

	return TRUE;
}