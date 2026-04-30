#include <stdio.h>
#include <stdlib.h>

int add(int, int);

// main: creating and testing function pointers

int main(void)
{
    int (*operation)(int, int);  // pointer for function with 2 integer arguments, returning an int

    int num1 = 2, num2 = 3;      // data for arguments

    // compute the sum using the function - print out the operands and answer

    int sum = add(num1, num2);
    printf("Result = %d\n", sum);

    // compute the sum using the pointer - print out the operands and answer

    operation = &add;
    sum = operation(num1, num2);
    printf("Result = %d\n", sum);

    return 0;
}

// integer operation implementations

int add(int i, int j)
{
    return i + j;
}
