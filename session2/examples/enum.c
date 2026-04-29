#include <stdio.h>

typedef enum _day {
    Monday = 1, Tuesday, Wednesday, Thursday,
    Friday, Saturday, Sunday
} Day;

int main(void)
{
    Day day = Monday;
    printf("%d\n", day);

    day = 2;
    printf("%d\n", day);
    if (day == Tuesday) {
        printf("This is a Tuesday\n");
    }

    day = 10;   // makes no sense but compiler allows this!
    printf("%d\n", day);

    return 0;
}
