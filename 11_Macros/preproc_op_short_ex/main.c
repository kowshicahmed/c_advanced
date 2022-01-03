#include <stdio.h>

// Continuation operator
#define MIN(x, y) \
((x) < (y) ? (x):(y))

// Defined operator
#define DEBUG
#define WINDOWS
#if defined (WINDOWS) || defined (WINDOWSNT)
    #define BOOT_DRIVE "C:/"
#else
    #define BOOT_DRIVE "D:/"
#endif

// The pound # is for string replacement
#define STR(x) #x   // str(testing) = "testing"
#define HELLO(y) printf("Hello, " #y "\n")
#define printint(var) printf(#var "=%i\n", var)

// The double pound ## is for concatenation
#define TOKENCONCAT(x, y) x##y  // TOKENCONCAT(O,K) is replaced by OK
#define MAKE_FUNCTION(name) int my_##name(int foo) \ 
        {printf("My func name is "#name " passed: %d\n", foo);}

MAKE_FUNCTION(bar)  // create a function called my_bar()

#define EAT(what) puts("I am eating " #what " today\n")

int main(void)
{
    // Continuation example
    int i = MIN(4,5);
    printf("The min number is: %d\n", i);

    // Defined examples
    #if defined (DEBUG)    // Same as ifdef DEBUG
        printf("Debug is enabled\n");
    #endif

    printf("Here is the boot drive path: %s\n", BOOT_DRIVE);

    // # operator example
    printf(STR(Programming is C is fun. \n));
    HELLO(John);    // printf("Hello, ""John""\n") => printf("Hello, John\n")
    
    int count = 5;
    printint(count); // printf("count""=%i\n", count)

    // ## operator examples
    int xy = 10;
    printf("%d\n", TOKENCONCAT(x,y));     //printf("%d", xy)
    
    my_bar(5);

    EAT(fruit);     // puts("I am eating " "fruit" " today")
    return 0;
}