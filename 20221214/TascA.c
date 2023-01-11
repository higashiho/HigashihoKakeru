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
    START = -1,
    LEFT = 0,
    UP = 1,
    RIGHT = 2,
    DOWN = 3
} move;

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
int searchRight[SEARCH_SIZE];
int nowSearchRightValue = 0;
int searchLeft[SEARCH_SIZE];
int nowSearchLeftValue = 0;

// プロトタイプ宣言
bool checkValue(int);
void printData();
bool goalChek(int);
void movePush();
void moveIndex(int*, int*);
void onExplored(int*, int);
void moveSearch(int*, int*);
void plasMove(int*, int, int*);
void startMoveSearch();

int main()
{

    move = START;
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
            printf("Up%d,Down%d,Left%d,Right%d",
                nowSearchUpValue,
                nowSearchDownValue,
                nowSearchLeftValue,
                nowSearchRightValue
            );
            printf("\n");
            for (int i = 0; i < nowSearchDownValue; i++)
            {
                printf("%d,", searchDown[i]);
            }
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
    return 0;
}

// 移動した場所格納用
void onExplored(int* index, int value)
{
    int ind = *index;
    explored[ind++] = value;
    *index = ind;
}
// 移動回数
void plasMove(int* index, int value, int* data)
{
    int ind = *index;
    data[ind++] = value;
    *index = ind;
}

// 移動した先格納と移動
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
                return;
                //return 0;
            }
        }
    }
}

// 移動ステート
void movePush()
{
    int nowValue = data[row][col];
    switch (move)
    {
    case START:
        startMoveSearch();
        move = LEFT;
        break;
    case LEFT:
        moveSearch(&nowSearchLeftValue, searchLeft);
        move = UP;
        break;
    case UP:
        moveSearch(&nowSearchUpValue, searchUp);
        move = RIGHT;
        break;
    case RIGHT:
        moveSearch(&nowSearchRightValue, searchRight);
        move = DOWN;
        break;
    case DOWN:
        moveSearch(&nowSearchDownValue, searchDown);
        move = LEFT;
        break;
    default:
        break;
    }
}

// 移動先調査
void moveSearch(int* value, int* moveData)
{
    int count = 0;
    int right = 1, left = -1, up = -1, down = 1;

    if (checkValue(data[row + left][col]) && (row + left) >= MIN_ROW)
    {
        onExplored(&exploredIndex, data[row + left][col]);
        plasMove(value, data[row + left][col], moveData);
        count++;
    }
    if (checkValue(data[row][col + up]) && (col + up) >= MIN_COL)
    {
        plasMove(value, data[row][col + up], moveData);
        onExplored(&exploredIndex, data[row][col + up]);
        count++;
    }
    if (checkValue(data[row + right][col]) && (row + right) < MAX_ROW)
    {
        plasMove(value, data[row + right][col], moveData);
        onExplored(&exploredIndex, data[row + right][col]);
         count++;
    }
    if (checkValue(data[row][col + down]) && (col + down) < MAX_COL)
    {
        plasMove(value, data[row][col + down], moveData);
        onExplored(&exploredIndex, data[row][col + down]);
        count++;
    }
    if (count == 0)
        *value = 0;
}

// 初期移動用
void startMoveSearch()
{
    int count = 0;
    int right = 1, left = -1, up = -1, down = 1;

    if (checkValue(data[row + left][col]) && (row + left) >= MIN_ROW)
    {
        plasMove(&nowSearchLeftValue, data[row + left][col], searchLeft);
        onExplored(&exploredIndex, data[row + left][col]);
        count++;
    }
    if (checkValue(data[row][col + up]) && (col + up) >= MIN_COL)
    {
        plasMove(&nowSearchUpValue, data[row][col + up], searchUp);
        onExplored(&exploredIndex, data[row][col + up]);
        count++;
    }
    if (checkValue(data[row + right][col]) && (row + right) < MAX_ROW)
    {
        plasMove(&nowSearchRightValue, data[row + right][col], searchDown);
        onExplored(&exploredIndex, data[row + right][col]);
        count++;
    }
    if (checkValue(data[row][col + down]) && (col + down) < MAX_COL)
    {
        plasMove(&nowSearchDownValue, data[row][col + down], searchRight);
        onExplored(&exploredIndex, data[row][col + down]);
        count++;
    }
}


// 表示
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

// いけない道か判断
bool checkValue(int data)
{
    for (int i = 0; i < exploredIndex; i++)
    {
        if (explored[i] == data)
        {
            return false;
        }
    }
    for (int i = 0; i < _countof(noMove); i++)
    {
        if (noMove[i] == data)
        {
            return false;

        }
    }

    return true;
}

// ゴールチェック
bool goalChek(int data)
{
    if (data == goalValue)
        return true;
    else return false;
}