#include <iostream>
#include <vector>

#define size 5

std::vector<int>stack({});

// プロトタイプ宣言
void push(int);
int pop();
int main()
{
    push(1);
    push(3);
    push(5);
    push(7);
    push(9);
    pop();
    pop();

    return 0;
}

void push(int n)
{
    stack.emplace_back(n);
    for (auto vec : stack)
        std::cout << vec << ",";

    std::cout << std::endl;
}


int pop()
{
    stack.pop_back();
    for (auto vec : stack)
        std::cout << vec << ",";

    std::cout << std::endl;
    return 0;

}