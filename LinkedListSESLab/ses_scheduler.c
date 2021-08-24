/*INCLUDES ************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ses_scheduler.h"


/* PRIVATE VARIABLES **************************************************/
/** list of scheduled tasks */
static taskDescriptor *taskList = NULL;

/*FUNCTION DEFINITION *************************************************/
static void scheduler_update(void)
{
	taskDescriptor *ptr;
	ptr = taskList;
    int expire_value = ptr->expire;
    while (ptr) {
	while (ptr->expire != 0) {
		ptr->expire--;
	}
        printf("\nExpire = %d\n", ptr->expire);
		if (ptr->expire == 0) {
            printf("\nExpire = %d\n", ptr->expire);
			//ptr->expire = ptr->period;
			ptr->execute = 1;
			printf("\nExecute = %d\n", ptr->execute);
		}

        if (ptr->period == 0 &&ptr->expire == 0)
        {
            ptr = ptr->next;
        }

        else if (ptr->period > 0 && ptr->expire == 0)
        {
            //ptr->expire = expire_value;
            ptr->period--;
        }

        //ptr = ptr->next;
	}

}

void scheduler_init()
{

    scheduler_update ();

}

void scheduler_run(void *value)
{
    taskDescriptor *current_task, *to_delete;


	while (1)
	{
		current_task = taskList;
        int expire_value = current_task->expire;
		while (current_task)
		{
			if (current_task->execute == 1)
			{
				printf("\nExecute = %d\n", current_task->execute);
				current_task->task (current_task->param);
				//current_task->expire = current_task->period;
				current_task->execute = 0;
			}

			if (current_task->period == 0)
			{
				to_delete = current_task;
				scheduler_remove (to_delete);
				current_task = current_task->next;
			}

			if (current_task->period > 0)
        {
            current_task->expire = expire_value;
            current_task->period--;
        }

			//current_task = current_task->next;
		}
	}
}

bool scheduler_add(taskDescriptor *toAdd)
{
	taskDescriptor *new_node = toAdd;
	new_node->next = taskList;
	taskList = new_node;

	return true;
}

void scheduler_remove(taskDescriptor *toRemove)
{
	taskDescriptor * current;
	current = taskList->next;

	if (toRemove == taskList)
	{
		free(taskList);
		taskList = current;
	}

	else
	{
		current = taskList;
		while (current)
		{
			if (current->next == toRemove)
			{
				current->next = toRemove->next;
				free (toRemove);
			}

			else
			{
				current = current->next;
			}

		}
	}
}

taskDescriptor *create_new_task(task_t task, uint16_t period, uint16_t expire, void *param)
{
	taskDescriptor *new_task = NULL;
	new_task = (taskDescriptor *)malloc(sizeof(taskDescriptor));

	if (new_task != NULL)
	{
		new_task->next = NULL;
		new_task->task = task;
		new_task->param = param;
		new_task->period = period;
		new_task->expire = expire;
		new_task->execute = 0;
	}
	return new_task;
}
