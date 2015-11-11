/*************************************************************************
    i> File Name: DynamicArray.h
    > Author: liuxuandong
	> Develop : Ubuntu 14.04    gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Sun 27 Sep 2015 04:48:32 PM CST
 ************************************************************************/
#ifndef DYNAMICARRAY_H

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
static BOOL ExpandArray(DynamicArray **array);
BOOL GetElem(const DynamicArray array, int index, datatype *data);
BOOL GetSubArray(const DynamicArray array, DynamicArray *subArray, int index, int size);
BOOL GetRandomElem(const DynamicArray array, datatype *data);
BOOL CombineArray(DynamicArray *array1, const DynamicArray array2);
int Find(const DynamicArray array, datatype data, int (*compare)(datatype, datatype));
BOOL IsEmpty(const DynamicArray array);
BOOL IsFull(const DynamicArray array);

BOOL IsFull(const DynamicArray array)
{
	return array.count >= array.size;
}

BOOL IsEmpty(const DynamicArray array)
{
	return array.count <= 0;
}

int Find(const DynamicArray array, datatype data, int (*compare)(datatype, datatype))
{
	int i;

	for(i = 0; i < array.count; i++) {
		if(compare(array.data[i], data)) {
			return i;
		}
	}

	return -1;
}

BOOL CombineArray(DynamicArray *array1, const DynamicArray array2)
{
	int i;

	if(array1 == NULL) {
		return FALSE;
	}

	while(array1->count + array2.count > array1->size) {
		ExpandArray(&array1);
	}

	for(i = 0; i < array2.count; i++) {
		array1->data[array1->count+i] = array2.data[i];
	}
	array1->count += array2.count;

	return TRUE;
}

BOOL GetRandomElem(const DynamicArray array, datatype *data)
{
	int index;
	if(IsEmpty(array)) {
		return FALSE;
	}

	srand((int)time(NULL));

	index = rand() % array.count;

	*data = array.data[index-1];

	return TRUE;
}

BOOL GetSubArray(const DynamicArray array, DynamicArray *subArray, int index, int size)
{
	int i;

	if(subArray == NULL) {
		return FALSE;
	}

	if(index + size > array.count) {
		return FALSE;
	}

	for(i = index; i < index+size; i++) {
		subArray->data[i] = array.data[i];
	}
	subArray->count = size;

	return TRUE;
}

BOOL GetElem(const DynamicArray array, int index, datatype *data)
{
	if(index < 0 || index >= array.count) {
		return FALSE;
	}

	*data = array.data[index];

	return TRUE;
}

static BOOL ExpandArray(DynamicArray **array)
{
	int i;
	datatype *temp;

	if(*array == NULL) { 
		return FALSE;
	}

	temp = (datatype *)malloc(sizeof(datatype) * (*array)->size * 2);
	if(temp == NULL) {
		return FALSE;
	}
	(*array)->size *= 2;
	
	for(i = 0; i < (*array)->count; i++) {
		temp[i] = (*array)->data[i];
	}

	free((*array)->data);
	(*array)->data = temp;

	return TRUE;
}

BOOL ClearArray(DynamicArray *array)
{
	if(array == NULL) {
		return FALSE;
	}

	array->count = 0;

	return TRUE;
}

BOOL DeleteArray(DynamicArray *array, int index)
{
	int i;

	if(array == NULL) {
		return FALSE;
	}

	if(index < 0 || index > array->count-1) {
		return FALSE;
	}

	for(i = index; i < array->count-1; i++) {
		array->data[i] = array->data[i+1];
	}
	array->count--;

	return TRUE;
}

BOOL InsertArray(DynamicArray *array, datatype data, int index)
{
	int i;

	if(array == NULL) {
		return FALSE;
	}

	if(index < 0 || index > array->count-1) {
		return FALSE;
	}

	if(IsFull(*array)) {
		ExpandArray(&array);
	}

	for(i = array->count; i > index; i--) {
		array->data[i] = array->data[i-1];
	}
	array->data[index] = data;
	array->count++;

	return TRUE;
}

BOOL DestoryArray(DynamicArray *array)
{
	if(array == NULL) {
		return FALSE;
	}

	free(array->data);

	return TRUE;
}

BOOL InitArray(DynamicArray *array, int size)
{
	if (array == NULL) {
		return FALSE;
	}

	array->data = (datatype *)malloc(sizeof(datatype) * size);
	if(array->data == NULL) {
		return FALSE;
	}
	array->size = size;
	array->count = 0;

	return TRUE;
}

#endif
