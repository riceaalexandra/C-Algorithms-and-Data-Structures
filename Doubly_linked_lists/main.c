#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "vectors.h"
#include "sort.h"
#include "utils.h"
#include "linked_lists.h"
#include "doubly_linked_lists.h"


int main(){
    struct doubly_node *head = malloc(sizeof(struct doubly_node));
    struct doubly_node *tail = malloc(sizeof(struct doubly_node));
    int aux;
    int aux2;

    head->previous = NULL;
    head->next = tail;
    head->info = 0;
    tail->previous = head;
    tail->next = NULL;

    printf("\n===== Pushing at the begining ======");
    dl_push_element_begining(head, tail, 1);
    dl_print_list(head,tail);
    dl_push_element_begining(head, tail, 2);
    dl_print_list(head,tail);
    dl_push_element_begining(head, tail, 3);
    dl_print_list(head, tail);

    printf("\n===== Printing reverse ======");
    dl_print_list_reverse(head, tail);

    printf("\n===== Pushing at the end ======");
    dl_print_list(head, tail);
    dl_push_element_end(head, tail, 4);
    dl_print_list(head, tail);
    dl_push_element_end(head, tail, 5);
    dl_print_list(head, tail);
    dl_push_element_end(head, tail, 6);
    dl_print_list(head, tail);

    printf("\n===== No elements in list ======");
    aux = dl_get_no_elements(head, tail);
    printf("\nThe list has %d elements ", aux);
    printf("\nThe list has %d elements ", head->info);

    printf("\n===== Pushing at specific position ======");
    dl_print_list(head, tail);
    dl_push_element_at_position(head,tail,4,10);
    dl_print_list(head, tail);

    printf("\n===== Poping from the begining ======");
    dl_print_list(head, tail);
    aux = dl_pop_element_begining(head, tail);
    printf("\n The poped element is %d",aux);
    dl_print_list(head, tail);

    printf("\n===== Poping from the end ======");
    dl_print_list(head, tail);
    aux = dl_pop_element_end(head, tail);
    printf("\n The poped element is %d",aux);
    dl_print_list(head, tail);

    printf("\n===== Poping from specific position ======");
    dl_print_list(head, tail);
    aux = dl_pop_element_at_position(head, tail, 4);
    printf("\n The poped element is %d",aux);
    dl_print_list(head, tail);

    printf("\n===== No elements in list ======");
    aux = dl_get_no_elements(head, tail);
    printf("\nThe list has %d elements ", aux);
    printf("\nThe list has %d elements ", head->info);

    printf("\n===== Empty list ======");
    dl_print_list(head, tail);
    dl_selection_sort(head);
    dl_print_list(head, tail);

    printf("\n===== Selection Sort ======");
    dl_print_list(head, tail);
    dl_empty_list(head, tail);
    dl_print_list(head, tail);

    printf("\n===== Queue (FIFO) ======");
    dl_push_element_begining(head, tail, 1);
    dl_push_element_begining(head, tail, 2);
    dl_push_element_begining(head, tail, 3);
    dl_print_list(head, tail);
    dl_pop_element_end(head, tail);
    dl_print_list(head,tail);
    dl_empty_list(head, tail);

    printf("\n===== Stack (LIFO) ======");
    dl_push_element_begining(head, tail, 1);
    dl_push_element_begining(head, tail, 2);
    dl_push_element_begining(head, tail, 3);
    dl_print_list(head, tail);
    dl_pop_element_begining(head, tail);
    dl_print_list(head,tail);
    dl_empty_list(head, tail);

    free(head);
    free(tail);

    return 0;
}
