/*************************************************************************
    i> File Name: DynamicArray.h
    > Author: liuxuandong
	> Develop : Ubuntu 14.04    gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Sun 27 Sep 2015 04:48:32 PM CST
 ************************************************************************/
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define		TRUE	1
#define		FALSE	0

typedef int BOOL;
typedef int datatype;

typedef struct _ARRAY {
	datatype *data;
	int size;
	int count;
}DynamicArray;

BOOL InitArray(DynamicArray *array, int size);
BOOL DestoryArray(DynamicArray *array);
BOOL InsertArray(DynamicArray *array, datatype data, int index);
BOOL DeleteArray(DynamicArray *array, int index);
BOOL ClearArray(DynamicArray *array);
BOOL GetElem(const DynamicArray array, int index, datatype *data);
BOOL GetSubArray(const DynamicArray array, DynamicArray *subArray, int index, int size);
BOOL GetRandomElem(const DynamicArray array, datatype *data);
BOOL CombineArray(DynamicArray *array1, const DynamicArray array2);
BOOL IsEmpty(const DynamicArray array);
BOOL IsFull(const DynamicArray array);
int Find(const DynamicArray array, datatype data, int (*compare)(datatype, datatype));
static BOOL ExpandArray(DynamicArray **array);

#endif
