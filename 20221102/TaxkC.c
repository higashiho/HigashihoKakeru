#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valueSize = 100;
    int value[valueSize];
    int startValue = 1;

    for(int i = 0; i < valueSize; i++)
        value[i] = i + startValue;
    
    for(int i = 0; i < valueSize; i++)
    {
        if(value[i] % 15 == 0)
            printf("fizz buzz [%d]\n", value[i]);
        else if(value[i] % 5 == 0)
            printf("fizz [%d]\n", value[i]);
        else if(value[i] % 3 == 0)
            printf("buzz [%d]\n", value[i]);
    }

    return 0;
}