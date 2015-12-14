/*************************************************************************
    > File Name: AdjList.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Mon 14 Dec 2015 06:27:37 PM CST
 ************************************************************************/
#ifndef		_ADJLIST_H_
#define		_ADJLIST_H_

#include <malloc.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define		TRUE		1
#define		FALSE		0

typedef int BOOL;
typedef char VertexData;

typedef struct _EDGE {
	int i;
	int j;
	int we;
}Edge;

typedef enum {
	DG = 1,
	DN,
	UDG,
	UDN
} GraphKind;

typedef struct _ARCNODE {
	int adjvex;
	int weight;
	struct _ARCNODE *nextarc;
} ArcNode;

typedef struct _VERTEXNODE {
	VertexData data;
	ArcNode *firstarc;
} VertexNode;

typedef struct _ADJLIST {
	VertexData *vertex;
	int vernum;
	int arcnum;
	GraphKind kind;
} AdjList;

BOOL CreateAdjList(AdjList *G, const VertexData *verData, int vernum, const Edge *edges, int arcnum, GraphKind kind);
BOOL DestroyAdjList(AdjList *G);
void PrintAdjList(const AdjList *G);
void DepthTraverseGraph(const AdjList *G);
void BreadthTraverseGraph(const AdjList *G);
static void DepthFirstSearch(const AdjList *G, int i);
static void BreadthFirstSearch(const AdjList *G, int i);

BOOL DestroyAdjList(AdjList *G)
{
	return TRUE;
}

void PrintAdjList(const AdjList *G)
{

}

void DepthTraverseGraph(const AdjList *G)
{

}

void BreadthTraverseGraph(const AdjList *G)
{

}

static void DepthFristSearch(const AdjList *G, int i)
{

}

static void BreadthFristSearch(const AdjList *G, int i)
{

}

CreateAdjList(AdjList *G, const VertexData *verData, int vernum, const Edge *edges, int arcnum, GraphKind kind)
{
//	int i, j;

	return TRUE;
}

#endif
