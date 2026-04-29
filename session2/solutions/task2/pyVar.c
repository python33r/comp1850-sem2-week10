#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data definitions (part a)

#define MAX_LENGTH 99

typedef enum _type {
    INTEGER, REAL, STRING
} Type;

typedef union _value {
    int ival;
    float fval;
    char sval[MAX_LENGTH + 1];
} Value;

typedef struct _variable {
    Type type;
    Value value;
} Variable;

// Functions (part b)

void print_value(Variable var)
{
    switch (var.type) {
        case INTEGER:
            printf("%d\n", var.value.ival);
            break;
        case REAL:
            printf("%f\n", var.value.fval);
            break;
        case STRING:
            printf("\"%s\"\n", var.value.sval);
            break;
        default:
            fprintf(stderr, "Error: unknown type in print()\n");
            exit(1);
    }
}

Variable assign(Type type, Value val)
{
    Variable var;
    var.type = type;
    switch (var.type) {
        case INTEGER:
            var.value.ival = val.ival;
            break;
        case REAL:
            var.value.fval = val.fval;
            break;
        case STRING:
            strncpy(var.value.sval, val.sval, MAX_LENGTH);
            break;
        default:
            fprintf(stderr, "Error: unknown type in assign()\n");
            exit(2);
    }
    return var;
}

Variable add(Variable var1, Variable var2)
{
    if (var1.type != var2.type) {
        fprintf(stderr, "Error: incompatible types for add()\n");
        exit(3);
    }

    Variable sum;
    sum.type = var1.type;
    int var1_size, var2_size;

    switch (sum.type) {
        case INTEGER:
            sum.value.ival = var1.value.ival + var2.value.ival;
            break;
        case REAL:
            sum.value.fval = var1.value.fval + var2.value.fval;
            break;
        case STRING:
            var1_size = strlen(var1.value.sval);
            var2_size = strlen(var2.value.sval);
            if (var1_size + var2_size > MAX_LENGTH) {
                fprintf(stderr, "Error: strings too long in add()\n");
                exit(4);
            }
            strncpy(sum.value.sval, var1.value.sval, var1_size);
            strncat(sum.value.sval, var2.value.sval, var2_size);
            break;
        default:
            fprintf(stderr, "Error: unknown type in add()\n");
            exit(5);
    }

    return sum;
}

// Demo program

int main(void)
{
    // Define variables of different types

    Variable var1 = { .type=INTEGER, .value.ival=2 };
    Variable var2 = { .type=REAL, .value.fval=3.141593 };
    Variable var3 = { .type=STRING, .value.sval="World" };

    printf("Type of var1 = %d, value = ", var1.type);
    print_value(var1);

    printf("Type of var2 = %d, value = ", var2.type);
    print_value(var2);

    printf("Type of var3 = %d, value = ", var3.type);
    print_value(var3);

    // Change type & value of var1

    printf("Reassigning var1...\n");
    var1 = assign(STRING, (Value){ .sval="Hello " });

    printf("Type of var1 = %d, value = ", var1.type);
    print_value(var1);

    // Add two of the variables

    Variable result = add(var1, var3);

    printf("Type of var1 + var3 = %d, value = ", result.type);
    print_value(result);

    return 0;
}
