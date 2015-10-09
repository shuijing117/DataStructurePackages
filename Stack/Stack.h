/*************************************************************************
    > File Name: Stack.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Fri 09 Oct 2015 09:55:26 PM CST
 ************************************************************************/
#ifndef _STACK_

#include <malloc.h>

typedef int datatype;

typedef struct _STACK {
	datatype *data;
	int top;
	int size;
}Stack;

int InitStack(Stack *s, int size);
int DestoryStack(Stack *s);
int IsEmpty(Stack s);
int IsFull(Stack s);
int Push(Stack *s, datatype data);
int Pop(Stack *s, datatype *data);
int ClearStack(Stack *s);
int GetTop(Stack s, datatype *data);

int GetTop(Stack s, datatype *data)
{
	if(IsEmpty(s)) {
		return -1;
	}
	*data = s.data[s.top];

	return 0;
}

int ClearStack(Stack *s)
{
	if(s == NULL) {
		return -1;
	}

	s->top = -1;

	return 0;
}

int Pop(Stack *s, datatype *data)
{
	if(s = NULL) {
		return -1;
	}

	if(IsEmpty(*s)) {
		return -2;
	}

	*data = s->data[(s->top)--];

	return 0;
}

int Push(Stack *s, datatype data)
{
	if(s = NULL) {
		return -1;
	}

	if(IsFull(*s)) {
		return -2;
	}

	s->data[++(s->top)] = data;

	return 0;
}

int IsFull(Stack s)
{
	return s.top >= s.size-1;
}
	
int IsEmpty(Stack s)
{
	return s.top <= -1;
}

int DestoryStack(Stack *s)
{
	if(s == NULL) {
		return -1;
	}

	free(s->data);

	return 0;
}

int InitStack(Stack *s, int size)
{
	if(s == NULL) {
		return -1;
	}

	s->data = (datatype *)malloc(sizeof(datatype) * size);
	if(s->data == NULL) {
		return -2;
	}
	s->size = size;
	s->top = -1;

	return 0;
}

#endif
