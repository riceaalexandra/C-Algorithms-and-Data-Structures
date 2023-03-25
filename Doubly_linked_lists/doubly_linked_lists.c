#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "doubly_linked_lists.h"

void dl_interchange_nodes_values(struct doubly_node *node_1, struct doubly_node *node_2){
    int aux;

    aux = node_1->info;
    node_1->info = node_2->info;
    node_2->info = aux;
}

void dl_push_element_begining(struct doubly_node *head, struct doubly_node *tail ,int new_element_value){
    struct doubly_node *new_element;
    new_element = malloc(sizeof(struct doubly_node));
    new_element->info = new_element_value;
    struct doubly_node *next_element;

    next_element = head->next;
    if (next_element != NULL){
        next_element->previous = new_element;
    }
    new_element->next = next_element;
    new_element->previous = head;
    head->next = new_element;
    head->info++;
}

int dl_get_no_elements(struct doubly_node *head, struct doubly_node *tail){
    int no_elements ;
    struct doubly_node *iterator_left;
    struct doubly_node *iterator_right;

    if (head->next == tail){
        return 0;
    }
    iterator_left = head->next;
    iterator_right = tail->previous;
    no_elements = 0;
    while ( 1 > 0 ){
        if (iterator_left == iterator_right){
            return no_elements + 1;
        }
        if (iterator_left->next == iterator_right){
            return  no_elements + 2;
        }
        no_elements = no_elements + 2;
        iterator_left = iterator_left->next;
        iterator_right= iterator_right->previous;
    }
}

///to be implemented
void dl_push_element_end(struct doubly_node *head ,struct doubly_node *tail ,int new_element_value){
    struct doubly_node *new_element;
    struct doubly_node *last_element;
    new_element = malloc(sizeof(struct doubly_node));
    new_element->info = new_element_value;
    last_element = tail->previous;
    new_element->next = tail;
    new_element->previous = last_element;
    tail->previous = new_element;
    last_element->next = new_element;
    head->info++;
}

void dl_push_element_at_position(struct doubly_node *head, struct doubly_node *tail, int position, int new_element_value){
    int no_elements;
    int current_positon;
    struct doubly_node *iterator;
    struct doubly_node *previous_element;
    struct doubly_node *next_element;
    struct doubly_node *new_element;

    no_elements = head->info;
    assert(position >= 0);
    assert(position <= no_elements);

    if (position <= no_elements/2){
        current_positon = 0;
        iterator = head;
        while (current_positon < position){
            iterator = iterator->next;
            current_positon++;
        }
        previous_element = iterator;
        next_element = iterator->next;
    }else{
        current_positon = no_elements;
        iterator = tail;
        while (current_positon > position){
            iterator = iterator->previous;
            current_positon--;
        }
        previous_element = iterator->previous;
        next_element = iterator;
    }

    new_element = malloc(sizeof(struct doubly_node));
    new_element->info = new_element_value;
    new_element->next = next_element;
    new_element->previous = previous_element;
    next_element->previous = new_element;
    previous_element->next = new_element;
    head->info++;
}

void dl_print_list(struct doubly_node *head, struct doubly_node *tail){
    struct doubly_node *iterator = head;

    printf("\n List: ");
    while (iterator->next != tail) {
        printf("%d ", iterator->next->info);
        iterator = iterator->next;
    }
}

///to be implemented
void dl_print_list_reverse(struct doubly_node *head, struct doubly_node *tail){
    struct doubly_node *iterator;

    iterator = tail;
    printf("\n List: ");
    while (iterator->previous != head) {
        printf("%d ", iterator->previous->info);
        iterator = iterator->previous;
    }
}

int dl_pop_element_begining(struct doubly_node *head, struct doubly_node *tail){
    struct doubly_node *poped_element;
    struct doubly_node *next_element;
    int aux;

    assert(head->next != tail);

    poped_element = head->next;
    next_element = head->next->next;
    head->next = next_element;
    next_element->previous = head;
    aux = poped_element->info;
    free(poped_element);
    head->info--;

    return aux;
}

///to be implemented
int dl_pop_element_end(struct doubly_node *head, struct doubly_node *tail){
    struct doubly_node *poped_element;
    struct doubly_node *previous_element;
    int aux;

    assert(head->next != tail);

    previous_element = tail->previous->previous;
    poped_element = tail->previous;
    aux = poped_element->info;
    previous_element->next = tail;
    tail->previous = previous_element;
    free(poped_element);
    head->info--;

    return aux;
}

///to be implemented
int dl_pop_element_at_position(struct doubly_node *head, struct doubly_node *tail, int position){
    int no_elements;
    int current_positon;
    int aux;
    struct doubly_node *iterator;
    struct doubly_node *previous_element;
    struct doubly_node *next_element;
    struct doubly_node *poped_element;

    no_elements = head->info;
    assert(position >= 0);
    assert(position < no_elements);

    if (position <= no_elements/2){
        current_positon = 0;
        iterator = head;
        while (current_positon < position){
            iterator = iterator->next;
            current_positon++;
        }
        previous_element = iterator;
        poped_element = iterator->next;
        next_element = iterator->next->next;
    }else{
        current_positon = no_elements-1;
        iterator = tail;
        while (current_positon > position){
            iterator = iterator->previous;
            current_positon--;
        }
        previous_element = iterator->previous->previous;
        poped_element = iterator->previous;
        next_element = iterator;
    }

    aux = poped_element->info;
    previous_element->next = next_element;
    next_element->previous = previous_element;
    free(poped_element);
    head->info--;

    return aux;
}

void dl_empty_list(struct doubly_node *head, struct doubly_node *tail){
    struct doubly_node *iterator_left;
    struct doubly_node *iterator_right;

    assert(head->next != tail);
    iterator_left = head->next;
    iterator_right = tail->previous;

    while( 1 > 0){
        if (iterator_left == iterator_right){
            free(iterator_left);
            break;
        }
        if (iterator_left->next == iterator_right){
            free(iterator_left);
            free(iterator_right);
            break;
        }
        iterator_left = iterator_left->next;
        free(iterator_left->previous);
        iterator_right = iterator_right->previous;
        free(iterator_right->next);
    }

    head->next = tail;
    head->info = 0;
    tail->previous = head;
}

///to be implemented
void dl_selection_sort(struct doubly_node *head){
    struct doubly_node *min;
    struct doubly_node *iterator_1;
    struct doubly_node *iterator_2;

    assert(head->next != NULL);
    assert(head->next->next != NULL);

    for(iterator_1 = head->next; iterator_1->next != NULL; iterator_1 = iterator_1->next){
        min = iterator_1;
        for (iterator_2 = iterator_1->next; iterator_2 != NULL; iterator_2 = iterator_2->next) {
            if (iterator_2->info < min->info){
                min = iterator_2;
            }
        }
        if (min->info < iterator_1->info){
            dl_interchange_nodes_values(min,iterator_1);
        }
    }
}
