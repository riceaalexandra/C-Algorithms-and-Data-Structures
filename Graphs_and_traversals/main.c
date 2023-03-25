#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

int main() {
    struct a_graph *graph_1;
    struct a_graph *graph_2;

    graph_1 = calloc(1, sizeof(struct a_graph));
    graph_2 = calloc(1, sizeof(struct a_graph));
    init_graph(graph_1);
    print_adj_matrix(graph_1);
    init_graph_file(graph_2);
    print_adj_matrix(graph_2);
    graph_bfs(graph_2,0);
    graph_dfs(graph_2,0);

    delete_graph(graph_1);
    delete_graph(graph_2);

    return 0;
}
