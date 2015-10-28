/*************************************************************************
    > File Name: Sort.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Sat 10 Oct 2015 07:53:16 PM CST
 ************************************************************************/
#ifndef _SORT_H_

#include <malloc.h>

typedef int datatype;

void Swap(datatype *a, datatype *b);
int InsertionSort(datatype *array, const int size);
int BinaryInsertionSort(datatype *array, const int size);
int ShellSort(datatype *array, const int size);
int SelectionSort(datatype *array, const int size);
int BubbleSort(datatype *array, const int size);
int QuickSort(datatype *array, const int low, const int high);
int MergeSort(datatype *array, const int low, const int high);
int HeapSort(datatype *array, const int size);
int HeapAdjust(datatype *array, const int size, int s);

int HeapAdjust(datatype *array, const int size, int s)
{
	int i, temp;

	if(array == NULL) {
		return -1;
	}

	temp = array[s];
	for(i = 2*s+1; i < size; i = 2*i+1) {
		if(i < size-1 && array[i] < array[i+1]) {
			++i;
		}

		if(temp >= array[i])
			break;

		array[s] = array[i];
		s = i;
	}
	array[s] = temp;

	return 0;
}

int HeapSort(datatype *array, const int size)
{
	int i;

	if(array == NULL) {
		return -1;
	}

	for(i = size/2; i > 0; i--) {
		HeapAdjust(array, size, i-1);
	}

	for(i = size-1; i > 0; i--) {
		Swap(array+i, array);
		HeapAdjust(array, i, 0);
	}

	return 0;
}

int MergeSort(datatype *array, const int low, const int high)
{
	int i, j, k;
	int mid;
	int *temp;

	if(array == NULL) {
		return -1;
	}

	if(low >= high) {
		return -1;
	}

	temp = (int *)malloc(sizeof(int)*(high-low+1));
	if(temp == NULL) {
		return -1;
	}

	mid = (low + high) / 2;

	MergeSort(array, low, mid);
	MergeSort(array, mid+1, high);

	i = low;
	j = mid+1;
	k = 0;
	while(i <= mid && j <=high) {
		if(array[i] < array[j]) {
			temp[k++] = array[i++];
		} else {
			temp[k++] = array[j++];
		}
	}

	while(i <= mid) {
		temp[k++] = array[i++];
	}

	while(j <= high) {
		temp[k++] = array[j++];
	}

	for(i = 0; i <= high-low; i++) {
		array[low+i] = temp[i];
	}

	return 0;
}

int QuickSort(datatype *array, const int low, int high)
{
	int i = low;
	int j = high;
	int temp;
	
	if(array == NULL) {
		return -1;
	}

	if(low >= high) {
		return -1;
	}

	temp = array[low];

	while(i != j) {
		for( ; j > i && array[j] > temp; j--) 
			;

		if(j > i) {
			array[i] = array[j];
			i++;
		}

		for( ; i < j && temp > array[i]; i++) 
			;
		
		if(i < j) {
			array[j] = array[i];
			j--;
		}
	}

	array[i] = temp;
	QuickSort(array, low, i-1);
	QuickSort(array, i+1, high);

	return 0;
}

int BubbleSort(datatype *array, const int size)
{
	int i, j;

	if(array == NULL) {
		return -1;
	}

	for(i = 0; i < size; i++) {
		for(j = i; j < size-1; j++) {
			if(array[j] > array[j+1]) {
				Swap(array+j, array+j+1);
			}
		}
	}

	return 0;
}

int SelectionSort(datatype *array, const int size)
{
	int i, j, k;

	if(array == NULL) {
		return -1;
	}

	for(i = 0; i < size; i++) {
		k = i;
		for(j = i+1; j < size; j++) {
			if(array[k] > array[j]) {
				k = j;
			}
		}
		Swap(array+i, array+k);
	}

	return 0;
}

int ShellSort(datatype *array, int size)
{
	int i, j, temp;
	int increment = size;

	while(increment > 1) {
		increment = increment / 3 + 1;
		for(i = increment; i < size; i++) {
			if(array[i] < array[i-increment]) {
				temp = array[i];
				for(j = i-increment; j >= 0; j -= increment) {
					if(temp >= array[j]) {
						break;
					}
					array[j+increment] = array[j];
				}
				array[j+increment] = temp;
			}
		}
	}
}

int BinaryInsertionSort(datatype *array, int size)
{
	int i, j, low, high, mid;
	int temp;

	if(array == NULL) {
		return -1;
	}

	for(i = 1; i < size; i++) {
		low = 0;
		high = i-1;
		temp = array[i];

		while(low <= high) {
			mid = (low + high) / 2;
			if(array[mid] > temp) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		for(j = i; j > low; j--) {
			array[j] = array[j-1];
		}
		array[low] = temp;
	}

	return 0;
}

int InsertionSort(datatype *array, int size)
{
	int i, j;
	int temp;

	if(array == NULL) {
		return -1;
	}

	for(i = 1; i < size; i++) {
		temp = array[i];
		for(j = i-1; j >= 0; j--) {
			if(temp >= array[j]) {
				break;
			} 
			array[j+1] = array[j];
		}
		array[j+1] = temp;
	}

	return 0;
}

void Swap(datatype *a, datatype *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

#endif
