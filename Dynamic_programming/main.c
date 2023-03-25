#include <stdio.h>
#include <stdlib.h>
#include "knapsack.h"

int main(){
    struct object *objects;
    int no_objects;
    int knapsack_capacity;

    printf("Give the size of the knapsack: ");
    scanf("%d",&knapsack_capacity);

    printf("Give the number of objects: ");
    scanf("%d",&no_objects);

    objects = malloc(no_objects * sizeof(struct object));
    generate_objects(objects, no_objects);

    printf("\n=== Random objects ===");
    print_objects(objects, no_objects);

    dynamic_programming_knapsack_discrete(objects, no_objects, knapsack_capacity);

    return 0;
}
