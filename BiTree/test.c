/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Sat 05 Dec 2015 08:51:00 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "BiTree.h"

void Visit(char ch) {
	printf("%c", ch);
}

int main(void) 
{
	BiTree bt;

	printf("Please input a extensional pre order of binary tree:\n");
	printf("For example:\n");
	printf("Have a binary tree:\n");
	printf("           A\n");
	printf("          /\\\n");
	printf("         /  \\\n");
	printf("        B   C\n");
	printf("        \\    \\\n");
	printf("         \\    \\\n");
	printf("          D    E\n");
	printf("          /\\    \\\n");
	printf("         /  \\    \\\n");
	printf("        F    G    H\n");
	printf("The pre order of this binary tree : ABDFGCEH\n");
	printf("The extensional pre order of this binary tree : AB.DF..G..C.E.H..\n");
	printf("Extensional pre order = Pre Order + NULL child binarytree.\n");
	printf("Use '.' represent null.\n");
	printf("Please input : ");

	if(!CreateBiTree(&bt)) {
		printf("Create BiTree Failed!\n");
		return -1;
	}

	printf("PreOrder:\t\t");
	PreOrder(bt, Visit);
	printf("\nInOrder:\t\t");
	InOrder(bt, Visit);
	printf("\nPostOrder:\t\t");
	PostOrder(bt, Visit);
	printf("\nLevelOrder:\t\t");
	LevelOrder(bt, Visit);
	printf("\nBiTreeHeight:\t\t%d\n", GetBiTreeHeight(bt));
	printf("NodeNumber:\t\t%d\n", GetNodeNumber(bt));
	printf("LeafNodeNumber:\t\t%d\n", GetLeafNodeNumber(bt));
	printf("3th Level Node Number:\t%d\n", GetKthLevelNodeNumber(bt, 3));
	printf("6th Level Node Number:\t%d\n", GetKthLevelNodeNumber(bt, 6));
	printf("10th Level Node Number:\t%d\n", GetKthLevelNodeNumber(bt, 10));

	DestroyBiTree(&bt);

	return 0;
}
