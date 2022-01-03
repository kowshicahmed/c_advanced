#include <stdio.h>

#define PI 3.14     // Symbolic constant
// Macro example
#define PRNT(a,b)\
    printf("value 1 = %d\n", a); \
    printf("value 2 = %d\n", b);

int main()
{
    int x = 2;
    int y = 3;

    PRNT(x, y);

    return 0;
}