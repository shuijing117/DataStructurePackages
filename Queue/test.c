/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Fri 09 Oct 2015 11:00:11 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Queue.h"

void Print(Queue q);

//Just test. Queue can not use this way to print.
void Print(Queue q)
{
	int i;
	int temp = q.rear > q.front ? q.rear : q.size;
	if(q.front == q.rear) {
		return;
	}

	printf("Queue->front:%d, Queue->rear;%d  --- Queue: ", q.front, q.rear);
	for(i = q.front; i < temp; i++) {
		printf("%d ", q.data[i]);
	}

	if(q.rear < q.front) {
		for(i = 0; i < q.rear; i++) {
			printf("%d ", q.data[i]);
		}
	}
	printf("\n");
}

int main(void)
{
	Queue q;
	datatype data;
	int i;

	srand((unsigned int)time(NULL));

	InitQueue(&q, 20);

	for(i = 0; i < 15; i++) {
		EnQueue(&q, rand()%100);
	}
	Print(q);//15  front=0 rear=15

	for(i = 0; i < 5; i++) {
		DeQueue(&q, &data);
	}
	Print(q);//10 front=5 rear=15

	for(i = 0; i < 7; i++) {
		EnQueue(&q, rand()%100);
	}
	Print(q);//17 front=5 rear=2

	for(i = 0; i < 3; i++) {
		EnQueue(&q, rand()%100);
	}
	Print(q);//19 front=5 rear=4  The third number can not enter queue.

	GetHead(q, &data);
	printf("GetHead:%d\n", data);

	ClearQueue(&q);
	Print(q);

	DestoryQueue(&q);

	return 0;
}
