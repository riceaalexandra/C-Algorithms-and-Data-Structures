#ifndef CODE_DOUBLY_LINKED_LISTS_H
#define CODE_DOUBLY_LINKED_LISTS_H

struct doubly_node{
    int info;
    struct doubly_node *next;
    struct doubly_node *previous;
};
void dl_interchange_nodes_values(struct doubly_node *node_1, struct doubly_node *node_2);
void dl_push_element_begining(struct doubly_node *head, struct doubly_node *tail ,int new_element_value);
void dl_push_element_end(struct doubly_node *head ,struct doubly_node *tail ,int new_element_value);
void dl_push_element_at_position(struct doubly_node *head, struct doubly_node *tail, int position, int new_element_value);
void dl_print_list(struct doubly_node *head, struct doubly_node *tail);
void dl_print_list_reverse(struct doubly_node *head, struct doubly_node *tail);
void dl_empty_list(struct doubly_node *head, struct doubly_node *tail);
void dl_selection_sort(struct doubly_node *head);
int dl_pop_element_begining(struct doubly_node *head, struct doubly_node *tail);
int dl_get_no_elements(struct doubly_node *head, struct doubly_node *tail);
int dl_pop_element_end(struct doubly_node *head, struct doubly_node *tail);
int dl_pop_element_at_position(struct doubly_node *head, struct doubly_node *tail, int position);


#endif //CODE_DOUBLY_LINKED_LISTS_H

