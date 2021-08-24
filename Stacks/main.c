#include <stdio.h>
#include <stdlib.h>


//linked list implementation of stack
struct node {
    int data;
    struct node *link;

}node;

struct node *top = NULL;

void push (int data)
{
    struct node *temp = malloc(sizeof(node));
    if (temp !=NULL)
    {
        temp->data = data;
        temp->link = top;
        top = temp;
    }
}

int is_empty()
{
    return top == NULL;
}

void pop ()
{
    struct node *temp = malloc(sizeof(node));
    if (temp!=NULL)
    {
        temp = top;
        top = top->link;
        temp->link  = NULL;
        free(temp);
    }
}

void display ()
{
    struct node *temp = malloc(sizeof(node));

    if (temp!=NULL)
    {
        temp = top;
        while (temp !=NULL)
        {
            printf("\n%d:", temp->data);
            temp = temp->link;
        }
    }
}

int main()
{
    push (1);
    push (2);
    push (3);
    push (4);

    display();

    pop();
    pop();
    display();
    return 0;
}
