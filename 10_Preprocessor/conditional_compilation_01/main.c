#include <stdio.h>

#define JUST_CHECKING   // if this is not defined, only grand total will be printed
#define LIMIT 4

#define MYDEF 4
#define MYOTHERDEF 2

int main(void)
{
    // ********* #ifdef example *************************
    int i = 0;
    int total = 0;

    for (i = 1; i <= LIMIT; i++)
    {
        total += 2*i*i + 1;

        #ifdef JUST_CHECKING
            printf("i=%d, running total = %d\n", i, total);
        #endif
    }

    printf("Grand total = %d\n", total);

    // ********* #if example *************************
    #if MYDEF == 4 && MYOTHERDEF == 2
        printf("Hello");
    #endif

    return 0;
}