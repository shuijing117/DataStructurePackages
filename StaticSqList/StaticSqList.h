/*************************************************************************
 * FileName    : StaticSqList.h
 * Environment : Ubuntu 14.04 LTS
 *               VIM - Vi IMproved 7.4
 *               GCC 4.8.4
 * Author      : liuxuandong
 * Mail        : 1004319075@qq.com 
 * Created Time: 2016年10月17日 星期一 15时15分03秒
 * Description : 
 ************************************************************************/

#ifndef _STATICSQLIST_H_
#define _STATICSQLIST_H_

#define _MAX_SIZE 10

typedef struct _StaticSqList {
	int data[_MAX_SIZE];
	int length;
}StaticSqList;

int staticSqList_Init(StaticSqList *sq);
int staticSqList_Clear(StaticSqList *sq);
int staticSqList_GetLength(const StaticSqList *sq);
int staticSqList_ModifyByIndex(StaticSqList *sq, int index, int newData);
int staticSqList_ModifyByValue(StaticSqList *sq, int data, int newData);
int staticSqList_GetValue(const StaticSqList *sq, int index, int *data);
int staticSqList_GetValueFirstIndex(const StaticSqList *sq, int data);
int staticSqList_GetValueLastIndex(const StaticSqList *sq, int data);
int staticSqList_GetValueCount(const StaticSqList *sq, int data);
int staticSqList_DeleteByIndex(StaticSqList *sq, int index, int *data);
int staticSqList_DeleteByValue(StaticSqList *sq, int data);
int staticSqList_InsertValue(StaticSqList *sq, int index, int data);
void staticSqList_Print(const StaticSqList *sq);


#endif
