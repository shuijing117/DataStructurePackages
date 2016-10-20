/*************************************************************************
 * FileName    : LinkList.h
 * Environment : CentOS release 6.6 (Final)
 *               VIM - Vi IMproved 7.2.411
 *               GCC 4.4.7
 * Author      : liuxuandong
 * Mail        : 1004319075@qq.com 
 * Created Time: Wed 19 Oct 2016 05:24:50 PM CST
 * Description : 单链表的头文件
 ************************************************************************/

#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef struct _Node {
	int data;
	struct _Node * next;
}Node, *Position, *LinkList;

LinkList linkList_Init();
int linkList_Destory(LinkList list);
int linkList_GetLength(LinkList list);
Position linkList_GetNodePosition(LinkList list, int data);

#endif
