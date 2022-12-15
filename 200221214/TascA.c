#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10        // スタックサイズ
#define EXPLORED_SIZE 65
#define SEARCH_SIZE 65
#define NO_MOVE_SIZE 26
#define MAX_ROW 8
#define MAX_COL 8
#define MIN_ROW 0
#define MIN_COL 0

enum MOVE_CASE {
    LEFT = 0,
    UP = 1,
    RIGHT = 2,
    DOWN = 3
};
MOVE_CASE move;

int data[MAX_ROW][MAX_COL];
int value = 0;
int noMove[NO_MOVE_SIZE] =
{ 9, 10, 12, 13, 15, 16, 17, 18, 28, 29, 30, 33, 34, 35, 36, 37, 38, 44, 46, 49, 50, 51, 61, 62, 63 };
int row = 2, col = 3;    // スタート座標
int goalValue = 54;
int exploredIndex = 0;
int explored[EXPLORED_SIZE];
int searchCount = 0;        // 探索回数

int searchUp[SEARCH_SIZE];
int nowSearchUpValue = 0;
int searchDown[SEARCH_SIZE];
int nowSearchDownValue = 0;
int searchRigit[SEARCH_SIZE];
int nowSearchRigitValue = 0;
int searchLeft[SEARCH_SIZE];
int nowSearchLeftValue = 0;

// プロトタイプ宣言
bool checkValue(int);
void printData();
bool goalChek(int);
void movePush();
void moveIndex(int*, int*);
void onExplored(int*, int);
void moveSearch(int*);


int main()
{
    move = LEFT;
    for (int i = 0; i < _countof(data); i++)
    {
        for (int j = 0; j < _countof(data[i]); j++)
        {
            data[i][j] = value++;
        }
    }
    // 初期場所代入
    onExplored(&exploredIndex, data[row][col]);
    int m_goalCount = 0;
    while (true)
    {
        printf("\n");
        if (goalChek(data[row][col]))
        {
            printf("I'm on Goal.\n");
            printf("Small value is.");
            break;
        }
        else
        {
            moveIndex(&row, &col);
            searchCount++;
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
void moveIndex(int* row, int* col)
{
    int value = explored[searchCount];
    for (int i = 0; i < _countof(data); i++)
    {
        for (int j = 0; j < _countof(data[i]); j++)
        {
            if (data[i][j] == value)
            {
                *row = i;
                *col = j;
                movePush();
                return 0;
            }
        }
    }
}
void movePush()
{
    int nowValue = data[row][col];
    switch (move)
    {
    case LEFT:
        moveSearch(&nowSearchLeftValue);
        move = UP;
        break;
    case UP:
        moveSearch(&nowSearchUpValue);
        move = RIGHT;
        break;
    case RIGHT:
        moveSearch(&nowSearchRigitValue);
        move = DOWN;
        break;
    case DOWN:
        moveSearch(&nowSearchDownValue);
        move = UP;
        break;
    default:
        break;
    }
}

void moveSearch(int* value)
{
    int count = 0;
    int right = 1, left = -1, up = -1, down = 1;

    if (checkValue(data[row + left][col]) && (row + left) >= MIN_ROW)
    {
        onExplored(&exploredIndex, data[row + left][col]);
        *value++; count++;
    }
    if (checkValue(data[row][col + up]) && (col + up) >= MIN_COL)
    {
        onExplored(&exploredIndex, data[row][col + up]);
        *value++; count++;

    }
    if (checkValue(data[row + right][col]) && (row + right) < MAX_ROW)
    {
        onExplored(&exploredIndex, data[row + right][col]);
        *value++; count++;

    }
    if (checkValue(data[row][col + down]) && (col + down) < MAX_COL)
    {
        onExplored(&exploredIndex, data[row][col + down]);
        *value++; count++;
    }
    if (count == 0)
        *value = 0;
}

void printData()
{
    for (int i = 0; i < _countof(data); i++)
    {
        for (int j = 0; j < _countof(data[i]); j++)
        {
            if (checkValue(data[i][j]))
                printf("%2d\n", data[i][j]);
        }
    }
}
bool checkValue(int data)
{
    for (int i = 0; i < exploredIndex; i++)
    {
        if (explored[i] == data)
        {
            printf("b");
            return false;
        }
    }
    for (int i = 0; i < _countof(noMove); i++)
    {
        if (noMove[i] == data)
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
    if (data == goalValue)
        return true;
    else return false;
}