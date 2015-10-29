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

void Print(datatype *data, const int size);
void Copy(datatype *data1, datatype *data2, const int size);

void Copy(datatype *data1, datatype *data2, const int size)
{
	int i;

	for(i = 0; i < size; i++) {
		data2[i] = data1[i];
	}
}

void Print(datatype *data, const int size)
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
	datatype temp[N];
	int i;

	srand((unsigned int)time(NULL));

	for(i = 0; i < N; i++) {
		data[i] = rand()%201;
	}
	Print(data, N);
	Copy(data, temp, N);
//	Print(temp, N);

	printf("InsertionSort: \n");
//	Print(data, N);
	InsertionSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("BinaryInsertionSort:\n");
//	Print(data, N);
	BinaryInsertionSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("ShellSort:\n");
//	Print(data, N);
	ShellSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("SelectionSort:\n");
//	Print(data, N);
	SelectionSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("BubbleSort:\n");
//	Print(data, N);
	BubbleSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("QuickSort:\n");
//	Print(data, N);
	QuickSort(data, 0, N-1);
	Print(data, N);

	Copy(temp, data, N);
	printf("MergeSort:\n");
//	Print(data, N);
	MergeSort(data, 0, N-1);
	Print(data, N);

	Copy(temp, data, N);
	printf("HeapSort:\n");
//	Print(data, N);
	HeapSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("CountingSort:\n");
	CountingSort(data, N);
	Print(data, N);

	return 0;
}
