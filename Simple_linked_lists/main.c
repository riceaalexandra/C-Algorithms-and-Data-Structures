#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "vectors.h"
#include "sort.h"
#include "utils.h"
#include "linked_lists.h"


int main(){
    struct g_node *head = malloc(sizeof(struct g_node));
    int aux;
    int aux2;

    head->next = NULL;

    printf("\n===== Pushing at the begining ======");
    push_element_begining(head, 1);
    print_list(head);
    push_element_begining(head, 2);
    print_list(head);

    printf("\n===== Pushing at the end ======");
    push_element_end(head, 3);
    print_list(head);

    printf("\n===== Pushing at specific position ======");
    print_list(head);
    push_element_at_position(head,3,10);
    print_list(head);

    printf("\n===== No elements in list ======");
    aux = return_no_elements(head);
    printf("\nThe list has %d elments ", aux);

    printf("\n===== Finding the position of a specific element ======");
    printf("\nGive the searched element's value: ");
    scanf("%d",&aux);
    aux2 = find_postion_of_value(head,aux);
    printf("\nThe position of element %d is %d", aux, aux2);

    printf("\n===== Poping from the begining ======");
    aux = pop_element_begining(head);
    printf("\n The poped element is %d",aux);
    print_list(head);

    printf("\n===== Poping from the end ======");
    aux = pop_element_end(head);
    printf("\n The poped element is %d",aux);
    print_list(head);

    printf("\n===== Poping from specific position ======");
    push_element_begining(head,2);
    push_element_begining(head,3);
    print_list(head);
    aux = pop_element_at_position(head,0);
    printf("\n The poped element is %d",aux);
    print_list(head);

    free(head);

    return 0;
}
