/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Wed 11 Nov 2015 10:24:48 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#include "Search.h"
#include "../Sort/Sort.h"

#define N 30

BOOL compare(datatype data1, datatype data2);
void Print(int *array, int len);

void Print(int *array, int len)
{
	int i;

	for(i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

BOOL compare(datatype data1, datatype data2)
{
	return data1 - data2;
}

int main(void) 
{
	int array[N];
	int i;
	int data;
	int index;

	srand((unsigned int)time(NULL));

	for(i = 0; i < N; i++) {
		array[i] = rand() % 100;
	}
	Print(array, N);
	QuickSort(array, 0, N-1);
	Print(array, N);

	while(scanf("%d", &data) != EOF) {
		printf("LinearSearch:\n");
		index = LinearSearch(array, N, data, compare);
		printf("index:%d\n", index);
		printf("BinarySearch:\n");
		index = BinarySearch(array, N, data, compare);
		printf("index:%d\n", index);
		printf("BinarySearchRecursion:\n");
		index = BinarySearchRecursion(array, 0, N-1, data, compare);
		printf("index:%d\n", index);
	}

	return 0;
}
