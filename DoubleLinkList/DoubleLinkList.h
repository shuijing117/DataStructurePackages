/*************************************************************************
    > File Name: DoubleLinkList.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Tue 29 Sep 2015 09:34:19 AM CST
 ************************************************************************/
#ifndef _DOUBLELINKLIST_H_

#include <malloc.h>

typedef int datatype;

typedef struct _DLINKLIST {
	datatype data;
	struct _DLINKLIST *prior;
	struct _DLINKLIST *next;
}*DoubleLinkList, *Position, Node;

int InitDoubleLinkList(DoubleLinkList *L);
int DestoryDoubleLinkList(DoubleLinkList *L);
int HeadInsert(DoubleLinkList *L, datatype data);
int TailInsert(DoubleLinkList *L, datatype data);
int ClearDoubleLinkList(DoubleLinkList *L);

int ClearDoubleLinkList(DoubleLinkList *L)
{
	Node *p, *q;

	if(L == NULL || *L == NULL) {
		return -1;
	}

	p = *L;
	while(p->next) {
		p = p->next;
	}
	q = p->prior;
	while(p != *L) {
		free(p);
		p = q;
		q = q->prior;
	}
	(*L)->next = NULL;


	return 0;
}

int TailInsert(DoubleLinkList *L, datatype data)
{
	Node *p, *q;

	if(L == NULL || *L == NULL) {
		return -1;
	}

	p = (Node *)malloc(sizeof(Node));
	if(p == NULL) {
		return -2;
	}
	p->data = data;

	q = *L;
	while(q->next) {
		q = q->next;
	}
	p->next = q->next;
	p->prior = q;
	q->next = p;

	return 0;
}

int HeadInsert(DoubleLinkList *L, datatype data)
{
	Node *p;

	if(L == NULL || *L == NULL) {
		return -1;
	}

	p = (Node *)malloc(sizeof(Node));
	if(p == NULL) {
		return -2;
	}
	p->data = data;
	p->prior = *L;
	p->next = (*L)->next;

	if((*L)->next != NULL)
		(*L)->next->prior = p;

	(*L)->next = p;

	return 0;
}

int DestoryDoubleLinkList(DoubleLinkList *L)
{
	DoubleLinkList p, q;
	if(L == NULL || *L == NULL) {
		return -1;
	}

	q = *L;
	p = q->next;
	while(p != NULL) {
		free(q);
		q = p;
		p = p->next;
	}
	free(q);

	return 0;
}

int InitDoubleLinkList(DoubleLinkList *L)
{
	if(L == NULL) {
		return -1;
	}

	*L = (DoubleLinkList)malloc(sizeof(Node));
	if(*L == NULL) {
		return -1;
	}
	(*L)->prior = NULL;
	(*L)->next = NULL;

	return 0;
}


#endif
