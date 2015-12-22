/*************************************************************************
    > File Name: Sort.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Sat 10 Oct 2015 07:53:16 PM CST
 ************************************************************************/
#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define		TRUE			1
#define		FALSE			0
	
#define		LAPSE_RATE		1.3

typedef int BOOL;
typedef int datatype;

typedef struct Node {
	datatype data;
	struct Node *next;
}Node;

void Swap(datatype *a, datatype *b);

static BOOL HeapAdjust(datatype *array, int size, int s);
static BOOL GetMax(datatype *array, int size, int *max);
static BOOL GetMin(datatype *array, int size, int *min);
static int GetBit(const int number);

BOOL InsertionSort(datatype *array, int size);
BOOL BinaryInsertionSort(datatype *array, int size);
BOOL ShellSort(datatype *array, int size);
BOOL SelectionSort(datatype *array, int size);
BOOL BubbleSort(datatype *array, int size);
BOOL QuickSort(datatype *array, int low, int high);
BOOL MergeSort(datatype *array, int low, int high);
BOOL HeapSort(datatype *array, int size);
BOOL HighOrderRadixSort(datatype *array, int size);
BOOL LowOrderRadixSort(datatype *array, int size);
BOOL BucketSort(datatype *array, int size, int numberLimits);
BOOL PigeonholeSort(datatype *array, int size);
BOOL CocktailSort(datatype *array, int size);
BOOL GnomeSort(datatype *array, int size);
BOOL OddEvenSort(datatype *array, int size);
BOOL PatienceSort(datatype *array, int size);
BOOL BeadSort(datatype *array, int size);
BOOL CombSort(datatype *array, int size);
BOOL BogoSort(datatype *array, int size);

#endif
