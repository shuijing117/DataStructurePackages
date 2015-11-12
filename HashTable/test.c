/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Thu 12 Nov 2015 11:37:44 AM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#include "HashTable.h"

void Print(HashTable ht);

void Print(HashTable ht)
{
	int i;
	Node *p;

	if(ht.mode == _LINEAR_PROBE_) {
		for(i = 0; i < ht.size; i++) {
			printf("%d ", (ht.linearData)[i]);
		}
		printf("\n");
	} else if(ht.mode == _LINK_PROBE_) {
		for(i = 0; i < ht.p; i++) {
			p = (ht.linkData)[i];

			if(p == NULL) {
				printf("nil");
			} else {
				while(p) {
					printf("%d ", p->data);
					p = p->next;
				}
			}
			printf("\n");
		}
	} else {
		return ;
	}

	return ;
}

int main(void)
{
	HashTable ht1, ht2;
	int data;
	int i;

	srand((unsigned int)time(NULL));

	InitHashTable(&ht1, 20, _LINEAR_PROBE_);
	InitHashTable(&ht2, 20, _LINK_PROBE_);

	for(i = 0; i < 15; i++)
	{
		data = rand() % 40 + 1;
		printf("%d ", data);
		InsertValue(&ht1, data);
		InsertValue(&ht2, data);
	}
	printf("\n");

	Print(ht1);
	Print(ht2);

	DestoryHashTable(&ht1);
	DestoryHashTable(&ht2);

	return 0;
}
