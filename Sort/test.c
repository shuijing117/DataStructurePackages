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

#define N 30
#define NUM_LIMITS 99

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
		data[i] = rand() % (NUM_LIMITS + 1);
	}
	Print(data, N);
	Copy(data, temp, N);

	printf("InsertionSort: \n");
	InsertionSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("BinaryInsertionSort:\n");
	BinaryInsertionSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("ShellSort:\n");
	ShellSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("SelectionSort:\n");
	SelectionSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("BubbleSort:\n");
	BubbleSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("QuickSort:\n");
	QuickSort(data, 0, N-1);
	Print(data, N);

	Copy(temp, data, N);
	printf("MergeSort:\n");
	MergeSort(data, 0, N-1);
	Print(data, N);

	Copy(temp, data, N);
	printf("HeapSort:\n");
	HeapSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("PigeonholeSort:\n");
	PigeonholeSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("BucketSort:\n");
	BucketSort(data, N, NUM_LIMITS);
	Print(data, N);

	Copy(temp, data, N);
	printf("CocktailSort:\n");
	CocktailSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("GnomeSort:\n");
	GnomeSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("OddEvenSort:\n");
	OddEvenSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("PatienceSort:\n");
	PatienceSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("BeadSort:\n");
	BeadSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("CombSort:\n");
	CombSort(data, N);
	Print(data, N);

	Copy(temp, data, N);
	printf("BogoSort(Do you believe fortune?):\n");
//	BogoSort(data, N);
//	Print(data, N);	

	return 0;
}
