/* Bubble sort benchmark */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_VALUE = 999999;
const int DEFAULT_SIZE = 5000;
const int DEFAULT_TRIALS = 5;


void generate_random_numbers(int* data, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        data[i] = 1 + rand() % MAX_VALUE;
    }
}


void bubble_sort(int* data, int size)
{
    bool swapped;

    for (int i = 0; i < size; ++i) {
        swapped = false;
        for (int j = 0; j < size - 1; ++j) {
            if (data[j] > data[j+1]) {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}


int main(int argc, char* argv[])
{
    int* data;
    int size = DEFAULT_SIZE;
    int num_trials = DEFAULT_TRIALS;
    float total_time = 0.0f;

    if (argc > 1) {
        size = atoi(argv[1]);
    }

    if (argc > 2) {
        num_trials = atoi(argv[2]);
    }

    data = calloc(size, sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "Error: failed to allocate memory\n");
        return 1;
    }

    for (int i = 1; i <= num_trials; ++i) {
        generate_random_numbers(data, size);
        clock_t start_time = clock();
        bubble_sort(data, size);
        total_time += (float)(clock() - start_time) / CLOCKS_PER_SEC;
        printf("Trial %d done\n", i);
    }

    free(data);

    float average_time = total_time / num_trials;
    printf("%d numbers sorted in %.5f seconds\n", size, average_time);

    return 0;
}
