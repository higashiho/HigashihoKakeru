#include <iostream>
#include <vector>


std::vector<int> queue({});

void  printQueue();
void enqueue(int);
void dequeue();


int main()
{

    enqueue(1);
    printQueue();
    enqueue(3);
    printQueue();
    enqueue(5);
    printQueue();
    enqueue(7);
    printQueue();
    enqueue(9);
    printQueue();

    dequeue();
    printQueue();
    dequeue();
    printQueue();

    queue.shrink_to_fit();

    return 0;
}

// データ追加
void enqueue(int input)
{
    queue.emplace_back(input);
}

// データ取得
void dequeue()
{
    queue.erase(queue.begin());
}

void printQueue()
{
    for (auto vec : queue)
    {
        std::cout << vec << ",";
    }
    std::cout << std::endl;
}
