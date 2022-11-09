#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maxValue = 100, value = 1;
    int data[100];

    for(int i = 0; i < maxValue; i++)
    {
        data[i] = rand();
    }
    for(int i = 0; i < maxValue; i++)
    {
        for(int j = i + 1; j < maxValue; j++)
        {
            if(data[i] > data[j])
            {
                int tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }

    for(int i = 0; i < maxValue; i++)
    {
        printf("%d \n", data[i]);
    }

    return 0;
}
