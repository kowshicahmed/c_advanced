#include <stdio.h>
#include <stdlib.h>

#include "other.h"

typedef int my_int;

void (*myfuncpointer) ();
void anotherfunc (void (*a) ());
int main()
{
    extern int number;

    my_int number2 = 8;
    printf("%d\n", getfavoritenumber());
    printf("%d\n", number);
    printf("%d\n", number2);


    return 0;
}
