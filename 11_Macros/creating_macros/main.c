#include <stdio.h>

#define PI 3.14
#define CIRCLE_AREA(x) ((PI) * (x) * (x))

// Variadic macro
#define Warning(...) fprintf(stderr, __VA_ARGS__)

// Multiple expressions
#define FOO BAR
#define BAR (12)
#define MISC(x) (puts("incrementing:", (x)++))  // This does not work
#define MAX(a,b) ((a) > (b) ? (a) : (b))

// Loops
#define UpTo(i, n) for (int i = 0; (i) < (n); (i)++)


int main()
{
    int area = CIRCLE_AREA(4);
    printf("Area is %d\n", area);

    Warning("%s: this program is here\n", "Jason");
    printf("%d\n", MAX(3,4));
    UpTo(i, 10)
    {
        printf("Hi\n");
    }

    return 0;
}