/*************************************************************************
    > File Name: Search.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Wed 11 Nov 2015 10:11:58 PM CST
 ************************************************************************/
#ifndef	_SEARCH_H_
#define _SEARCH_H_

#include <malloc.h>

#define		TRUE	1
#define		FALSE	0

typedef int BOOL;
typedef int datatype;

int LinearSearch(const datatype *array, int len, datatype data, BOOL (*compare)(datatype, datatype));
int BinarySearch(const datatype *array, int len, datatype data, BOOL (*compare)(datatype, datatype));
int BinarySearchRecursion(const datatype *array, int low, int high, datatype data, BOOL (*compare)(datatype, datatype));

int BinarySearchRecursion(const datatype *array, int low, int high, datatype data, BOOL (*compare)(datatype, datatype))
{
	int mid = (low + high) / 2;

	if(array == NULL) {
		return -1;
	}

	if(low > high) {
		return -1;
	}

	if(compare(array[mid], data) == 0) {
		return mid;
	} else if(compare(array[mid], data) > 0) {
		return BinarySearchRecursion(array, low, mid-1, data, compare);
	} else {
		return BinarySearchRecursion(array, mid+1, high, data, compare);
	}
}

int BinarySearch(const datatype *array, int len, datatype data, BOOL (*compare)(datatype, datatype))
{
	int low, high, mid;

	if(array == NULL) {
		return -1;
	}

	low = 0;
	high = len-1;

	while(low <= high) {
		mid = (low + high) / 2;

		if(compare(array[mid], data) == 0) {
			return mid;
		} else if(compare(array[mid], data) > 0) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return -1;
}

int LinearSearch(const datatype *array, int len, datatype data, BOOL (*compare)(datatype, datatype))
{
	int i;

	if(array == NULL || compare == NULL) {
		return -1;
	}

	for(i = 0; i < len; i++) {
		if(compare(array[i], data) == 0) {
			return i;
		}
	}

	return -1;
}

#endif
