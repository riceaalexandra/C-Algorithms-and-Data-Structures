#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"
#include "sort.h"



int main(){
    int *vector_1;
    int vector_1_length;
    int min_position;

    int *vector_2;
    int vector_2_length;

    int *vector3;
    int vector_3_length;

    int vector_4[] = {3, 1, 19, 17};
    int vector_4_length = sizeof(vector_4) / sizeof(vector_4[0]);

    int vector_5[] = {13, 5, 6, 8, 11, 10};
    int vector_5_length = sizeof(vector_5) / sizeof(vector_5[0]);

    int *merged_vector;

    printf("\n=========== Insertion Sort ===========");
    printf("\nThe sorted values, insertion sort method, of vector 4 is:");
    insertion_sort(vector_4, vector_4_length);
    printf("\n=========== Selection Sort ===========");
    write_vector(&vector_4[0], 0, vector_4_length);
    printf("\nThe sorted values, insertion sort method, of vector 5 is:");
    selection_sort(vector_5, vector_5_length);
    write_vector(&vector_5[0], 0, vector_5_length);

    printf("\n=========== Merging sorted arrays ===========");
    merged_vector = merge_vectors(vector_4, vector_4_length, vector_5, vector_5_length);
    printf("\nThe result of merging vectors is:");
    write_vector(merged_vector, 0, vector_4_length + vector_5_length);

    printf("\n=========== Binary Search ===========\n");
    int element_to_find = 1;
    int result = binary_search(vector_5, 0, vector_5_length - 1, element_to_find);
    if (result == -1){
        printf("\n The element was not found!");
    }else{
        printf("The element was found at index %d", result);
    }
    int *vector_7;
    int vector_7_length;
    printf("\nInput the number of elements: ");
    scanf("%d",&vector_7_length);
    vector_7=(int*)malloc(vector_7_length*sizeof(int));
    read_vector(vector_7,vector_7_length);

    printf("\n=========== Merge Sort ===========");
    write_vector(&vector_7[0], 0, vector_7_length);
    merge_sort(vector_7,0,vector_7_length-1);
    printf("\nThe sorted values, merge sort method, of vector 7 is:");
    write_vector(&vector_7[0], 0, vector_7_length);

    free(vector_7);

    return 0;
}
