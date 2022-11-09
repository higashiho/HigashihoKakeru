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
    int right = maxValue;

    int target = 50;
    while(left <= right) {
     int mid = (left + right) / 2; 
     printf("%d is\n", data[mid]);
        if (data[mid] == target) {
            printf("Found!\n");
            return 0;
        } else if (data[mid] < target) {
            printf("include :%d\n",mid);
            left = mid + 1; 
        } else {
            printf("include :%d\n",mid);
            right = mid - 1; 
        }
    }
    printf("Not Found.\n");
    return 0;
}