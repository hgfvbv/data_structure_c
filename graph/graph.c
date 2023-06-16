#include "graph.h"
int visited[MAX];
graph_t *create_graph()
{
	graph_t *g = NULL;
	g = (graph_t*)malloc(sizeof(graph_t));
	if(NULL == g)
	{
		printf("malloc is fail!\n");
		return NULL;	
	}
	memset(g, 0, sizeof(graph_t));
	for(int i = 0; i < MAX; ++i)
	{
		g->V[i] = i;
		visited[i] = 0;	
	}
	return g;
}

void input_edge(graph_t *g)
{
	int i = 0, j = 0;
	printf("Input edge like (V0,V1) (V0,V2) ... \n"); 	
	while(scanf("(V%d,V%d)", &i, &j) == 2) 
	{
		g->matrix[i][j] = g->matrix[j][i] = 1;
		getchar();	
	}
	while('\n' != getchar());
}

void print_matrix(graph_t *g)
{
	printf("%3c", ' ');
	for(int i = 0; i < MAX; ++i)
	{
		printf("V%-2d", i);	
	}
	printf("\n");
	for(int i = 0; i < MAX; ++i)
	{
		printf("V%-2d", i);
		for(int j = 0; j < MAX; ++j)
		{
			printf("%-3d", g->matrix[i][j]);	
		}	
		printf("\n");
	}
}

int first_adj(graph_t *g, int v)
{
	for(int i = 0; i < MAX; ++i)
	{
		if(0 != g->matrix[v][i])
			return i;	
	}
	return -1;
}

int next_adj(graph_t *g, int v, int u)
{
	for(int i = u + 1; i < MAX; ++i)
	{
		if(0 != g->matrix[v][i])
			return i;	
	}
	return -1;
}

void DFS(graph_t *g, int v)
{
	int u = 0;
	printf("V%-3d", v);
	visited[v] = 1;
	u = first_adj(g, v);
	while(u > -1)
	{
		if(0 == visited[u])
		{
			DFS(g, u);	
		}	
		u = next_adj(g, v, u);
	}
}

void BFS(graph_t *g, int v)
{
	int t = 0;
	linkqueue_t *q = create_empty_linkqueue();
	if(NULL == q)
	{
		printf("malloc is fail!\n");
		return;	
	}
	visited[v] = 1;
	enter_linkqueue(q, v);
	while(!is_empty_linkqueue(q))
	{
		t = delete_linkqueue(q);
		printf("V%-3d ", t);
		for(int i = 0; i < MAX; ++i)
		{
			if(1 == g->matrix[t][i] && 0 == visited[i])
			{
				visited[i] = 1;
				enter_linkqueue(q, i);	
			}	
		}	
	}	
}
