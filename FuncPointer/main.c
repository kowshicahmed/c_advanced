#include <stdio.h>
#include <stdlib.h>

//typedef int (*pFunction) (int);
int (*pFunction) (int);
int displayNumber (int a);

int somedisplay ();

int main()
{
    pFunction = displayNumber;
    //pFunction ptr1 = displayNumber;

    //ptr1 (6);
    pFunction (5);

    int (*func_ptr) ();
    func_ptr = somedisplay;
    printf("Address of func somedisplay %p\n", func_ptr);
    func_ptr ();
    return 0;
}

int displayNumber (int a)

{
    printf("The number is: %d\n", a);

    return 0;
}

int somedisplay()
{
    printf("Displaying some text\n");
    return 0;
}
