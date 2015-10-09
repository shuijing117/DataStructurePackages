/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Fri 09 Oct 2015 09:56:02 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Stack.h"

void Print(Stack s);

//Just test. Stack can not use this way to print.
void Print(Stack s)
{
	int i;

	printf("Stack:");
	for(i = 0; i <= s.top; i++)	{
		printf("%d ", s.data[i]);
	}
	printf("\n");
}

int main(void)
{
	int i;
	datatype data;
	Stack s;

	InitStack(&s, 20);
	Print(s);

	for(i = 0; i < 20; i++) {
		Push(&s, rand()%100);
	}
	Print(s);

	Pop(&s, &data);
	printf("Pop:%d\n", data);
	Print(s);

	GetTop(s, &data);
	printf("GetTop:%d\n", data);
	Print(s);

	ClearStack(&s);
	Print(s);




	DestoryStack(&s);

	return 0;
}
