#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"
#include "sort.h"
#include "utils.h"


int main()
{
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


    //TODO: Read values from input file, call is_prime and sum_of_digits here in order to obtain all the resulting numbers,
    //and write the result to the output file.
    int a,b,i;
    FILE *in_file;
    FILE *out_file;
    in_file = fopen("C:\\Users\\Alexandra\\Desktop\\code_skeleton_codeblocks_lab3\\data\\data.in", "r");
    out_file = fopen("C:\\Users\\Alexandra\\Desktop\\code_skeleton_codeblocks_lab3\\data\\data.out", "w");
    if(in_file == NULL || out_file == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }
    fscanf(in_file, "%d %d", &a, &b);
    for(i = a; i <= b; i++)
    {
        if( is_prime(i) == 1 && is_prime(sum_of_digits(i)) == 1 )
        {
            fprintf(out_file, "%d ", i);
        }
    }
    fclose(in_file);
    fclose(out_file);
    return 0;
}
