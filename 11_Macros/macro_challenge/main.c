#include <stdio.h>

// Challenge-2 macro function sum
#define SUM(x, y) printf("The sum of " #x " and " #y " is: %d\n", x+y)

// Challenge-3 macro function square and cube
#define SQUARE(x) (x * x)
#define CUBE(x) (x * x * x)
#define SQANDCUBE(x) printf("SQUARE("#x") = %d\nCUBE("#x") = %d\n", SQUARE(x), CUBE(x))

// Challenge-4 is_upper or is_lower
#define IS_UPPER(x) (x >= 'A' && x <= 'Z')
#define IS_LOWER(x) (x >= 'a' && x <= 'z')

// Additional macros
#define IS_ALPHABET(x) (IS_LOWER(x) || IS_UPPER(x))

#define IS_VOWEL_LOWER(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
#define IS_VOWEL_UPPER(x) (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
#define IS_VOWEL(x) (IS_VOWEL_LOWER(x) || IS_VOWEL_UPPER(x))

#define IS_DIGIT(x) (x >= '0' && x <= '9')
#define IS_ALPHANUMERIC(x) (IS_ALPHABET(x) || IS_DIGIT(x))

#define IS_WHITE_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || x == '\n' || x == '\0')

#define IS_SPECIAL_CHARACTERS(x) (x >= 32 && x <= 127 && !IS_ALPHABET(x) && !IS_DIGIT(x) && !IS_WHITE_SPACE(x))

int main(void)
{
    // Challenge-1 predefined macros
    printf("The line number is %d\n", __LINE__);
    printf("The filename is %s\n", __FILE__);
    printf("Today's date is %s\n", __DATE__);
    printf("The time is %s\n", __TIME__);
    printf("__STDC__ = %d\n", __STDC__);

    // Challenge-2 macro function sum
    SUM(3,4);

    // Challenge-3
    SQANDCUBE(10);

    // Challenge-4
    if (IS_UPPER('A'))
        printf("A is uppercase\n");

    return 0;
}