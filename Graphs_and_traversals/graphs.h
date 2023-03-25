#ifndef CODE_SKELETON_GRPAPHS_GRAPHS_H
#define CODE_SKELETON_GRPAPHS_GRAPHS_H

struct a_graph {
    int no_nodes;
    int init;
    int *adj_matrix;
};

struct a_list_node{
    int info;
    struct a_list_node *next;
};

void set_adj_matrix_value(struct a_graph *graph, int row_index, int column_index, int element_value);
void init_graph(struct a_graph *graph);
void init_graph_file(struct a_graph *graph);
void print_adj_matrix(struct a_graph *graph);
void delete_graph(struct a_graph *graph);
void push_begining_list(struct a_list_node *head, int new_element_value);
void graph_bfs(struct a_graph *graph, int start_node);
void graph_dfs(struct a_graph *graph, int start_node);
int pop_begining_list(struct a_list_node *head);
int pop_end_list(struct a_list_node *head);
int get_adj_matrix_value(struct a_graph *graph, int row_index, int column_index);

#endif //CODE_SKELETON_GRPAPHS_GRAPHS_H
