#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graphs.h"

void set_adj_matrix_value(struct a_graph *graph, int row_index, int column_index, int element_value){
    int position;

    assert(row_index < graph->no_nodes);
    assert(column_index < graph->no_nodes);

    position = row_index * graph->no_nodes + column_index;
    *(graph->adj_matrix + position) = element_value;
}


int get_adj_matrix_value(struct a_graph *graph, int row_index, int column_index) {
    int position;

    assert(row_index < graph->no_nodes);
    assert(column_index < graph->no_nodes);

    if (graph->init == 1){
        position = row_index * graph->no_nodes + column_index;
        return *(graph->adj_matrix + position);
    }else{
        printf("Please read the graph first");
        return -1;
    }
}

void init_graph(struct a_graph *graph){
    int iterator_rows;
    int iterator_columns;
    int aux;

    printf("\nGive no nodes = ");
    scanf("%d", &graph->no_nodes);
    graph->init = 1;
    graph->adj_matrix = calloc(graph->no_nodes * graph->no_nodes,sizeof(int));

    assert((graph->no_nodes * graph->no_nodes) > 0);

    for (iterator_rows = 0; iterator_rows < graph->no_nodes; iterator_rows++ ){
        for (iterator_columns = 0; iterator_columns < graph->no_nodes; iterator_columns++ ){
            printf(" graph[%d][%d]= ",iterator_rows, iterator_columns);
            scanf("%d", &aux);
            set_adj_matrix_value(graph, iterator_rows, iterator_columns, aux);
        }
    }
}

void init_graph_file(struct a_graph *graph){
    FILE *file_in;
    int iterator_rows;
    int iterator_columns;
    int aux;

    file_in = fopen("data\\in.txt", "r");
    if (file_in == NULL){
        printf("\n File does not exist.");
        fclose(file_in);
        return;
    }
    fscanf(file_in, "%d", &graph->no_nodes);
    graph->init = 1;
    graph->adj_matrix = calloc(graph->no_nodes * graph->no_nodes, sizeof(int));

    assert((graph->no_nodes * graph->no_nodes) > 0);

    for (iterator_rows = 0; iterator_rows < graph->no_nodes; iterator_rows++ ){
        for (iterator_columns = 0; iterator_columns < graph->no_nodes; iterator_columns++ ){
            fscanf(file_in, "%d ", &aux);
            set_adj_matrix_value(graph, iterator_rows, iterator_columns, aux);
        }
    }

    fclose(file_in);
    printf("=== Reading from file successfull ===\n");
}



void print_adj_matrix(struct a_graph *graph){
    int iterator_rows;
    int iterator_columns;
    int aux;

    if (graph->init == 1){
        printf("=== Printing adj_matrix ===\n");
        for (iterator_rows = 0; iterator_rows < graph->no_nodes; iterator_rows++ ){
            for (iterator_columns = 0; iterator_columns < graph->no_nodes; iterator_columns++ ){
                aux = get_adj_matrix_value(graph, iterator_rows, iterator_columns);
                printf(" %d ", aux);
            }
            printf("\n");
        }
    }else{
        printf("\nPlease read the adj_matrix first");
    }
}

void delete_graph(struct a_graph *graph){
    free(graph->adj_matrix);
    free(graph);
}

void push_begining_list(struct a_list_node *head, int new_element_value){
    struct a_list_node *next_element;
    struct a_list_node *new_element;

    next_element = head->next;
    new_element = malloc(sizeof(struct a_list_node));
    new_element->info = new_element_value;
    new_element->next = head->next;
    head->next = new_element;
}

int pop_begining_list(struct a_list_node *head){
    struct a_list_node *deleted_element;
    int aux;

    if (head->next != NULL) {
        deleted_element = head->next;
        aux = deleted_element->info;
        head->next = deleted_element->next;
        free(deleted_element);
        return aux;
    }else{
        printf("\n The list is empty");
        return -1; //the list is empty
    }
}

int pop_end_list(struct a_list_node *head) {
    struct a_list_node *deleted_element;
    struct a_list_node *iterator;
    int aux;

    if (head->next != NULL) {
        for (iterator = head; iterator->next->next != NULL; iterator = iterator->next);
        deleted_element = iterator->next;
        aux = deleted_element->info;
        iterator->next = deleted_element->next;
        free(deleted_element);
        return aux;
    } else {
        printf("\n The list is empty");
        return -1; //the list is empty
    }
}

void graph_bfs(struct a_graph *graph, int start_node){
    struct a_list_node *head_queue;
    int *visited;
    int column_index;
    int aux;
    int current_node;

    head_queue = calloc(1, sizeof(struct a_list_node));
    head_queue->next = NULL;
    head_queue->info = 0; //no of elements in the queue
    visited = calloc((graph->no_nodes), sizeof(int));
    push_begining_list(head_queue, start_node);
    visited[start_node] = 1;

    printf("\nBFS traversal: ");
    while (head_queue->next != NULL){
        current_node = pop_end_list(head_queue);
        printf("%d,",current_node);
        for(column_index = 0; column_index < graph->no_nodes; column_index++){
            aux = get_adj_matrix_value(graph, current_node, column_index);
            if ( (aux != 0) && ( (visited[column_index]) == 0 )){
                push_begining_list(head_queue, column_index);
                visited[column_index] = 1;
            }
        }
    }

    free(head_queue);
    free(visited);
}

void graph_dfs(struct a_graph *graph, int start_node){

    struct a_list_node *head_queue;
    int *visited;
    int column_index;
    int aux;
    int current_node;

    head_queue = calloc(1, sizeof(struct a_list_node));
    head_queue->next = NULL;
    head_queue->info = 0; //no of elements in the queue
    visited = calloc((graph->no_nodes), sizeof(int));
    push_begining_list(head_queue, start_node);
    visited[start_node] = 1;

    printf("\nBFS traversal: ");
    while (head_queue->next != NULL){
        current_node = pop_end_list(head_queue);
        printf("%d,",current_node);
        for(column_index = 0; column_index < graph->no_nodes; column_index++){
            aux = get_adj_matrix_value(graph, current_node, column_index);
            if ( (aux != 0) && ( (visited[column_index]) == 0 )){
                push_begining_list(head_queue, column_index);
                visited[column_index] = 1;
            }
        }
    }

    free(head_queue);
    free(visited);

}
