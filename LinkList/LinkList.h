/*************************************************************************
    > File Name: LinkList.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Mon 28 Sep 2015 05:09:00 PM CST
 ************************************************************************/
#ifndef _LINKLIST_H_

#include <malloc.h>
#include <stdlib.h>
#include <time.h>

typedef int datatype;

typedef struct _LINKLIST {
	datatype data;
	struct _LINKLIST *next;
}Node, * Position;

typedef struct _LINKLISTHEAD {
	int count;
	struct _LINKLIST *next;
}LinkList;

#define  _HEAD_INSERT_  0
#define  _TAIL_INSERT_  1

int InitLinkList(LinkList *head);
int DestoryLinkList(LinkList *head);
int InsertLinkList(LinkList *head, datatype data, int mode);
int TailInsert(LinkList *head, datatype data);
int HeadInsert(LinkList *head, datatype data);
Position Find(LinkList *head, datatype data, int (*compare)(datatype, datatype));
Position FindPrevious(LinkList *head, datatype data, int (*compare)(datatype, datatype));
int Delete(LinkList *head, datatype data, int (*compare)(datatype, datatype));
int IsEmpty(const LinkList head);

int IsEmpty(const LinkList head)
{
	return head.count == 0;
}

int Delete(LinkList *head, datatype data, int (*compare)(datatype, datatype))
{
	Position p, q;

	if(head == NULL) {
		return -1;
	}

	while(1) {
		p = FindPrevious(head, data, compare);
		if(p == NULL) {
			return -1;
		} else if(p == (Position)1) {
			q = head->next;
			head->next = q->next;
			free(q);
		} else {
			q = p->next;
			p->next = q->next;
			free(q);
		}
	}
	head->count--;

	return 0;
}

Position FindPrevious(LinkList *head, datatype data, int (*compare)(datatype, datatype))
{
	Position p = head->next;

	if(p == NULL) {
		return NULL;
	}

	if(compare(p->data, data)) {
		return (Position)1;
	}

	while(p->next) {
		if(compare(p->next->data, data)) {
			return p;
		}
		p = p->next;
	}

	return NULL;
}

Position Find(LinkList *head, datatype data, int (*compare)(datatype, datatype))
{
	Position p = head->next;

	while(p) {
		if(compare(p->data, data)) {
			return p;
		}
		p = p->next;
	}

	return NULL;
}


int HeadInsert(LinkList *head, datatype data)
{
	Node *p;

	if(head == NULL) {
		return -1;
	}

	p = (Node *)malloc(sizeof(Node));
	if(p == NULL) {
		return -1;
	}
	p->data = data;
	p->next = head->next;
	head->next = p;
	head->count++;

	return 0;
}

int TailInsert(LinkList *head, datatype data)
{
	Node *p, *q;

	if(head == NULL) {
		return -1;
	}

	p = (Node *)malloc(sizeof(Node));
	if(p == NULL ) {
		return -1;
	}
	p->data = data;
	p->next = NULL;

	if(head->next == NULL) {
		head->next = p;
	} else {
		for(q = head->next; q->next != NULL; q = q->next)
			;

		q->next = p;
	}
	head->count++;

	return 0;
}

int InsertLinkList(LinkList *head, datatype data, int mode)
{
	if(head == NULL) {
		return -1;
	}

	if(mode == _HEAD_INSERT_) {
		if(HeadInsert(head, data)) {
			return -1;
		}
	} else if(mode == _TAIL_INSERT_) {
		if(TailInsert(head, data)) {
			return -1;
		}
	}

	return 0;
}

int DestoryLinkList(LinkList *head)
{
	Node *p;

	if(head == NULL) {
		return -1;
	}

	if(head->count == 0) {
		return 0;
	}

	if(head->count == 1) {
		free(head->next);
		return 0;
	}
	
	for(p = head->next->next; p != NULL; p = p->next) {
		free(head->next);
		head->next = p;
	}

	return 0;
}

int InitLinkList(LinkList *head)
{
	if(head == NULL) {
		return -1;
	}

	head->count = 0;
	head->next = NULL;

	return 0;
}

#endif
