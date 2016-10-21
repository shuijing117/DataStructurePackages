/*************************************************************************
    > File Name: LinkList.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Mon 28 Sep 2015 05:09:00 PM CST
 ************************************************************************/
#ifndef _S_INKLIST_H_
#define _S_LINKLIST_H_

#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define		TRUE	1
#define		FALSE	0

typedef int BOOL;
typedef int datatype;

typedef struct _LINKLIST {
	datatype data;
	struct _LINKLIST *next;
}Node, *Position;

typedef struct _LINKLISTHEAD {
	int count;
	struct _LINKLIST *next;
}*LinkList, HeadNode;

BOOL InitLinkList(LinkList *head);
BOOL DestoryLinkList(LinkList *head);
BOOL InsertLinkList(LinkList *head, datatype data, Position p);
BOOL TailInsert(LinkList *head, datatype data);
BOOL HeadInsert(LinkList *head, datatype data);
Position Find(LinkList *head, datatype data, int (*compare)(datatype, datatype));
Position FindPrevious(LinkList *head, datatype data, int (*compare)(datatype, datatype));
BOOL Delete(LinkList *head, datatype data, int (*compare)(datatype, datatype));
BOOL IsEmpty(const LinkList head);

#endif
