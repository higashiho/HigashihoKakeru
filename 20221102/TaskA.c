#include <stdio.h>

int main()
{
    printf("Hello. World\n"); 

    int value = 1;
    int maxValue = 10;

    for(int i = 0; i < maxValue; i++){
        printf("%d\n", value + i);
    }
    return 0;
}