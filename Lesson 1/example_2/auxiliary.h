#include <stdio.h>
#include "math.h"
float read_input(char *label)
{
    float number;
    printf("%s: ", label);
    scanf("%f", &number);
    return number;
}

void print_stats(float num1, float num2)
{
    printf("Mean: %.2f\n", media(num1, num2));
    printf("Multiplication: %.2f\n", mul(num1, num2));
}