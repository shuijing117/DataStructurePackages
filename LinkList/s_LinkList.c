/*************************************************************************
    > File Name: LinkList/LinkList.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Tue 22 Dec 2015 10:16:46 AM CST
 ************************************************************************/

#include "s_LinkList.h"

BOOL IsEmpty(const LinkList head)
{
	return head->count == 0;
}

BOOL Delete(LinkList *head, datatype data, int (*compare)(datatype, datatype))
{
	Position p, q;

	if(head == NULL) {
		return FALSE;
	}

	while(1) {
		p = FindPrevious(head, data, compare);
		if(p == NULL) {
			return FALSE;
		} else if(p == (Position)1) {
			q = (*head)->next;
			(*head)->next = q->next;
			free(q);
		} else {
			q = p->next;
			p->next = q->next;
			free(q);
		}
	}
	(*head)->count--;

	return TRUE;
}

Position FindPrevious(LinkList *head, datatype data, int (*compare)(datatype, datatype))
{
	Position p = (*head)->next;

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
	Position p = (*head)->next;

	while(p) {
		if(compare(p->data, data)) {
			return p;
		}
		p = p->next;
	}

	return NULL;
}


BOOL HeadInsert(LinkList *head, datatype data)
{
	Node *p;

	if(head == NULL) {
		return FALSE;
	}

	p = (Node *)malloc(sizeof(Node));
	if(p == NULL) {
		return FALSE;
	}
	p->data = data;
	p->next = (*head)->next;
	(*head)->next = p;
	(*head)->count++;

	return TRUE;
}

BOOL TailInsert(LinkList *head, datatype data)
{
	Node *p, *q;

	if(head == NULL) {
		return FALSE;
	}

	p = (Node *)malloc(sizeof(Node));
	if(p == NULL ) {
		return FALSE;
	}
	p->data = data;
	p->next = NULL;

	if((*head)->next == NULL) {
		(*head)->next = p;
	} else {
		for(q = (*head)->next; q->next != NULL; q = q->next)
			;

		q->next = p;
	}
	(*head)->count++;

	return TRUE;
}

BOOL InsertLinkList(LinkList *head, datatype data, Position p)
{
	Node *node;

	if(head == NULL) {
		return FALSE;
	}

	node = (Node *)malloc(sizeof(Node));
	if(node == NULL) {
		return FALSE;
	}
	node->data = data;
	node->next = p->next;
	p->next = node;

	(*head)->count++;

	return TRUE;
}

BOOL DestoryLinkList(LinkList *head)
{
	Node *p;

	if(head == NULL) {
		return FALSE;
	}

	if((*head)->count == 0) {
		return TRUE;
	}

	if((*head)->count == 1) {
		free((*head)->next);
		return TRUE;
	}
	
	for(p = (*head)->next->next; p != NULL; p = p->next) {
		free((*head)->next);
		(*head)->next = p;
	}

	return TRUE;
}

BOOL InitLinkList(LinkList *head)
{
	if(head == NULL) {
		return FALSE;
	}

	*head = (LinkList)malloc(sizeof(HeadNode));
	if(*head == NULL) {
		return FALSE;
	}

	(*head)->count = 0;
	(*head)->next = NULL;

	return TRUE;
}
