#include <stdio.h>

//#pragma GCC poison printf       // can't use printf

#pragma GCC warning "hello"
#pragma GCC error "what"
#pragma message "ok"

int main()
{
    printf("Hello");        // error

    return 0;
}