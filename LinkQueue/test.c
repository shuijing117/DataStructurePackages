/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Wed 11 Nov 2015 08:24:35 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#include "LinkQueue.h"

void Print(LinkQueue q);

void Print(LinkQueue q) 
{
	Node *p = q.front;

	printf("LinkQueue:\n");
	while(p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main(void) {
	LinkQueue q;
	datatype data;
	int i;

	srand((unsigned int)time(NULL));

	InitLinkQueue(&q);
	Print(q);

	for(i = 0; i < 10; i++) {
		EnLinkQueue(&q, rand() % 100);
	}
	Print(q);

	for(i = 0; i < 12; i++) {
		DeLinkQueue(&q, &data);
		printf("data:%d\n", data);
		Print(q);
	}
//	DeLinkQueue(&q, &data);
//	printf("data:%d\n", data);
//	Print(q);

	DestoryLinkQueue(&q);

	return 0;
}
