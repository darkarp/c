#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "auxiliary.h"

float mean(struct FLOAT_VEC data)
{
    float counter = 0;
    int size = data.len;
    for (int i = 0; i < size; i++)
    {
        counter += data.arr[i];
    }
    return (counter / size);
}

float mul(struct FLOAT_VEC data)
{
    float counter = 1;
    int size = data.len;
    for (int i = 0; i < size; i++)
    {
        counter *= data.arr[i];
    }
    return counter;
}

float area_triangle(struct FLOAT_VEC data)
{
    return (data.arr[0] * data.arr[1]) / 2;
}