#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



typedef struct taskdescriptor_s
{
    int data;
    struct taskdescriptor_s *next;
}taskdescriptor;

taskdescriptor *tasklist = NULL;

taskdescriptor* create_task (int data);

void task_add (taskdescriptor *task);

int main()
{

    taskdescriptor *task1 = NULL;
    task1 = create_task(10);

    task_add(task1);


    return 0;
}

taskdescriptor* create_task (int data)
{
    taskdescriptor *newtask = NULL;
    newtask = malloc (sizeof(taskdescriptor));

    newtask->data = data;

    return newtask;
}

void task_add(taskdescriptor *task)
{
    taskdescriptor *newnode;

    newnode = task;

    if (tasklist == NULL)
    {
        tasklist = newnode;
        tasklist ->next = NULL;
    }

    printf("%d", tasklist->data);
}

