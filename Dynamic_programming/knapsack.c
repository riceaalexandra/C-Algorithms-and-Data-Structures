#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "knapsack.h"

void generate_objects(struct object *objects, int no_objects){
    int iterator;
    time_t t;

    srand((unsigned) time(&t));
    for(iterator = 1; iterator <= no_objects; iterator++){
        objects[iterator].id = iterator;
        objects[iterator].size = rand() % 10 + 1;
        objects[iterator].value = rand() % 10 + 1;
    }
}

void print_objects(struct object *objects, int no_objects){
    int iterator;

    printf("\n Objects:");
    for (iterator = 1; iterator <= no_objects ; iterator++) {
        printf("\n id: %d size: %d value: %d",objects[iterator].id, objects[iterator].size, objects[iterator].value);
    }
}

void set_matrix_value(struct a_matrix matrix, int row_index, int column_index, int element_value){
    int position;
    if (column_index == 0){
        printf("da");
    }
    position = row_index * matrix.no_cols + column_index;
    *(matrix.matrix + position) = element_value;
}


int get_matrix_value(struct a_matrix matrix, int row_index, int column_index){
    int position;

    position = row_index * matrix.no_cols + column_index;
    return *(matrix.matrix + position);
}

void print_matrix(struct a_matrix matrix){
    int iterator_rows;
    int iterator_columns;

    printf("\n === Matrix === \n");
    for(iterator_rows = 0; iterator_rows < matrix.no_rows; iterator_rows++){
        for(iterator_columns = 0; iterator_columns < matrix.no_cols; iterator_columns++){
            printf("%d ",matrix.matrix[iterator_rows * matrix.no_cols + iterator_columns]);
        }
        printf("\n");
    }
}

int get_max(int val1, int val2){
    if (val1 > val2){
        return val1;
    }else{
        return val2;
    }
}

void dynamic_programming_knapsack_discrete(struct object *objects, int no_objects, int knapsack_capacity){
    int iterator=0;
    int knapsack_current_capacity;
    float knapsack_value=0;
    float fractional_part;
    knapsack_current_capacity=knapsack_capacity;
    printf("=====\n");
    while((knapsack_current_capacity>0)&&(iterator<no_objects)){
        if(objects[iterator].size<=knapsack_current_capacity){
            knapsack_value+=objects[iterator].value;
            knapsack_current_capacity-=objects[iterator].size;
            printf("\n id: %d size: %d value: %d value per unit: %f",objects[iterator].id, objects[iterator].size, objects[iterator].value, value_per_unit(objects[iterator]));
        }
        else{
            fractional_part=objects[iterator].size-knapsack_current_capacity;

            knapsack_value+=(fractional_part*100)/knapsack_current_capacity;
            knapsack_current_capacity-=fractional_part;
           printf("\n id: %d size: %d value: %d value per unit: %f",objects[iterator].id, objects[iterator].size, objects[iterator].value, value_per_unit(objects[iterator]));
        }
        iterator++;
    }

    printf("\nValue in the knapsack: %f", knapsack_value);
}
