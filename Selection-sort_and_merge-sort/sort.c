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

void selection_sort(int *vector, int vector_length){
    int i, j, minim;
    for (i = 0; i < vector_length-1; i++)
    {
        minim = i;
        for (j = i + 1; j < vector_length; j++)
        {
            if(*(vector + j) < *(vector + minim))
            {
                minim = j;
            }
        }
        interchange_values(vector + i, vector + minim);
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
