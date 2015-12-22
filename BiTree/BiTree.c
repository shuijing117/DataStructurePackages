/*************************************************************************
    > File Name: BiTree/BiTree.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Tue 22 Dec 2015 10:15:55 AM CST
 ************************************************************************/

#include "BiTree.h"

int GetKthLevelNodeNumber(const BiTree btree, int k)
{
	if(btree == NULL || k < 1) {
		return 0;
	}

	if(k == 1) {
		return 1;
	}

	return GetKthLevelNodeNumber(btree->lchild, k-1) + GetKthLevelNodeNumber(btree->rchild, k-1);
}

void LevelOrder(const BiTree btree, void Visit(char))
{
	BiTree *q;
	int rear, front, size;
	BiTree t;

	if(btree == NULL) {
		return;
	}

	size = GetNodeNumber(btree);
	front = rear = 0;
	q = (BiTree *)malloc(sizeof(BiTree) * size);
	if(q == NULL) {
		return;
	}

	q[rear] = btree;
	rear = (rear+1) % size;

	while(front != rear) {
		t = q[front];
		front = (front+1) % size;
		Visit(t->data);

		if(t->lchild != NULL) {
			q[rear] = t->lchild;
			rear = (rear+1) % size;
		}

		if(t->rchild != NULL) {
			q[rear] = t->rchild;
			rear = (rear+1) % size;
		}
	}
}

int GetLeafNodeNumber(const BiTree btree)
{
	if(btree == NULL) {
		return 0;
	}

	if(btree->lchild == NULL && btree->rchild == NULL) {
		return 1;
	}

	return GetLeafNodeNumber(btree->lchild) + GetLeafNodeNumber(btree->rchild);
}

int GetNodeNumber(const BiTree btree)
{
	if(btree == NULL) {
		return 0;
	}

	return GetNodeNumber(btree->lchild) + GetNodeNumber(btree->rchild) + 1;
}

int GetBiTreeHeight(const BiTree btree)
{
	int lHeight, rHeight;

	if(btree == NULL) {
		return 0;
	}

	lHeight = GetBiTreeHeight(btree->lchild);
	rHeight = GetBiTreeHeight(btree->rchild);

	return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
}

void PostOrder(BiTree btree, void Visit(char))
{
	if(btree != NULL) {
		PostOrder(btree->lchild, Visit);
		PostOrder(btree->rchild, Visit);
		Visit(btree->data);
	}
}

void InOrder(BiTree btree, void Visit(char))
{
	if(btree != NULL) {
		InOrder(btree->lchild, Visit);
		Visit(btree->data);
		InOrder(btree->rchild, Visit);
	}
}

void PreOrder(BiTree btree, void Visit(char))
{
	if(btree != NULL) {
		Visit(btree->data);
		PreOrder(btree->lchild, Visit);
		PreOrder(btree->rchild, Visit);
	}
}

BOOL DestroyBiTree(BiTree *btree)
{
	if(btree == NULL || *btree == NULL) {
		return FALSE;
	}

	DestroyBiTree(&((*btree)->lchild));
	DestroyBiTree(&((*btree)->rchild));
	free(*btree);

	return TRUE;
}

BOOL CreateBiTree(BiTree *btree)
{
	char ch;

	ch = getchar();

	if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
		*btree = (BiTNode *)malloc(sizeof(BiTNode));
		if(*btree == NULL) {
			return FALSE;
		}
		(*btree)->data = ch;

		CreateBiTree(&((*btree)->lchild));
		CreateBiTree(&((*btree)->rchild));
	} else {
		*btree == NULL;
	}

	return TRUE;
}
