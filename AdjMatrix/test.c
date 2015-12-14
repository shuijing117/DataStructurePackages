/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Fri 11 Dec 2015 11:17:49 AM CST
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "AdjMatrix.h"

int main(void) 
{
    AdjMatrix G;
	int kind;
	int vernum, arcnum;
	char *vertex;
	int i, tag = TRUE;
	char yes[5];
	Edge *edges;

	printf("1-Directed Graph.\n");
	printf("2-Directed Network.\n");
	printf("3-Undirected Graph.\n");
	printf("4-Undirected network.\n");
	printf("Please choose kind of your graph : ");

	while(tag) {
		scanf("%d", &kind);

		if(kind > 0 && kind < 5)
			tag = FALSE;
		else
			printf("Please input 1~4:");
	}

	printf("How many vertexs in graph? ");
	scanf("%d", &vernum);
	getchar();

	vertex = (char *)malloc(sizeof(char) * (vernum + 1));
	if(vertex == NULL)
		return FALSE;

	tag = TRUE;
	printf("Please input your vertexs' info : ");
	while(tag){
		scanf("%s", vertex);

		if(strlen(vertex) == vernum)
		{
			printf("Vertex Information:\n");
			for(i = 0; i < vernum; i++)
				printf("%d:%c\n", i, vertex[i]);

			printf("The above output right? (yes/no) :");
			scanf("%s", yes);
		
			for(i = 0; i < strlen(yes); i++)
				yes[i] = toupper(yes[i]);

			if(strcmp(yes, "Y") == 0 || strcmp(yes, "YES") == 0)
				tag = FALSE;
		}
		if (tag)
			printf("Please input your vertexs' info again : ");
	}


	printf("How many edges in graph? ");
	scanf("%d", &arcnum);
	getchar();

	edges = (Edge *)malloc(sizeof(Edge) * arcnum);

	printf("Input edges.\n");
	printf("Example:\n");
	printf("if you choose directed graph or undirected graph, use <arc1, arc2>.\n");
	printf("if you choose directed network or undirected network, use <arc1, arc2, weight>.\n");
	printf("arc1 and arc2 is edges' number.\n");
	printf("Please input edges:\n");

	for(i = 0; i < arcnum; i++) {
		if(kind == DG || kind == UDG) {
			scanf("%d,%d", &(edges[i].i), &(edges[i].j));
		} else if(kind == DN || kind == UDN) {
			scanf("%d,%d,%d", &(edges[i].i), &(edges[i].j), &(edges[i].we));
		} else {
			return FALSE;
		}
	}

	CreateAdjMatrix(&G, vertex, vernum, edges, arcnum, (GraphKind)kind);

	PrintAdjMatrix(&G);

	printf("DepthTraverseGraph: ");
	DepthTraverseGraph(&G);
	printf("\n");

	printf("BreadthTraverseGraph:");
	BreadthTraverseGraph(&G);
	printf("\n");

	DestroyAdjMatrix(&G);

	return 0;
}
