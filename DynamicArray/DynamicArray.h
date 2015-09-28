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

typedef int datatype;

typedef struct _ARRAY {
	datatype *data;
	int size;
	int count;
}DynamicArray;

int InitArray(DynamicArray *array, int size);
int DestoryArray(DynamicArray *array);
int InsertArray(DynamicArray *array, datatype data, int index);
int DeleteArray(DynamicArray *array, int index);
int ClearArray(DynamicArray *array);
int ExpandArray(DynamicArray **array);
int GetElem(const DynamicArray array, int index, datatype *data);
int GetSubArray(const DynamicArray array, DynamicArray *subArray, int index, int size);
int GetRandomElem(const DynamicArray array, datatype *data);
int CombineArray(DynamicArray *array1, const DynamicArray array2);
int Find(const DynamicArray array, datatype data, int (*compare)(datatype, datatype));
int IsEmpty(const DynamicArray array);
int IsFull(const DynamicArray array);

int IsFull(const DynamicArray array)
{
	return array.count >= array.size;
}

int IsEmpty(const DynamicArray array)
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

int CombineArray(DynamicArray *array1, const DynamicArray array2)
{
	int i;

	if(array1 == NULL) {
		return -1;
	}

	while(array1->count + array2.count > array1->size) {
		ExpandArray(&array1);
	}

	for(i = 0; i < array2.count; i++) {
		array1->data[array1->count+i] = array2.data[i];
	}
	array1->count += array2.count;

	return 0;
}

int GetRandomElem(const DynamicArray array, datatype *data)
{
	int index;
	if(IsEmpty(array)) {
		return -1;
	}

	srand((int)time(NULL));

	index = rand() % array.count;

	*data = array.data[index-1];

	return 0;
}

int GetSubArray(const DynamicArray array, DynamicArray *subArray, int index, int size)
{
	int i;

	if(subArray == NULL) {
		return -1;
	}

	if(index + size > array.count) {
		return -2;
	}

	for(i = index; i < index+size; i++) {
		subArray->data[i] = array.data[i];
	}
	subArray->count = size;

	return 0;
}

int GetElem(const DynamicArray array, int index, datatype *data)
{
	if(index < 0 || index >= array.count) {
		return -1;
	}

	*data = array.data[index];

	return 0;
}

int ExpandArray(DynamicArray **array)
{
	int i;
	datatype *temp;

	if(*array == NULL) { 
		return -1;
	}

	temp = (datatype *)malloc(sizeof(datatype) * (*array)->size * 2);
	if(temp == NULL) {
		return -2;
	}
	(*array)->size *= 2;
	
	for(i = 0; i < (*array)->count; i++) {
		temp[i] = (*array)->data[i];
	}

	free((*array)->data);
	(*array)->data = temp;

	return 0;
}

int ClearArray(DynamicArray *array)
{
	if(array == NULL) {
		return -1;
	}

	array->count = 0;

	return 0;
}

int DeleteArray(DynamicArray *array, int index)
{
	int i;

	if(array == NULL) {
		return -1;
	}

	if(index < 0 || index > array->count-1) {
		return -2;
	}

	for(i = index; i < array->count-1; i++) {
		array->data[i] = array->data[i+1];
	}
	array->count--;

	return 0;
}

int InsertArray(DynamicArray *array, datatype data, int index)
{
	int i;

	if(array == NULL) {
		return -1;
	}

	if(index < 0 || index > array->count-1) {
		return -2;
	}

	if(IsFull(*array)) {
		ExpandArray(&array);
	}

	for(i = array->count; i > index; i--) {
		array->data[i] = array->data[i-1];
	}
	array->data[index] = data;
	array->count++;

	return 0;
}

int DestoryArray(DynamicArray *array)
{
	if(array == NULL) {
		return -1;		
	}

	free(array->data);

	return 0;
}

int InitArray(DynamicArray *array, int size)
{
	if (array == NULL) {
		return -1;
	}

	array->data = (datatype *)malloc(sizeof(datatype) * size);
	if(array->data == NULL) {
		return -1;
	}
	array->size = size;
	array->count = 0;

	return 0;
}

#endif
