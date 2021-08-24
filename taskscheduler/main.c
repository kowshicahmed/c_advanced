#include <stdio.h>
#include <stdlib.h>

void get(void *aNumber); // input task
void increment(void* aNumber); // computation task
void display(void* aNumber); // output task

void get(void* aNumber) { //input task
int* intPtr = (int*) aNumber;
printf("Enter a number: 0..9");
*intPtr = getchar();
getchar();
*intPtr -= '0';
return;
}
void increment(void* aNumber) { // computation task
int* intPtr = (int*) aNumber;
(*intPtr)++;
return;
}
void display(void* aNumber) { // output task
printf("The result is: %d\n", *(int*) aNumber);
return;
}

void main() {
int i = 0; // queue index
int data; // shared data
int* intPtr = &data; // pointer to data
void (*queue[3])(void*); // task queue
queue[0] = get;
queue[1] = increment;
queue[2] = display;
while (1) { // scheduler
queue[i]((void*) intPtr); // dispatch task
i = (i+1)% 3;
}
return;
}
