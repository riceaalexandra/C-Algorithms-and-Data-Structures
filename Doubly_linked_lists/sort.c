#include "vectors.h"

void insertion_sort(int vector[], int vector_length){
    int i, j, key;

    for (i = 1; i < vector_length; i++){
        key = vector[i];
        j = i - 1;
        while (j >= 0 && vector[j] > key){
            vector[j + 1] = vector[j];
            j = j - 1;
        }
        vector[j + 1] = key;
    }
}
/**
 * This function does Selection Sort
 * @param vector - vector
 * @param vector_length - length of the vector
 */
void selection_sort(int *vector, int vector_length){
    int iterator;
    int iterator_2;
    int min_position;

    for(iterator = 0; iterator < vector_length - 1; iterator++){
        min_position = iterator;
        for(iterator_2 = iterator + 1; iterator_2 < vector_length; iterator_2++){
            if ( *(vector + iterator_2) < *(vector + min_position) ) {
                min_position = iterator_2;
            }
            interchange_values(vector + iterator, vector + min_position);
        }
    }
}

void merge_sort(int *vector, int left, int right){
    int middle;

    if (left != right){
        middle = (left + right) / 2;
        merge_sort(vector, left, middle);
        merge_sort(vector, middle + 1, right);
        merge_left_right(vector, left, middle, right);
    }
}

void quick_sort(int *vector, int left, int right){
    int pivot_position = 0;

    if (left < right){
        pivot_position = partition(vector, left, right);
        quick_sort(vector, left, pivot_position);
        quick_sort(vector, pivot_position + 1, right);
    }
}
