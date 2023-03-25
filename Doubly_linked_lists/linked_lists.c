#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_lists.h"

void push_element_begining(struct g_node *head, int new_element_value){
    struct g_node *new_element = malloc(sizeof(struct g_node));

    new_element->info = new_element_value;
    new_element->next = head->next;
    head->next = new_element;
}

void push_element_end(struct g_node *head, int new_element_value){
    struct g_node *new_element = malloc(sizeof(struct g_node));
    struct g_node *iterator = head;
    struct g_node *last_element;

    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    last_element = iterator;

    last_element->next = new_element;
    new_element->info = new_element_value;
    new_element->next = NULL;
}

///to be implemented
void push_element_at_position(struct g_node *head, int position, int new_element_value){
    struct g_node *iterator;
    struct g_node *previous_element;
    struct g_node *new_element;
    int current_position;

    assert(position >= 0);
    new_element = malloc(sizeof(struct g_node));
    new_element->info = new_element_value;
    iterator = head;
    current_position = 0;

    while( (current_position < position) && (iterator->next != NULL)){
        current_position++;
        iterator = iterator->next;
    }

    previous_element = iterator;
    new_element->next = previous_element->next;
    previous_element->next = new_element;
}

void print_list(struct g_node *head){
    struct g_node *iterator = head;

    printf("\n List: ");
    while (iterator->next != NULL) {
        printf("%d ", iterator->next->info);
        iterator = iterator->next;
    }
}

///to be implemented
int find_postion_of_value(struct g_node *head ,int element_value){
    int position = -1; //list is empty
    struct g_node *iterator = head;
    int element_found = 0;

    while (iterator->next != NULL) {
        position++;
        if (iterator->next->info == element_value){
            element_found = 1;
            break;
        }
        iterator = iterator->next;
    }

    if (element_found == 1){
        return position;
    }else{
        return -2; // not found in list
    }

}

///to be implemented
int pop_element_begining(struct g_node *head){
    struct g_node *poped_element;
    int aux;

    poped_element = head->next;
    head->next = poped_element->next;
    aux = poped_element->info;
    free(poped_element);

    return aux;
}

///to be implemented
int pop_element_end(struct g_node *head){
    struct g_node *poped_element;
    struct g_node *iterator;
    int aux;

    iterator = head;
    while (iterator->next->next != NULL) {
        iterator = iterator->next;
    }

    poped_element = iterator->next;
    iterator->next = poped_element->next;
    aux = poped_element->info;
    free(poped_element);

    return aux;
}

///to be implemented
int pop_element_at_position(struct g_node *head, int position){
    struct g_node *iterator;
    struct g_node *poped_element;
    struct g_node *previous_element;
    int current_position;
    int aux;

    assert(position >= 0);
    iterator = head;
    current_position = 0;

    while( (current_position < position) && (iterator->next != NULL)){
        current_position++;
        iterator = iterator->next;
    }

    previous_element = iterator;
    poped_element = previous_element->next;
    previous_element->next = poped_element->next;
    aux = poped_element->info;
    free(poped_element);

    return aux;
}

///to be implemented
int return_no_elements(struct g_node *head){
    int no_elements ;
    struct g_node *iterator;
    iterator = head;
    no_elements = 0;

    while (iterator->next != NULL){
        no_elements++;
        iterator = iterator->next;
    }

    return no_elements;
}
