#include <stdio.h>
#include <stdlib.h>

// The macro below will do the same task as the functions
// #define DeclareSort(prefix, type) \
// static int \
// _DeclareSort_ ## prefix ## _Compare(const void *a, const void *b) \
// { \
//     const type *aa; const type *bb; \
//     aa = a; bb = b; \
//     if(aa < bb) return -1; \
//     else if (bb < aa) return 1; \
//     else return 0; \
// }\
// \
// void \
// prefix ## _sort(type *a, int n) \
// { \
//     qsort(a, sizeof(type), n, _DeclareSort_ ## prefix ## _Compare); \
// }

// /* note: must appear outside of any function, and has to trailing */
// DeclareSort(int, int)

// Function Definitions
static int _DeclareSort_int_Compare(const void *a, const void *b);
void int_sort(int *a, int n);

int main(void)
{
    int x = 5;
    int *a = &x;
    int n = 6;
    int_sort(a, n);
}

/* How the macro would look like after expansion */
static int _DeclareSort_int_Compare(const void *a, const void *b)
{
    const int *aa; const int *bb;
    aa = a; bb = b;
    if(aa < bb) return -1;
    else if (bb < aa) return 1;
    else return 0;
}

void int_sort(int *a, int n)
{
    qsort(a, sizeof(int), n, _DeclareSort_int_Compare);
}