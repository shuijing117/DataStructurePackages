/*************************************************************************
 * FileName    : DynamicSqList.h
 * Environment : Ubuntu 14.04 LTS
 *               VIM - Vi IMproved 7.4
 *               GCC 4.8.4
 * Author      : liuxuandong
 * Mail        : 1004319075@qq.com 
 * Created Time: 2016年10月17日 星期一 15时15分03秒
 * Description : 
 ************************************************************************/

#ifndef _DynamicSqList_H_
#define _DynamicSqList_H_

typedef struct _DynamicSqList {
	int *data;
	int size;
	int length;
}DynamicSqList;

int dynamicSqList_Init(DynamicSqList *sq, int size);
int dynamicSqList_Clear(DynamicSqList *sq);
int dynamicSqList_GetLength(const DynamicSqList *sq);
int dynamicSqList_ModifyByIndex(DynamicSqList *sq, int index, int newData);
int dynamicSqList_ModifyByValue(DynamicSqList *sq, int data, int newData);
int dynamicSqList_GetValue(const DynamicSqList *sq, int index, int *data);
int dynamicSqList_GetValueFirstIndex(const DynamicSqList *sq, int data);
int dynamicSqList_GetValueLastIndex(const DynamicSqList *sq, int data);
int dynamicSqList_GetValueCount(const DynamicSqList *sq, int data);
int dynamicSqList_DeleteByIndex(DynamicSqList *sq, int index, int *data);
int dynamicSqList_DeleteByValue(DynamicSqList *sq, int data);
int dynamicSqList_InsertValue(DynamicSqList *sq, int index, int data);
void dynamicSqList_Print(const DynamicSqList *sq);

static int dynamicSqList_Extend(DynamicSqList *sq);


#endif
