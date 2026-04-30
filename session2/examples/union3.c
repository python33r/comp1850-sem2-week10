#include <stdio.h>

typedef union _myunion {
    int k;
    float f;
    char* s;
} MyUnion;

int main(void)
{
    MyUnion u;

    u.f = 3.1415927;

    printf("Value of f = %f\n", u.f);
    printf("Value of k = %d\n", u.k);

    return 0;
}
