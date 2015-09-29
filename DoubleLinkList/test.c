/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Tue 29 Sep 2015 09:35:13 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "DoubleLinkList.h"

void Print(DoubleLinkList L);

void Print(DoubleLinkList L)
{
	int i;
	DoubleLinkList p = L;

	for(i = 1; p != NULL; i++, p = p->next) {
		printf("%d-%p:%d ", i, p, p->data);
	}
	printf("\n");
}

int main(void)
{
	int i;
	DoubleLinkList L;

	InitDoubleLinkList(&L);
	printf("Init:\n");
	Print(L);

	srand((int)time(NULL));

	for(i = 0; i< 5; i++) {
		HeadInsert(&L, rand()%100);
	}
	printf("HeadInsert:\n");
	Print(L);

	for(i = 0; i< 5; i++) {
		TailInsert(&L, rand()%100);
	}
	printf("TailInsert:\n");
	Print(L);

	ClearDoubleLinkList(&L);
	Print(L);

	DestoryDoubleLinkList(&L);

	return 0;
}
