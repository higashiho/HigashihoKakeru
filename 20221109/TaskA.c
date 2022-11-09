#include <stdio.h>
#include <stdlib.h>
int main()
{
    int valueSize = 10, value = 1;
    int data[10];

    for(int i = 0; i < valueSize; i++)
    {
        data[i] = value + i;
        printf("%d\n",data[i]);
    }

    for (int i = 0; i< valueSize; i++)
    {
        int r = rand() % valueSize;
        int tmp = data[i];
        data[i] = data[r];
        data[r] = tmp;
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