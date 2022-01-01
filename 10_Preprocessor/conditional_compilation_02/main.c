#include <stdio.h>

#define US 0
#define UK 1
#define France 2
#define Germany 3
#define Country France

int main()
{
    #if Country == US || Country == UK
        #define Greeting "Hello."
    #elif Country == France
        #define Greeting "Bonjour."
    #elif Country == Germany
        #define Greeting "Guten Tag"
    #endif
    printf("Greeting is: %s", Greeting);
    
    return 0;
}