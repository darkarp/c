#include <stdio.h>
#include "auxiliary.h"

void exercise_1()
{
    float num1 = read_input("First number");
    float num2 = read_input("Second number");
    print_stats(num1, num2);
}
void exercise_2()
{
    float base = read_input("Base of triangle");
    float height = read_input("Height of triangle");
    printf("The area is: %.2f\n", triangle_area(base, height));
}

int main(int argc, char *argv[])
{
    exercise_1();
    exercise_2();
    return 0;
}