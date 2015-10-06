/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Wed 30 Sep 2015 10:40:52 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#include "StringMatching.h"

#define _MAX_SIZE_ 100

void Print(const char *mStr, const char *pStr, int pos);

void Print(const char *mStr, const char *pStr, int pos)
{
	int i;

	if(pos > -1){
		printf("%s\n", mStr);
		for(i = 0; i < pos; i++)
			printf(" ");
		printf("%s\n", pStr);
	} else {
		printf("No Match.\n");
	}
}

int main(void)
{
	char mStr[_MAX_SIZE_];
	char pStr[_MAX_SIZE_];
	int i, position;

	printf("main string :");
	scanf("%s", mStr);
	printf("pattern string:");
	scanf("%s", pStr);

	position = BruteForceMatching(mStr, pStr);
//	printf("position : %d\n", position);
	printf("SimpleMatching:\n");
	Print(mStr, pStr, position);
	return 0;
}
