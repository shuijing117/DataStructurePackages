/*************************************************************************
    > File Name: DoubleLinkList.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Tue 29 Sep 2015 09:34:19 AM CST
 ************************************************************************/
#ifndef _DOUBLELINKLIST_H_

#include <malloc.h>

typedef int datatype;

typedef struct _DLINKLIST {
	datatype data;
	struct _DLINKLIST *prior;
	struct _DLINKLIST *next;
}*DoubleLinkList, *Position, Node;

#endif
