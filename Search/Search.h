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

#endif
