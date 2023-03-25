//
// Created by Ionut on 4/21/2019.
//

#ifndef CODE_SKELETON_LAB10_KNAPSACK_H
#define CODE_SKELETON_LAB10_KNAPSACK_H

struct object{
    int id;
    int size;
    int value;
};

struct a_matrix{
    int no_rows;
    int no_cols;
    int *matrix;
};

void generate_objects(struct object *objects, int no_objects);
void print_objects(struct object *objects, int no_objects);
void set_matrix_value(struct a_matrix matrix, int row_index, int column_index, int element_value);
void dynamic_programming_knapsack_discrete(struct object *objects, int no_objects, int knapsack_capacity);
void print_matrix(struct a_matrix matrix);
int get_matrix_value(struct a_matrix matrix, int row_index, int column_index);
int get_max(int val1, int val2);

#endif //CODE_SKELETON_LAB10_KNAPSACK_H
