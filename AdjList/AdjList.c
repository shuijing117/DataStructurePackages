/*************************************************************************
    > File Name: AdjList.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Tue 22 Dec 2015 10:15:13 AM CST
 ************************************************************************/

#include "AdjList.h"

BOOL DestroyAdjList(AdjList *G)
{
	int i;
	ArcNode *p, *q;

	if(G == NULL)
		return FALSE;

	for(i = 0; i < G->vernum; i++) {
		p = (G->vertex)[i].firstarc;
		while(p) {
			q = p->nextarc;
			free(p);
			p = q;
		}
	}

	free(G->vertex);
	free(visited);

	return TRUE;
}

void PrintAdjList(const AdjList *G)
{
	int i;
	ArcNode *p;

	if(G == NULL)
		return;

	printf("\nAdjList:\n");
	for(i = 0; i < G->vernum; i++) {
		printf("%d %c", i, (G->vertex)[i].data);
		p = (G->vertex)[i].firstarc;
		while(p) {
			if(G->kind == UDG || G->kind == DG)
				printf(" -> %d", p->adjvex);
			else
				printf(" -> %d %d", p->adjvex, p->weight);

			p = p->nextarc;
		}
		printf("\n");
	}
}

void DepthTraverseList(const AdjList *G)
{
	int i;

	for(i = 0; i < G->vernum; i++)
		visited[i] = FALSE;

	for(i = 0; i < G->vernum; i++)
		if(visited[i] == FALSE)
			DepthFirstSearch(G, i);
}

void BreadthTraverseList(const AdjList *G)
{
	int i;

	for(i = 0; i < G->vernum; i++)
		visited[i] = FALSE;

	for(i = 0; i < G->vernum; i++)
		if(visited[i] == FALSE)
			BreadthFirstSearch(G, i);
}

static void DepthFirstSearch(const AdjList *G, int i)
{
	int j;
	ArcNode *p;

	printf("%c ", (G->vertex)[i].data);
	visited[i] = TRUE;

	p = (G->vertex[i]).firstarc;
	while(p) {
		if(visited[p->adjvex] == FALSE)
			DepthFirstSearch(G, p->adjvex);
		p = p->nextarc;
	}
}

static void BreadthFirstSearch(const AdjList *G, int i)
{
	int *que;
	int front, rear;
	ArcNode *p;
	int t;

	que = (int *)malloc(sizeof(int) * (G->vernum));
	if(que == NULL)
		return;
	front = rear = 0;

	que[rear] = i;
	rear = (rear+1) % (G->vernum);
	visited[i] = TRUE;
	printf("%c ", (G->vertex)[i].data);

	while(front != rear) {
		t = que[front];
		front = (front+1) % (G->vernum);
//		printf("%c ", (G->vertex)[t].data);

		p = (G->vertex)[t].firstarc;
		while(p) {
			if(visited[p->adjvex] == FALSE) {
				que[rear] = p->adjvex;
				rear = (rear+1) % (G->vernum);
				visited[p->adjvex] = TRUE;
				printf("%c ", (G->vertex)[p->adjvex].data);
			}
			p = p->nextarc;
		}
	}
}

CreateAdjList(AdjList *G, const VertexData *verData, int vernum, const Edge *edges, int arcnum, GraphKind kind)
{
	int i;
	ArcNode *p, *q;

	G->vernum = vernum;
	G->arcnum = arcnum;
	G->kind = kind;

	visited = (int *)calloc(G->vernum, sizeof(int));
	if(visited == NULL)
		return FALSE;

	G->vertex = (VertexNode *)calloc(G->vernum, sizeof(VertexNode));
	if(G->vertex == NULL) 
		return FALSE;

	for(i = 0; i < G->vernum; i++) {
		(G->vertex)[i].data = verData[i];
		(G->vertex)[i].firstarc = NULL;
	}

	for(i = 0; i < arcnum; i++) {
		if(edges[i].i >= 0 && edges[i].i < G->arcnum && edges[i].j >= 0 && edges[i].j < G->arcnum) {
			p = (ArcNode *)malloc(sizeof(ArcNode));
			if(p == NULL) 
				return FALSE;
			p->adjvex = edges[i].j;
			p->weight = edges[i].we;

			p->nextarc = (G->vertex)[edges[i].i].firstarc;
			(G->vertex)[edges[i].i].firstarc = p;
			
			if(G->kind == UDG || G->kind == UDN) {
				q = (ArcNode *)malloc(sizeof(ArcNode));
				if(q == NULL) 
					return FALSE;
				q->adjvex = edges[i].i;
				q->weight = edges[i].we;

				q->nextarc = (G->vertex)[edges[i].j].firstarc;
				(G->vertex)[edges[i].j].firstarc = q;
			}
		}
	}

	return TRUE;
}