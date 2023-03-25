#include "homework.h"

int maximum(int *array, int left, int right)
{
    int max_1, max_2, middle;
    if (left == right){
        return array[left];
    }
    else
    {
        middle = (left + right) / 2;
        max_1 = maximum(array, left, middle);
        max_2 = maximum(array, middle + 1, right);
        if (max_1 > max_2){
            return max_1;
        }
        else{
            return max_2;
        }
    }
}

 int minimum(int *array, int left, int right)
{
    int min_1, min_2, middle;
    if (left == right){
        return array[left];
    }
    else {
        middle = (left + right) / 2;
        min_1 = minimum(array, left, middle);
        min_2 = minimum(array, middle + 1, right);
        if (min_1 < min_2){
            return min_1;
        }
        else {
            return min_2;
        }
    }
}
