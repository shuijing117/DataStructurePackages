/*************************************************************************
    > File Name: BiTree.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Mon 23 Nov 2015 08:00:28 PM CST
 ************************************************************************/
#ifndef _BITREE_H_
#define _BITREE_H_

#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define		TRUE	1
#define		FALSE	0

#define		N		20

typedef int BOOL;

typedef struct _NODE {
	char data;
	struct _NODE *lchild;
	struct _NODE *rchild;
}BiTNode, * BiTree;

BOOL CreateBiTree(BiTree *btree);
BOOL DestroyBiTree(BiTree *btree);
void PreOrder(const BiTree btree, void Visit(char));
void InOrder(const BiTree btree, void Visit(char));
void PostOrder(const BiTree btree, void Visit(char));
void LevelOrder(const BiTree btree, void Visit(char));
int GetBiTreeHeight(const BiTree btree);
int GetNodeNumber(const BiTree btree);
int GetLeafNodeNumber(const BiTree btree);
int GetKthLevelNodeNumber(const BiTree btree, int k);

#endif
