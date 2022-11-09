#include <stdio.h>

int main()
{
    int valueSize = 10, value = 1;
    int data[10];

    for(int i = 0; i < valueSize; i++)
    {
        data[i] = value + i;
        printf("%d\n",data[i]);
    }

    int target = 5, i = 0;
    while(i < valueSize)
    {
        if(target == data[i])
        {
            printf("%d Found it. index is %d", target, i);
            break;
        }
        i++;
        if(i == valueSize)
        {
            printf("%d Not Found.", target);
        }
    }
    return 0;
}