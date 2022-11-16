#include <stdio.h>

#define size 5

int stack[size];        // スタック
int sp = 0;

// プロトタイプ宣言
void push(int);
int pop();
int main()
{
    int d;
    push(1);
    push(3);
    push(5);
    push(7);
    push(9);
    pop();
    d = pop();

    return 0;
}

void push(int n)
{
    if(sp < size)
    {
        stack[sp] = n;
        sp++;
    }
    else
    {
        return 0;
    }
    for(int i = 0; i < sp; i++)
        printf("%d,",stack[i]);
    printf("\n");
}


int pop()
{
    if(sp > 0)
    {
		sp--;
    }
    else
    {
        return -1;
    }
    

    for(int i = 0; i < sp; i++)
        printf("%d,",stack[i]);
    printf("\n");
	return 0;

}