//
// Created by Ionut on 3/24/2019.
//

#ifndef CODE_LISTS_H
#define CODE_LISTS_H

struct g_node{
    int info;
    struct g_node *next;
};

void push_element_begining(struct g_node *head ,int new_element_value);
void push_element_end(struct g_node *head ,int new_element_value);
void push_element_at_position(struct g_node *head, int position, int new_element_value);
void push_element_at_position(struct g_node *head, int position, int new_element_value);
void print_list(struct g_node *head);
int find_postion_of_value(struct g_node *head ,int element_value);
int pop_element_begining(struct g_node *head);
int pop_element_end(struct g_node *head);
int pop_element_at_position(struct g_node *head, int position);
int return_no_elements(struct g_node *head);

#endif //CODE_LISTS_H
