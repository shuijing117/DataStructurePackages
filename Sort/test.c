/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Sat 10 Oct 2015 07:54:04 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Sort.h"

#define N 40

void Print(datatype *data, int size);

void Print(datatype *data, int size)
{
	int i;

	if(data == NULL) {
		return;
	}

	for(i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}

int main(void)
{
	datatype data[N];
	int i;

	srand((unsigned int)time(NULL));

	for(i = 0; i < N; i++) {
		data[i] = rand()%100;
	}
	Print(data, N);

	printf("InsertionSort: \n");
	InsertionSort(data, N);
	Print(data, N);

	printf("BinaryInsertionSort:\n");
	BinaryInsertionSort(data, N);
	Print(data, N);

	printf("ShellSort:\n");
	ShellSort(data, N);
	Print(data, N);

	printf("SelectionSort:\n");
	SelectionSort(data, N);
	Print(data, N);

	printf("BubbleSort:\n");
	BubbleSort(data, N);
	Print(data, N);

	printf("QuickSort:\n");
	QuickSort(data, 0, N-1);
	Print(data, N);

	printf("MergeSort:\n");
	MergeSort(data, 0, N-1);
	Print(data, N);

	return 0;
}
