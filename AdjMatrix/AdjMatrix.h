/*************************************************************************
    > File Name: AdjMatrix.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Fri 11 Dec 2015 09:56:52 AM CST
 ************************************************************************/
#ifndef		_ADJ_MAXTRIX_H_
#define		_ADJ_MAXTRIX_H_

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>

#define		TRUE		1
#define		FALSE		0

#define		INFINITY	2147483647

typedef int BOOL;
typedef char VertexData;
typedef enum{
	DG = 1,		// Directed Graph
	DN,			// Directed Network
	UDG,		// Undirected Graph
	UDN			// Undirected Network
} GraphKind;

typedef struct _ARCNODE {
	int adj;
	//OtherInfo
}ArcNode;

typedef struct _EDGE {
	int i;
	int j;
	int we;
}Edge;

typedef struct _ADJMATRIX {
	VertexData *vertex;
	ArcNode **arcs;
	int vernum;
	int arcnum;
	GraphKind kind;
}AdjMatrix;

int *visited;

BOOL CreateAdjMatrix(AdjMatrix *G, const VertexData *verData, int vernum, const Edge *edges, int arcnum, GraphKind kind);
void DestroyAdjMatrix(AdjMatrix *G);
void PrintAdjMatrix(const AdjMatrix *G);
void DepthTraverseGraph(const AdjMatrix *G);
void BreadthTraverseGraph(const AdjMatrix *G);
static void DepthFirstSearch(const AdjMatrix *G, int i);
static void BreadthFirstSearch(const AdjMatrix *G, int i);

#endif
