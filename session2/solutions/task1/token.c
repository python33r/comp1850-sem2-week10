#include <ctype.h>
#include <stdio.h>
#include <string.h>

void display(const char* buffer, int size)
{
    for (int i = 0; i < size; ++i) {
        char ch = buffer[i];
        printf("%0x", ch);
        if (isprint(ch)) printf(" %c", ch);
        printf("\n");
    }
}

int main(void)
{
    char buffer[50] = "the quick brown fox jumped over the lazy dog";

    #ifdef VERBOSE
    printf("Buffer before tokenisation:\n");
    display(buffer, sizeof buffer);
    printf("\n");
    #endif

    char* token = strtok(buffer, " ");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    #ifdef VERBOSE
    printf("\nBuffer after tokenisation:\n");
    display(buffer, sizeof buffer);
    #endif

    return 0;
}
