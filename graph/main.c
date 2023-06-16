#include "graph.h"

void main(int argc, const char* argv[])
{
	graph_t *g = NULL;
	g = create_graph();
	input_edge(g);
	print_matrix(g);
	// DFS(g, 0);
	BFS(g, 0);
	putchar('\n');
}
