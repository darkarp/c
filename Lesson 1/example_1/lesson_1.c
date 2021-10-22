#include <stdio.h>
float triangle_area(float base, float height)
{
    return (base * height) / 2;
}

float media(float num1, float num2)
{
    return (num1 + num2) / 2;
}

float mul(float num1, float num2)
{
    return num1 * num2;
}

void print_stats(float num1, float num2)
{
    printf("Mean: %.2f\n", media(num1, num2));
    printf("Multiplication: %.2f\n", mul(num1, num2));
}

void exercise_1()
{
    float num1, num2;
    printf("First number: ");
    scanf("%f", &num1);
    printf("Second number: ");
    scanf("%f", &num2);
    print_stats(num1, num2);
}
void exercise_2()
{
    float base, height;
    printf("Base of triangle: ");
    scanf("%f", &base);
    printf("Height of triangle: ");
    scanf("%f", &height);
    printf("The area is: %.2f\n", triangle_area(base, height));
}

int main(int argc, char *argv[])
{
    exercise_1();
    exercise_2();
    return 0;
}