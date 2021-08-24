#include <stdio.h>
#include <stdlib.h>
//array implementation of stack
#define MAXSIZE 5

struct stack {
    int stk[MAXSIZE];
    int top;
};

typedef struct stack STACK;

STACK s;

void push ();
int pop();
void display ();

int main()
{
    push ();
    push ();
    push ();
    display ();

    pop ();
    display ();
    return 0;
}

void push ()
{
    int num = 0;
    if (s.top == (MAXSIZE-1))
    {
        printf ("Stack is full \n");
        return;
    }

    else
    {
        printf("enter the element to be pushed \n");
        scanf("%d", &num);
        s.top = s.top +1;
        s.stk[s.top] = num;
    }
}

int pop ()
{
    int num = 0;

    if (s.top == -1)
    {
        printf("stack is empty \n");
        return (s.top);
    }

    else
    {
        num = s.stk[s.top];
        printf("poped element is = %d\n", s.stk[s.top]);
        s.top = s.top -1;
    }
    return (num);
}

void display ()
{
    int i = 0;
    if (s.top == -1)
    {
        printf("\nStack is empty\n");
    }

    else
    {
        for (i = s.top; i >0; i--)
        {
            printf("data = %d\n", s.stk[i]);
        }
    }
}
