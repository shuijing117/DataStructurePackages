/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com
    > Created Time: Mon 28 Sep 2015 10:04:32 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LinkList.h"

void Print(LinkList head);
int compare(datatype data1, datatype data2);

int compare(datatype data1, datatype data2)
{
	return data1 == data2;
}

void Print(LinkList head)
{
	Node *p;
	int i = 1;

	p = head->next;
	while(p) {
		printf("%d-%p:%d ", i, p, p->data);
		p = p->next;
		i++;
	}
	printf("\n");
}

int main(void)
{
	int i;
	datatype data;
	LinkList head;
	Position p;
	LinkList *q;

	srand((int)time(NULL));

	InitLinkList(&head);

	Print(head);

	for(i = 0; i < 5; i++) {
		HeadInsert(&head, rand()%100);
	}

	printf("count:%d\n", head->count);
	Print(head);

	for(i = 0; i < 5; i++) {
		TailInsert(&head, rand()%100);
	}

	printf("count:%d\n", head->count);
	Print(head);

	printf("Find :");
	scanf("%d", &data);
	if(p = Find(&head, data, compare)) {
		printf("%p:%d\n", p, p->data);
	} else {
		printf("none.\n");
	}

	InsertLinkList(&head, data+1, p);
	Print(head);

	if(p = FindPrevious(&head, data, compare)) {
		if(p == (Position)1) {
			printf("head:%p count:%d\n", &head, head->count);
		} else {
			printf("%p:%d %d\n", p, p->data, data);
		}
	} else {
		printf("none.\n");
	}

	printf("Delete:");
	scanf("%d", &data);
	Delete(&head, data, compare);
	Print(head);

	DestoryLinkList(&head);
}
