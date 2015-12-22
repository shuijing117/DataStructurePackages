/*************************************************************************
    > File Name: Stack.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Fri 09 Oct 2015 09:55:26 PM CST
 ************************************************************************/
#ifndef _STACK_
#define _STACK_

#include <malloc.h>

#define		TRUE	1
#define		FALSE	0

typedef int BOOL;
typedef int datatype;

typedef struct _STACK {
	datatype *data;
	int top;
	int size;
}Stack;

BOOL InitStack(Stack *s, int size);
BOOL DestoryStack(Stack *s);
BOOL IsEmpty(Stack s);
BOOL IsFull(Stack s);
BOOL Push(Stack *s, datatype data);
BOOL Pop(Stack *s, datatype *data);
BOOL ClearStack(Stack *s);
BOOL GetTop(Stack s, datatype *data);

#endif
