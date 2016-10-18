/*************************************************************************
 * FileName    : test.c
 * Environment : Ubuntu 14.04 LTS
 *               VIM - Vi IMproved 7.4
 *               GCC 4.8.4
 * Author      : liuxuandong
 * Mail        : 1004319075@qq.com 
 * Created Time: 2016年10月17日 星期一 15时14分53秒
 * Description : 
 ************************************************************************/

#include <stdio.h>
#include "StaticSqList.h"

int main(void)
{
	StaticSqList sq;
	int data;

	staticSqList_Init(&sq);

	staticSqList_Print(&sq);

	staticSqList_InsertValue(&sq, 0, 1);
	staticSqList_InsertValue(&sq, 0, 2);
	staticSqList_InsertValue(&sq, 0, 3);
	staticSqList_InsertValue(&sq, 2, 4);
	staticSqList_InsertValue(&sq, 2, 5);
	staticSqList_InsertValue(&sq, 0, 6);
	staticSqList_InsertValue(&sq, 3, 7);
	staticSqList_InsertValue(&sq, 0, 1);
	staticSqList_InsertValue(&sq, -1, 8);
	staticSqList_InsertValue(&sq, 20, 9);

	staticSqList_Print(&sq);  // 1 6 3 2 7 5 4 1


	printf("%d\n", staticSqList_GetValueFirstIndex(&sq, 1));
	printf("%d\n", staticSqList_GetValueFirstIndex(&sq, 8));
	printf("%d\n", staticSqList_GetValueLastIndex(&sq, 1));
	printf("%d\n", staticSqList_GetValueLastIndex(&sq, 8));

	staticSqList_GetValue(&sq, 0, &data);
	printf("%d\n", data);

	int count;
	count =	staticSqList_GetValueCount(&sq, 1);
	printf("%d\n", count);
	count = staticSqList_GetValueCount(&sq, 7);
	printf("%d\n", count);
	count =	staticSqList_GetValueCount(&sq, 9);
	printf("%d\n", count);

	staticSqList_ModifyByIndex(&sq, 0, 10);
	staticSqList_ModifyByValue(&sq, 7, 10);
	staticSqList_Print(&sq);

	staticSqList_DeleteByIndex(&sq, 0, &data);
	staticSqList_Print(&sq);
	staticSqList_DeleteByValue(&sq, 10);
	staticSqList_Print(&sq);
	staticSqList_DeleteByValue(&sq, 1);
	staticSqList_Print(&sq);

	return 0;
}
