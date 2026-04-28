#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char buffer[100] = "the quick brown fox jumped over the lazy dog";

    // Assume:
    // - String starts and ends with a token char
    // - Token delimiter is a single space

    char* argv[10];  // argv is an array of 10 char* pointers
    int argc = 0;    // argc max is 10

    char* p = buffer;

    // Assign first token
    argv[argc] = p;
    argc++;

    // While there are chars to process...
    while (*p != '\0') {
        // Are we currently looking at a space?
        if (*p == ' ') {
            // Replace space with a null byte, so that the pointers in
            // argv will point to strings that are individual tokens
            *p = '\0';
            // Is there room to store another token?
            if (argc < 10) {
                // Since p was pointing to a space, p + 1 will be first
                // char of the new token
                argv[argc] = p + 1;
                argc++;
            }
        }
        p++;
    }

    // Check argc & argv
    printf("argc = %d\n", argc);
    for (int k = 0; k < argc; ++k) {
        printf("argv[%d] = %s\n", k, argv[k]);
    }

    return 0;
}
