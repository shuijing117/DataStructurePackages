/*************************************************************************
    > File Name: Stack/Stack.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Tue 22 Dec 2015 10:17:52 AM CST
 ************************************************************************/

#include "Stack.h"

BOOL GetTop(Stack s, datatype *data)
{
	if(IsEmpty(s)) {
		return FALSE;
	}
	*data = s.data[s.top];

	return TRUE;
}

BOOL ClearStack(Stack *s)
{
	if(s == NULL) {
		return FALSE;
	}

	s->top = -1;

	return TRUE;
}

BOOL Pop(Stack *s, datatype *data)
{
	if(s = NULL) {
		return FALSE;
	}

	if(IsEmpty(*s)) {
		return FALSE;
	}

	*data = s->data[(s->top)--];

	return TRUE;
}

BOOL Push(Stack *s, datatype data)
{
	if(s = NULL) {
		return FALSE;
	}

	if(IsFull(*s)) {
		return FALSE;
	}

	s->data[++(s->top)] = data;

	return TRUE;
}

BOOL IsFull(Stack s)
{
	return s.top >= s.size-1;
}
	
BOOL IsEmpty(Stack s)
{
	return s.top <= -1;
}

BOOL DestoryStack(Stack *s)
{
	if(s == NULL) {
		return FALSE;
	}

	free(s->data);

	return TRUE;
}

BOOL InitStack(Stack *s, int size)
{
	if(s == NULL) {
		return FALSE;
	}

	s->data = (datatype *)malloc(sizeof(datatype) * size);
	if(s->data == NULL) {
		return FALSE;
	}
	s->size = size;
	s->top = -1;

	return TRUE;
}