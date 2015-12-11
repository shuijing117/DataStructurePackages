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
	ArcNode **adj;
	int vernum;
	int arcnum;
	GraphKind kind;
}AdjMatrix;

BOOL CreateAdjMatrix(AdjMatrix *G);
void DestroyAdjMatrix(AdjMatrix *G);
void PrintAdjMatrix(AdjMatrix *G);

void PrintAdjMatrix(AdjMatrix *G)
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
			if((G->adj)[i][j].adj == INFINITY)
				printf("\t+");
			else
				printf("\t%d", (G->adj)[i][j].adj);
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
		free((G->adj)[i]);
	free(G->adj);
}

BOOL CreateAdjMatrix(AdjMatrix *G)
{
	int i;
	int m, n;
	int we;

	printf("\n1-Directed Graph.\n2-Directed Network.\n3-Undirected Graph.\n4-Undirected network.\nPlease choose kind of your graph.):");
	scanf("%d", &m);

	G->kind = (GraphKind)m;

	printf("How many vertexs in graph? ");
	scanf("%d", &(G->vernum));
	getchar();
	
	G->vertex = (VertexData *)malloc(sizeof(VertexData) * G->vernum);
	if(G->vertex == NULL)
		return FALSE;

	printf("Please input your vertexs' info : ");
	for(i = 0; i < G->vernum; i++)
		scanf("%c", &((G->vertex)[i]));

	printf("Vertex Information:\n");
	for(i = 0; i < G->vernum; i++)
		printf("%d:%c\n", i, (G->vertex)[i]);

	G->adj = (ArcNode **)malloc(sizeof(ArcNode *) * G->vernum);
	if(G->adj == NULL)
		return FALSE;

	for (i = 0; i < G->vernum; i++) {
		(G->adj)[i] = (ArcNode *)calloc(G->vernum, sizeof(ArcNode));
		if((G->adj)[i] == NULL)
			return FALSE;
	}
	printf("How many edges in graph? ");
	scanf("%d", &(G->arcnum));
	getchar();

	printf("Please input edges.\n");
	printf("Example:\n");
	printf("\tif you choose directed graph or undirected graph, use <arc1, arc2>.\n");
	printf("\tif you choose directed network or undirected graph, use <arc1, arc2, weight>.\n");
	printf("\tarc1 and arc2 is edges' number.\n");

	for(i = 0; i < G->arcnum; i++) {
		if(G->kind == DG) {
			scanf("%d,%d", &m, &n);
			(G->adj)[m][n].adj = 1;
		} else if(G->kind == DN) {
			scanf("%d,%d,%d", &m, &n, &we);
			(G->adj)[m][n].adj = we;
		} else if(G->kind == UDG) {
			scanf("%d,%d", &m, &n);
			(G->adj)[m][n].adj = 1;
			(G->adj)[n][m].adj = 1;
		} else if(G->kind == UDN) {
			scanf("%d,%d,%d", &m, &n, &we);
			(G->adj)[m][n].adj = we;
			(G->adj)[n][m].adj = we;
		} else {
			return FALSE;
		}
	}

	if(G->kind == DN || G->kind == UDN)
		for(m = 0; m < G->vernum; m++)
			for(n = 0; n < G->vernum; n++) 
				if(m != n && (G->adj)[m][n].adj == 0) {
					(G->adj)[m][n].adj = INFINITY;
					if(G->kind == UDN)
						(G->adj)[n][m].adj = INFINITY;
				}
	
	return TRUE;
}

#endif
