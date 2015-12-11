/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Fri 11 Dec 2015 11:17:49 AM CST
 ************************************************************************/

#include <stdio.h>

#include "AdjMatrix.h"

int main(void) 
{
    AdjMatrix G;

	CreateAdjMatrix(&G);

	PrintAdjMatrix(&G);

	printf("DepthTraverseGraph: ");
	DepthTraverseGraph(&G);
	printf("\n");

	printf("BreadthTraverseGraph:");
	BreadthTraverseGraph(&G);
	printf("\n");

	DestroyAdjMatrix(&G);

	return 0;
}
