/*************************************************************************
 * FileName    : LinkList.c
 * Environment : CentOS release 6.6 (Final)
 *               VIM - Vi IMproved 7.2.411
 *               GCC 4.4.7
 * Author      : liuxuandong
 * Mail        : 1004319075@qq.com 
 * Created Time: Wed 19 Oct 2016 05:24:57 PM CST
 * Description : 单链表的实现文件
 ************************************************************************/

#include <malloc.h>

/**
 * desc   : 单链表的初始化函数 
 * param  : void
 * return : NULL - 生成单链表失败 !NULL - 单链表的头指针
 */
LinkList linkList_Create()
{
	LinkList = ( LinkList) malloc( sizeof(Node) );
	if ( LinkList == NULL )
	{
		return NULL;
	}

	LinkList->next = NULL;

	return LinkList;
}

/**
 * desc   : 单链表的销毁函数
 * param  : list - 单链表的头指针
 * return : -1 - 销毁失败  0 - 销毁成功
 */
int linkList_Destory(LinkList list)
{
	Node *q, *p = list;

	while ( p )
	{
		q = p;
		p = p->next;
		free(q);
	}

	list = NULL;

	return 0;
}

/**
 * desc   : 获取单链表的长度
 * param  : list - 单链表的头指针
 * return : -1 - 获取失败 >=0 单链表的长度
 */
int linkList_GetLength(LinkList list)
{
	Node *p;
	int nodeNum;

	if ( list == NULL )
		return -1;

	for (p = list->next, nodeNum = 0; p; p = p->next, ++nodeNum )
		;

	return nodeNum;
}

/**
 * desc   : 获取数据为data的节点的地址
 * param  : list - 单链表的头节点 data - 数值
 * return : NULL - 获取失败 !NULL - 节点的地址
 */
Position linkList_GetNodePosition(LinkList list, int data)
{
	Node *p = list;

	while ( p )
	{
		p = p->next;
		if ( p->data == data )
		{
			return p;
		}
	}

	return NULL;
}

/**
 * desc    : 获取传入的节点的位置的前一个节点的位置
 * param   : list - 单链表的头节点  p - 单链表中一个节点的首地址
 * return  : NULL - 获取失败 !NULL - 节点的地址
 */
Position linkList_GetPrePosition(LinkList list, Position p)
{
	if (p == NULL || list == NULL || p == list->next )
	{
		return NULL;
	}

	Node *q = list->next;

	while ( q )
	{
		if ( p->next == q )
			return q;
	}

	return NULL;
	
}
