#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int valueSize = 10, value = 1;
    int data[10];

    for(int i = 0; i < valueSize; i++)
    {
        data[i] = value + i;
    }

    for (int i = 0; i< valueSize; i++)
    {
        int r = rand() % valueSize;
        int tmp = data[r];
        data[r] = data[i];
        data[i] = tmp;
    }

    for(int i = 0; i<valueSize;i++)
    {
        printf("%d\n", data[i]);
    }

    int target = 5;
    int result = -1;
    for(int i = 0;i < valueSize; i++)
    {
        if(target == data[i])
        {
            result = i;
            break;
        }
    }
    printf("target is index : %d", result);
    return 0;
}