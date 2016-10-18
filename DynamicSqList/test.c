/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Mail: 100431075@qq.com 
    > Created Time: Sun 27 Sep 2015 05:02:35 PM CST
 ************************************************************************/

#include <stdio.h>

#include "DynamicSqList.h"

int main(void)
{
	int data;
	DynamicSqList sq;

	dynamicSqList_Init(&sq, 10);
	dynamicSqList_Print(&sq);

	dynamicSqList_InsertValue(&sq, 0, 1);
	dynamicSqList_InsertValue(&sq, 0, 2);
	dynamicSqList_InsertValue(&sq, 0, 3);
	dynamicSqList_InsertValue(&sq, 0, 4);
	dynamicSqList_InsertValue(&sq, 0, 5);
	dynamicSqList_InsertValue(&sq, 0, 6);
	dynamicSqList_InsertValue(&sq, 0, 7);
	dynamicSqList_InsertValue(&sq, 0, 8);
	dynamicSqList_InsertValue(&sq, 0, 9);
	dynamicSqList_InsertValue(&sq, 0, 10);
	dynamicSqList_InsertValue(&sq, 0, 11); // Extend
	dynamicSqList_InsertValue(&sq, 0, 12);
	dynamicSqList_InsertValue(&sq, 0, 12);
	dynamicSqList_InsertValue(&sq, 0, 12);
	dynamicSqList_Print(&sq);

	printf("%d\n", dynamicSqList_GetValueFirstIndex(&sq, 12));
	printf("%d\n", dynamicSqList_GetValueFirstIndex(&sq, 20));
	printf("%d\n", dynamicSqList_GetValueLastIndex(&sq, 12));
	printf("%d\n", dynamicSqList_GetValueLastIndex(&sq, 20));

	dynamicSqList_GetValue(&sq, 7, &data);
	printf("%d\n", data);

	int count;
	count =	dynamicSqList_GetValueCount(&sq, 1);
	printf("%d\n", count);
	count = dynamicSqList_GetValueCount(&sq, 12);
	printf("%d\n", count);
	count =	dynamicSqList_GetValueCount(&sq, 20);
	printf("%d\n", count);

	dynamicSqList_ModifyByIndex(&sq, 0, 10);
	dynamicSqList_ModifyByValue(&sq, 7, 10);
	dynamicSqList_Print(&sq);

	dynamicSqList_DeleteByIndex(&sq, 0, &data);
	dynamicSqList_Print(&sq);

	dynamicSqList_DeleteByValue(&sq, 10);
	dynamicSqList_Print(&sq);

	dynamicSqList_DeleteByValue(&sq, 12);
	dynamicSqList_Print(&sq);

	return 0;
}
