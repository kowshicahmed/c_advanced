#include <stdio.h>
#include <stdlib.h>
#include "ses_scheduler.h"

enum color {RED, GREEN, YELLOW};
void led_toggle(int color);

int main()
{


    taskDescriptor * task_1 = NULL;

	task_1 = malloc(sizeof(taskDescriptor));
	task_1 = (taskDescriptor *)create_new_task((task_t)led_toggle,1,2000, (void *)GREEN);
    scheduler_add(task_1);


    taskDescriptor * task_2 = NULL;
    task_2 = malloc(sizeof(taskDescriptor));
    task_2 = (taskDescriptor *)create_new_task((task_t)led_toggle,2,2000, (void *)YELLOW);
    scheduler_add(task_2);

    scheduler_init();
	scheduler_run();
    return 0;
}

void led_toggle(int color){

    printf("the color is %d", color);
}
