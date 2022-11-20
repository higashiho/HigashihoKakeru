#include <stdio.h>

// 管理するデータの上限数＋１
#define MAX_NUM (5+1)

typedef struct QUEUE{
    int tail;               // データの最後尾
    int head;               // データの先頭
    int data[MAX_NUM];      // キューのデータ
} QUEUE_T;

void initQueue(QUEUE_T*);
void  printQueue(QUEUE_T*);
void enqueue(QUEUE_T*, int);
int dequeue(QUEUE_T*);

// 初期化
void initQueue(QUEUE_T *queue)
{
    queue->head = 0;
    queue->tail = -1;
}

// データ追加
void enqueue(QUEUE_T* queue, int input)
{
    
    // キューが満杯の場合
    if((queue->tail +2) % MAX_NUM == queue->head)
    {
        return;
    }

    // データを最後尾の一つ後ろに格納
    queue->data[(queue->tail + 1) % MAX_NUM] = input;
    // データの最後尾を一つ後ろに移動
    queue->tail = (queue->tail +1) % MAX_NUM;
}

// データ取得
int dequeue(QUEUE_T* queue)
{
    int ret = 0;

    // キューが空の場合
    if((queue->tail + 1) % MAX_NUM == queue->head)
    {
        return -1;
    }

    // データの先頭からデータ取得
    ret = queue->data[queue->head];

    // 先頭を一つ後ろにずらす
    queue->head = (queue->head +1) % MAX_NUM;

    return ret;
}

void printQueue(QUEUE_T *queue)
{
    int i = 0;
    int num;

    // キュー内のデータ個数計算
    if(queue->tail < queue->head)
    {
        num = queue->tail + MAX_NUM - queue->head +1;
    }
    else
    {
        num = queue->tail - queue->head + 1;
    }

    for(i = 0; i < num; i++)
    {
        // データの先頭からnum子分のデータ表示
        printf("%d,", queue->data[(queue->head + i) % MAX_NUM]);
    }
    printf("\n");
}

int main()
{
    int output;
    QUEUE_T queue;

    initQueue(&queue);

    enqueue(&queue, 1);
    printQueue(&queue);
    enqueue(&queue, 3);
    printQueue(&queue);
    enqueue(&queue, 5);
    printQueue(&queue);
    enqueue(&queue, 7);
    printQueue(&queue);
    enqueue(&queue, 9);
    printQueue(&queue);
    
    output = dequeue(&queue);
    printQueue(&queue);

    output = dequeue(&queue);
    printQueue(&queue);

    return 0;
}