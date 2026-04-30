#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OPS 3

int add(int, int);
int subtract(int, int);
int multiply(int, int);
bool not_integer(const char*);
int operation_index(const char*);

int main(int argc, char* argv[])
{
    int (*operations[NUM_OPS])(int, int) = { add, subtract, multiply };

    // Check command line

    if (argc != 4) {
        fprintf(stderr, "Usage: ./calc <num1> <operator> <num2>\n\n");
        fprintf(stderr, "num1 and num2 must both be integers\n");
        fprintf(stderr, "operator must be +, - or x\n");
        return 1;
    }

    if (not_integer(argv[1]) || not_integer(argv[3])) {
        fprintf(stderr, "Error: num1 and num2 must both be integers\n");
        return 2;
    }

    int i = operation_index(argv[2]);
    if (i == -1) {
        fprintf(stderr, "Error: operator must be +, - or x!\n");
        return 3;
    }

    // Perform requested operation

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);

    int result = operations[i](num1, num2);
    printf("%d\n", result);

    return 0;
}

bool not_integer(const char* arg)
{
    int num_chars = strlen(arg);

    for (int i = 0; i < num_chars; ++i) {
        if (i == 0 && (arg[i] == '-' || arg[i] == '+')) {
            // first char allowed to be a + or -
            continue;
        }
        if (! isdigit(arg[i])) {
            return true;
        }
    }

    return false;
}

int operation_index(const char* arg)
{
    if (strlen(arg) > 1) {
        return -1;
    }

    char symbols[NUM_OPS] = { '+', '-', 'x' };

    for (int i = 0; i < NUM_OPS; ++i) {
        if (arg[0] == symbols[i]) {
            return i;
        }
    }

    return -1;
}

int add(int i, int j)
{
    return i + j;
}

int subtract(int i, int j)
{
    return i - j;
}

int multiply(int i, int j)
{
    return i * j;
}
