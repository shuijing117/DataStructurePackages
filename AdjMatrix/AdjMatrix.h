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

BOOL CreateAdjMatrix(AdjMatrix *G, const char *verData, int vernum, const Edge *edges, int arcnum, GraphKind kind);
void DestroyAdjMatrix(AdjMatrix *G);
void PrintAdjMatrix(const AdjMatrix *G);
void DepthTraverseGraph(const AdjMatrix *G);
void BreadthTraverseGraph(const AdjMatrix *G);
static void DepthFirstSearch(const AdjMatrix *G, int i);
static void BreadthFirstSearch(const AdjMatrix *G, int i);

static void BreadthFirstSearch(const AdjMatrix *G, int i)
{
	int *queue;
	int front, rear;
	int j, t;

	queue = (int *)malloc(sizeof(int) * G->vernum);
	if(queue == NULL)
		return;
	front = rear = 0;

	queue[rear] = i;
	rear = (rear+1) % G->vernum;
	visited[i] = TRUE;

	while(front != rear) {
		t = queue[front];
		front = (front+1) % G->vernum;
		printf("%c ", (G->vertex)[t]);

		for(j = 0; j < G->vernum; j++)
			if(visited[j] == FALSE && (G->arcs)[t][j].adj != 0 && (G->arcs)[t][j].adj != INFINITY) {
				queue[rear] = j;
				rear = (rear+1) % G->vernum;
				visited[j] = TRUE;
			}
	}

}

void BreadthTraverseGraph(const AdjMatrix *G)
{
	int i;

	for(i = 0; i < G->vernum; i++)
		visited[i] = FALSE;

	for(i = 0; i < G->vernum; i++)
		if(visited[i] == FALSE)
			BreadthFirstSearch(G, i);
	
}

static void DepthFirstSearch(const AdjMatrix *G, int i)
{
	int j;

	printf("%c ", (G->vertex)[i]);
	visited[i] = TRUE;

	for(j = 0; j < G->vernum; j++) 
		if(visited[j] == FALSE && (G->arcs)[i][j].adj != 0 && (G->arcs)[i][j].adj != INFINITY)
			DepthFirstSearch(G, j);
}

void DepthTraverseGraph(const AdjMatrix *G)
{
	int i;

	for(i = 0; i < G->vernum; i++)
		visited[i] = FALSE;

	for(i = 0; i < G->vernum; i++)
		if(visited[i] == FALSE)
			DepthFirstSearch(G, i);
}

void PrintAdjMatrix(const AdjMatrix *G)
{
	int i, j;

	if(G == NULL)
		return;

	for(i = 0; i < G->vernum; i++)
		printf("\t%c", (G->vertex)[i]);
	printf("\n");

	for(i = 0; i < G->vernum; i++) {
		printf("%c", (G->vertex)[i]);
		for(j = 0; j < G->vernum; j++)
			if((G->arcs)[i][j].adj == INFINITY)
				printf("\t+");
			else
				printf("\t%d", (G->arcs)[i][j].adj);
		printf("\n");
	}
}

void DestroyAdjMatrix(AdjMatrix *G)
{
	int i;

	if(G == NULL)
		return;

	free(G->vertex);

	for(i = 0; i < G->vernum; i++) 
		free((G->arcs)[i]);
	free(G->arcs);

	free(visited);
}

BOOL CreateAdjMatrix(AdjMatrix *G, const char *verData, int vernum, const Edge *edges, int arcnum, GraphKind kind)
{
	int i, j;

	G->vernum = vernum;
	G->arcnum = arcnum;
	G->kind = kind;

	visited = (int *)malloc(sizeof(int) * G->vernum);
	if(visited == NULL)
		return FALSE;
	
	G->vertex = (VertexData *)malloc(sizeof(VertexData) * (G->vernum+1));
	if(G->vertex == NULL)
		return FALSE;

	strcpy(G->vertex, verData);

	G->arcs = (ArcNode **)malloc(sizeof(ArcNode *) * G->vernum);
	if(G->arcs == NULL)
		return FALSE;

	for (i = 0; i < G->vernum; i++) {
		(G->arcs)[i] = (ArcNode *)calloc(G->vernum, sizeof(ArcNode));
		if((G->arcs)[i] == NULL)
			return FALSE;
	}

	for(i = 0; i < G->arcnum; i++) {
		if(edges[i].i >= 0 && edges[i].i < G->vernum && edges[i].j >= 0 && edges[i].j < G->vernum && edges[i].i != edges[i].j) {
			if(G->kind == DG) 
				(G->arcs)[edges[i].i][edges[i].j].adj = 1;
			else if(G->kind == UDG) 
				(G->arcs)[edges[i].i][edges[i].j].adj  = (G->arcs)[edges[i].j][edges[i].i].adj = 1;
			else if(G->kind == DN)
				(G->arcs)[edges[i].i][edges[i].j].adj = edges[i].we;
			else if(G->kind == UDN)
				(G->arcs)[edges[i].i][edges[i].j].adj = (G->arcs)[edges[i].j][edges[i].i].adj = edges[i].we;
			else
				return FALSE;
		}
	}

	if(G->kind == DN || G->kind == UDN)
		for(i = 0; i < G->vernum; i++)
			for(j = 0; j < G->vernum; j++) 
				if(i != j && (G->arcs)[i][j].adj == 0) {
					(G->arcs)[i][j].adj = INFINITY;
				}
	
	return TRUE;
}

#endif
