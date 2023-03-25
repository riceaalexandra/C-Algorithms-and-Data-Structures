#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

int is_prime(int n)
{
    if(n <= 1)
    {
        return 0;
    }
    for(int i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int sum_of_digits(int n)
{
    int sum = 0, u;
    while(n != 0)
    {
        u = n % 10;
        sum = u + sum;
        n = n / 10;
    }
    return sum;
}
