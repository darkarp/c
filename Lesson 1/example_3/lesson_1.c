#include "math.h"

void print_stats(struct FLOAT_VEC data)
{
    float avg = mean(data);
    printf("The average is: %.3f\n", avg);
    printf("Multiplied, the result is: %.3f\n", mul(data));
}

void exercise_1()
{
    struct CHAR_VEC input = input_numbers("Type numbers separated by comma");
    struct FLOAT_VEC numbers = char_to_float(input);
    print_stats(numbers);
}
void exercise_2()
{
    struct CHAR_VEC input = input_numbers("Type base and height separated by comma");
    struct FLOAT_VEC numbers = char_to_float(input);
    printf("The area is: %.3f\n", area_triangle(numbers));
}

int main(int argc, char *argv[])
{
    exercise_1();
    exercise_2();
    return 0;
}