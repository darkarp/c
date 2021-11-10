#include<stdio.h>

int print_formatting() {
    // Just an example on print formats.
    printf("%d, %5d, %7.2f, %g, %e", 10, 12, 14.5, 44.3, 8);
    return 0;
}

float sum(float num1, float num2) {
    // Returns the sum of two floats
    return num1+num2;
}

void sum_numbers() {
    // This is the second example, asking for two numbers and outputing their sum.
    float num1, num2;
    printf("Type two numbers to add (comma separated): ");
    scanf("%f,%f", &num1, &num2); // Reads two inputs
    printf("The sum is: %.2f", sum(num1, num2));
}

/* Function Definition!
    RETURN_TYPE name(ARG_TYPE arg1, ARG_TYPE arg2, etc..) {
        return RETUR_VALUE
    }
    RETURN_TYPE is the type of the return. It can be void if nothing is returned.
    Arguments come after their types inside the parenthesis. You don't need to have arguments.

    Look at the function main (it accepts 2 arguments).
    The function sum also accepts two arguments.
    The function sum_numbers doesn't take any parameters and doesn't have a return type.

*/



int main(int argc, char const *argv[])
{
    sum_numbers();
    return 0;
}

