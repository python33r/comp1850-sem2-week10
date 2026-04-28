/*
   Displays the number of clock ticks per second on this system.

   If you use clock() to count the number of ticks required to execute a
   piece of code, that count divided by the number displayed by this program
   will be the CPU time to execute that code, in seconds.
*/

#include <stdio.h>
#include <time.h>

int main(void)
{
    printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);
    return 0;
}
