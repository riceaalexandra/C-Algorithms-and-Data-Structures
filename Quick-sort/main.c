#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"
#include "sort.h"
#include "utils.h"

int main(){
    /*int *vector_1;
    int vector_1_length;
    int min_position;

    int *vector_2;
    int vector_2_length;

    int *vector3;
    int vector_3_length;

    int vector_4[] = {2, 6, 19, 17};
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
    merge_sort(vector_5, 0, vector_5_length - 1);
    write_vector(&vector_5[0], 0, vector_5_length);

    printf("\n=========== Merging sorted arrays ===========");
    merged_vector = merge_vectors(vector_4, vector_4_length, vector_5, vector_5_length);
    printf("\nThe result of merging vectors is:");
    write_vector(merged_vector, 0, vector_4_length + vector_5_length);

    printf("\n=========== Binary Search ===========\n");
    int element_to_find = 13;
    int result = binary_search(vector_5, 0, vector_5_length - 1, element_to_find);

    if (result == -1){
        printf("\n The element was not found!");
    }else{
        printf("The element was found at index %d", result);
    }*/

    FILE* file = fopen ("data\\data.in", "r");
    FILE* file_out = fopen ("data\\data.out", "w");

    if(!file || !file_out){
        return -1;
    }
    int *vector, vector_length;
    fscanf(file,"%d",&vector_length);
    vector=(int*)malloc(vector_length*sizeof(int));
    for(int i = 0; i < vector_length; i++){
        fscanf(file, "%d", &vector[i]);
    }
    fprintf(file_out,"\n=========== Quick sort ===========");
    quick_sort(vector, 0, vector_length-1);
    fprintf(file_out,"\nThe sorted values, quick sort method, of vector 7 is:");
    for(int i = 0; i < vector_length; i++){
        fprintf(file_out, " %d ", vector[i]);
    }
    free(vector);
    fclose (file);
    fclose (file_out);

    return 0;
}
