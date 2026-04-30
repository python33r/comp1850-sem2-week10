#include <stdio.h>
#include <stdlib.h>

/*
 * structure definition
 */
typedef struct _class {
    
    // state
    int op1, op2;
    char op;
    int result;

    // behaviour
    void (*print)(struct _class*);
    void (*parser)(struct _class*, int, char, int);
    void (*calculate)(struct _class*);

} Class;

/*
 * function headers
 */
Class* init(void);
void print(Class*);
void parser(Class*, int, char, int);
void calculate(Class*);

/*
 * initialise the "class"
 */
Class* init(void)
{
    Class *new = malloc(sizeof(Class));

    new->op1 = 0;
    new->op2 = 0;
    new->op = ' ';
    new->result = 0;

    new->print = print;
    new->parser = parser;
    new->calculate = calculate;

    return new;
}

/*
 * parse
 */
void parser(Class* calc, int k1, char op, int k2)
{
    calc->op1 = k1;
    calc->op2 = k2;
    calc->op = op;
}

/*
 * print class data
 */
void print(Class* calc)
{
    printf(" %d %c %d = %d\n", calc->op1, calc->op, calc->op2, calc->result);
}

/*
 * calculate result
 */
void calculate(Class* calc) {
    switch(calc->op) {
        case '+':
            calc->result = calc->op1 + calc->op2;
            break;
        case '-':
            calc->result = calc->op1 - calc->op2;
            break;
        case '*':
            calc->result = calc->op1 * calc->op2;
            break;
        default:
            printf("Error: Unknown operation\n");
            break;
    }
}

/* 
 * main: creating and testing 
 */
int main(int argc, char* argv[])
{
    Class* calculator = init();

    calculator->print(calculator);

    // use the parser function to set the internal data 
    calculator->parser(calculator, 1, '+', 3);
    calculator->print(calculator);

    // call the calculator function to compute the result 
    // print the result using the class print function

    calculator->calculate(calculator);
    calculator->print(calculator);

    free(calculator);

    return 0;
}
