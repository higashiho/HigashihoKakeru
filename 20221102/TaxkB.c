#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valueSize = 10;
    int value[valueSize];

    for(int i = 0; i < valueSize; i++)
    {
        value[i] = rand();
        printf("%d\n",value[i]);
    }
    return 0;
}