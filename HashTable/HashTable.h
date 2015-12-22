/*************************************************************************
    > File Name: HashTable.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Thu 12 Nov 2015 11:11:56 AM CST
 ************************************************************************/
#ifndef	_HASHTABLE_H_
#define	_HASHTABLE_H_

#include <malloc.h>

#define		TRUE			1
#define		FALSE			0
#define		_LINEAR_PROBE_	1
#define		_LINK_PROBE_	0

typedef	int	BOOL;

typedef struct _NODE {
	int data;
	struct _NODE *next;
}Node;

typedef struct _HASHTABLE {
	int *linearData;
	Node **linkData;
	int count;
	int size;
	int mode;
	int p;
}HashTable;

BOOL InitHashTable(HashTable *ht, int size, int mode);
BOOL DestoryHashTable(HashTable *ht);
BOOL InsertValue(HashTable *ht, int data);
static BOOL IsPrimeNumber(int number);
static int GetMaxPrimeNumber(int number);
static int GetHashAddress(const HashTable *ht, int data);
static double GetFillingFactor(const HashTable *ht);

#endif
