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

typedef struct _ADJMATRIX {
	VertexData *vertex;
	ArcNode **arcs;
	int vernum;
	int arcnum;
	GraphKind kind;
}AdjMatrix;

int *visited;

BOOL CreateAdjMatrix(AdjMatrix *G);
void DestroyAdjMatrix(AdjMatrix *G);
void PrintAdjMatrix(const AdjMatrix *G);
void DepthTraverseGraph(const AdjMatrix *G);
void BreadthTraverseGraph(const AdjMatrix *G);
static void DepthFristSearch(const AdjMatrix *G, int i);
static void BreadthFristSearch(const AdjMatrix *G, int i);

static void BreadthFristSearch(const AdjMatrix *G, int i)
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
			BreadthFristSearch(G, i);
	
}

static void DepthFristSearch(const AdjMatrix *G, int i)
{
	int j;

	printf("%c ", (G->vertex)[i]);
	visited[i] = TRUE;

	for(j = 0; j < G->vernum; j++) 
		if(visited[j] == FALSE && (G->arcs)[i][j].adj != 0 && (G->arcs)[i][j].adj != INFINITY)
			DepthFristSearch(G, j);
}

void DepthTraverseGraph(const AdjMatrix *G)
{
	int i;

	for(i = 0; i < G->vernum; i++)
		visited[i] = FALSE;

	for(i = 0; i < G->vernum; i++)
		if(visited[i] == FALSE)
			DepthFristSearch(G, i);
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

BOOL CreateAdjMatrix(AdjMatrix *G)
{
	int i;
	int m, n;
	int we;

	printf("1-Directed Graph.\n");
	printf("2-Directed Network.\n");
	printf("3-Undirected Graph.\n");
	printf("4-Undirected network.\n");
	printf("Please choose kind of your graph.):");
	scanf("%d", &m);

	G->kind = (GraphKind)m;

	printf("How many vertexs in graph? ");
	scanf("%d", &(G->vernum));
	getchar();

	visited = (int *)malloc(sizeof(int) * G->vernum);
	if(visited == NULL)
		return FALSE;
	
	G->vertex = (VertexData *)malloc(sizeof(VertexData) * G->vernum);
	if(G->vertex == NULL)
		return FALSE;

	printf("Please input your vertexs' info : ");
	for(i = 0; i < G->vernum; i++)
		scanf("%c", &((G->vertex)[i]));

	printf("Vertex Information:\n");
	for(i = 0; i < G->vernum; i++)
		printf("%d:%c\n", i, (G->vertex)[i]);

	G->arcs = (ArcNode **)malloc(sizeof(ArcNode *) * G->vernum);
	if(G->arcs == NULL)
		return FALSE;

	for (i = 0; i < G->vernum; i++) {
		(G->arcs)[i] = (ArcNode *)calloc(G->vernum, sizeof(ArcNode));
		if((G->arcs)[i] == NULL)
			return FALSE;
	}
	printf("How many edges in graph? ");
	scanf("%d", &(G->arcnum));
	getchar();

	printf("Input edges.\n");
	printf("Example:\n");
	printf("if you choose directed graph or undirected graph, use <arc1, arc2>.\n");
	printf("if you choose directed network or undirected network, use <arc1, arc2, weight>.\n");
	printf("arc1 and arc2 is edges' number.\n");
	printf("Please input edges:\n");

	for(i = 0; i < G->arcnum; i++) {
		if(G->kind == DG) {
			scanf("%d,%d", &m, &n);
			(G->arcs)[m][n].adj = 1;
		} else if(G->kind == DN) {
			scanf("%d,%d,%d", &m, &n, &we);
			(G->arcs)[m][n].adj = we;
		} else if(G->kind == UDG) {
			scanf("%d,%d", &m, &n);
			(G->arcs)[m][n].adj = 1;
			(G->arcs)[n][m].adj = 1;
		} else if(G->kind == UDN) {
			scanf("%d,%d,%d", &m, &n, &we);
			(G->arcs)[m][n].adj = we;
			(G->arcs)[n][m].adj = we;
		} else {
			return FALSE;
		}
	}

	if(G->kind == DN || G->kind == UDN)
		for(m = 0; m < G->vernum; m++)
			for(n = 0; n < G->vernum; n++) 
				if(m != n && (G->arcs)[m][n].adj == 0) {
					(G->arcs)[m][n].adj = INFINITY;
					if(G->kind == UDN)
						(G->arcs)[n][m].adj = INFINITY;
				}
	
	return TRUE;
}

#endif
