#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void send (void *pData, int nLength);



int main()
{
    int i = 10;
    float f = 2.34;
    char ch = 'k';

    void *vptr = NULL;
    vptr = &i;
    printf("value of i = %d\n", *(int *)vptr);

    vptr = &f;
    printf("Value of f = %.2f\n", *(float *)vptr);

    vptr = &ch;
    printf("Value of ch = %c", *(char *)vptr);

    char *data = "blah";
    send (data, strlen(data));

    int aiData[3] = {100, 200, 300};

    void *pvData = &aiData[0];
    pvData += sizeof(int);
    printf("\n%d", *(int *)pvData);
    return 0;
}

void send (void *pData, int nLength)
{
    for(int i = nLength; i >0; i--)
    {
        printf("\nvalue of void = %c", *(char *)pData);
        pData++;
    }

}
