/*************************************************************************
    > File Name: HashTable/HashTable.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Tue 22 Dec 2015 10:16:33 AM CST
 ************************************************************************/

#include "HashTable.h"

static double GetFillingFactor(const HashTable *ht)
{
	return (double)(ht->count)/(ht->size);
}

static int GetHashAddress(const HashTable *ht, int data)
{
	return data % ht->p;
}

BOOL InsertValue(HashTable *ht, int data)
{
	int i, hashAddr;
	Node *p = NULL;
	Node *s = NULL;

	if(ht == NULL) {
		return FALSE;
	}

	if(GetFillingFactor(ht) >= 1) {
		return FALSE;
	}

//	printf("%f\n", GetFillingFactor(ht));

	hashAddr = GetHashAddress(ht, data);

	if(ht->mode == _LINEAR_PROBE_) {
		for(i = hashAddr; (ht->linearData)[i] != 0; i = (i+1) % (ht->size))
			;
		(ht->linearData)[i] = data;
	} else if(ht->mode == _LINK_PROBE_) {
		p = (ht->linkData)[hashAddr];

		s = (Node *)malloc(sizeof(Node));
		if(s == NULL) {
			return FALSE;
		}
		s->data = data;
		s->next = NULL;

		if(p == NULL) {
			(ht->linkData)[hashAddr] = s;
		} else {
			while(p->next) {
				p = p->next;
			}

			p->next = s;
		}
	} else {
		return FALSE;
	}

	ht->count++;

	return TRUE;
}

static BOOL IsPrimeNumber(int number)
{
	int i;

	for(i = 2; i < number; i++) {
		if(number % i == 0) {
			return FALSE;
		}
	}

	return TRUE;
}

static int GetMaxPrimeNumber(int number)
{
	int i;

	for(i = number; i > 0; i--) {
		if(IsPrimeNumber(i)) {
			return i;
		}
	}

	return 1;
}

BOOL DestoryHashTable(HashTable *ht)
{
	if(ht == NULL) {
		return FALSE;
	}

	if(ht->mode == _LINEAR_PROBE_) {
		free(ht->linearData);
		ht->linearData = NULL;
	} else if(ht->mode == _LINK_PROBE_) {
		free(ht->linkData);
		ht->linkData = NULL;
	} else {
		return FALSE;
	}

	return TRUE;
}

BOOL InitHashTable(HashTable *ht, int size, int mode)
{
	if(ht == NULL) {
		return FALSE;
	}

	ht->size = size;
	ht->mode = mode;
	ht->count = 0;
	ht->p = GetMaxPrimeNumber(size);
	ht->linkData = NULL;
	ht->linearData = NULL;

//	printf("p:%d\n", ht->p);

	if(mode == _LINEAR_PROBE_) {
		ht->linearData = (int *)calloc(size, sizeof(int));
		if(ht->linearData == NULL) {
			return FALSE;
		}
	} else if(mode == _LINK_PROBE_) {
		ht->linkData = (Node **)calloc(ht->p, sizeof(Node *));
		if(ht->linkData == NULL) {
			return FALSE;
		}
	}

	return 0;
}