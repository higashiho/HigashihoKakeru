#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10        // スタックサイズ
#define MAX_ROW 8
#define MAX_COL 8
#define MIN_ROW 0
#define MIN_COL 0

int stack[SIZE];        // スタック
int sp = 0;

int data[MAX_ROW][MAX_COL];
int value = 0;
int noMove[26] = 
{9, 10, 12, 13, 15, 16, 17, 18, 28, 29, 30, 33, 34, 35, 36, 37, 38, 44, 46, 47, 49, 50, 51, 61, 62, 63};
int row = 2,col = 3;    // スタート座標
int goalValue = 54;
int exploredIndex = 0;
int explored[65];

// プロトタイプ宣言
void push(int);
int pop();
bool chekValue(int);
void printData();
bool goalChek(int);
void movePush();
void moveIndex(int*,int*);
void onExplored(int*, int);


int main()
{
    for(int i = 0; i < _countof(data); i++)
    {
        for(int j = 0; j < _countof(data[i]); j ++)
        {
            data[i][j] = value++;
        }
    }
    // 初期場所代入
    onExplored(&exploredIndex, data[row][col]);
    while(true)
    {
        printf("\n");
        if(goalChek(data[row][col]))
        {
            printf("I'm on Goal.\n");
            break;
        }
        else 
        {
            movePush();
            moveIndex(&row, &col);
            printf("index : [%d:%d] value : %d\n", row, col, data[row][col]);
        }
        
        for (int i = 0; i < exploredIndex; i++)
        {
            printf("%d ", explored[i]);
        }
        printf("\n");
    }
}

void onExplored(int* index, int value)
{
    int ind = *index;
    explored[ind++] = value;
    *index = ind;
}
void moveIndex(int* row,int* col)
{
    int value = pop();
    for(int i = 0; i < _countof(data); i++)
    {
        for(int j = 0; j < _countof(data[i]); j++)
        {
            if(data[i][j] == value)
            {
                *row = i;
                *col = j;
                return 0;
            }
        }
    }
}
void movePush()
{
    int nowValue = data[row][col];
    int right = 1, left = -1, up = -1, down = 1;
    
    if(chekValue(data[row][col + down]) && (col + down) < MAX_COL)
    {
        onExplored(&exploredIndex, data[row][col + down]);
        push(data[row][col + down]);
    }
    if(chekValue(data[row + right][col]) && (row + right) < MAX_ROW)
    {
        onExplored(&exploredIndex, data[row + right][col]);
        push(data[row + right][col]);
    }
    if(chekValue(data[row][col + up]) && (col + up) >= MIN_COL)
    {
        onExplored(&exploredIndex, data[row][col + up]);
        push(data[row][col + up]);
    }
    if(chekValue(data[row + left][col]) && (row + left) >= MIN_ROW)
    {
        onExplored(&exploredIndex, data[row + left][col]);
        push(data[row + left][col]);
    }
}

void printData()
{
    for(int i = 0; i < _countof(data); i++)
    {
        for(int j = 0; j < _countof(data[i]); j++)
        {
            if(chekValue(data[i][j]))
                printf("%2d\n",data[i][j]);
        }
    }
}
bool chekValue(int data)
{
    for(int i = 0; i < exploredIndex; i++)
    {
        if(explored[i] == data)
        {
            printf("b");
            return false;
        }
    }
    for(int i = 0; i < _countof(noMove); i++)
    {
        if(noMove[i] == data)
        {
            printf("a");
            return false;

        }
    }
    
    printf("c");
    return true;
}
bool goalChek(int data)
{
    if(data == goalValue)
        return true;
    else return false;
}
void push(int n)
{
    if(sp < SIZE)
    {
        stack[sp] = n;
        sp++;
    }
    else
    {
        return 0;
    }
    for(int i = 0; i < sp; i++)
        printf("%d ",stack[i]);
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
	return stack[sp];
}