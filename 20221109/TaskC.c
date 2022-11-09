#include<stdio.h>
#include<stdlib.h>

int main()
{
    int maxValue = 100, value = 1;
    int data[100];

    for(int i = 0; i < maxValue; i++)
    {
        data[i] = rand() % 100;
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

    int left = 0;
    int right = maxValue - 1;
    int result = -1;

    int target = 50;
    while(left < right) {
     int mid = (left + right) / 2; 
        if (data[mid] == target) {
            result = mid;
            break;
        } else if (data[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid; 
        }
    }
    if(result >= 0)
        printf("Target is index : %d\n", result);
    else
        printf("Not Find.\n");
    return 0;
}