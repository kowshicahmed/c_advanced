#include <stdio.h>

struct command
{
    char *name;
    void (*function) (void);
};

// The string constant can be created with stringizing 
// The function name can be created by concatenating NAME with _command
#define COMMAND(NAME) {#NAME, NAME##_command}

void quit_command(void)
{
    printf("Quitting\n");
}

void help_command(void)
{
    printf("Helping\n");
}

int main(void)
{
    struct command commands[] = {COMMAND(quit), COMMAND(help)};
    commands[1].function();
    return 0;
}