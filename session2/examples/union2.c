// Comparison of structs and unions

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

    printf("MyStruct:\n");
    printf("Size = %lu bytes\n", sizeof s);
    printf("Address of k: %p\n", &(s.k));
    printf("Address of f: %p\n", &(s.f));
    printf("Address of s: %p\n", &(s.s));

    printf("\nMyUnion:\n");
    printf("Size = %lu bytes\n", sizeof u);
    printf("Address of k: %p\n", &(u.k));
    printf("Address of f: %p\n", &(u.f));
    printf("Address of s: %p\n", &(u.s));

    return 0;
}
