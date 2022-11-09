#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maxValue = 100, value = 1;
    int data[100];

    for(int i = 0; i < maxValue; i++)
    {
        data[i] = rand();
        printf("%d \n", data[i]);
    }
}
