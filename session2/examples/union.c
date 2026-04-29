// Demo of size difference between structs and unions

#include <stdio.h>

typedef struct _mystruct {
    int k;
    float f;
    char* s;
} MyStruct;

typedef union _myunion {
    int k;
    float f;
    char* s;
} MyUnion;

int main(void)
{
    MyStruct s;
    MyUnion u;

    printf("Size of MyStruct = %lu\n", sizeof s);
    printf("Size of MyUnion = %lu\n", sizeof u);

    return 0;
}
