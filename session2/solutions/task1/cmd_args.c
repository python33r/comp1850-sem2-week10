#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char buffer[100] = "The quick brown fox jumped over the lazy dog";

    // Assume:
    // - String starts and ends with a token char
    // - Token delimiter is a single space

    char **argv;   // dynamic array of char*
    int argc = 1;  // must be at least one token (per assumptions)

    // 1. First pass - count argc
    // don't assign argv just locate spaces and count tokens

    char* p = buffer;

    // While there are chars to process...
    while (*p != '\0') {
        // If we are looking at a space, we know there must be
        // another token (per assumptions)
        if (*p == ' ') {
            ++argc;
        }
        ++p;
    }

    // 2. Dynamically allocate argv array

    argv = calloc(argc, sizeof(char*));
    if (argv == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        return 1;
    }

    // 3. Second pass - allocate and fill argv

    p = argv[0] = buffer;
    int i = 1;  // index for next arg

    // While there are chars to process...
    while (*p != '\0') {
        // Are we currently looking at a space?
        if (*p == ' ') {
            // Replace space with a null byte, so that the pointers in
            // argv will point to strings that are individual tokens
            *p = '\0';
            // Since p was pointing to a space, p + 1 will be first
            // char of the new token
            argv[i] = p + 1;
            ++i;
        }
        ++p;
    }

    // Check output for argc, argv

    printf("argc = %d\n", argc);
    for (i = 0; i < argc; ++i) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    // Free argv dynamic memory

    free(argv);

    return 0;
}
