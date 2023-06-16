#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkqueue.h"
#define MAX 9
typedef int vertex_t;
typedef struct
{
	vertex_t V[MAX];
	int matrix[MAX][MAX];
}graph_t;
extern int visited[MAX];
extern graph_t *create_graph();
extern void input_edge(graph_t*);
extern void print_matrix(graph_t*);
extern void DFS(graph_t*, int);
extern void BFS(graph_t*, int);
extern int first_adj(graph_t*, int);
extern int next_adj(graph_t*, int, int);
#endif
